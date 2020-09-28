/*
	Segfault
	Zhang, James (TTH 2:20)

	May 17, 2020

	CS A250
	Project 2 - Part A
*/

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.
CharacterType::CharacterType()
{
	//Strings are initialized as null already so there is no need.
	id = 0;
}

CharacterType::CharacterType(const string& newFirstName,
	const string& newLastName, int newidNumber)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newidNumber;
}

void CharacterType::setCharacterInfo(const string& newFirstName,
	const string& newLastName, int newidNumber)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newidNumber;
}

string CharacterType::getFirstName() const
{
	return firstName;
}

string CharacterType::getLastName() const
{
	return lastName;
}

int CharacterType::getID() const
{
	return id;
}

void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}


void CharacterType::printCharacterInfo() const
{
	printID();
	cout << " " << firstName << " " << lastName;
}

void CharacterType::printID() const
{
	cout << "ID# " << id;
}

CharacterType::~CharacterType()
{

}
