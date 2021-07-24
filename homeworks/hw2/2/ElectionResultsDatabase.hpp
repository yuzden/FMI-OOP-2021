#pragma once
#include "SectionVotes.hpp"
#include <fstream>
#include <iostream>
#include <vector>


class ElectionResultsDatabase
{
    std::vector<SectionVotes> results;
public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);
};