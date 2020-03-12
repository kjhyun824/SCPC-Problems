#include <iostream>
using namespace std;

const int kMaxNum = 1000000;

int Answer;
int counts[kMaxNum+1];
int sums[kMaxNum+1];

void preprocess() {
	counts[1] = 0; counts[2] = 1;
	sums[1] = 0; sums[2] = 1;

	for(int num = 3; num <= kMaxNum; num++) {
		if(num%2 == 0) { // Even Num
			counts[num] = counts[num/2] + 1;
		} else { // Odd Num
			counts[num] = counts[(num+1)/2] + 2;
		}
		sums[num] = sums[num-1] + counts[num];
	}
}

int main(int argc, char** argv) {
	preprocess();

	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++) {
		int n1, n2;
		cin >> n1 >> n2;

		cout << "Case #" << test_case+1 << endl;
		cout << sums[n2] - sums[n1] + counts[n1] << endl;
	}

	return 0;
}
