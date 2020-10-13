#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

std::string Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	std::cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		if(test_case == 0) std::cin.ignore();
		std::string equation, answer;
		std::getline(std::cin, equation);
		equation.erase(std::remove_if(equation.begin(), equation.end(), isspace), equation.end());
		
		size_t pos[3] = {equation.find("x"), equation.find("-"), equation.find("=")};
		int a = std::atoi(equation.substr(0, pos[0]).c_str());
		int b = std::atoi(equation.substr(pos[1] + 1, pos[2] - pos[1] - 1).c_str());
		int c = std::atoi(equation.substr(pos[2] + 1, equation.length() - pos[2]).c_str());
		int gcd = std::__gcd(a, b + c);

		int numerator = (b + c) / gcd;
		int denominator = a / gcd;

		Answer = std::to_string(numerator) + " / " + std::to_string(denominator);

		std::cout << "Case #" << test_case+1 << std::endl;
		std::cout << Answer << std::endl;
	}

	return 0;
}
