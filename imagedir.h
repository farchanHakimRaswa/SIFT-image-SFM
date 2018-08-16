#ifndef IMAGEDIR_H
#define IMAGEDIR_H

#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;
class imageDir
{
private:
    string fileName = "/home/achan/Documents/CODE_OF_NOTHING/Watch/fileTXT/outputlist.txt";

    struct dirent *de;
    DIR *dr;
    string list_image_file;
    int i=0;

    vector<string> names;
    string word;



public:
    string IMAGE_DIR = "/home/achan/Documents/CODE_OF_NOTHING/Watch/IMAGE_DIR";
    imageDir();
    void saveFileTxt();
    int listImage(char* directory);
    int sortList();
    vector<string> openFile();

};

#endif // IMAGEDIR_H
