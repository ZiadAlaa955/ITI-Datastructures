#include <iostream>
using namespace std;

template<class T>
class DynamicArray {
private:
	T* arr; //pointer -> array
	int size; //number of elements in array
	int capacity; //physical array size in memory => number of elements + number of empty reserved places in memory
	static const int spareCapacity = 16; //base capacity size 

public:
	explicit DynamicArray(int initCapacity = 0) 
	{
		if (initCapacity < spareCapacity) {
			initCapacity = spareCapacity;
		}
		size = 0;
		capacity = initCapacity;
		arr = new T[capacity];
	}
	 
	DynamicArray(const DynamicArray& other) {
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}

	}

	~DynamicArray() {
		delete[] arr;
	}

	DynamicArray& operator=(const DynamicArray& other) {
		if (this != &other) 
		{
			delete[] arr;
			size = other.size;
			capacity = other.capacity;
			arr = new T[capacity];
			for (int i = 0; i < size; i++) {
				arr[i] = other.arr[i];
			}
		}
			return *this;
	}

	T& operator[](int index)
	{
		return arr[index];
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	void push_back(T value) {
		if (size == capacity) {
			resize(capacity * 2);
		}
		arr[size] = value;
		size++;
	}

	void trim() {
		if (size < capacity) {
			resize(size);
		}
	}

	int search(const T& value) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == value)return i;
		}
		return -1;
	}

	void popback() {
		if (size == 0) {
			cout << "Array is empty..." << endl;
		}
		else {
			size--;
			cout << "Last element popped.." << endl;
		}
	}

	void removeAt(int index) {
		if (index < 0 || index >= size) {
			cout << "index is out of range..." << endl;
			return;
		}
		else {
			for (int i = index; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
			cout << "element removed successfully" << endl;
		}
	}

	void remove(const T& value) {
		int index = search(value);
		removeAt(index);
	}

	void insertAt(int index, T value) {
		if (index < 0 || index > size) {
			cout << "index is out of range..." << endl;
			return;
		}
		if (size == capacity) resize(capacity * 2);
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		size++;
	}

protected:
	void resize(int newCapacity) {
		if (newCapacity < size) //capacity less than number of elments
		{
			return;
		}
		else {
			T* newArr = new T[newCapacity];
			for (int i = 0; i < size; i++) {
				newArr[i] = arr[i];
			}
			capacity = newCapacity;
			delete[] arr;
			arr = newArr;
		}
	}
};

int main()
{
	DynamicArray<int> intArr;
	intArr.push_back(10);
	intArr.push_back(20);
	intArr.push_back(30);
	cout << "Size: " << intArr.getSize() << endl;
	cout << "Capacity: " << intArr.getCapacity() << endl;
	for (int i = 0; i < intArr.getSize(); i++) {
		cout << intArr[i] << " ";
	}
	cout << endl;
	intArr.trim();
	cout << "Size: " << intArr.getSize() << endl;
	cout << "Capacity: " << intArr.getCapacity() << endl;
	intArr.remove(20);
	intArr.removeAt(1);
	for (int i = 0; i < intArr.getSize(); i++) {
		cout << intArr[i] << " ";
	}
	cout << endl;

	cout << "---------------------------------------" << endl;
	
	
	DynamicArray<string> stringArr;
	stringArr.push_back("Ziad");
	stringArr.push_back("Ezzat");
	stringArr.insertAt(1, "Alaa");
	for (int i = 0; i < stringArr.getSize(); i++) {
		cout << stringArr[i] << " ";
	}
	cout << endl;
	cout << "\"Ziad\" at index: " << stringArr.search("Ziad") << endl;
	stringArr.popback();
	for (int i = 0; i < stringArr.getSize(); i++) {
		cout << stringArr[i] << " ";
	}
	cout << endl;

}








/*
template dynamic array ✅
constructor & destrucor ✅
copy constructor ✅
= operator ✅
[] operator => get & update ✅
return size ✅
return capacity ✅
Resize ✅
push back ✅
search ✅
pop back ✅
remove (value)✅
remove (index)✅
insert at ✅
*/