/*
	Segfault
	Zhang, James (TTH 2:20)

	May 17, 2020

	CS A250
	Project 2 - Part A
*/

#include "CandidateType.h"
#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms];
}

CandidateType::CandidateType(const CandidateType& temp)
	:CharacterType(temp.getFirstName(), temp.getLastName()
	, temp.getID())
{
	totalVotes = temp.totalVotes;
	numOfKingdoms = temp.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];
	
	for (int i = 0; i < numOfKingdoms; i++)
	{
		kingdomVotes[i] = temp.kingdomVotes[i];
	}

}

CandidateType& CandidateType::operator=(const CandidateType& temp)
{
	if (&temp != this)
	{
		totalVotes = temp.totalVotes;
		if (numOfKingdoms != temp.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[temp.numOfKingdoms];
			numOfKingdoms = temp.numOfKingdoms;
		}

		for (int i = 0; i < numOfKingdoms; i++)
		{
			kingdomVotes[i] = temp.kingdomVotes[i];
		}
		
	}
	else
	{
		cerr << "=> The calling object is the same.";
	}

	return *this;
}

bool CandidateType::operator==(int tempID) const
{
	return(this->getID() == tempID);
}

void CandidateType::updateVotesByKingdom(int index, int numVotes)
{
	totalVotes += numVotes;
	kingdomVotes[index] = numVotes;
}

int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

void CandidateType::printCandidateInfo() const
{
	CharacterType::printID();
	cout << " - ";
	CharacterType::printName();
}

void CandidateType::printCandidateTotalVotes() const
{
	cout << "    => Total Votes: " << totalVotes << endl;
}

CandidateType::~CandidateType()
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}