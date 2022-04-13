#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FatCatPlugin.h"

#include <iostream>

void FatCatPlugin::input(std::string file) {
 inputfile = file;
    std::ifstream infile(file.c_str(), std::ios::in);
    std::string singlefile;
    std::string lastread="";
    while (!infile.eof()) {
       infile >> singlefile;
       std::cout << "READING: " << singlefile << std::endl;
       if (singlefile.length() > 1 && singlefile != lastread) {
       catFiles.push_back(singlefile);
       lastread = singlefile;
       }
    }
 }

void FatCatPlugin::run() {}

void FatCatPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "cat ";
    std::cout << catFiles.size() << std::endl;
    for (int i = 0; i < catFiles.size(); i++)
       myCommand += std::string(PluginManager::prefix()) + "/" + catFiles[i] + " ";
    myCommand += ">& "+outputfile;
    std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<FatCatPlugin> FatCatPluginProxy = PluginProxy<FatCatPlugin>("FatCat", PluginManager::getInstance());
