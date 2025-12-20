#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;

string redColor = "\033[31m", greenColor = "\033[32m", defaultANSI = "\033[0m";

bool isPrime(int num) {
	if (num <= 1) return false;
	if (num == 2 || num == 3)return true;
	if (num % 2 == 0)return false;
	for (int i = 3; i * i  <= num; i++) {
		if (num % i == 0)return false;
	}
	return true;
}

class Employee {
	string name;
	int age;
	double salary;
public:
	Employee() :name("Unknown"), age(21), salary(1000) {}
	Employee(string name, int age, double salary) :name(name), age(age), salary(salary) {}

	friend ostream& operator<<(ostream& cout, const Employee& e) {
		cout << "Name: " << e.name << endl;
		cout << "Age: " << e.age << endl;
		cout << "Salary: " << e.salary << endl;
		cout << "--------------" << endl;
		return cout;
    }
};

template<class keyType, class valueType>
class MapEntry {
	keyType key; //int
	valueType value; //employee

public:
	MapEntry(keyType key, valueType value) : key(key), value(value) {}

	bool operator==(const keyType& otherKey)const 
	{
		return key == otherKey;
	}
	bool operator==(const MapEntry& other)const {
		return this.key == other.key;
	}
	//Getters
	keyType getKey() { return key; }
	valueType getValue() { return value; }
};

template<class keyType,class valueType>
class HashTable {
	//vector => buckets AND List => Chain
	vector<list<MapEntry<keyType, valueType>>> tableLists; 
	int currentSize;
public:
	HashTable(int size = 101) : tableLists(size), currentSize(0) {}

	int size() {
		return tableLists.size();
	}

	bool contains(const keyType& myKey) {
		//1-search which bucket should this key be in
		int whichList = hashingKey(myKey);
		//2-create bucket with the index that the key should be in
		list<MapEntry<keyType, valueType>>& bucket = tableLists[whichList];
		//3-iterate over the chain in the specified bucket to find the key
		for (auto it : bucket) {
			if (it == myKey)return true;
		}
		return false;
	}

	bool insert(const keyType& myKey, const valueType& myValue) {
		if (contains(myKey))
			return false;

		int whichList = hashingKey(myKey); //bucket index
		MapEntry<keyType, valueType> employeeData(myKey, myValue);
		tableLists[whichList].push_back(employeeData);
		currentSize++;

		if ((double)currentSize / tableLists.size() > 0.7)
			rehash();

		return true;
	}

	bool remove(const keyType& myKey) {
		int whichList = hashingKey(myKey);
		auto it = find(tableLists[whichList].begin(), tableLists[whichList].end(), myKey);
		if (it == tableLists[whichList].end())return false;
		tableLists[whichList].erase(it);
		currentSize--;
		return true;
	}

	void makeEmpty() {
		for (auto& it : tableLists)it.clear();
		currentSize = 0;
	}

	valueType lookUp(const keyType& myKey)  {
		bool found = false;
		int whichList = hashingKey(myKey);
		//2-create bucket with the index that the key should be in
		list<MapEntry<keyType, valueType>>& bucket = tableLists[whichList];
		//3-iterate over the chain in the specified bucket to find the key
		auto entry = bucket.begin();
		while (entry != bucket.end()) {
			if (*entry == myKey) {
				found = true;
				break;
			}
			entry++;
		}

		if (found == true) {
			return entry->getValue();
		}
		else {
			throw runtime_error("Key not found");
		}
	}

protected:
	int hashingKey(const keyType& mykey) const
	{
		//1-turn key into massive integer
		hash<keyType> hasher; 
		//2-assign the hashed key into initial var
		int initialHashValue = hasher(mykey); 
		//3-hashed_key % list_size => return index to be stored in the list
		return initialHashValue % tableLists.size(); 
	}

	void rehash() {
		//step1: backup data
		vector<list<MapEntry<keyType, valueType>>> oldLists = tableLists;
		//step2: resize vector => size*2 + next_prime
		int newSize = tableLists.size() * 2;
		while (!isPrime(newSize)) {
			newSize++;
		}
		//step3: clear the list
		makeEmpty();
		tableLists.resize(newSize);
		//step4: insertion
		for (int i = 0; i < oldLists.size(); i++) {
			for (auto bucket : oldLists[i]) {
				insert(bucket.getKey(), bucket.getValue());
			}
		}
	}
};

int main()
{
	cout << greenColor << "-------------Hash Table Test----------" << defaultANSI << endl;

	HashTable<int, Employee> myTable;
	myTable.insert(100, Employee("Ziad", 22, 5000));
	myTable.insert(110, Employee("Ahmed", 25, 10000));
	myTable.insert(120, Employee("Amr", 30, 6000));

	if (myTable.contains(100))
		cout << "key 100 exists" << endl;
	else
		cout << "key 100 does not exist" << endl;

	cout << "Key 110 Data: " << endl;
	cout << myTable.lookUp(110) << endl;

	myTable.remove(100);
	if (myTable.contains(100))
		cout << "key 100 exists" << endl;
	else
		cout << "key 100 does not exist" << endl;

	for (int i = 0; i < 100; i++) {
		myTable.insert(200 + i, Employee("TestUser", 20, 3000));
	}

	if (myTable.contains(205))
		cout << "key 100 exists" << endl;
	else
		cout << "key 100 does not exist" << endl;

	return 0;
}

/*
hash table class (template)✅
contains()✅
Insert()✅
Remove()✅
MakeEmpty()✅
Rehash()✅
LookUP()✅
MyHashFunction()✅

MapEntry class (template)✅
GetKey()✅
GetValue()✅
*/