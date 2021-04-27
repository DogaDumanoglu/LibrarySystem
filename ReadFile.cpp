//
// Created by dumanoglu on 1.12.2020.
//
#include <string.h>
#include "ReadFile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "LibrarySystem.h"
extern ofstream  outputFile;
//This file reads instructions and calls the neccessary methods
using namespace  std;
LibrarySystem librarySystem=LibrarySystem();
vector<string> splitFromTabs(string s){
    //this function splits commands from \t
    vector<string> splitElements;
    std::string delimiter = "\t";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        splitElements.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    splitElements.push_back(s);
    return splitElements;
}

void ReadFile::readCommandFile(string input) {//reads file
    vector<string> fileInfos;
    string lastCommand=" ";
    string currentCommand;

    fstream  commandFile;
    string commands;
    cout << commands << endl;

    commandFile.open(input);

    if(commandFile.is_open()){
        while(!commandFile.eof()){
            while(getline(commandFile,commands)){
                fileInfos.push_back(commands);}
        }
        commandFile.close();
    }
    for(int i=0;i<fileInfos.size();i++){
        if(i!=fileInfos.size()-1){
            fileInfos[i].erase(fileInfos[i].size()-1);//calls related functions
        }

        vector<string> commandVector=splitFromTabs(fileInfos[i]);
        currentCommand=commandVector[0];

        string output="\n==="+currentCommand+"() method test==\n";
        if(lastCommand==" "){
           outputFile<<"===Movie Library System===\n";
            outputFile<<output;
         }
        else if(lastCommand!=currentCommand){
            outputFile<<output;
        }
        const char* commandsCharArray=fileInfos[i].c_str();
        if(strncmp(commandsCharArray,"addMovie",8)==0){
            int movieId=stoi(commandVector[1]);
            string movieTitle=commandVector[2];
            int movieYear=stoi(commandVector[3]);
            librarySystem.addMovie(movieId,movieTitle,movieYear);
        }
        else if(strncmp(commandsCharArray,"addUser",7)==0){
            int userId=stoi(commandVector[1]);
            string userName=commandVector[2];
            librarySystem.addUser(userId,userName);
        }
        else if(strncmp(commandsCharArray,"showAllMovie",12)==0){
            librarySystem.showAllMovie();
        }

        else if(strncmp(commandsCharArray,"checkoutMovie",13)==0){
            int movieId=stoi(commandVector[1]);
            int userId=stoi(commandVector[2]);
            librarySystem.checkOutMovie(movieId,userId);
        }
        else if(strncmp(commandsCharArray,"showMovie",9)==0){
            int movieId=stoi(commandVector[1]);
            librarySystem.showMovie(movieId);
        }
        else if(strncmp(commandsCharArray,"showUser",8)==0){
            int userId=stoi(commandVector[1]);
            librarySystem.showUser(userId);
        }
        else if(strncmp(commandsCharArray,"deleteMovie",11)==0){
            int movieId=stoi(commandVector[1]);
            librarySystem.deleteMovie(movieId);
        }
        else if(strncmp(commandsCharArray,"deleteUser",10)==0){
            int userId=stoi(commandVector[1]);
            librarySystem.deleteUser(userId);
        }
        else if(strncmp(commandsCharArray,"returnMovie",11)==0){
            int movieId=stoi(commandVector[1]);
            librarySystem.returnMovie(movieId);
        }
    lastCommand=currentCommand;}

}
