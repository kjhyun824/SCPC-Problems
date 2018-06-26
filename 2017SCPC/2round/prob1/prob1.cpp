#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		string Answer = "YES";
		int numDisk;
		unsigned long long totalSum = 0;
		string a;
		cin >> numDisk >> a;

		for(int i = 0 ; i < numDisk; i++) {
			char temp = a[i];
			int num;
			if(temp == 'A') {
				num = 0;
			}
			else if (temp = 'B') {
				num = 1;
			} else {
				num = 2;
			}

			totalSum += num;
		}

		int restDisk;
		for(int i = numDisk-1; i >= 0; i++) {
			if(a[i] != 'B') {
				restDisk = i;
				break;
			}
		}

		if(a[numDisk-1] == 'C') Answer = "NO";
		else {
			if(totalSum > 3*numDisk) Answer = "NO";
		}

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
