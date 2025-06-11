<!-- ===================================================== -->
<!--   ⚡️  Data-Structures & Algorithms | Version 1.0     -->
<!-- ===================================================== -->

# 📚 Data-Structures & Algorithms in Modern C++

> A hands-on playground of classic data structures & algorithms,  
> coded **from scratch** in **C++17** for maximum learning impact.

---

## 🗂️ File Index

| File | What it Shows |
|------|---------------|
| **BST.cpp** | Binary Search Tree (insert, search, delete, traversals) |
| **Binary_tree.cpp** | Generic binary-tree traversal templates |
| **LinkedList.cpp** | Singly linked list (push, insert, delete) |
| **Priority_Queues.cpp** | Array-based priority queue (O(n) insert / O(1) remove-max) |
| **QueueArrayV1.cpp** | Queue with **one pointer** (rear) — simplest, but shifts elements |
| **QueueArrayV2.cpp** | Queue with **two pointers** (front & rear) — no shifting, faster |
| **QueueArrayV3.cpp** | **Circular queue** using array (front & rear wrap-around) |
| **QueueLinkedList.cpp** | Queue implemented with a linked list |
| **bigInteger.cpp** | Arbitrary-precision integer (+, −, ×, ÷) |
| **circular_linked_list.cpp** | Circular singly linked list |
| **doubly_linked_list.cpp** | Doubly linked list |
| **heap.cpp** | Min/Max binary heap (array representation) |
| **infix_to_postfix.cpp** | Shunting-Yard algorithm (infix → postfix) |
| **infix_to_postfix_solve_expression.cpp** | Postfix evaluation for arithmetic expressions |
| **stack_based_array.cpp** | Stack using dynamic array |
| **stack_based_linkedList.cpp** | Stack using linked list |

*(The repo also contains this README)*

---

## 💡 Queue Showcase

We explored **three array-based designs**—plus a linked-list variant—to highlight trade-offs:

| Version | Pointer(s) Used | Space Efficiency | `enqueue` | `dequeue` | Note |
|---------|-----------------|------------------|-----------|-----------|------|
| **V1** `QueueArrayV1.cpp` | 1 → `rear` | 🟥 Low (shifts elements) | O(1) | O(n) | Easiest to grasp |
| **V2** `QueueArrayV2.cpp` | 2 → `front`, `rear` | 🟨 Good | O(1) | O(1) | Classic linear queue |
| **V3** `QueueArrayV3.cpp` | 2 (circular) | 🟩 Excellent | O(1) | O(1) | No wasted slots |
| **Linked** `QueueLinkedList.cpp` | Pointers in nodes | 🟩 Dynamic | O(1) | O(1) | Grows/shrinks freely |

---

## 🔥 Highlights

- **Zero STL for core logic** → every pointer & index is managed manually.
- **Rich comments** explaining *why*, not just *how*.
- **Self-contained files** — compile only what you want to test.
- Perfect for university assignments, interviews, or brushing up fundamentals.

---

## 🛠️ Build & Run

```bash
# Compile any module
g++ -std=c++17 -O2 QueueArrayV3.cpp -o circular_queue
./circular_queue

# (Add a Makefile later for one-liner builds)
