#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Variables
std::vector<std::string> upperParameters;
std::string upperString;

// Code
std::vector<std::string> splitString(char splitWith, std::stringstream SSIn){
    std::string tmp;
    std::vector<std::string> returnStrings;
    
    while(std::getline(SSIn, tmp, splitWith)){
        returnStrings.push_back(tmp);
    }

    return returnStrings;
}

void readFile(std::string file){
    std::ifstream fileOpen(file);
    std::getline(fileOpen, upperString);
    fileOpen.close();

    std::string tmp;
    std::stringstream SS(upperString);
    std::vector<std::string> result = splitString(' ', SS);
}

int main(){
    readFile("test.in");
    return 0;
}