#include <iostream>
#include <stack>
using namespace std;

int Answer;

// ( : 40, ) : 41, [ : 91, ] : 93, { : 123, } : 125
int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {
		Answer = 0;
		string input;
		cin >> input;

		std::stack<char> bracket;
		int count = 0;
		int startIdx;
		bool normal;
		for(int i = 0; i < input.length(); i++) {
			if(input[i] == 40 || input[i] == 91 || input[i] == 123) {
				if(bracket.empty())
					startIdx = i;
				bracket.push(input[i]);
				count++;
			} else {
				if(bracket.empty()) {
					count = 0;
					continue;
				}

				char topmember = bracket.top();
				normal = false;
				if((input[i] == 41 && topmember == 40) || (input[i] == 93 && topmember == 91) || (input[i] == 125 && topmember == 123)) {
					bracket.pop();
					normal = true;
				}

				if(!normal) {
					count = 0;
					i = startIdx;
					while(!bracket.empty())
						bracket.pop();
				} else {
					if(bracket.size() == 0)
						if(Answer < 2 * count)
							Answer = count * 2;
				}
			}

			if(i == input.length() - 1 && !bracket.empty()) {
				while(!bracket.empty())
					bracket.pop();
				i = startIdx;
				count = 0;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
