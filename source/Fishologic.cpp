#include "Fishologic.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "fstream"

#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

Fishologic Fishologic::fishinstance;

Fishologic::~Fishologic()
{
	Conversation.clear();
}

void Fishologic::SetUpFishMap()
{
	Conversation[0] = Talking{ "", "", "", "", "Tim", false};
	Conversation[1] = Talking{ "", "", "", "", "Pikel", false};
	Conversation[2] = Talking{ "", "", "", "", "Tuna Vandare", false};
	Conversation[3] = Talking{ "", "", "", "", "Sharky", false};
	Conversation[4] = Talking{ "", "", "", "", "Puffy", false};
}

void Fishologic::CharacterNameShake()
{
	{
		ImGui::Text("Who?:");
		
		if (ImGui::BeginCombo(" ", selected))
		{
			for (size_t i = 0; i < Conversation.size(); i++)
			{
				if (ImGui::Selectable(Conversation[i].name.c_str()))
				{
					selected = (Conversation[i].name).c_str();
					k = i;
				}
			}
			ImGui::EndCombo();
		};
	ImGui::Text("Shake: ");
	ImGui::Checkbox("\n", &Conversation[k].isShaking);
	}
}