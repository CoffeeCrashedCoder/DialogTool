#include "Framework.hpp"

Framework::Framework()
{
}

Framework::~Framework()
{
}

//--------------------------------------------------------//



void Framework::TextBox(const char* text)
{
	//Add an Imgui textbox (string)

	ImGui::Text(text, 123);

	/* Examples:
		InitialD.CharacterNameShake(0); //shaking
		ImGui::Text("Says: ", 123); //Text
		ImGui::InputText("", InitialD.Conversation[0].Topic, IM_ARRAYSIZE(InitialD.Conversation[0].Topic)); //Text
	*/
}

const char* Framework::ChooseBox(const char* chosen, std::vector<std::string>& list, std::string& title)
{
	title += ":";
	ImGui::Text((title).c_str());
	if (ImGui::BeginCombo(" ", chosen))
	{
		for (size_t i = 0; i < list.size(); i++)
		{
			if (ImGui::Selectable(list.at(i).c_str()))
			{
				chosen = (list.at(i)).c_str();
			}
		}
		ImGui::EndCombo();
	};
	return chosen;
}

void Framework::NrOfWindowsToAddBox()
{
	//intbox with "add" button on same line
	//Adds new boxes (aka AddSubject or AddChoice)
	if (this->isSubject);

	/*Examples:
		ImGui::Text("Choice count:", 123);
		ImGui::InputInt("int", InitialD.nrChoicesPtr, 1);
	*/
}

void Framework::UpdateButton()
{
	//Updates the box
	//Should pop up an indicator saying "Updated!"
	if (ImGui::Button("Update"))
	{
		SaveJson();
		parseJson();
		LoadJson();
	}
	
	/* Example:
	if (ImGui::Button("Update")) {
			for (size_t i = 0; i < Sub->choiceNodes.size(); i++)
			{
				Sub->choiceNodes.at(i) = nullptr;
				delete Sub->choiceNodes.at(i);
			}
			Sub->choiceNodes.clear();
			for (size_t i = 0; i < InitialD.nrChoices; i++)
				Sub->choiceNodes.push_back(Sub->ChoiceStructPtr);
			Sub->nInt = InitialD.nrChoices;
		}
	*/
}

void Framework::SpeakerHandler()
{
}

void Framework::WindowHandler()
{
	/*
	* Set size of window depending on need
	* Set position of window based on ID (choice1 / choice2 / answer1 etc.)
	*/
}

void Framework::ButtonHandler()
{
	/*
	* Set position of buttons and activate functions that happens on being pressed,
	depending on who is being pressed.
	*/
}

void Framework::WindowDeleter()
{
}

void Framework::ErrorHandler(const char* errorMsg)
{
	//Should Create a window with one string (errorMsg) in the center of the screen.
	//Has one button that says "Okay" or "Close" on it.
	isError = true;

	OpenWindow();
	TextBox(errorMsg);
	CloseWindow();

	isError = false;
}

void Framework::OpenWindow()
{
	if (isError)
	{
		if (ImGui::Begin("Error"))
			windowOpen = true;
	}
	else if (isSubject)
	{
		if (ImGui::Begin("Subject"))
			windowOpen = true;
	}
	else if (isChoice)
	{
		if (ImGui::Begin("Choice"))
			windowOpen = true;
	}
	else
		ErrorHandler("Error: Subject nor Choice found!");
}

void Framework::CloseWindow()
{
	windowOpen = false;
	if (windowOpen == false)
		ImGui::End();
	else
		ErrorHandler("Error: Couldn't close window!");
}

void Framework::SaveJson()
{
	//Write to json
}

void Framework::LoadJson()
{
	//Should update all boxes to whatever Json has in store for it and show it to the user.
}

void Framework::parseJson()
{
}


/*
GOTTA BE FIXED:
*"isSubject" & "isChoice" needs to have a way being added as a new choice or new subject
* 
* 
* 
*/