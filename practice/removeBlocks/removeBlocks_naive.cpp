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
int *currB, *prevB;

bool isDone() {
    for(int i = 1; i <= numRow; i++) {
        if(currB[i] != 0) return false;
    }

    return true;
}

void removeBlocks() {
    prevB = currB;
    currB = new int[numRow+2];
    currB[0] = 0;
    currB[numRow+1] = 0;

    int idx = 1;
    while(idx <= numRow) {
        if(prevB[idx] == 0) {
            currB[idx-1] = 0;
            currB[idx] = 0;
            currB[idx+1] = 0;
            idx += 2;
        } else {
            int minimum = min(prevB[idx-1], prevB[idx+1]);

            if(minimum >= prevB[idx])
                currB[idx] = prevB[idx] - 1;
            else
                currB[idx] = minimum;

            idx += 1;
        }
    }

    delete [] prevB;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        cin >> numRow;

        currB = new int[numRow+2];
        currB[0] = 0;
        currB[numRow+1] = 0;
        for(int i = 1; i <= numRow; i++) {
            cin >> currB[i];
        }

        while(true) {
            if(isDone()) break;

            removeBlocks();
            Answer++;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
