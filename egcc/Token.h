#pragma once
enum typeToken
{
	Unknown = 0,
	Program,
	Main,
	Function,
	GlobvalVar,
	Type, // тип переменной
	Const, // явное значение
	Var, // переменная
	Move, // оператор присвоения
	MathOperator, // математический оператор (*,/ и т.д.
	LogicOperator, // логический оператор
	IfOperator,
	If, // условия
	Then,
	Else, // иначе
	ForOperator,
	For, // оператор цикла
	BeginBlock, // {
	EndBlock, // }
	BeginExp, // (
	EndExp // )
};

class Token
{
private:
	Token* parent;
	int priority = 0;
	typeToken type;
	std::string text;
	std::vector<Token*> *subtokens;
public:
	Token()
	{
		type = Program;
	}
	Token(Token* parent, int priority)
	{
		this->parent = parent;
		this->priority = priority;
	}
	void SetTextToken(std::string textToken);
	void SetType(typeToken type);
	void CreateTree();
	

};

