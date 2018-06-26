/*
 * =====================================================================================
 *
 *       Filename:  detection.cpp
 *
 *    Description:  Find minimum of maximum movement of detecting robot
 *
 *        Version:  1.0
 *        Created:  04/29/18 23:54:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long LL;

LL Answer;
int numRobots;
LL range, special, _range;
LL locs[100000];

LL minMovements() {
    return 0;
}

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        cin >> numRobots; // First Line
        cin >> range >> special; // Second Line
        _range = range * 2;

        for(int i = 0; i < numRobots; i++) // Third Line
            cin >> locs[i];

        LL minRobots = (special + _range - 1) / _range;

        if(minRobots > numRobots) {
            cout << "Case #" << test_case+1 << endl;
            cout << -1 << endl;
            continue;
        }

        Answer = minMovements();

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
