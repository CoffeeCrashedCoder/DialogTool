#pragma once

#include <iostream>
#include <map>
#include <unordered_map>

#include <vector>
#include <string>

class Fishologic
{
public:


	static Fishologic& Get()
	{
		return fishinstance;
	};
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
	};
	struct Choices
	{

	};
	//Functions --------------------------------
	void SetUpFishMap();
	void CharacterNameShake();
	//Variables --------------------------------

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

private:
	Fishologic() {};

	static Fishologic fishinstance;
	bool imguiOn;
	bool fishBoxImguiOn;
	const char* selected{};
	bool isChecked{};
	int k{};

};