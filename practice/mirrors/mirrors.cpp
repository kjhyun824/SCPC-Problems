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
int currPos[2], direction;
char rooms[1000][1000];
bool visited[1000][1000];

bool isDone() {
    // Check the tracing is done
    if((currPos[0] < 0) || (currPos[0] >= size) || (currPos[1] < 0) || (currPos[1] >= size)) {
        return true;
    }

    return false;
}

void computeNextPos() {
    switch(direction) {
        case LEFT:
            currPos[1] -= 1;
            break;
        case UP:
            currPos[0] -= 1;
            break;
        case RIGHT:
            currPos[1] += 1;
            break;
        case DOWN:
            currPos[0] += 1;
            break;
    }
}

void mirrorRight() {
    switch(direction) {
        case LEFT:
            direction = DOWN;
            break;
        case UP:
            direction = RIGHT;
            break;
        case RIGHT:
            direction = UP;
            break;
        case DOWN:
            direction = LEFT;
            break;
    }

    if(!visited[currPos[0]][currPos[1]]) {
        passNum++;
        visited[currPos[0]][currPos[1]] = true;
    }
}

void mirrorLeft() {
    switch(direction) {
        case LEFT:
            direction = UP;
            break;
        case UP:
            direction = LEFT;
            break;
        case RIGHT:
            direction = DOWN;
            break;
        case DOWN:
            direction = RIGHT;
            break;
    }

    if(!visited[currPos[0]][currPos[1]]) {
        passNum++;
        visited[currPos[0]][currPos[1]] = true;
    }
}

void process() {
    switch(rooms[currPos[0]][currPos[1]]) {
        case '0':
            break;
        case '1':
            mirrorRight();
            break;
        case '2':
            mirrorLeft();
            break;
    }

    computeNextPos();
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

        currPos[0] = 0;
        currPos[1] = 0;
        direction = RIGHT;

        while(true) {
            if(!isDone()) {
                process();
            } else {
                break;
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << passNum << endl;
	}

	return 0;
}
