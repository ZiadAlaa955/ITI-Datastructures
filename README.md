# ITI Data Structures & Algorithms Repository

This repository contains the assignments and lab work for the **Data Structures & Algorithms** course at the **Information Technology Institute (ITI)**, Mobile App Cross-Platform Track (9-Month Program).

All implementations are written in **C++** with a focus on Object-Oriented Programming (OOP) principles and algorithmic efficiency.

## 📂 Repository Structure

The repository is organized by assignment to keep the codebase clean:

| Folder Name | Description | Key Concepts |
| :--- | :--- | :--- |
| **Assignment-01-Algorithms** | Basic sort & search algorithms | Selection, Bubble, Merge, Quick, and Heap Sort & Linear and Binary Search |
| **Assignment-02-LinkedList** | Advanced Doubly Linked List, Stack and Queue | Inheritance, Polymorphism, Stack (LIFO), Queue (FIFO), Sorted Insertion |

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
