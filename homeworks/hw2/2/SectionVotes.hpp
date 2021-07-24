#pragma once

#include <iostream>

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
    int party1Votes, party2Votes, party3Votes;

public:

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    SectionVotes();

    int getParty1Votes() const;
    int getParty2Votes() const;
    int getParty3Votes() const;

    friend std::istream& operator>>(std::istream&, SectionVotes&);
    friend std::ostream& operator<<(std::ostream&, const SectionVotes&);
};

