#include "all.h"


map<std::string*, int> ParseBlockToSupblocks(std::string *textAnalysis)
{
	std::string text = *textAnalysis;
	char* textTemp = (char*)text.c_str();
	int startIndex = 0;
	char simbolEndBlock = '}';
	char simbolStartBlock = '{';
	char simbolEndLine = ';';
	std::string* currentText = new std::string;
	char currentSimbol;
	stack<char> borderBlocks;

	map<std::string*, int> supblocks;
	
	int k = 0;

	for (size_t i = 0; i < text.size(); i++)
	{
		currentSimbol = textTemp[i];
		if ((currentSimbol == simbolEndLine) && (borderBlocks.empty()))
		{
			k++;
			supblocks.insert(std::pair<std::string*, int>(currentText, k));
			currentText = new std::string;
			startIndex = i + 1;
		}
		else if (currentSimbol == simbolStartBlock) {
			borderBlocks.push(simbolStartBlock);
			*currentText += currentSimbol;
		}
		else if (currentSimbol == simbolEndBlock) {
			borderBlocks.pop();
			*currentText += currentSimbol;
			if (borderBlocks.empty())
			{
				k++;
				supblocks.insert(std::pair<std::string*, int>(currentText, k));
				currentText = new std::string;
				startIndex = i + 1;
			}
		}
		else
		{
		*currentText += currentSimbol;
		}


	};

	return supblocks;
	
}

bool EqualTemmplate(const char* templateToken, std::string* text)
{



	return 0;
}

typeToken GetTypeToken(map<const char*, typeToken> *templatesToken, std::string *text)
{
	

	for (auto& item : *templatesToken)
	{
		if (EqualTemmplate(item.first, text))
			return item.second;
	}

	return Unknown;
}


void Token::SetTextToken(std::string textToken)
{
	this->text = textToken;
}

void Token::SetType(typeToken type)
{
	this->type = type;
}

void Token::CreateTree()
{
	map<const char*, typeToken> templatesToken;

	map<std::string*, int> supblocks = ParseBlockToSupblocks(&text);

	if (type == Program)
	{
		templatesToken.insert(std::pair<const char*, typeToken>("<type> main () { <operators> }", Main));
		templatesToken.insert(std::pair<const char*, typeToken>("<type> <name> () { <operators> }", Function));
		templatesToken.insert(std::pair<const char*, typeToken>("<type> <name> [= <exp>];", GlobvalVar));
		
	};

	for (auto& item : supblocks)
	{
		typeToken typeBlock = GetTypeToken(&templatesToken, item.first);
		if (typeBlock == Unknown)
			continue;
		Token* token = new Token(this, item.second);
		token->SetTextToken(*item.first);
		token->SetType(typeBlock);
		token->CreateTree();
	}

}
