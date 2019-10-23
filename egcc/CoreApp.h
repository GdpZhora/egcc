#pragma once

class CoreApp
{
	private:
		char *filename;
		std::string *code;
		std::vector<Token> *tokens;
	public:
		
		//CoreApp();
		~CoreApp();
		
		bool ReadFile(char* filename);
		void SetTextCode(std::string *textCode);
		
		void RunPreprocessor();
		void RunParsing();




};

