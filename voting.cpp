#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Variables
std::vector<std::string> parameters[2];
std::string strings[2];

std::vector<std::string> totalVotes;

int votingData[3]; // 0: Total, 1: Voted, 2: Candidates

// Code
void printData(){
    std::cout << "Total: " << votingData[0] << "\nVoted: " << votingData[1] << "\nCandidates: " << votingData[2] << std::endl;
    for (auto i : totalVotes){
        std::cout << i << std::endl;
    }
}

std::vector<std::string> splitString(char splitWithCharacter, std::string stringIn){
    std::string tmpData;
    std::stringstream StringStream(stringIn);
    std::vector<std::string> returnStrings;
    
    while(std::getline(StringStream, tmpData, splitWithCharacter)){
        returnStrings.push_back(tmpData);
    }

    return returnStrings;
}

void processData(){
    // Split Strings
    parameters[1] = splitString(' ', strings[1]);
    parameters[0] = splitString(' ', strings[0]);

    // Pass Parameters from split strings to variables
    votingData[0] = std::stoi(parameters[1][0]);
    votingData[1] = std::stoi(parameters[1][4]);
    votingData[2] = std::stoi(parameters[1][2]);

    // Add all votes that are specified
    for (int i; i < votingData[1] * 2; i++) {
        if(i % 2 == 0){
            totalVotes.push_back(parameters[0][i]);
        }
    }
}

void readFile(std::string file){
    // Open file, read to end and save line data
    std::ifstream fileOpen(file);
    std::getline(fileOpen, strings[1]);
    std::getline(fileOpen, strings[0]);
    fileOpen.close();
}

int main(){
    readFile("test.in");
    processData();
    printData();

    return 0;
}