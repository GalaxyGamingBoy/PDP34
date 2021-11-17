#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

// Classes
class Candidate{
    public:
        Candidate(int candidateId){
            _id = candidateId;
        }
        int getVotes(){
            return _votes;
        }
        int getId(){
            return _id;
        };
        void addVote(){
            _votes++;
        };
    private:
        int _id;
        int _votes;
};

// Variables
std::vector<std::string> parameters[2];
std::string strings[2];

std::vector<std::string> totalVotes;

std::vector<Candidate> candidates;

int votingData[4]; // 0: Total, 1: Voted, 2: Candidates, 3: Not Voted

int passingCandidates;

// Code
std::vector<std::string> splitString(char splitWithCharacter, std::string stringIn){
    // Split string into segments
    std::string tmpData;
    std::stringstream StringStream(stringIn);
    std::vector<std::string> returnStrings;
    
    while(std::getline(StringStream, tmpData, splitWithCharacter)){
        returnStrings.push_back(tmpData);
    }

    return returnStrings;
}

void writeFile(std::string fileName, int data){
    std::ofstream file;
    file.open(fileName);
    file << data << "\n";
    file.close();
}

void declareCandidate(){
    std::vector<int> allCandidateVotes;
    for (Candidate i : candidates){
        allCandidateVotes.push_back(i.getVotes());
    }

    // Get max vote
    int maxVoted = *max_element(allCandidateVotes.begin(), allCandidateVotes.end());

    if(votingData[0] != votingData[1]){
        for (int i : allCandidateVotes){
            if(i + votingData[3] > maxVoted){
                passingCandidates++;
            }
        }
    }
}

void countVotes(){
    // Add votes to candidate
    for (auto i : totalVotes){
        for (Candidate ii : candidates){
            if (ii.getId() == std::stoi(i) - 1){
                ii.addVote();
                candidates[ii.getId()] = ii;
            }
        }
    }
}

void addCandidates(){
    // Add candidates
    for(int i; i < votingData[2]; i++){
        candidates.push_back(Candidate(i));
    }
}

void processData(){
    // Split strings
    parameters[1] = splitString(' ', strings[1]);
    parameters[0] = splitString(' ', strings[0]);

    // Pass parameters from split strings to variables
    votingData[0] = std::stoi(parameters[1][0]);
    votingData[1] = std::stoi(parameters[1][4]);
    votingData[2] = std::stoi(parameters[1][2]);
    votingData[3] = votingData[0] - votingData[1];

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
    readFile("voting.in");
    processData();
    addCandidates();
    countVotes();
    declareCandidate();
    writeFile("voting.out", passingCandidates);
}
