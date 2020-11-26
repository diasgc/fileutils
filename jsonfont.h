//
// Created by gusta on 23/11/2020.
//

#ifndef DEVXP_R_JSONFONT_H
#define DEVXP_R_JSONFONT_H

#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "binread.h"
#include "json/json.h"

#ifdef _WIN32
#define E 0
#else
#define E 1
#endif
#endif //DEVXP_R_JSONFONT_H

// reference https://docs.microsoft.com/en-us/typography/opentype/spec/
// reference https://github.com/kv01/ttf-parser/blob/master/src/ttfParser.h

extern const char* EncodingId[7];
extern const char* PlatformID[5];
extern const char* NameID[26];


struct TableRecord {

    Tag      tag;
    uint32   checkSum;
    Offset32 offsetPos;
    uint32   length;

    uint32_t read(const char* data, uint32_t offset) {
        uint32_t o = offset;
        o += tag.read(E, data + o);
        o += checkSum.read(E, data + o);
        o += offsetPos.read(E, data + o);
        o += length.read(E, data + o);
        return o - offset;
    }

    bool checksum(){
        uint32_t *Strptr = (uint32_t *) offsetPos.value;
        uint32_t Sum = 0L;
        uint32_t *Endptr = Strptr + ((length.value + 3) & ~3) / sizeof(uint32_t);
        while (Strptr < Endptr)
            Sum += *Strptr++;
        return Sum == checkSum.value;
    }

    void json(Json::Value &out){
        out[".checkSum"]     = checkSum.value;
        out[".offsetPos"]    = offsetPos.value;
        out[".length"]       = length.value;
    }

};

struct Header {

    uint32      sfntVersion;
    uint16      numTables;
    uint16      searchRange;
    uint16      entrySelector;
    uint16      rangeShift;

    uint32_t read(const char* data) {
        uint32_t o = 0;
        o += sfntVersion.read(E,data);
        o += numTables.read(E,data + o);
        o += searchRange.read(E,data + o);
        o += entrySelector.read(E,data + o);
        o += rangeShift.read(E,data + o);
        return o;
    }

    void json(Json::Value &out){

        Json::Value jhead;
        jhead["sfntVersion"]    = sfntVersion.c_str(FMT_HEX);
        jhead["numTables"]      = numTables.c_str(FMT_HEX);
        jhead["searchRange"]    = searchRange.c_str(FMT_HEX);
        jhead["entrySelector"]  = entrySelector.c_str(FMT_HEX);
        jhead["rangeShift"]     = rangeShift.c_str(FMT_HEX);

        out["Header"] = jhead;
    }

};


// cmap (REQUIRED)      Character to glyph mapping

struct EncodingRecord {

    uint16 	    platformID; 	// Platform ID.
    uint16 	    encodingID; 	// Platform-specific encoding ID.
    Offset32 	subtableOffset; // Byte offset from beginning of table to the subtable for this encoding.

};

struct cmap {

    uint16 	version; 	// Table version number (0).
    uint16 	numTables; 	// Number of encoding tables that follow.
    struct EncodingRecord  *encodingRecords[];

};

// head (REQUIRED)      Font header
struct head {

    uint16  majorVersion;
    uint16  minorVersion;
    Fixed   fontRevision;
    uint32  checkSumAdjustment;
    uint32  magicNumber;//0x5F0F3CF5
    uint16  flags;
    uint16  unitsPerEm;
    LONGDATETIME createdDate;
    LONGDATETIME modifiedData;
    int16 xMin;
    int16 yMin;
    int16 xMax;
    int16 yMax;
    uint16 macStyle;
    uint16 lowestRecPPEM;
    int16 fontDirectionHintl;
    int16 indexToLocFormat;
    int16 glyphDataFormat;

    uint32_t read(const char* data, uint32_t offset) {

        uint32_t o = offset;
        o += majorVersion.read(E, data + o);
        o += minorVersion.read(E, data + o);
        o += fontRevision.read(E, data + o);
        o += checkSumAdjustment.read(E, data + o);
        o += magicNumber.read(E, data + o);

        o += flags.read(E, data + o);
        o += unitsPerEm.read(E, data + o);

        o += createdDate.read(E, data + o);
        o += modifiedData.read(E, data + o);

        o += xMin.read(E, data + o);
        o += yMin.read(E, data + o);
        o += xMax.read(E, data + o);
        o += yMax.read(E, data + o);
        o += macStyle.read(E, data + o);
        o += lowestRecPPEM.read(E, data + o);
        o += fontDirectionHintl.read(E, data + o);
        o += indexToLocFormat.read(E, data + o);
        o += glyphDataFormat.read(E, data + o);

        return o - offset;
    }
};

// hhea (REQUIRED)      Horizontal header
struct hhea {

    const char *_desc = "Horizontal Header Table";

    uint16 majorVersion;
    uint16 minorVersion;
    FWORD	Ascender;
    FWORD	Descender;
    FWORD	LineGap;
    UFWORD advanceWidthMax;
    FWORD	minLeftSideBearing;
    FWORD	minRightSideBearing;
    FWORD	xMaxExtent;
    int16	caretSlopeRise;
    int16	caretSlopeRun;
    int16	caretOffset;
    //int16 reserved
    //int16 reserved
    //int16 reserved
    //int16 reserved
    int16	metricDataFormat;
    uint16 numberOfHMetrics;

    uint32_t read(const char* data, uint32_t offset) {
        uint32_t o = offset;
        o += majorVersion.read(E, data + o);//majorVersion, data + o);
        o += minorVersion.read(E, data + o);//minorVersion, data + o);
        o += Ascender.read(E, data + o);//Ascender, data + o);
        o += Descender.read(E, data + o);//Descender, data + o);
        o += LineGap.read(E, data + o);//LineGap, data + o);
        o += advanceWidthMax.read(E, data + o);//advanceWidthMax, data + o);
        o += minLeftSideBearing.read(E, data + o);//minLeftSideBearing, data + o);
        o += minRightSideBearing.read(E, data + o);//minRightSideBearing, data + o);
        o += xMaxExtent.read(E, data + o);//xMaxExtent, data + o);
        o += caretSlopeRise.read(E, data + o);//caretSlopeRise, data + o);
        o += caretSlopeRun.read(E, data + o);//caretSlopeRun, data + o);

        o += sizeof(int16) * 4;

        o += metricDataFormat.read(E, data + o);
        o += numberOfHMetrics.read(E, data + o);

        return o - offset;
    }

    void json(Json::Value &out, uint16_t flags){
        out["majorVersion"] = majorVersion.value;
        out["minorVersion"] = minorVersion.value;
        out["Ascender"] = Ascender.value;
        out["Descender"] = Descender.value;
        out["LineGap"] = LineGap.value;
        out["advanceWidthMax"] = advanceWidthMax.value;
        out["minLeftSideBearing"] = minLeftSideBearing.value;
        out["minRightSideBearing"] = minRightSideBearing.value;
        out["xMaxExtent"] = xMaxExtent.value;
        out["caretSlopeRise"] = caretSlopeRise.value;
        out["caretSlopeRun"] = caretSlopeRun.value;
        out["caretOffset"] = caretOffset.value;
        out["metricDataFormat"] = metricDataFormat.value;
        out["numberOfHMetrics"] = numberOfHMetrics.value;
    }

};

// hmtx (REQUIRED)      Horizontal metrics
struct hmtx {

};

// maxp (REQUIRED)      Maximum profile
struct maxp {

    uint32 version;
    uint16 numGlyphs;
    uint16 maxPoints;
    uint16 maxContours;
    uint16 maxCompositePoints;
    uint16 maxCompositeContours;
    uint16 maxZones;
    uint16 maxTwilightPoints;
    uint16 maxStorage;
    uint16 maxFunctionDefs;
    uint16 maxInstructionDefs;
    uint16 maxStackElements;
    uint16 maxSizeOfInstructions;
    uint16 maxComponentElements;
    uint16 maxComponentDepth;

    const char *desc(){
        return "Maximum Profile";
    }

    uint32_t read(const char* data, uint32_t offset) {
        uint32_t o = offset;
        o += version.read(E, data + o);
        o += numGlyphs.read(E, data + o);
        o += maxPoints.read(E, data + o);
        o += maxContours.read(E, data + o);
        o += maxCompositePoints.read(E, data + o);
        o += maxCompositeContours.read(E, data + o);
        o += maxZones.read(E, data + o);
        o += maxTwilightPoints.read(E, data + o);
        o += maxStorage.read(E, data + o);
        o += maxFunctionDefs.read(E, data + o);
        o += maxInstructionDefs.read(E, data + o);
        o += maxStackElements.read(E, data + o);
        o += maxSizeOfInstructions.read(E, data + o);
        o += maxComponentElements.read(E, data + o);
        o += maxComponentDepth.read(E, data + o);

        return o - offset;
    }
};

// name (REQUIRED)      Naming table
struct NameRecord {

    uint16 platformID;
    uint16 encodingID;
    uint16 languageID;
    uint16 nameID;
    uint16 length;
    uint16 offset_value;

    uint32_t read(const char* data, uint32_t offset) {
        uint32_t o = offset;
        o += platformID.read(E, data + o);
        o += encodingID.read(E, data + o);
        o += languageID.read(E, data + o);
        o += nameID.read(E, data + o);
        o += length.read(E, data + o);
        o += offset_value.read(E, data + o);
        return o - offset;
    }

    const char* getName(const char* data, uint32_t offsetString){
        char *dst = (char *) malloc (length.value + 1);
        memcpy(dst, data + offsetString + offset_value.value, length.value);
        return dst;
    }

    const char* getNameID(){
        return nameID.value >= 0 && nameID.value < 25 ? NameID[nameID.value] : "unknown";
    }

    const char* getEncoding(){
        return encodingID.value >= 0 && encodingID.value < 7 ? EncodingId[encodingID.value] : "unknown";
    }

    const char* getPlatform(){
        return platformID.value >= 0 && platformID.value < 5 ? PlatformID[platformID.value] : "unknown";
    }




};

struct name {

    uint16      format;
    uint16      count;
    uint16      stringOffset;
    uint32_t    nameRecordsOffset;

    uint32_t read(const char* data, uint32_t offset) {

        uint32_t o = offset;
        o += format.read(E, data + o);
        o += count.read(E, data + o);
        o += stringOffset.read(E, data + o);
        nameRecordsOffset = o;

        return o - offset;
    }

    NameRecord getRecord(const char* data, uint16_t idx){
        NameRecord record;
        record.read(data,nameRecordsOffset + idx * 12);
        return record;
    }
};

// OS/2 (REQUIRED)      OS/2 and Windows specific metrics
struct os2 {

};

// post (REQUIRED)      PostScript information
struct post {

};





struct BASE {

    // version 0
    uint16		majorVersion;		// Major version of the BASE table, = 1
    uint16		minorVersion;		// Minor version of the BASE table, = 0
    Offset16 	horizAxisOffset;	// Offset to horizontal Axis table, from beginning of BASE table (may be NULL)
    Offset16 	vertAxisOffset;		// Offset to vertical Axis table, from beginning of BASE table (may be NULL)

    // version 1
    Offset32 	itemVarStoreOffset;	//Offset to Item Variation Store table, from beginning of BASE table (may be null)

    uint32_t parse(const char* data, uint32_t offset) {
        // todo
        return offset;
    }
};

struct AXIS {

    Offset16	baseTagListOffset;		// Offset to BaseTagList table, from beginning of Axis table (may be NULL)
    Offset16	baseScriptListOffset;	// Offset to BaseScriptList table, from beginning of Axis table

    uint32_t parse(const char* data, uint32_t offset) {
        // todo
        return offset;
    }

};

struct BaseTagList {

    uint16		baseTagCount;			// Number of baseline identification tags in this text direction — may be zero (0)
    Tag			baselineTags;			// Array of 4-byte baseline identification tags — must be in alphabetical order

    uint32_t parse(const char* data, uint32_t offset) {
        // todo
        return offset;
    }
};

void jsonFnt(int fd, Json::Value &out);
void addNameTable(const char* data, uint32_t offset, Json::Value &jname, Json::Value &root);