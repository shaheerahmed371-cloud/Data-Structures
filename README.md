# Data Structures Implementation (C++)
### Capital University of Science and Technology (CUST) - Fall 2025/Spring 2026

This repository contains my personal implementations of fundamental data structures using C++. The focus of these lab tasks was to understand memory management, pointer manipulation, and the efficiency of various algorithms.

## 📁 Repository Structure
Each folder contains the source code (`.cpp`) and potentially a header file (`.h`) for the following implementations:

* **Linked Lists**: Singly, Doubly, and Circular Linked Lists focusing on dynamic memory allocation.
* **Stacks & Queues**: Implementations using both Arrays (static) and Linked Lists (dynamic).
* **Trees**: Binary Search Trees (BST) with recursive traversal methods (In-order, Pre-order, Post-order).
* **Heaps**: Max-Heap and Min-Heap implementations for priority queues.
* **Graphs**: Representation using Adjacency Lists and Adjacency Matrices.

## 🛠️ Concepts Covered
* **Pointers & References**: Extensive use of `*` and `&` for efficient data handling.
* **Classes & OOP**: Encapsulating data structures within classes to ensure abstraction.
* **Templates**: Using `template <typename T>` to make structures generic.
* **Memory Management**: Proper use of `new` and `delete` to prevent memory leaks.

## 📊 Time Complexity Reference

| Data Structure | Access | Search | Insertion | Deletion |
| :--- | :--- | :--- | :--- | :--- |
| **Array** | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Linked List** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ |
| **Stack/Queue** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ |
| **BST (Avg)** | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ |

## 🚀 How to Run
To compile any of the files, use a C++ compiler like `g++`:
```bash
g++ filename.cpp -o output
./output
