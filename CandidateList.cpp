/*
	Segfault
	Zhang, James (TTH 2:20)

	May 17, 2020

	CS A250
	Project 2 - Part A
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition


CandidateList::CandidateList()
{

}

void CandidateList::addCandidate(CandidateType temp)
{
	candidates.push_back(temp);
}

int CandidateList::getWinner() const
{
	int winningVotes = 0;
	int winnerID = 0;

	for (auto candidate : candidates)
	{
		if (candidate.getTotalVotes() > winningVotes)
		{
			winningVotes = candidate.getTotalVotes();
			winnerID = candidate.getID();
		}
	}
	return winnerID;
}

bool CandidateList::isEmpty() const
{
	return candidates.empty();
}

bool CandidateList::searchCandidate(int tempID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	return searchCandidate(tempID, iter);
}

bool CandidateList::searchCandidate(int tempID,
	list<CandidateType>::const_iterator &iter) const
{
	if (iter->getID() == tempID)
	{
		return true;
	}

	iter = find(candidates.cbegin(), candidates.cend(), tempID);
	if (iter != candidates.cend())
	{
		return true;
	}
	else
	{
		cout << "    => ID not in the list." << endl;
		return false;
	}
}

void CandidateList::printCandidateName(int tempID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	if (searchCandidate(tempID, iter))
	{
		iter->printName();
	}

}

void CandidateList::printAllCandidates() const
{
	for (auto candidate : candidates)
	{
		candidate.printCandidateInfo();
		cout << endl;
	}
}

void CandidateList::printKingdomVotes(int tempID, int tempIndex) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	if (searchCandidate(tempID, iter))
	{
		cout << "    * " <<right << setw(2) << 
			iter->getVotesByKingdom(tempIndex) << "( => )"
			<< KINGDOMS[tempIndex] << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int tempID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	if (searchCandidate(tempID, iter))
	{
		iter->printCandidateTotalVotes();
	}
}

void CandidateList::printHeader() const
{
	cout << "************ FINAL RESULTS ************" << endl << endl;
	cout << left << setw(16) << setfill(' ') << "LAST";
	cout << left << setw(8) << setfill(' ') << "FIRST";
	cout << left << setw(8) << setfill(' ') << "TOTAL";
	cout << right << setw(7) << setfill(' ') << "POS";
	cout << endl;

	cout << left << setw(16) << setfill(' ') << "NAME";
	cout << left << setw(8) << setfill(' ') << "NAME";
	cout << left << setw(8) << setfill(' ') << "VOTES";
	cout << right << setw(7) << setfill(' ') << "#";
	cout << endl;
	cout << "_______________________________________" << endl;
	cout << endl;
}

void CandidateList::printCandidate(
	list<CandidateType>::const_iterator& iter,int position) const
{
	cout << left << setw(16) << setfill(' ')
		<< iter->getLastName();

	cout << left << setw(8) << setfill(' ')
		<< iter->getFirstName();

	cout << left << setw(8) << setfill(' ')
		<< iter->getTotalVotes();

	cout << right << setw(7) << setfill(' ')
		<< position << endl;

	if (position % 5 == 0)
	{
		cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
	}
}

void CandidateList::printFinalResults() const
{
	printHeader();
	int position = 1;
	int currentTopVotes = 0;
	int currentNextVotes = 0;
	list <CandidateType>::const_iterator iter = candidates.cbegin();
	list <CandidateType>::const_iterator iterEnd = candidates.cend();
	list<CandidateType>::const_iterator nextPlace = candidates.cend();

	for(iter; iter != iterEnd; ++iter)
	{
		if (iter->getTotalVotes() > currentTopVotes)
		{
			currentTopVotes = iter->getTotalVotes();
			nextPlace = iter;
		}
	}

	printCandidate(nextPlace, position);
	position++;
	nextPlace = candidates.cbegin();

	while (position < candidates.size() + 1)
	{
		for (iter = candidates.begin(); iter != candidates.end(); iter++)
		{
			if (iter->getTotalVotes() == currentTopVotes - 1)
			{
				nextPlace = iter;
				currentNextVotes = iter->getTotalVotes();
				break;
			}

			else
			{
				if (iter->getTotalVotes() > currentNextVotes
					&& iter->getTotalVotes() < currentTopVotes)
				{
					currentNextVotes = iter->getTotalVotes();
					nextPlace = iter;
				}
			}
		}
		printCandidate(nextPlace, position);
		position++;
		currentTopVotes = currentNextVotes;
		currentNextVotes = 0;
		nextPlace = candidates.cbegin();
	}
	cout << "_______________________________________" << endl;
}

/**************************************
*FUNCTION ADDED FOR SELECTION #6
**************************************/

void CandidateList::printAverageVotes(int tempID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	if (searchCandidate(tempID, iter))
	{
		cout << "    => Average Votes Per Kingdom: "
			<< iter->getTotalVotes() / NUM_OF_KINGDOMS << endl;
	}
}

CandidateList::~CandidateList()
{

}