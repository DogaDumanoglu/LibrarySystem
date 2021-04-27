#include <iostream>
#include "ReadFile.h"
#include <fstream>
#include <string.h>
using namespace std;
ofstream outputFile;
string  filename;
int main(int argc,char*argv[]) {
    filename = argv[2];
    outputFile.open(filename);
    ReadFile::readCommandFile(argv[1]);
}
