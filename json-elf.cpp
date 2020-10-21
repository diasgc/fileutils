#include <jsoncpp/json/json.h>
#inclide <elf.h>
#include "elf_strings.h"
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <iostream>

Json::Value getElf(std::string path){

  FILE* file = fopen(filename, "r");
  if (file == NULL){
      printf("Failed to open file\n");
      return ERR_OPEN_FILE;
  }
  Json::Value json(Json::arrayValue);

  struct stat file_stat;

  if (fstat(fileno(file), &file_stat) < 0){
      printf("Failed to stat file\n");
      return ERR_STAT_FILE;
  }

  file_data = malloc(file_stat.st_size * sizeof(char));

  if (!fread(file_data, file_stat.st_size, 1, file)){
      printf("Failed to read file contents\n");
      return ERR_READ_FILE;
  }

  fclose(file);
  
  header = (Elf64_Ehdr*)file_data;
  
  if (header->e_ident[EI_CLASS] == ELFCLASS32){
    
  }
  // Lookup shstrtab
  shstrtab = file_data + section_header(header->e_shstrndx)->sh_offset;
  // Find strtab
  for (int i = 0; i < header->e_shnum; i++){
      Elf64_Shdr* sh = section_header(i);

      if (sh->sh_type == SHT_STRTAB && strcmp(lookup_shstrtab(sh->sh_name), ".strtab") == 0){
          strtab = file_data + sh->sh_offset;
          break;
      }
  }
    
  if(dirp) {
    while( ( p = readdir(dirp)) != nullptr ){
      if( strcmp( p->d_name, ".") == 0 || strcmp( p->d_name, "..") == 0){
        continue;
      }
      if( p->d_type == DT_DIR) {
        Json::Value dir_val;
        dir_val["type"] = "directory";
        dir_val["name"] = p->d_name;
        dir_val["contents"] = getDirectoryTreeFromPath(path + std::string("/") + std::string(p->d_name));
        json.append(dir_val);
      } else if ( p->d_type == DT_REG ){
        Json::Value file_val;
        file_val["type"] = "file";
        file_val["name"] = p->d_name;
        json.append(file_val);
      }
    }

  }

  return json; 
}

Json::Value parse64BitHeader(int *file_data){
  
}

int main(int argc, char* argv[]){
  
  if(argc < 2){
    return EXIT_FAILURE;
  }
 
  std::cout <<
    getElf(std::string(argv[1])).toStyledString()
    << std::endl;

  return EXIT_SUCCESS;
}
