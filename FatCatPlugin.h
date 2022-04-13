#ifndef FATCATPLUGIN_H
#define FATCATPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class FatCatPlugin : public Plugin
{
public: 
 std::string toString() {return "FatCat";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> catFiles;
};

#endif
