/*
 * =====================================================================================
 *
 *       Filename:  stations.cpp
 *
 *    Description:  2018 SCPC 1Round - Problem 3 : Space Stations
 *
 *        Version:  1.0
 *        Created:  06/24/18 03:43:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

int Answer;

vector<int> graph[200001];
int numStats;
int numEdges;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int numStats, numEdges;
        cin >> numStats >> numEdges;

        for(int i = 0; i < numEdges; i++) {
            int s1, s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
