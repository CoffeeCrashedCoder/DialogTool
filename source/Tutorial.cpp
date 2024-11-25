#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Tutorial.hpp"
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "fstream"

nlohmann::json StringJson{};
nlohmann::json IntJson{};

Tutorial::Tutorial()
{
	
}

Tutorial::~Tutorial()
{
	PointerHandler();
}

void Tutorial::AppImG()
{
	
	StringJson["Subject"] = Sub->subject;

	SubjectBox();
	Choice1();
	Choice2();
	Choice3();
	
	//-------------------LINES-------------------//
	
	DrawLine(SubCenter, ChoCenter);

	//-------------------LINES-END---------------//

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

void Tutorial::SaveToJson()
{
	{
		std::string jsonstring = StringJson.dump(10);
		//change private bool to true while developing and back to false before commiting!
		if (developing){
			std::ofstream outFile("../source/Savedjson.json");
			if (outFile.is_open()) {
				outFile << jsonstring;
				outFile.close();
			}
		}
		else {
			std::ofstream outFile1("../data/dialogjson/Dialog.json");
			if (outFile1.is_open()) {
				outFile1 << jsonstring;
				outFile1.close();
			}
		}
	}
}

void Tutorial::LoadFromJson()
{
	
}

void Tutorial::PointerHandler()
{
	std::vector<Subject*> SubPtrVec{};
	SubPtrVec.push_back(Sub);
	SubPtrVec.push_back(Subject2);

	std::vector<Choice*> ChoPtrVec{};
	ChoPtrVec.push_back(Cho);
	ChoPtrVec.push_back(Sub->ChoiceStructPtr);

	std::vector<signed int*> SigIntVec{};
	SigIntVec.push_back(Sub->nrChoicesPtr);

	for (auto& sub : SubPtrVec)
	{
		sub = nullptr;
		delete sub;
	}
	for (auto& cho : ChoPtrVec)
	{
		cho = nullptr;
		delete cho;
	}
	for (auto& sig : SigIntVec)
	{
		sig = nullptr;
		delete sig;
	}
}

ImVec2 Tutorial::FromSubBox()
{

	ImVec2 box1Pos = ImVec2(250, 150);
	ImVec2 box1Size = ImVec2(75, 25);
	

	ImGui::SetCursorScreenPos(box1Pos);
	ImGui::Button("Box 1", box1Size);
	
	return ImVec2(box1Pos.x + box1Size.x / 2, box1Pos.y + box1Size.y / 2);
}
	
ImVec2 Tutorial::ToChoiceBox()
{
	ImVec2 box2Pos = ImVec2(300, 200);
	ImVec2 box2Size = ImVec2(75, 25);
	ImGui::SetCursorScreenPos(box2Pos);
	ImGui::Button("Box 2", box2Size);

	return ImVec2(box2Pos.x + box2Size.x / 2, box2Pos.y + box2Size.y / 2);
}

void Tutorial::DrawLine(ImVec2& first, ImVec2& second)
{
	ImDrawList* drawAList = ImGui::GetForegroundDrawList();
	drawAList->AddLine(first, second, IM_COL32(255, 0, 0, 255), 1.f);
}

void Tutorial::SubjectBox()
{
	if (ImGui::Begin("Subject"))
		running = true;
	{
		ImGui::Text("Type the question in this box", 123);
		ImGui::InputText("string", Sub->subject, IM_ARRAYSIZE(Sub->subject));
		if (ImGui::Button("Save"))
			SaveToJson();

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
		SubCenter = FromSubBox();
	}
	if (running == false)
		ImGui::End();
}

void Tutorial::Choice1()
{
	if (ImGui::Begin("Choice 1"))
		running = true;
	{
		ImGui::Text("Type the first choice in this box:", 123);
		ImGui::InputText("string", Cho->choice, IM_ARRAYSIZE(Cho->choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
		ChoCenter = ToChoiceBox();
	}
	if (running == false)
		ImGui::End();
}

void Tutorial::Choice2()
{
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
}

void Tutorial::Choice3()
{
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
}
