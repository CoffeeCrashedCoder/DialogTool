#pragma once
#include "Framework.hpp"
#include "Subject.hpp"
#include "Choices.hpp"

class FishApp
{
public:
	FishApp();
	~FishApp();

	const char* WhoSpeaking(const char*, std::vector<std::string>);

	////////////////////////////////////////////

	const char* Speaker{};
	char Topic[113]{}; //can be a vector for longer conversations
	std::string answer1{};
	std::string answer2{};
	std::string answer3{};
	std::string name{};
	bool isShaking{};

	std::vector<Choices*> ChoicePtrs{};

	////////////////////////////////////////////

	std::vector<std::string> names
	{
		"Tim",				//0
		"Pikel",			//1
		"Tuna Vandare",		//2
		"Sharky",			//3
		"Puffy"				//4
	};

	////////////////////////////////////////////

private:

};

