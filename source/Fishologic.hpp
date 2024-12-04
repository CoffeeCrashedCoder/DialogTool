#pragma once

#include <iostream>
#include <map>
#include <unordered_map>

#include <vector>
#include <string>
#include "Tutorial.hpp"

class Fishologic : public Tutorial
{
public:
	Fishologic();
	~Fishologic();

	///////////////////////////////////////////////////////
//Structs --------------------------------
	struct Talking
	{
		char Topic[113]{}; //can be a vector for longer conversations
		std::string Answer1{};
		std::string Answer2{};
		std::string Answer3{};
		std::string name{};
		bool isShaking{};

		//-----------------------------------//

	};
		signed int* nrChoicesPtr{ &nrChoices };
		signed int nrChoices{};
	struct Choices
	{
		char choice[113]{};
		std::vector<Talking*> subjectNodes{};
	};
	//Functions --------------------------------
	void SetUpFishMap();
	void CharacterNameShake(int);
	void NewChoices();
	void ChoiceF();
	//Variables --------------------------------
	std::vector<Choices*>Answers{};
	std::unordered_map<int, Talking> Conversation;
	std::vector<std::string> names
	{
		"Tim",				//0
		"Pikel",			//1
		"Tuna Vandare",		//2
		"Sharky",			//3
		"Puffy"				//4
	};

	///////////////////////////////////////////////////////

	Tutorial* master;
private:

	bool imguiOn;
	bool fishBoxImguiOn;
	const char* selected{};
	bool isChecked{};
	int k{};

};