#include <iostream>
using namespace std;

int Answer;

void merge(int arr[], int leftLow, int leftHigh, int rightLow, int rightHigh);

void mergeSort(int arr[], int low, int high) {
  if( low >= high ) return;

  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, mid+1, high);
}

void merge(int arr[], int leftLow, int leftHigh, int rightLow, int rightHigh) {
    int length = rightHigh-leftLow+1;
    int temp[length];
    int left = leftLow;
    int right = rightLow;
    for (int i = 0; i < length; ++i) { 
        if (left > leftHigh)
            temp[i] = arr[right++];
        else if (right > rightHigh)
            temp[i] = arr[left++];
        else if (arr[left] <= arr[right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++]; 
    }
    
    for (int i=0; i< length; ++i) 
        arr[leftLow++] = temp[i];
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        int num;
        cin >> num;

        int arr[num];

        for(int i = 0; i < num; i++) {
          cin >> arr[i];
        }

        mergeSort(arr, 0, num-1);

        int mult = 1;
        for(int i = 0; i < num; i++) {
          Answer += mult * arr[i];
          mult *= -1;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
