/*
 * =====================================================================================
 *
 *       Filename:  pelindrome.cpp
 *
 *    Description:  2018 SCPC 1Round - Problem 2 : Pelindrome Sum
 *
 *        Version:  1.0
 *        Created:  06/23/18 13:11:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> pList;
bool pelindromes[10001];
bool twosums[20002];
int Answer;

bool isPelindrome(int num) {
    string _num = to_string(num);
    string rev = _num;
    reverse(_num.begin(), _num.end());
    if(_num == rev) return true;
    else return false;
}

void getAll() {
    for(int i = 1; i <= 10000; i++) {
        pelindromes[i] = false;
        if(isPelindrome(i)) {
            pelindromes[i] = true;
            pList.push_back(i);
        }
    }
    
    for(int i = 0; i < pList.size(); i++) {
        for(int j = 0; j < pList.size(); j++) {
            twosums[pList[i] + pList[j]] = true;
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

    getAll();
	for(test_case = 0; test_case  < T; test_case++)
	{
        int targetNum;
        cin >> targetNum;

		cout << "Case #" << test_case+1 << endl;
        if(pelindromes[targetNum]) {
		    cout << "1 " << targetNum << endl;
        } else if(twosums[targetNum]) {
            int res[2];
            for(int i = 0; i < pList.size(); i++) {
                if(pelindromes[targetNum - pList[i]]) {
                    res[0] = pList[i];
                    res[1] = targetNum - pList[i];
                    break;
                }
            }
            sort(res, res+2);

            cout << "2 " << res[1] << " " << res[0] << endl;
        } else {
            int res[3];
            bool isPossible = false;
            for(int i = 0; i < pList.size(); i++) {
                if(twosums[targetNum - pList[i]]) {
                    res[0] = pList[i];
                    targetNum -= pList[i];
                    isPossible = true;
                    break;
                }
            }

            if(!isPossible) {
                cout << "0" << endl;
                continue;
            }

            for(int i = 0; i < pList.size(); i++) {
                if(pelindromes[targetNum - pList[i]]) {
                    res[1] = pList[i];
                    res[2] = targetNum - pList[i];
                    break;
                }
            }
            sort(res, res+3);
            cout << "3 " << res[2] << " " << res[1] << " " << res[0] << endl;
        }
	}

	return 0;
}
