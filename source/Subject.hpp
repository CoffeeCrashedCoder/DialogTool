#pragma once
#include "Framework.hpp"

class Subject : public Framework
{
public:
	Subject();
	~Subject();

	void AddSubject();
	void TextShake();
	void NrOfWindowsToAddBox() override;

	////////////////////////////////////////////

	std::vector<std::string>list{};
	std::string listTitle{};
	const char* listChoice{};
private:

};