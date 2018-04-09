#include <iostream>
using namespace std;

typedef unsigned long long ULL;

ULL pow(ULL a, ULL b) {
    ULL num = 1;
    for(ULL i = 0; i < b; i++) {
        num *= a;
    }

    return num;
}

int main(int argc, char** argv)
{
    int arr[9] = {1,2,4,8,16,5,10,3,6};
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int num;
        ULL min, max;
        cin >> num;

        if(num < 9) min = arr[num];
        else min = 3 * pow(2,num-7);

        max = pow(2,num);
        
		cout << "Case #" << test_case+1 << endl;
		cout << min << " " << max << endl;
	}

	return 0;
}
