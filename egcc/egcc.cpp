// egcc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "all.h"

int main()
{
	std::string code = "";

	code += "int main() {int a=2; int b; b=a*3; return 0; }";

	CoreApp coreapp = CoreApp();
	coreapp.SetTextCode(&code);
	coreapp.RunPreprocessor();
	coreapp.RunParsing();
	return 0;
}

