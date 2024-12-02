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
	ImVec2 FromSubBox();
	ImVec2 ToChoiceBox();
	void DrawLine(ImVec2&, ImVec2&);
	void SubjectBox();
	void Choice1();
	void Choice2();
	void Choice3();
	void NewChoices();
	void SaveToCon1();

	ImVec2 SubCenter{};
	ImVec2 ChoCenter{};
	//std::vector<int> existingChoices{ nrChoices };
	

//-------------------POINTERS-------------------//
	Subject*    Sub         { new Subject };
	Subject*    Subject2    { new Subject };
	Choice*     Cho         { new Choice  };
//-------------------POINTERS-END---------------//


private:
	bool running{};
	bool developing{true};
};