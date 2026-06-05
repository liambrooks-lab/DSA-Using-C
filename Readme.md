# DSA Using C

Welcome to the ultimate repository for Data Structures and Algorithms implemented natively in C. This repository contains **20 robust, production-grade, and intermediate-level programs** structured to match academic laboratory curriculum with industry-standard code design.

---

## Table of Contents

- [Key Architectural Features](#key-architectural-features)
- [Repository Blueprint](#repository-blueprint)
- [Execution & Compilation Guide](#execution--compilation-guide)
- [Contribution & Development Lifecycle](#contribution--development-lifecycle)
- [Author](#author)
- [License](#license)

---

## 🛠️ Key Architectural Features

* **Dynamic Memory Management:** Deep integration of `malloc()` and pointer references across linked lists and trees.
* **Optimized Execution Paths:** Includes logic improvements, such as early-termination flags in sorting algorithms to reduce execution overhead.
* **Modular Codebase:** Clean separation of business logic with descriptive naming conventions and minimal reliance on hardcoded limits.

---

## 📁 Repository Blueprint

Here is how the data structures are organized across the subsystem pipelines:

```text
DSA-Using-C/
├── sorting/
│   ├── Bubble Sort.c
│   ├── Insertion Sort.c
│   ├── Selection Sort.c
│   ├── Merge Sort.c
│   ├── Quick Sort.c
│   └── Radix Sort.c
├── stack and queue/
│   ├── Stack Operations.c
│   ├── Linear Queue.c
│   └── Circular Queue.c
├── linked list/
│   ├── Single Linked List.c
│   ├── Double Linked List.c
│   └── Circular Linked List.c
├── trees/
│   ├── Tree Data Structure.c
│   └── Tree Traversal.c
├── graphs/
│   ├── Adjacency Matrix.c
│   ├── DFS Graph Traversal.c
│   └── BFS Graph Traversal.c
└── Core Arrays/
    ├── 1D and 2D Array Operations.c
    ├── Linear Search.c
    └── Binary Search.c
```

---

## Execution & Compilation Guide

To compile and execute any module locally, ensure you have a standard C compiler (gcc or clang) mapped to your system environment paths.

```bash
# 1. Navigate to the specific subsystem directory
cd "sorting"

# 2. Compile the target codebase using GCC
gcc "Quick Sort.c" -o quick_sort_runtime

# 3. Fire up the compiled binary framework
./quick_sort_runtime
```

---

## 🛠️ Contribution & Development Lifecycle

Got an optimization patch for the Graph structures or a faster pivot strategy for Quick Sort? Contributions are always welcome!

1. Fork the repository pipelines.
2. Create your feature tracking branch (git checkout -b feature/OptimizedDS).
3. Commit your analytical code blocks (git commit -m 'feat: optimize tree node allocation').
4. Push directly to the remote origin (git push origin feature/OptimizedDS).
5. Open a formal Pull Request for architectural review.

---

## 👤 Author

- Name: Rudranarayan Jena
- Role: Systems Architect & Lead Full-Stack Engineer
- Organization: Founder @ Voxion-Labs
- GitHub: @liambrooks-lab

---

## 📜 License
This repository is configured under the standard MIT License. Feel free to fork it, break it, modify it, or use it to ace your lab examinations!