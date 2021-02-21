#include <iostream>
using namespace std;

int Answer;

int pos[100001];

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

		int num;
		cin >> num;

		for(int idx = 1; idx <= num; idx++) {
			int input;
			cin >> input;
			pos[input] = idx;
		}

		for(int idx = num; idx >= 1; idx--) {
			Answer += (idx - pos[idx]);
			for(int i = num - 1; i >= 1; i--) {
				if(pos[i] > pos[idx]) pos[i]--;
			}
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
