#include <iostream>
using namespace std;

class Employee {
public:
    int id = 0;
    string name;
    int age;
    double salary;

    Employee() : id(0), name("unknown"), age(20), salary(1000) {}
    Employee(int id, string name, int age, double salary) : id(id), name(name), age(age), salary(salary) {}
};

class Node {
public:
    Employee data;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(Employee e) : data(e), next(nullptr), prev(nullptr) {}
};

class BaseDLL {
public:
    Node* head;
    Node* tail;

    BaseDLL() : head(nullptr), tail(nullptr) {}
    BaseDLL(BaseDLL& other)  {
        head = nullptr;
        tail = nullptr;
        Node* current = other.head;
        while (current != nullptr) {
            insertNode(current->data);
            current = current->next;
        }
    }

    BaseDLL& operator=(BaseDLL& other) {
        if (this == &other)return* this;
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;

        current = other.head;
        while (current != nullptr) {
            insertNode(current->data);
            current = current->next;
        }
        return *this;
    }

    void operator[](int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                cout << "-----Employee Data------" << endl;
                cout << "ID: " << current->data.id << endl;
                cout << "Name: " << current->data.name << endl;
                cout << "Age: " << current->data.age << endl;
                cout << "Salary: " << current->data.salary << endl;
                cout << "---------------------" << endl;
            }
            else {
                count++;
            }
            current = current->next;
        }
        if(count == 0) cout << "Not found..." << endl;
    }

    virtual void insertNode(Employee employee) = 0;

    Node* searchNode(int nodeID) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.id == nodeID)break;
            else current = current->next;
        }
        return current;
    }

    bool deleteNode(int nodeID) {
        Node* current = searchNode(nodeID);
        if (current == nullptr) {
            cout << "ID not found" << endl;
            return false;
        }
        else {
            if (head == tail) head = tail = nullptr;
            else if (current == head) {
                head = head->next;
                head->prev = nullptr;
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
    }

    void displayNode(int nodeID) {
        Node* current = searchNode(nodeID);
        if (current == nullptr) cout << "Not found..." << endl;
        else
        {
            cout << "-----Employee Data------" << endl;
            cout << "ID: " << current->data.id << endl;
            cout << "Name: " << current->data.name << endl;
            cout << "Age: " << current->data.age << endl;
            cout << "Salary: " << current->data.salary << endl;
            cout << "---------------------" << endl;
        }
    }

    void displayAll() {
        Node* current = head;
        cout << "-----------Employees Data---------" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->data.id << endl;
            cout << "Name: " << current->data.name << endl;
            cout << "Age: " << current->data.age << endl;
            cout << "Salary: " << current->data.salary << endl;
            cout << "---------------------" << endl;
            current = current->next;
        }
    }

    int NodeCount() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    virtual ~BaseDLL() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

class SortedDLL : public BaseDLL{
public:
    void insertNode(Employee employee) override{
        Node* newNode = new Node(employee);

        //If LL is empty
        if (head == nullptr) {
            head = tail = newNode;
        }
        else
        {
            Node* current = head;
            while ((current != nullptr) && (current->data.id < newNode->data.id)) current = current->next;
            if (current == head) // insert before head
            {
                newNode->next = current;
                head->prev = newNode;
                head = newNode;
            }
            else if (current == nullptr) // insert after tail
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else // insert in middle 
            {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

};

class UnsortedDLL : public BaseDLL {
public:
    void insertNode(Employee employee) override {
        Node* newNode = new Node(employee);
        //If LL is empty
        if (head == nullptr) {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
};

class Stack : public UnsortedDLL {
public:
    void push(Employee employee) {
        Node* newNode = new Node(employee);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    Node pop() {
        if (head == nullptr) {
            cout << "Stack is empty..." << endl;
            return Node();
        }
        else {
            Node current = *head;
            Node* temp = head;
            if (head == tail) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            return current;
        }
    }
    Node peek() {
        if (head == nullptr) {
            cout << "Stack is empty..." << endl;
            return Node();
        }
        else {
            return *head;
        }
    }
};

class Queue : public UnsortedDLL{
public:
    void enque(Employee employee) {
        insertNode(employee);
        /*Node* newNode = new Node(employee);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }*/
    }
    Node deque() {
        if (head == nullptr) {
            cout << "Queue is empty..." << endl;
            return Node();
        }
        else {
            Node current = *head;
            Node* temp = head;
            if (head == tail) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            return current;
        }
    }
    Node peek() {
        if (head == nullptr) {
            cout << "Queue is empty..." << endl;
            return Node();
        }
        else {
            return *head;
        }
    }

};

int main() {
    //Unsorted List
    cout << "--------------------------" << endl;
    cout << "\tUnsortedDLL" << endl;
    cout << "--------------------------" << endl;
    UnsortedDLL unsortedList;
    unsortedList.insertNode(Employee(99, "First", 50, 9000));
    unsortedList.insertNode(Employee(10, "Second", 20, 2000));
    unsortedList.insertNode(Employee(55, "Third", 30, 3000));
    unsortedList.displayAll();
    UnsortedDLL unsortedList2;
    unsortedList2 = unsortedList;
    unsortedList2.displayAll();
    unsortedList[2];


    // Sorted List
    cout << "--------------------------" << endl;
    cout << "\tSortedDLL" << endl;
    cout << "--------------------------" << endl;
    SortedDLL sortedList;
    sortedList.insertNode(Employee(3, "First", 20, 1000));
    sortedList.insertNode(Employee(1, "Second", 30, 3000));
    sortedList.insertNode(Employee(2, "Third", 25, 2000));
    sortedList.displayAll();
    cout << endl;

    // Stack
    cout << "--------------------------" << endl;
    cout << "\tStack" << endl;
    cout << "--------------------------" << endl;
    Stack s;
    s.push(Employee(10, "Ziad", 30, 3000));
    s.push(Employee(20, "Mohamed", 25, 4000));
    s.push(Employee(30, "Khaled", 20, 5000)); 
    cout << s.peek().data.name << endl;
    cout << "Pop: " << s.pop().data.name << endl;
    cout << s.peek().data.name << endl;
    cout << endl;

    //Queue
    cout << "--------------------------" << endl;
    cout << "\tQueue" << endl;
    cout << "--------------------------" << endl;
    Queue q;
    q.enque(Employee(1, "Ahmed", 22, 1000));
    q.enque(Employee(2, "Ali", 23, 2000));
    cout << q.peek().data.name << endl;
    cout << "Dequeue: " << q.deque().data.name << endl;
    cout << q.peek().data.name << endl;
    cout << endl;

   

    return 0;
}