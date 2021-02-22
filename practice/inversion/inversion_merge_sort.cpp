#include <iostream>
using namespace std;

unsigned long Answer;

int numbers[100000];

void merge(int left, int mid, int right) {
	int num_left = mid - left + 1;
	int num_right = right - mid;

	int left_arr[num_left], right_arr[num_right];

	for(int i = 0; i < num_left; i++) {
		left_arr[i] = numbers[left + i];
	}

	for(int i = 0; i < num_right; i++) {
		right_arr[i] = numbers[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;

	while (i < num_left && j < num_right) {
		if(left_arr[i] <= right_arr[j]) {
			numbers[k++] = left_arr[i++];
		} else {
			numbers[k++] = right_arr[j++];
			Answer += (num_left - i);
		}
	}

	while (i < num_left) {
		numbers[k++] = left_arr[i++];
	}

	while (j < num_right) {
		numbers[k++] = right_arr[j++];
	}
}

void mergeSort(int left, int right) {
	if(left >= right) return;

	int mid = left + (right - left) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
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

		for(int i = 0; i < num; i++) {
			cin >> numbers[i];
		}

		mergeSort(0, num - 1);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
