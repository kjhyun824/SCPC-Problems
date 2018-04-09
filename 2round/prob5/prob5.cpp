#include <iostream>
using namespace std;

int Answer;

struct Stick{
	int start;
	int end;
	int weight;
};

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int numStick;
		cin >> numStick;
		Stick sticks[numStick];
		int minStart = 1000000000, maxEnd = -1;
		for(int i = 0; i < numStick; i++) {
			cin >> sticks[i].start >> sticks[i].end >> sticks[i].weight;
			if(minStart > sticks[i].start) minStart = sticks[i].start;
			if(maxEnd < sticks[i].end) maxEnd = sticks[i].end;
		}



		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
