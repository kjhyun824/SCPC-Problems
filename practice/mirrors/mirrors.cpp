/*
 * =====================================================================================
 *
 *       Filename:  mirrors.cpp
 *
 *    Description:  Find the number of mirrors that reflects
 *
 *        Version:  1.0
 *        Created:  10/11/18 19:36:39
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

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

int passNum, size;
int currPos[2], nextPos[2], direction;
char rooms[1000][1000];
bool visited[1000][1000];

bool isDone() {
    // Check the tracing is done
    if((nextPos[0] < 0) || (nextPos[0] >= size) || (nextPos[1] < 0) || (nextPos[1] >= size)) {
        return true;
    }

    return false;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> size;

		passNum = 0;

        for(int i = 0; i < size; i++) {
            string room;
            cin >> room;
            for(int j = 0; j < size; j++) {
                rooms[i][j] = (char) room[j];
                visited[i][j] = false;
            }
        }

        nextPos[0] = 0;
        nextPos[1] = 0;
        direction = RIGHT;

        while(true) {
            if(!isDone()) {
                // TODO : 
            } else {
                break;
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << passNum << endl;
	}

	return 0;
}
