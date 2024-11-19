#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Tutorial.hpp"
#include <string>
#include <iostream>

Tutorial::Tutorial()
{
	
}

Tutorial::~Tutorial()
{
	Sub->nrChoicesPtr = nullptr;
	delete Sub->nrChoicesPtr;

	Sub->ChoiceStructPtr = nullptr;
	delete Sub->ChoiceStructPtr;

}

void Tutorial::AppImG()
{
	if (ImGui::Begin("Subject"))
		running = true;
	{
	
		ImGui::Text("Type the question in this box:", 123);
		ImGui::InputText("string", Sub->subject, IM_ARRAYSIZE(Sub->subject));
		if (ImGui::Button("Save"));
			//MySaveFunction();
		ImGui::Text("Choice count:", 123);
		ImGui::InputInt("int", Sub->nrChoicesPtr, 1);
		ImGui::SameLine();
		if (ImGui::Button("Update")) {
			for (size_t i = 0; i < Sub->choiceNodes.size(); i++)
			{
				Sub->choiceNodes.at(i) = nullptr;
				delete Sub->choiceNodes.at(i);
			}
			Sub->choiceNodes.clear();
			for (size_t i = 0; i < Sub->nrChoices; i++)
				Sub->choiceNodes.push_back(Sub->ChoiceStructPtr);
			Sub->nInt = Sub->nrChoices;
		}
			ImGui::Text(std::to_string(Sub->nInt).c_str(), 123);
	}
	if (running == false)
	ImGui::End();

	if (ImGui::Begin("Choice 1"))
		running = true;
	{
		ImGui::Text("Type the first choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 2"))
		running = true;
	{
		ImGui::Text("Type the second choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("choice 3"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
	ImGui::End();

	////////////////////////////////

	if (ImGui::Begin("choice 1.1"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

	if (ImGui::Begin("choice 1.2"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

	if (ImGui::Begin("choice 1.3"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

}