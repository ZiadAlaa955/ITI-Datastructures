#include <iostream>
using namespace std;

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void bubbleSort(int* arr, int size) {
	bool sorted;
	for (int i = 0; i < size - 1; i++) {
		sorted = true;

		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}
		if (sorted == true) {
			break;
		}
	}
}

void merge(int* arr, int lFirst, int lLast, int rFirst, int rLast) {
	int tempArr[8];
	int index = lFirst;
	int saveFirst = lFirst;

	while ((lFirst <= lLast) && (rFirst <= rLast)) {
		if (arr[lFirst] < arr[rFirst]) {
			tempArr[index] = arr[lFirst];
			index++;
			lFirst++;
		}
		else {
			tempArr[index] = arr[rFirst];
			index++;
			rFirst++;
		}
	}
	while (lFirst <= lLast) {
		tempArr[index] = arr[lFirst];
		index++;
		lFirst++;
	}
	while (rFirst <= rLast) {
		tempArr[index] = arr[rFirst];
		index++;
		rFirst++;
	}

	//Assign sorted elements to original array
	for (int i = saveFirst; i <= rLast; i++) {
		arr[i] = tempArr[i];
	}
}

void mergeSort(int* arr, int first, int last) {
	//if array has more than 1 element 
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, mid + 1, last);
	}
}

int sequentialSearch(int* arr, int size, int target) {
	if (arr[size - 1] < target || arr[0] > target) return -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) return i;
	}
}

void quickSort(int* arr, int first, int last) {
	int i = first;
	int j = last;
	int pivot = arr[(i + j) / 2];

	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (first < j)quickSort(arr, first, j);
	if (last > i)quickSort(arr, i, last);
}

void heapify(int* arr, int size, int i) {
	int largest = i; //suppose i is the root
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (arr[left] > arr[largest] && left < size) {
		largest = left;
	}
	if (arr[right] > arr[largest] && right < size) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int* arr, int size) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int binarySearchRecursive(int* arr, int first, int last, int target) {
	if (first <= last) {
		int mid = (first + last) / 2;
		if (target == arr[mid]) {
			return mid;
		}
		else if (target < arr[mid]) {
			return binarySearchRecursive(arr, first, mid, target);
		}
		else {
			return binarySearchRecursive(arr, mid + 1, last, target);
		}
	}
	return -1;
}

int binarySearchIterative(int* arr, int first, int last, int target) {
	while (first <= last) {
		int mid = (first + last) / 2;
		if (target == arr[mid])return mid;
		else if (target < arr[mid]) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}


void displayArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)cout << ", ";
	}
}

int main() {
	int arr[8] = { 5,8,2,3,1,7,6,4 };

	//bubbleSort(arr, 8);
	//mergeSort(arr, 0, 7);
	//quickSort(arr, 0, 7);
	heapSort(arr, 8);
	//cout << "target found at index: " << sequentialSearch(arr, 8, 5) << endl;
	//cout << "target found at index: " << binarySearchRecursive(arr, 0, 7, 6) << endl;
	//cout << "target found at index: " << binarySearchIterative(arr, 0, 7, 16) << endl;

	displayArray(arr, 8);


	return 0;
}

/*
bubble
merge
sequential

binary search
quick sort
heap
*/