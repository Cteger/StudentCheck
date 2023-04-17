#pragma once

#include <iostream>

struct InputData
{
	float abc[3];
	float answer[2];
	std::string name;
	int answer_flag;
};

int CheckAnswer(struct InputData inp, float* x);
struct InputData Read(struct InputData inp0);
float Find_discriminant(float* abc);
float* Find_solution(float* abc, float D, float* x0);
void Print_answer(struct InputData inp, float* x, float D);
