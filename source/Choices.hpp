#pragma once
#include "Framework.hpp"
#include "Subject.hpp"

class Choices : public Framework
{
public:
	Choices();
	~Choices();
	void NrOfWindowsToAddBox() override;

	/////////////////////////////////////////////

	char choice[113]{}; //for textinput
	Subject* SubPtr{ nullptr };

	/////////////////////////////////////////////

private:

};