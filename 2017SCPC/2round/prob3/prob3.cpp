#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int Answer;

#define MAX 100001
int** divisor;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	divisor = new int*[MAX];

	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int arrLen, numCase;
		cin >> arrLen >> numCase;
		int numArr[arrLen];
		for(int i = 0; i < arrLen; i++) {
			cin >> numArr[i];
		}

		for(int i = 0; i < numCase; i++) {
			int testNum, start, end;
			cin >> testNum >> start >> end;

			int numDiv = 0;
			int sqrtNum = ceil(sqrt(testNum));
			int divMax = 2*sqrtNum + 1;
			if(divisor[testNum] == NULL) {
				divisor[testNum] = new int[divMax];
				for(int j = 0; j < divMax; j++) {
					divisor[testNum][j] = -1;
				}
				numDiv = 0;

				for(int j = 1; j < sqrtNum; j++) {
					if(testNum % j == 0) {
						divisor[testNum][numDiv++] = j;
						divisor[testNum][numDiv++] = testNum / j;
					}
				}

				if(sqrtNum * sqrtNum == testNum) {
					divisor[testNum][numDiv++] = sqrtNum;
				}

				std::sort(divisor[testNum],divisor[testNum]+numDiv);
			} else {
				while(divisor[testNum][numDiv] != -1) {
					numDiv++;
				}
			}

			bool isAnswer[numDiv];
			isAnswer[0] = false;
			for(int j = 1 ; j < numDiv; j++) {
				isAnswer[j] = true;
			}


			for(int j = numDiv - 1; j > 0 ; j--) {
				if(!isAnswer[j]) continue;

				for(int k = start-1; k < end; k++) {
					if(numArr[k] % divisor[testNum][j] == 0) {
						for(int j2 = j; j2 > 0; j2--) {
							if(isAnswer[j2] && (divisor[testNum][j] % divisor[testNum][j2] == 0)) { 
								isAnswer[j2] = false;
							}
						}
						break;
					}
				}
			}

			for(int j = 0; j < numDiv; j++) {
				if(isAnswer[j]) {
					Answer++;
				}
			}
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
