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
bool pelindromes[10010];
bool twosums[20010];

bool isPelindrome(int num) {
    string _num = to_string(num);
    if(_num == string(_num.rbegin(), _num.rend())) return true;
    else return false;
}

void getAll() {
    for(int i = 0; i <= 10000; i++) {
        pelindromes[i] = false;
        if(isPelindrome(i)) {
            pelindromes[i] = true;
            pList.push_back(i);
        }
    }

    for(int i = 0; i < 20002; i++) {
        twosums[i] = false;
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

	for(test_case = 0; test_case  < T; test_case++) {
        int targetNum;
        cin >> targetNum;

		cout << "Case #" << test_case+1 << endl;

        if(pelindromes[targetNum]) { // Pelindrom itself
		    cout << "1 " << targetNum << endl;
        } else if(twosums[targetNum]) { // Available for two numbers sum
            int res[2];
            for(int i = 0; i < pList.size(); i++) {
                if(targetNum > pList[i] && pelindromes[targetNum - pList[i]]) {
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
                if(targetNum > pList[i] && twosums[targetNum - pList[i]]) {
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
                if(targetNum > pList[i] && pelindromes[targetNum - pList[i]]) {
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
