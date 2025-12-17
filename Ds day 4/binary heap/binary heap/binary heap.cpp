#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryHeap {
	int currentSize;
	vector<T> arr;

public:
	BinaryHeap(int capacity = 100) :arr(capacity + 1) {
		currentSize = 0;
		arr[0] = numeric_limits<T>::min();
	}

	T& operator[](int index) {
		return arr[index];
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	T& findMin() {
		return arr[1];
	}

	void insert(const T& value) {
		if (currentSize == arr.size() - 1) //array is full
		{
			arr.resize(arr.size() * 2);
		}
		currentSize++;
		int hole = currentSize;
		for (; value < arr[hole / 2]; hole /= 2) {
			arr[hole] = arr[hole / 2];
		}
		arr[hole] = value;
	}

	int LeftChild(int i) {
		return 2 * i;
	}

	int RightChild(int i) {
		return 2 * i + 1;
	}

	T deleteMin() {
		if (isEmpty())return -1;
		T minValue = findMin();
		arr[1] = arr[currentSize];
		currentSize--;
		percolateDown(1);
		return minValue;
	}

	void percolateDown(int hole) {
		T temp = arr[hole]; 
		int child;

		for (; LeftChild(hole) <= currentSize; hole = child) {
			child = LeftChild(hole);//Choose left

			if ((child != currentSize) && (arr[child + 1] < arr[child]))// choose right
			{
				child++;
			}

			if (arr[child] < temp) {
				arr[hole] = arr[child];
			}
			else {
				break;
			}
		}
			arr[hole] = temp;
	}

	void View() {
		if (isEmpty()) {
			cout << "Heap is empty..." << endl;
			return;
		}
		for (int i = 1; i <= currentSize; i++) {
			cout << arr[i] <<" ";
		}
		cout << endl;
	}
};

int main()
{
	BinaryHeap<int> heap;

	heap.insert(25);
	heap.insert(37);
	heap.insert(55);
	heap.insert(40);
	heap.insert(42);

	heap.View();
	cout << "-------------------" << endl;

	heap.deleteMin();

	heap.View();


}

/*
Left Child : 2 * i
Right Child : 2 * i + 1
Parent : i / 2 (Integer division)
*/

/*
template ✅
constructor ✅
isEmpty✅
findMin✅
operator [] (int Index ) ✅
insert ✅
percolateDown(int hole) ✅
deleteMin ✅
void View () ; => print State of Heap ✅
*/