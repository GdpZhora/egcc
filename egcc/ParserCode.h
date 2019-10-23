#pragma once
class ParserCode
{
private:
	Token* mainToken;
	std::vector<Token*> *tokens;
	std::string *code;
	
public:
	std::string codeMilled;

	void LoadTextCode(std::string *code);

	void RunProcessing();

	void MillingCode();



};

