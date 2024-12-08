#include "FishApp.hpp"

FishApp::FishApp()
{
}

FishApp::~FishApp()
{
}

const char* FishApp::WhoSpeaking(const char* npc, std::vector<std::string> choiceFrom)
{

	ImGui::Text("Who?:");

	if (ImGui::BeginCombo(" ", npc))
	{
		for (size_t i = 0; i < choiceFrom.size(); i++)
		{
			if (ImGui::Selectable(choiceFrom.at(i).c_str()))
			{
				npc = (choiceFrom.at(i)).c_str();
			}
		}
		ImGui::EndCombo();
	};
	return npc;
}