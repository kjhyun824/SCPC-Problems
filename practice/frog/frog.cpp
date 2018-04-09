#include <iostream>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        int numRocks, maxJump, pos = 0, idx = 0;
        cin >> numRocks;
        int *rocks;
        rocks = new int[++numRocks];
        rocks[0] = 0;
        for(int i = 1; i < numRocks; i++) {
            cin >> rocks[i];
        }
        cin >> maxJump;

        while(true) {
            bool hasJumped = false;
            while(true) {
                if(idx+1 < numRocks && rocks[idx+1] - pos <= maxJump) {
                    idx += 1;
                    hasJumped = true;
                    if(idx == numRocks - 1) break;
                } else {
                    break;
                }
            }

            if(hasJumped) {
                pos = rocks[idx];
                Answer++;
                if(idx == numRocks - 1) break;
            } else {
                Answer = -1;
                break;
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
