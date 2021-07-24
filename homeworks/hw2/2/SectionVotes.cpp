#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
	:party1Votes(party1Votes), party2Votes(party2Votes), party3Votes(party3Votes)
{
}

int SectionVotes::votesForParty(Party party) const
{
	if (party == Party::PARTY1) {
		return party1Votes;
	}
	else if (party == Party::PARTY2) {
		return party2Votes;
	}
	else {
		return party3Votes;
	}
}

SectionVotes::SectionVotes()
	:party1Votes(0), party2Votes(0), party3Votes(0)
{
}

int SectionVotes::getParty1Votes() const
{
	return party1Votes;
}

int SectionVotes::getParty2Votes() const
{
	return party2Votes;
}

int SectionVotes::getParty3Votes() const
{
	return party3Votes;
}

std::istream& operator>>(std::istream& input, SectionVotes& section)
{
	int party1Votes, party2Votes, party3Votes;
	input >> party1Votes >> party2Votes >> party3Votes;
	section = SectionVotes(party1Votes, party2Votes, party3Votes);
	return input;
}

std::ostream& operator<<(std::ostream& output, const SectionVotes& Votes)
{
	output << std::endl << Votes.party1Votes << " " << Votes.party2Votes << " " << Votes.party3Votes;
	return output;
}
