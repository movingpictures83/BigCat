#ifndef BIGCATPLUGIN_H
#define BIGCATPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class BigCatPlugin : public Plugin
{
public: 
 std::string toString() {return "BigCat";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> catFiles;
};

#endif
