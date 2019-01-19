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

int Answer, numRow;
int blocks[100002];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        cin >> numRow;

        blocks[0] = 0;
        blocks[numRow+1] = 0;
        for(int i = 1; i <= numRow; i++) {
            cin >> blocks[i];
        }

        int left[numRow+2], right[numRow+2];
        left[0] = 0;
        right[numRow+1] = 0;

        for(int i = 1; i <= numRow; i++) {
            left[i] = min(left[i-1] + 1, blocks[i]);
        }

        for(int i = numRow; i >= 1; i--) {
            right[i] = min(right[i+1] + 1, blocks[i]);
        }

        for(int i = 1; i<= numRow; i++) {
            int minimum = min(left[i], right[i]);

            if(Answer < minimum) {
                Answer = minimum;
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
