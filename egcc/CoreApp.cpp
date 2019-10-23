#include "all.h"

CoreApp::~CoreApp()
{
}

bool CoreApp::ReadFile(char *filename)
{
	this->filename = filename;

	ifstream in(filename);
	
	if (!(in.is_open()))
	{
		return 1;
	};

	while (in)
	{
		in >> *code;
	}

	return 0;
}

void CoreApp::SetTextCode(std::string *textCode)
{
	code = textCode;
}

void CoreApp::RunPreprocessor()
{
	Preprocessor* preprocessor = new Preprocessor();
	preprocessor->LoadTextCode(code);
	preprocessor->RunProcessing();
}

void CoreApp::RunParsing()
{
	ParserCode parser = ParserCode();
	parser.LoadTextCode(code);
	parser.RunProcessing();
}

