/*
	Segfault
	Zhang, James (TTH 2:20)

	May 17, 2020

	CS A250
	Project 2 - Part A
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <list>

#include <iostream>
#include <string>
#include <iomanip>

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(CandidateType temp);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;

	// searchCandidate
	bool searchCandidate(int tempID) const;

	// printCandidateName
	void printCandidateName(int tempID) const;

	// printAllCandidates
	void printAllCandidates() const;

	// printKingdomVotes
	void printKingdomVotes(int tempID, int tempIndex) const;

	// printCandidateTotalVotes
	void printCandidateTotalVotes(int tempID) const;

	// printFinalResults
	void printFinalResults() const;
	
	/**************************************
	*FUNCTION ADDED FOR SELECTION #6
	**************************************/
	void printAverageVotes(int tempID) const;

	// Destructor
	~CandidateList();



private:
	// searchCandidate
	bool searchCandidate(int tempID, 
		std::list<CandidateType>::const_iterator& iter) const;
	void printHeader() const;
	void printCandidate(std::list<CandidateType>::const_iterator& iter,
		int position) const;
	std::list<CandidateType> candidates;
};

#endif
