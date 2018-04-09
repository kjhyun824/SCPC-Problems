#include <iostream>
using namespace std;

int Answer;

int min(int h, int e, int l, int o) {
    int he, lo;
    if (h < e) he = h;
    else he = e;
    if (l < o) lo = l;
    else lo = o;

    if(he < lo) return he;
    else return lo;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int h=0, e=0, l=0, o=0;
        string input;
		Answer = 0;
        cin >> input;
        for(int i = 0; i < input.length(); i++) {
            switch(input[i]) {
                case 'h':
                    h++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                    break;
            }
        }
        l /= 2;

        Answer = min(h,e,l,o);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
