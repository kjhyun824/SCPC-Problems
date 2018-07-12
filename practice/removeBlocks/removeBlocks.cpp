/*
 * =====================================================================================
 *
 *       Filename:  removeBlocks.cpp
 *
 *    Description:  Count number of processes to remove all blocks
 *
 *        Version:  1.0
 *        Created:  07/12/18 23:12:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int Answer;
int blocks[100000];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        int numRow;
        cin >> numRow;
        for(int i = 0; i < numRow; i++) {
            cin >> blocks[i];
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
