//
// Created by dumanoglu on 1.12.2020.
//

#include "Output.h"
#include <fstream>
extern string filename;
string* argv;
void Output::writeFile(const string& outputs) {
    ofstream outputFile;
    cout << filename << endl;
    outputFile.open(filename,ios::out|ios::app);
    outputFile<<outputs;
}
