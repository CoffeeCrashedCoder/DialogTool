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

	Subject* Sub { new Subject };
	Choice* Cho { new Choice };

private:
	bool running{};
};