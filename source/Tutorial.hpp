#pragma once
#include <vector>

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	struct Choice;

	struct Subject
	{
		char subject[113]{};
		int nInt{};
		Choice* ChoiceStructPtr{ new Choice };
		signed int* nrChoicesPtr{&nrChoices};
		signed int nrChoices{};
		std::vector<Choice*> choiceNodes{};
	};

	struct Choice
	{
		char choice[113]{};
		std::vector<Subject*> subjectNodes{};
	};

	void AppImG();
	void SaveToJson();
	void LoadFromJson();
	void PointerHandler();

//-------------------POINTERS-------------------//
	Subject*    Sub         { new Subject };
	Subject*    Subject2    { new Subject };
	Choice*     Cho         { new Choice  };
//-------------------POINTERS-END---------------//


private:
	bool running{};
	bool developing{false};
};