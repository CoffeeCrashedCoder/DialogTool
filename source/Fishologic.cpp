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

void Fishologic::CharacterNameShake()
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
					k = i;
				}
			}
			ImGui::EndCombo();
		};
	ImGui::Text("Shake: ");
	ImGui::Checkbox("\n", &Conversation[k].isShaking);
	}
}