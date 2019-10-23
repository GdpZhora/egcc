#pragma once
class Preprocessor
{
private:
	std::string *code;
public:
	Preprocessor();

	void LoadTextCode(std::string *code);

	void RunProcessing();

};

