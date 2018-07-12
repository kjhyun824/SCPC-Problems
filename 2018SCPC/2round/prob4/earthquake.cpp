/* * =====================================================================================
 *
 *       Filename:  earthquake.cpp
 *
 *    Description:  2018 SCPC 2Round - Problem 4 : Earthquake
 *
 *        Version:  1.0
 *        Created:  07/07/18 13:21:45
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
using namespace std;

int Answer;
int data[10000];
int pat[300];
int idx[10001];
int patIdx[10001];
int dataIdx[10001];
int N, M, K;

void rankArr(int arr[], int len) {
    int temp[len];
    for(int i = 0; i < len; i++) {
        temp[i] = arr[i];
    }

    sort(temp, temp+len);

    for(int i = 0; i < len; i++) {
        idx[temp[i]] = i;
    }

    for(int i = 0; i < len; i++) {
        arr[i] = idx[arr[i]]; 
    }
}

bool isEQ(int _temp[], int _pat[], int thr, int len) {
    if(thr == 0) {
        for(int i = 0; i < M; i++) {
            if(_temp[i] != pat[i]) return false;
        }

        return true;
    } else {
        for(int i = 0; i < len; i++) {
            int __temp[len-1], __pat[len-1];
            for(int j = 0; j < i; j++) {
                __temp[j] = _temp[j];
                __pat[j] = _pat[j];
            }
            for(int j = i+1; j < len; j++) {
                __temp[j-1] = _temp[j];
                __pat[j] = _pat[j];
            }

            if(isEQ(__temp, __pat, thr-1, len-1)) return true;
        }
        
        return true;
    }
}

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        cin >> N >> M >> K;

        for(int i = 0; i < N; i++)
            cin >> data[i];

        for(int i = 0; i < M; i++) 
            cin >> pat[i];

        rankArr(pat, M);

        for(int i = 0; i < M; i++) {
            patIdx[pat[i]] = i;
        }

        for(int start = 0; start <= N-M; start++) {
            int _temp[M];
            for(int i = start; i < start+M; i++)
                _temp[i-start] = data[i];

            rankArr(_temp, M);

            for(int i = 0; i < M; i++) {
                dataIdx[_temp[i]] = i;
            }

            for(int k = 0; k <= K; k++) {
                if(isEQ(_temp, pat, k, M)) {
                    Answer++;
                    break;
                }
            }
        }

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
