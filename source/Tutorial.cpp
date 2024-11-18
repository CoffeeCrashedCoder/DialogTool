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
	
		ImGui::Text("Hello, world %d", 123);
		if (ImGui::Button("Save"));
			//MySaveFunction();
		ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));

	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 1"))
		running = true;
	{


	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 2"))
		running = true;
	{


	}
	if (running == false)
	ImGui::End();
	if (ImGui::Begin("Choice 3"))
		running = true;
	{


	}
	if (running == false)
	ImGui::End();

}