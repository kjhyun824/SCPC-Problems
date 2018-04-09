#include <iostream>
#include <vector>

using namespace std;

int start;
int fin;
char findList[] = { 'a', 'e', 'i', 'o', 'u' };

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		start = -2;
		fin = -2;

		int numLines;
		cin >> numLines;
		char* input;
		input = new char[numLines];
		int* startPoint;
		startPoint = new int[numLines];
		int numA = 0;

		for (int i = 0; i < numLines; i++) {
			cin >> input[i];
			if (input[i] == 'a') {
				startPoint[numA++] = i;
			}
		}

		int minDist = numLines;
		for (int i = 0; i < numA; i++) {
			int currPos = startPoint[i];
			int startPos = currPos;
			int nextFind = 1;
			while (currPos < numLines) {
				if (input[currPos] == findList[nextFind]) {
					nextFind++;
				}

				if (nextFind == 5) {
					if (minDist > currPos - startPos) {
						minDist = currPos - startPos;
						start = startPos;
						fin = currPos;
					}
					break;
				}
				currPos++;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << start + 1 << " " << fin + 1<< endl;
	}

	return 0;
}
