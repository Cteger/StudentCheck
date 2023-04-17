#include "Header.h"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define input_file "C:/Users/user/source/repos/StudentCheck/StudentCheck/Input.txt"
#define output_file "C:/Users/user/source/repos/StudentCheck/StudentCheck/Output.txt"

int CheckAnswer(struct InputData inp, float* x)
{
    if (inp.answer[0] == x[0] && inp.answer[1] == x[1]
        || inp.answer[0] == x[1] && inp.answer[1] == x[0])
    {
        return 2;
    }
    else if (inp.answer[0] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

struct InputData Read(struct InputData inp0)
{
    struct InputData inp = inp0;
    std::string line;

    std::ifstream in(input_file);
    if (in.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            getline(in, line);
            inp.abc[i] = std::stof(line);
        }
        for (int i = 0; i < 3; i++)
        {
            getline(in, line);
            if (!line.empty() && line.find_first_not_of("-.0123456789")
                == std::string::npos)
            {
                inp.answer[i] = std::stof(line);
            }
            else
            {
                if (i == 1)
                {
                    inp.answer[i] = 0;
                }
                inp.name = line;
                break;
            }
        }
    }

    in.close();

    return(inp);
}

float Find_discriminant(float* abc)
{
    float D;
    float* crutch = 0;
    D = abc[1] * abc[1] - 4 * abc[0] * abc[2];

    return D;
}

float* Find_solution(float* abc, float D, float* x0)
{
    float* x = x0;

    x[0] = ((-1) * abc[1] + sqrt(D)) / (2 * abc[0]);
    x[1] = ((-1) * abc[1] - sqrt(D)) / (2 * abc[0]);

    if (x[0] == x[1])
        x[1] = 0;
    return x;
}

void Print_answer(struct InputData inp, float* x, float D)
{
    std::ofstream out;
    out.open(output_file);

    if (out.is_open())
    {
        if (D >= 0)
        {
            out << "The first root is: " << x[0] << std::endl;
            out << "The second root is: " << x[1] << std::endl;
        }
        else
        {
            out << "No roots" << std::endl;
        }
        out << "Student answer: " << inp.answer[0] << " | " << inp.answer[1] << std::endl;

        out << inp.name << ": ";

        if (inp.answer_flag == 0)
        {
            out << "It is a bad student" << std::endl;
        }
        else if (inp.answer_flag == 1)
        {
            out << "It is a usual student" << std::endl;
        }
        else if (inp.answer_flag == 2)
        {
            out << "It is a good student" << std::endl;
        }
    }
}
