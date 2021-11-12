#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Variables
std::vector<std::string> upperParameters;
std::string upperString;

// Code
std::vector<std::string> splitString(char splitWith, std::string line){
    std::string tmp;
    std::stringstream SSIn(line);
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
}

int main(){
    readFile("test.in");
    return 0;
}