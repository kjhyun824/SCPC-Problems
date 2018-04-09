#include <iostream>
using namespace std;

int Answer;
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
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        int num;
        cin >> num;

        int arr[num];

        for(int i = 0; i < num; i++) {
          cin >> arr[i];
        }

        quickSort(arr, 0, num-1);

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
