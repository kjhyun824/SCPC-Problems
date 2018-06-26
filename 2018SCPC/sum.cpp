/*
 * =====================================================================================
 *
 *       Filename:  sum.cpp
 *
 *    Description: Orientation for 2018SCPC 
 *
 *        Version:  1.0
 *        Created:  06/22/18 12:53:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int num1, num2;
        cin >> num1 >> num2;
        Answer = num1 + num2;

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
