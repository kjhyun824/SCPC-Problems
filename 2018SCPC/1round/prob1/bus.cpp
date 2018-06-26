/*
 * =====================================================================================
 *
 *       Filename:  bus.cpp
 *
 *    Description:  2018 SCPC 1Round - Problem 1 : Bus
 *
 *        Version:  1.0
 *        Created:  06/23/18 09:34:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int ability[200000];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int numPlayer, threshold;
        cin >> numPlayer >> threshold;

        for(int i = 0; i < numPlayer; i++) {
            cin >> ability[i];
        }

        sort(ability, ability + numPlayer);

        int busCount = 1;

        std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
        Q.push(ability[0] + threshold);

        for(int i = 1; i < numPlayer; i++) {
            int mini = Q.top();
            if(ability[i] > mini) {
                Q.pop();
            } else {
                busCount++;
            }
            Q.push(ability[i] + threshold);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << busCount << endl;
	}

	return 0;
}
