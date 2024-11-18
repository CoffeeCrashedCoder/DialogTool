#pragma once

class Tutorial
{
public:
	Tutorial();
	~Tutorial();

	void AppImG();

private:
	bool running{};
	char Subject[256];
	char Choice[256];
};

