/*
 * $ sudo apt-get install libjsoncpp-dev
 * $ g++ json_dir_tree.cpp -std=c++11 -ljsoncpp
 * $ ./a.out $(pwd)
 *  Directory tree output in json format
 *
 */

#include <jsoncpp/json/json.h>
#include <dirent.h>
#include <cstring>
#include <iostream>

Json::Value getDirectoryTreeFromPath(std::string path){

  DIR* dirp;
  struct dirent *p;
  dirp = opendir(path.c_str());

  Json::Value json(Json::arrayValue);

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

int main(int argc, char* argv[]){
  
  if(argc < 2){
    return EXIT_FAILURE;
  }
 
  std::cout <<
    getDirectoryTreeFromPath(std::string(argv[1])).toStyledString()
    << std::endl;

  return EXIT_SUCCESS;
}
