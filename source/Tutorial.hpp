#pragma once

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	void AppImG();

private:
	bool running{};
	char buf[256];
};

