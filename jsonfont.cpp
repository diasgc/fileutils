//
// Created by gusta on 23/11/2020.
//

#include <unistd.h>
#include "jsonfont.h"


const char* EncodingId[7] = {
        "Unicode 1.0 semantics—deprecated",
        "Unicode 1.1 semantics—deprecated",
        "ISO/IEC 10646 semantics—deprecated",
        "Unicode 2.0 and onwards semantics, Unicode BMP only",
        "Unicode 2.0 and onwards semantics, Unicode full repertoire",
        "Unicode Variation Sequences—for use with subtable format 14",
        "Unicode full repertoire—for use with subtable format 13"
};

const char* PlatformID[5] = {
        "Unicode",              // Various
        "Macintosh",            // Script manager code
        "ISO [deprecated]",     // [deprecated]	ISO encoding [deprecated]
        "Windows",              // Windows encoding
        "Custom"                // Custom
};

const char* NameID[26] = {
        /* 0*/  "Copyright notice",
        /* 1*/  "Font Family",
        /* 2*/  "Font Subfamily",
        /* 3*/  "Unique font identifier",
        /* 4*/  "Full Name",
        /* 5*/  "Version",
        /* 6*/  "PostScript name",
        /* 7*/  "Trademark",
        /* 8*/  "Manufacturer",
        /* 9*/  "Designer",
        /*10*/  "Description",
        /*11*/  "URL Vendor",
        /*12*/  "URL Designer",
        /*13*/  "License Description",
        /*14*/  "License Info URL",
        /*15*/  "(Reserved)",
        /*16*/  "Typographic Family",
        /*17*/  "Typographic Subfamily",
        /*18*/  "Compatible Full",
        /*19*/  "Sample text",
        /*20*/  "PostScript CID",
        /*21*/  "WWS Family Name",
        /*22*/  "WWS Subfamily Name",
        /*23*/  "Light Background Palette",
        /*24*/  "Dark Background Palette",
        /*25*/  "Variations PostScript Name Prefix"
};

void jsonFnt(int fd, Json::Value &out){

    uint32_t fsz;

    if ((fsz = lseek(fd,0,SEEK_END)) == -1){
        out["err"] = strerror(errno);
        return;
    }
    lseek(fd,0,SEEK_SET);
    char* data = (char*) malloc(fsz);
    if (data == NULL){
        out["err"] = "error memory allocation";
        return;
    }
    if (read(fd, data, fsz) != fsz){
        out["err"] = "error reading file";
        return;
    }
    Header *hd;
    uint32_t offset;
    offset = hd->read(data);
    hd->json(out);

    Json::Value jtables;
    TableRecord table;
    for (int i = 0; i < hd->numTables.value; i++) {
        table.read(data, 12 + i * 16);
        const char* tag = table.tag.c_str();
        Json::Value jtable;
        if (strcmp(tag,"name") == 0){
            name n;
            n.read(data,table.offsetPos.value);
            jtable[".format"] = n.format.value;
            jtable[".count"] = n.count.value;
            NameRecord nr;
            for (int i = 0 ; i < n.count.value ; i++){
                nr = n.getRecord(data,i);
                jtable["encodingID"] = nr.getEncoding();
                jtable["platformID"] = nr.getPlatform();
                out[nr.getNameID()] = nr.getName(data + table.offsetPos.value, n.stringOffset.value);
            }
        }
        table.json(jtable);
        jtables[tag] = jtable;
    }
    out["Tables"] = jtables;

    free(data);
}

void addNameTable(const char* data, uint32_t offset, Json::Value &jname, Json::Value &root){

}