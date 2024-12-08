#include "Fishologic.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "fstream"

#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

Fishologic::Fishologic()
{
	SetUpFishMap();
}

Fishologic::~Fishologic()
{
	Conversation.clear();
}

void Fishologic::SetUpFishMap()
{
	Conversation[0] = Talking{ "", "", "", "", names.at(0), false};
	Conversation[1] = Talking{ "", "", "", "", names.at(1), false};
	Conversation[2] = Talking{ "", "", "", "", names.at(2), false};
	Conversation[3] = Talking{ "", "", "", "", names.at(3), false};
	Conversation[4] = Talking{ "", "", "", "", names.at(4), false};
	Conversation[5] = Talking{ "", "", "", "", names.at(0), false};
	Conversation[6] = Talking{ "", "", "", "", names.at(1), false};
	Conversation[7] = Talking{ "", "", "", "", names.at(2), false};
	Conversation[8] = Talking{ "", "", "", "", names.at(3), false};
	Conversation[9] = Talking{ "", "", "", "", names.at(4), false};
}

void Fishologic::CharacterNameShake(int convIndex)
{
	{
		ImGui::Text("Who?:");
		
		if (ImGui::BeginCombo(" ", selected))
		{
			for (size_t i = 0; i < names.size(); i++)
			{
				if (ImGui::Selectable(names.at(i).c_str()))
				{
					selected = (names.at(i)).c_str();
					Conversation[convIndex].name = selected;
				}
			}
			ImGui::EndCombo();
		};
	ImGui::Text("Shake: ");
	ImGui::Checkbox("\n", &Conversation[convIndex].isShaking);
	}
}

void Fishologic::NewChoices()
{
	for (size_t i = 0; i < nrChoices; i++)
	{
		Answers.push_back(new Fishologic::Choices);
	}
}

void Fishologic::ChoiceF()
{
	for (size_t i; i < nrChoices; i++)
	{
		std::string tempConcat{ "Choice" };
		tempConcat += std::to_string(i);
		if (ImGui::Begin(tempConcat.c_str()))
			running = true;
		{
			ImGui::Text("Type the first choice in this box:", 123);
			ImGui::InputText("string", Answers.at(i)->choice, IM_ARRAYSIZE(Answers.at(i)->choice));
			if (ImGui::Button("Save"))
				SaveToJson();
			ChoCenter = ToChoiceBox();
		}
		if (running == false)
			ImGui::End();
	}
}

void Fishologic::PointerHandlerFish()
{
	std::vector<signed int*> SigIntVec{};
	SigIntVec.push_back(nrChoicesPtr);

	for (auto& sig : SigIntVec)
	{
		sig = nullptr;
		delete sig;
	}
	for (auto& Ans : Answers)
	{
		Ans = nullptr;
		delete Ans;
	}
}
