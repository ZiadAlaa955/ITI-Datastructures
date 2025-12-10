#include <iostream>
#include <vector>
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
	Employee employee;
	Node* left;
	Node* right;

    Node() :  left(nullptr), right(nullptr) {}
    Node(Employee e) : employee(e), left(nullptr), right(nullptr) {}
};

class BST {
	Node* root;
	
    void insertNodeHelper(Node*& root, Employee e) {
        Node* newNode = new Node(e);
        if (root == nullptr) //first node
        {
            root = newNode;
        }
        else if (newNode->employee.id < root->employee.id) //add node less than root id
        {
            insertNodeHelper(root->left, newNode->employee);
        }
        else if (newNode->employee.id > root->employee.id) {
            insertNodeHelper(root->right, newNode->employee);
        }
        else {
            cout << "Ignored dunplicate id..." << endl;
        }
    }

    void traverseHelper(Node* root) {
        if (root != nullptr) {
            traverseHelper(root->left);
            cout << "Name: " << root->employee.name << endl;
            cout << "ID: " << root->employee.id << endl;
            cout << "Age: " << root->employee.age << endl;
            cout << "Salary: " << root->employee.salary << endl;
            cout << "-------------------" << endl;
            traverseHelper(root->right);
        }
    }

    void removeNodeHelper(Node*& root, int id) {
        if (root == nullptr) // id not found
        {
            cout << "Employee not found..." << endl;
            return;
        }
        else // id found
        {
            //search for node id
            if (id < root->employee.id) removeNodeHelper(root->left, id);
            else if (id > root->employee.id) removeNodeHelper(root->right, id);
            // after search
            else
            {
                // has one or no nodes
                if (root->left == nullptr) 
                {
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if (root->right == nullptr) 
                {
                    Node* temp = root;
                    root = root->left;
                    delete temp;
                }
                else // has 2 children
                {
                    //find max
                    Node* maxNode = root->left; 
                    while (maxNode->right != nullptr) 
                    {
                        maxNode = maxNode->right;
                    }
                    //swap 
                    root->employee = maxNode->employee;
                    //delete 
                    removeNodeHelper(root->left, maxNode->employee.id);
                }
            }
        }
    }

    int countLevelsHelper(Node* root) {
        if (root == nullptr)return -1; //empty tree
        else 
        {
            int leftLevels = countLevelsHelper(root->left);
            int rightLevels = countLevelsHelper(root->right);
            return 1 + max(leftLevels, rightLevels);
        }
    }

    int countNodesHelper(Node* root) {
        return countNodesHelper(root->left) + 1 + countNodesHelper(root->right);
    }
public:
    BST() :root(nullptr) {}
    
    void insertNode(Employee e) {
        insertNodeHelper(root, e);
    }
    
    void traverse() {
        cout << "----------Employees Data------------" << endl;
        traverseHelper(root);
    }

    int countNodes() {
        return countNodesHelper(root);
    }

    int countLevels() {
        return countLevelsHelper(root);
    }

    void removeNode(int id) {
        removeNodeHelper(root, id);
    }

    //------------Balancing tree-----------
    //1- Store Nodes data in vector
    void storeNodesInOrder(Node* root, vector<Employee>& nodes) {
        if (root == nullptr) return;
        else {
            storeNodesInOrder(root->left, nodes);
            nodes.push_back(root->employee);
            storeNodesInOrder(root->right, nodes);
        }
    }
    //2- destroy old tree
    void destroyTree(Node* root) {
        if (root == nullptr) return;
        else {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }
    //3- build balanced tree
    Node* buildBalancedTree(vector<Employee>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node* newNode = new Node(nodes[mid]);
        newNode->left = buildBalancedTree(nodes, start, mid - 1);
        newNode->right = buildBalancedTree(nodes, mid + 1, end);
        return newNode;
    }
    void balanceTree() {
        if (root == nullptr) {
            cout << "Tree is empty..." << endl;
            return;
        }
        else {
            vector<Employee> nodes;
            storeNodesInOrder(root, nodes);
            
            destroyTree(root);

            root = buildBalancedTree(nodes, 0, nodes.size() - 1);
        }
    }

};

int main()
{
    BST tree;

    tree.insertNode(Employee(1, "Ziad", 20, 1000));
    tree.insertNode(Employee(2, "Ahmed", 20, 1000));
    tree.insertNode(Employee(3, "Mohamed", 20, 1000));
    tree.insertNode(Employee(4, "Ali", 20, 1000));
    tree.insertNode(Employee(5, "Omar", 20, 1000));

    cout << "Levels Before Balancing: " << tree.countLevels() << endl;
    tree.traverse();

    tree.balanceTree();
    cout << "Levels After Balancing: " << tree.countLevels() << endl;
    tree.traverse();

    cout << "\nRemoving ID 3 (Root)..." << endl;
    tree.removeNode(3);
    tree.traverse();
}

/* 
Delete Node:
- leaf
- node with one chile => the child take place its parent
- node with 2 children => find max node in left subtreee + copy its data to current node + delete max node from left subtree
*/