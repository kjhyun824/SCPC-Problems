/*
 * =====================================================================================
 *
 *       Filename:  goodNum.cpp
 *
 *    Description:  Finding good numbers
 *
 *        Version:  1.0
 *        Created:  04/02/18 17:00:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int goodNum;

int arrSum[400001];

int main(int argc, char** argv)
{
  int T, test_case;

  cin >> T;
  for(test_case = 0; test_case  < T; test_case++)
  {
    for(int i = 0; i < 400001; i++) {
      arrSum[i] = 0;
    }

    goodNum = 0;
    int num;
    cin >> num;

    int arr[num];

    for(int i = 0 ; i < num; i++) {
      cin >> arr[i];

      for(int j = 0; j < i; j++) {
        if(arrSum[arr[i] - arr[j] + 200000] == 1) {
          goodNum++;
          break;
        }
      }

      for(int j = 0; j <= i; j++) {
        arrSum[arr[i] + arr[j] + 200000] = 1;
      }
    }

    cout << "Case #" << test_case+1 << endl;
    cout << goodNum << endl;
  }

  return 0;
}
