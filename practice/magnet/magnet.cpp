/*
 * =====================================================================================
 *
 *       Filename:  magnet.cpp
 *
 *    Description:  Find the minimum currency that the sticks attatch to magnet
 *
 *        Version:  1.0
 *        Created:  04/10/18 14:55:43
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
#include <algorithm>
using namespace std;

struct stick {
    unsigned int start;
    unsigned int end;
    unsigned int weight;
    bool operator<(const stick &rhs) const {
        return end < rhs.end;
    }
};

vector<stick> sticks;
int numSticks;

int Answer;

int getMinCurrent() {
    for(auto a : sticks){
        printf("[DEBUG] %d, %d, %d\n", a.start, a.end, a.weight);
    }
    return 0;
}

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        sticks.clear();
        Answer = 0;
        cin >> numSticks;

        for(int i = 0; i < numSticks; i++) {
            stick temp;
            cin >> temp.start >> temp.end >> temp.weight;
            sticks.push_back(temp);
        }
        sort(sticks.begin(), sticks.end());

        Answer = getMinCurrent();

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
