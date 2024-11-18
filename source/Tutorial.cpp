#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Tutorial.hpp"

Tutorial::Tutorial()
{

}

Tutorial::~Tutorial()
{

}

void Tutorial::AppImG()
{
	if (ImGui::Begin("Subject"))
		running = true;
	{
	
		ImGui::Text("Type the question in this box:", 123);
		ImGui::InputText("string", Subject, IM_ARRAYSIZE(Subject));
		if (ImGui::Button("Save"));
			//MySaveFunction();

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 1"))
		running = true;
	{
		ImGui::Text("Type the first choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 2"))
		running = true;
	{
		ImGui::Text("Type the second choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 3"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
	ImGui::End();

	////////////////////////////////

	if (ImGui::Begin("Choice 1.1"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

	if (ImGui::Begin("Choice 1.2"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

	if (ImGui::Begin("Choice 1.3"))
		running = true;
	{
		ImGui::Text("Type the third choice in this box:", 123);
		ImGui::InputText("string", Choice, IM_ARRAYSIZE(Choice));
		if (ImGui::Button("Save"));
		//MySaveFunction();
	}
	if (running == false)
		ImGui::End();

}