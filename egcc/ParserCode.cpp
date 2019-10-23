#include "all.h"

enum TypeSymbol
{
	none = 0,
	identify,
	special,
	constant

};

void ParserCode::LoadTextCode(std::string *code)
{
	this->code = code;
}

void ParserCode::RunProcessing()
{
	MillingCode();
	mainToken = new Token();
	mainToken->SetTextToken(*code);
	mainToken->CreateTree();
}

void ParserCode::MillingCode()
{
	std::string codeText = *code;

	vector<char> aloneSimbol;

	TypeSymbol typeSimbol = none;

	codeMilled = "";

	std::string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_";
	std::string number = "1234567890.";
	std::string spec = "!#@%^&*/%(){}+=-,;";

	const char* codeChar = codeText.c_str();
	char buf;
	int codeSimbol;

	for (int i = 0; i < codeText.size(); i++)
	{
		char separator = ' ';
		buf = codeChar[i];
		//codeSimbol = (int)(buf);
		if (alphabet.find(buf) != std::string::npos)
		{
			if (typeSimbol != identify) {
				typeSimbol = identify;
				codeMilled += separator;
			};
			codeMilled += buf;
		}
		else if (spec.find(buf) != std::string::npos)
		{
			if (typeSimbol != special) {
				typeSimbol = special;
				codeMilled += separator;
			}
			codeMilled += buf;
		}
		else if (number.find(buf) != std::string::npos)
		{
			if ((typeSimbol != identify)&&(typeSimbol != constant)) {
				typeSimbol = constant;
				codeMilled += separator;
			}
			codeMilled += buf;
		
		}
		else
		{
			typeSimbol = none;
		}

	};
	//cout << codeMilled;

}
