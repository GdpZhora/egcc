#pragma once
enum typeToken
{
	Unknown = 0,
	Program,
	Main,
	Function,
	GlobvalVar,
	Type, // ��� ����������
	Const, // ����� ��������
	Var, // ����������
	Move, // �������� ����������
	MathOperator, // �������������� �������� (*,/ � �.�.
	LogicOperator, // ���������� ��������
	IfOperator,
	If, // �������
	Then,
	Else, // �����
	ForOperator,
	For, // �������� �����
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

