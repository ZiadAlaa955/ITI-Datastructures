# ITI Data Structures & Algorithms Repository

This repository contains the assignments and lab work for the **Data Structures & Algorithms** course at the **Information Technology Institute (ITI)**, Mobile App Cross-Platform Track (9-Month Program).

All implementations are written in **C++** with a focus on Object-Oriented Programming (OOP) principles and algorithmic efficiency.

## 📂 Repository Structure

The repository is organized by assignment to keep the codebase clean:

| Folder Name | Description | Key Concepts |
| :--- | :--- | :--- |
| **Assignment-01-Algorithms** | Basic sort & search algorithms | Selection, Bubble, Merge, Quick, and Heap Sort & Linear and Binary Search |
| **Assignment-02-LinkedList** | Advanced Doubly Linked List, Stack and Queue | Inheritance, Polymorphism, Stack (LIFO), Queue (FIFO), Sorted Insertion |
| **Assignment-03-BST** |Binary Search Tree (BST) | Recursion, Tree Balancing, In-Order Predecessor, Traversal (In/Pre/Post), Tree Height |
| **Assignment-04-vector&heap** |Dynamic Array (Vector) & Priority Queue (Binary Heap) | Templates, Dynamic Memory, Amortized Analysis, Percolate Up/Down, Sentinel Values |

---

## 🚀 Assignments Detail

### Assignment 1: Sorting & Searching Algorithms
* **Objective:** Implement and analyze fundamental algorithms for data organization and retrieval.
* **Algorithms Implemented:**
    * **Sorting:** Selection Sort, Bubble Sort, Merge Sort, Quick Sort, and Heap Sort.
    * **Searching:** Linear Search and Binary Search.
* **Focus:** Understanding time complexity (Big O) and the logic behind divide-and-conquer vs. iterative approaches.

### Assignment 2: Generalized Linked List System
* **Objective:** Implement a flexible Doubly Linked List (DLL) that supports different behaviors using **Inheritance** and **Polymorphism**.
* **Architecture:**
    * `BaseDLL`: Abstract base class handling common logic (Search, Delete, Display).
    * `SortedDLL`: Auto-sorts employees by ID upon insertion.
    * `UnsortedDLL`: Appends employees based on insertion order.
    * `Stack`: Inherits from UnsortedDLL to implement **LIFO** (Push/Pop).
    * `Queue`: Inherits from UnsortedDLL to implement **FIFO** (Enqueue/Dequeue).
 
### Assignment 3: Binary Search Tree (BST) System
* **Objective:** Implement a recursive Binary Search Tree to manage Employee records, focusing on efficient data retrieval and tree balancing algorithms.
* **Architecture & Key Features:**
* Node Structure: Each node encapsulates an Employee object (ID, Name, Age, Salary) and pointers to left/right children.
* **Core Operations:**
* `Insertion:` Recursive placement of nodes based on Employee ID.
* `Deletion:` robust handling of all three removal cases (Leaf node, Single child, and Two children using In-Order Predecessor replacement).
* `Traversal:` In-Order traversal to display employees sorted by ID.
* `Tree Balancing:` Implemented a balanceTree() algorithm that converts the skewed BST into a sorted std::vector and rebuilds a perfectly balanced tree using a divide-and-conquer approach (minimizing tree height for optimal search time).
* `Metrics:` Recursive functions to calculate countNodes() and countLevels() (Tree Height).

### Assignment 4: Dynamic Array & Binary Heap
* **Objective:** Build robust, templated data structures from scratch to understand memory management and tree-based priority queues.
* **Architecture:**
* `DynamicArray`: A resizable vector class handling generic types (T).
* `Memory Management`: Implements the "Big Three" (Destructor, Copy Constructor, Assignment Operator) to ensure safe deep copying.
* `Operations`: Supports push_back, pop_back, insertAt, removeAt, and dynamic resizing (Amortized O(1)).
* `BinaryHeap`: An array-based implementation of a Min-Heap.
* `Structure`: Uses 1-based indexing with a Sentinel value at index 0 to simplify parent/child calculations.
* `Core Logic`: Efficient insert (percolate up) and deleteMin (percolate down) operations to maintain heap order.

---

## 🛠️ Tools & Technologies
* **Language:** C++ 
* **IDE:** Visual Studio 2019
* **Version Control:** Git & GitHub

## 🏃‍♂️ How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/YOUR_USERNAME/ITI-DataStructures.git](https://github.com/YOUR_USERNAME/ITI-DataStructures.git)
    ```
2.  Open the main folder in **Visual Studio 2019**.
3.  Select the specific assignment folder you wish to run.
4.  Build and Run (`Ctrl + F5`).

---
*Created by [Your Name] - ITI Intake 45*
