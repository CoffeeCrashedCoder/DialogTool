#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <string>
#include <vector>
#include <iostream>

#include <nlohmann/json.hpp>
#include "fstream"

class Framework
{
public:
	Framework();
	~Framework();
	void TextBox(const char*);
	const char* ChooseBox(const char* chosen, std::vector<std::string>& list, std::string& title);
	virtual void NrOfWindowsToAddBox();
	void UpdateButton();
	void OpenWindow();
	void CloseWindow();
	void SaveJson();
	void LoadJson();
	void parseJson();

	void SpeakerHandler();
	void WindowHandler();
	void ButtonHandler();
	void WindowDeleter();
	void ErrorHandler(const char* errorMsg);



	bool windowOpen{};
	bool isSubject{};
	bool isChoice{};
	bool isError{};
private:

};