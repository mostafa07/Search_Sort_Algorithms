#include <iostream>

using namespace std;

#define SIZE	10
#define RANGE	99

void printArray(int arr[]);

int linearSearch(int arr[], int num);
int binarySearch_Iterative(int arr[], int num, int left, int right);
int binarySearch_Recursive(int arr[], int num, int left, int right);

void insertionSort(int arr[]);
void selectionSort(int arr[]);
void bubbleSort(int arr[]);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void countingSort(int arr[]);



int main(void) {

	int arr1[SIZE] = {1, 3, 4, 10, 50, 55, 60, 80, 88, 99};

	cout << linearSearch(arr1, 88) << endl;
	cout << binarySearch_Iterative(arr1, 10, 0, SIZE - 1) << endl;
	cout << binarySearch_Recursive(arr1, 10, 0, SIZE - 1) << endl;

	int arr2[SIZE] = {2, 3, 10, 99, 85, 11, 12, 13, 67, 33};

	//insertionSort(arr2);
	//selectionSort(arr2);
	//bubbleSort(arr2);
	//mergeSort(arr2, 0, SIZE - 1);
	countingSort(arr2);
	printArray(arr2);

	int arr3[3] = {42, 43, 44};
	cout << endl;
	cout << binarySearch_Iterative(arr3, 42, 0, 3-1) << endl;
	cout << binarySearch_Recursive(arr3, 42, 0, 2) << endl;


	return 0;
}



void printArray(int arr[]) {

	cout << "[ ";
	for (int i = 0; i < SIZE; ++i)
		cout << arr[i] << ' ';
	cout << ']';
}

int linearSearch(int arr[], int num) {

	for (int i = 0; i < SIZE; ++i) {
		if (arr[i] == num)
			return i;
	}

	return -1;	// indicates that element is not found
}

int binarySearch_Iterative(int arr[], int num, int left, int right) {

	//int left = 0, right = size - 1;

	while (left <= right) {
		int mid = ( (unsigned int)left + (unsigned int)right ) >> 1;

		if (arr[mid] == num)
			return mid;
		else if (arr[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

int binarySearch_Recursive(int arr[], int num, int left, int right) {

	if (left > right) {
		return -1;
	}

	int mid = ( (unsigned int)left + (unsigned int)right ) >> 1;

	if (arr[mid] == num)
		return mid;
	else if (arr[mid] > num)
		return binarySearch_Recursive(arr, num, left, mid - 1);
	else
		return binarySearch_Recursive(arr, num, mid + 1, right);

}

void insertionSort(int arr[]) {

	for (int i = 0; i < SIZE; ++i) {
		int element = arr[i];
		int j = i - 1;

		while (j >= 0 && element < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = element;
	}
}

void selectionSort(int arr[]) {

	for (int i = 0; i < SIZE - 1; ++i) {
		int minIdx = i;

		for (int j = i + 1; j < SIZE; ++j)
			if (arr[j] < arr[minIdx])
				minIdx = j;

		swap(arr[i], arr[minIdx]);
	}
}

void bubbleSort(int arr[]) {

	bool swapped = true;
	for (int i = 0; i < SIZE - 1 && swapped; ++i) {
		swapped = false;
		for (int j = 0; j < SIZE - i - 1; ++j) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
	}
}

void merge(int arr[], int left, int mid, int right) {

	int i, j, k;
	int size1 = mid - left + 1;
	int size2 = right - mid;

	int tmpLeft[size1];
	int tmpRight[size2];

	for (i = 0; i < size1; ++i)
		tmpLeft[i] = arr[left + i];
	for (j = 0; j < size2; ++j)
		tmpRight[j] = arr[mid + 1 + j];

	i = 0; j = 0;
	k = left;

	while (i < size1 && j < size2) {
		if (tmpLeft[i] <= tmpRight[j])
			arr[k++] = tmpLeft[i++];
		else
			arr[k++] = tmpRight[j++];
	}

	while (i < size1)
		arr[k++] = tmpLeft[i++];
	while (j < size2)
		arr[k++] = tmpRight[j++];

}

void mergeSort(int arr[], int left, int right) {

	if (left < right) {
		int mid = ( (unsigned int)left + (unsigned int)right ) >> 1;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void countingSort(int arr[]) {

	int count[RANGE+1] = {0};
	int output[SIZE];

	for (int i = 0; i < SIZE; ++i)
		++count[ arr[i] ];

	for (int i = 1; i <= RANGE; ++i)
		count[i] += count[i-1];

	for (int i = 0; i < SIZE; ++i) {
		output[ count[ arr[i] ]  - 1 ] = arr[i];
		--count[ arr[i] ];
	}

	for (int i = 0; i < SIZE; ++i)
		arr[i] = output[i];
}



