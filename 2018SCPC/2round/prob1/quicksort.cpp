/*
 * =====================================================================================
 *
 *       Filename:  quicksort.cpp
 *
 *    Description:  2018 SCPC 2Round - Problem 1 : Quick Sort 
 *
 *        Version:  1.0
 *        Created:  07/07/18 12:00:16
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

int Answer;
int modArr[200000];
int origin[200000];

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;

            while (arr[j] > pivot)
                  j--;

            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);

      if (i < right)
            quickSort(arr, i, right);
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		Answer = 0;
        int len;
        cin >> len;

        for(int i = 0; i < len; i++) {
            cin >> origin[i];
            modArr[i] = origin[i];
        }

        quickSort(modArr, 0, len-1);

        int preMax = -1;
        for(int i = 0; i < len; i++) {
            if(modArr[i] == origin[i] && preMax < origin[i]) {
                Answer++;
            }
            
            if(preMax < origin[i]) preMax = origin[i];
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
