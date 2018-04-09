#include <iostream>
using namespace std;

void hanoi(int num, int a, int b, int c) {
	if(num == 1) {
		cout << a << "->" << c << endl;
	} else {
		hanoi(num-1,a,c,b);
		cout << a << "->" << c << endl;
		hanoi(num-1,b,a,c);
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int numDisk;
		cin >> numDisk;
		cout << "Case #" << test_case+1 << endl;
		hanoi(numDisk,1,2,3);
	}
	
	return 0;//Your program should return 0 on normal termination.
}
