#pragma once
#include <string>
#include <vector>
#include "constants.h"

const int CPS_ESC_SEQUENCE_TYPE_TEMPALTERMODIFIERS = 1;
const int CPS_ESC_SEQUENCE_TYPE_SLEEP = 2;

struct VKeyEvent
{
    int vcode = 0;
    bool isDownstroke = true;
};

bool readSanitizeIniFile(std::vector<std::string>& iniLines);

std::vector<std::string> getSectionFromIni(std::string sectionName, std::vector<std::string> iniContent);
std::vector<std::string> getTaggedLinesFromIni(std::string tag, std::vector<std::string> iniContent);
bool configHasKey(std::string key, std::vector<std::string> iniLines);
bool configHasTaggedKey(std::string tag, std::string key, std::vector<std::string> sectionLines);
bool getStringValueForTaggedKey(std::string tag, std::string key, std::string & value, std::vector<std::string> sectionLines);
bool getStringValueForKey(std::string key, std::string & value, std::vector<std::string> sectionLines);
bool getIntValueForTaggedKey(std::string tag, std::string key, int & value, std::vector<std::string> sectionLines);
bool getIntValueForKey(std::string key, int & value, std::vector<std::string> sectionLines);
bool parseFunctionModdedkey(std::string& funcParams, std::string  scLabels[], std::vector<VKeyEvent>& strokeSeq, bool& retflag);
bool parseKeywordCombo(std::string line, int &key, unsigned short(&mods)[6], std::vector<VKeyEvent> &strokeSequence, std::string scLabels[]);
bool parseKeywordsAlpha_FromTo(std::string mapFromTo, int(&alphamap)[MAX_VCODES], std::string scLabels[]);
bool parseKeywordRewire(std::string line, int & keyA, int & keyB, int & keyC, int & keyD, std::string scLabels[]);
