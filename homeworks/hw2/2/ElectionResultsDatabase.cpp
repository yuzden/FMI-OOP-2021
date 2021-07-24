#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    SectionVotes temp;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        while (inputFile >> temp) {
            results.push_back(temp);
        }
    }
}

int ElectionResultsDatabase::numberOfSections() const
{
    int numOfLines = results.size();
    return numOfLines;
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
    int allVotesForParty = 0;
   
    for (int i = 0; i < results.size(); i++) {
        if (party == Party::PARTY1) {
            allVotesForParty += results[i].getParty1Votes();
        }
        else if (party == Party::PARTY2) {
            allVotesForParty += results[i].getParty2Votes();
        }
        else {
            allVotesForParty += results[i].getParty3Votes();
        }
    }
    return allVotesForParty;
}

Party ElectionResultsDatabase::winningParty() const
{
    int allVotesParty1 = votesForParty(Party::PARTY1);
    int allVotesParty2 = votesForParty(Party::PARTY2);
    int allVotesParty3 = votesForParty(Party::PARTY3);

    if (allVotesParty1 >= allVotesParty2 && allVotesParty1 >= allVotesParty3) {
        return Party::PARTY1;
    }
    else if (allVotesParty2 > allVotesParty1 && allVotesParty2 >= allVotesParty3) {
        return Party::PARTY2;
    }
    else {
        return Party::PARTY3;
    }
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& database)
{
    SectionVotes votes;
    while (input >> votes) {
        database.results.push_back(votes);
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const ElectionResultsDatabase& database)
{
    int size = database.results.size();
    for (int i = 0; i < size; i++) {
        output << database.results[i];
    }
    return output;
}
