#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Variables
std::vector<std::string> upperParameters;
std::string upperString;

std::vector<std::string> lowerParameters;
std::string lowerString;

std::vector<std::string> totalVotes;

int votingData[2]; // 0: Total, 1: Voted
int totalCandidates;
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

void processData(){
    upperParameters = splitString(' ', upperString);
    lowerParameters = splitString(' ', lowerString);

    votingData[0] = std::stoi(upperParameters[0]);
    votingData[1] = std::stoi(upperParameters[4]);
    totalCandidates = std::stoi(upperParameters[2]);

    std::cout << "Total: " << votingData[0] << "\nVoted: " << votingData[1] << "\nCandidates: " << totalCandidates << std::endl;

    for (int i; i < votingData[1]; i++) {
        int lastDone;
        if(i % 2 == 0){
            std::cout << i << std::endl;
            totalVotes.push_back(lowerParameters[i]);
            lastDone = i;
        }else{
            if(i != lastDone){
                totalVotes.push_back(lowerParameters[i+1]);
                std::cout << i+1 << std::endl;
            }
        }
    }

    // for(auto i : totalVotes){
    //     std::cout << i << std::endl;
    // }
}

void readFile(std::string file){
    std::ifstream fileOpen(file);
    std::getline(fileOpen, upperString);
    std::getline(fileOpen, lowerString);
    fileOpen.close();
}

int main(){
    readFile("test.in");
    processData();

    return 0;
}