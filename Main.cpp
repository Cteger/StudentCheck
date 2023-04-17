#include "Header.h"

#include <iostream>

int main()
{
	float* x;
	float D;
	struct InputData inp;
	inp = Read(inp);

	D = Find_discriminant(inp.abc);

	if (D >= 0)
	{
		x = new float[2];

		x = Find_solution(inp.abc, D, x);

		std::cout << "The first root is: " << x[0] << std::endl;
		std::cout << "The second root is: " << x[1] << std::endl;

		inp.answer_flag = CheckAnswer(inp, x);

		Print_answer(inp, x, D);

		delete[] x;
	}
	else
	{
		std::cout << "No roots" << std::endl;
	}

	std::cout << "Student answer: " << inp.answer[0] << " | " << inp.answer[1] << std::endl;
	
	std::cout << inp.name << ": ";

	if (inp.answer_flag == 0)
	{
		std::cout << "It is a bad student" << std::endl;
	}
	else if (inp.answer_flag == 1)
	{
		std::cout << "It is a usual student" << std::endl;
	}
	else if (inp.answer_flag == 2)
	{
		std::cout << "It is a good student" << std::endl;
	}
}