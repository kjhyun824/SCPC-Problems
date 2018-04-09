#include <iostream>
#include <numeric>
using namespace std;

int Answer;

struct runnerInfo {
	int speed;
	int totalLen;
	int start;
	int firstNatural;
	int diff;
	bool checked;
};

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	while( b != 0 ) {
		unsigned long long r = a % b;
		a = b;
		b = r;
	}

	return a;
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
	return ((a*b) / gcd(a,b));
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int numRunner; 
		cin >> numRunner;
		runnerInfo runner[numRunner];
		int maxDiff = -1, maxDiffIdx;

		for(int i = 0; i < numRunner; i++) {
			cin >> runner[i].speed >> runner[i].totalLen >> runner[i].start;
			runner[i].checked = false;

			int runLength = (runner[i].totalLen - runner[i].start); // First track running length
			runner[i].firstNatural = -1;

			for(int j = 0; j < runner[i].speed; j++) {
				if(runLength % runner[i].speed == 0) {
					runner[i].firstNatural = runLength / runner[i].speed;
					break;
				}
				runLength += runner[i].totalLen;
			}

			runLength = 0;
			for(int j = 1; j <= runner[i].speed; j++) {
				runLength += runner[i].totalLen;
				if(runLength % runner[i].speed == 0) {
					runner[i].diff = runLength / runner[i].speed;
					if(runner[i].diff > maxDiff) {
						maxDiff = runner[i].diff;
						maxDiffIdx = i;
					}
					break;
				}
			}
		}

		unsigned long long diff = maxDiff;
		unsigned long long runTime = runner[maxDiffIdx].firstNatural;
		runner[maxDiffIdx].checked = true;
		bool hasError = false;

		while(true) {
			for(int i = 0; i < numRunner; i++) {
				if(runner[i].checked) continue;
				unsigned long long value = runTime + (unsigned long long) (runner[i].diff - runner[i].firstNatural);
				if(value % runner[i].diff != 0) {
					hasError = true;
				} else {
					diff = lcm(diff,runner[i].diff);
					runner[i].checked = true;
				}
			}

			if(!hasError) {
				Answer = runTime;
				break;
			} else {
				hasError = false;
				runTime += diff;
			}
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	return 0;
}
