#include "Subject.hpp"

Subject::Subject()
{

}

Subject::~Subject()
{
	listChoice = nullptr;
	delete listChoice;
}





void Subject::NrOfWindowsToAddBox()
{

}

void Subject::AddSubject()
{
	isSubject = true;
	/*
	* Should add a box
	* Have structure of a subjectbox (order of buttons and boxes)
	*/

	//Open
	OpenWindow();
	//TextBox(Who says)
	ChooseBox(listChoice, list, listTitle);
	//TextBox(What that person says)
	//Multiple lines?
	//AddSubjectButton (pops out new subject box on click)
	//AddChoiceButton
	//SaveButton on bottom
	//"Remove" this window (in a corner?)
	//Close

}



void Subject::TextShake()
{
	ImGui::Text("Shake: ");
	ImGui::Checkbox("\n", &Conversation[convIndex].isShaking);
}
