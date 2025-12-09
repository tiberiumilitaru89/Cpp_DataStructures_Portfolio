# C++ Custom Linked List Implementation

### 🚀 Overview
This project demonstrates a manual implementation of a **Singly Linked List** in C++, focusing on efficient memory management and pointer logic.

Unlike standard library containers (`std::list`), this implementation is built from scratch to showcase low-level data structure manipulation, critical for embedded systems and performance-sensitive applications.

### 🛠️ Key Features
* **Manual Memory Management:** Explicit `new` and `delete` operations.
* **Leak Prevention:** A custom **Destructor (`~LinkedList`)** ensures all nodes are properly deallocated when the list goes out of scope, preventing memory leaks.
* **Safe Deletion:** The `deleteNode` function handles edge cases (like deleting the head) and safely rewires pointers before deletion to avoid Segmentation Faults.

### 💻 Code Snippet (Memory Cleanup)
```cpp
// The Destructor ensures no memory leaks occur
~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current; // Manual cleanup
        current = nextNode;
    }
}
