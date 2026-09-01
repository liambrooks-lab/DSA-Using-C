# DSA Using C

A structured collection of **Data Structures and Algorithms implemented in C**, created for academic practice, problem-solving, and building a strong foundation in core computer science concepts.

The repository contains **20 implementations** covering fundamental searching, sorting, linear data structures, trees, and graph algorithms. Each implementation is written in standard C with a focus on readable logic, conventional naming, and practical understanding of the underlying algorithms.

---

## Table of Contents

* [Topics Covered](#topics-covered)
* [Repository Structure](#repository-structure)
* [Compilation and Execution](#compilation-and-execution)
* [Complexity Reference](#complexity-reference)
* [Requirements](#requirements)
* [Contributing](#contributing)
* [Author](#author)
* [License](#license)

---

## Topics Covered

### Arrays

Basic operations and searching techniques using one-dimensional and two-dimensional arrays.

**Includes:**

* 1D and 2D array operations
* Linear search
* Binary search

### Sorting

Implementation of commonly used comparison and non-comparison sorting algorithms.

**Includes:**

* Bubble sort
* Insertion sort
* Selection sort
* Merge sort
* Quick sort
* Radix sort

### Stacks and Queues

Implementations of fundamental linear data structures using arrays.

**Includes:**

* Stack operations
* Linear queue
* Circular queue

### Linked Lists

Dynamic data structures demonstrating node creation, traversal, and pointer manipulation.

**Includes:**

* Singly linked list
* Doubly linked list
* Circular linked list

### Trees

Basic tree construction and traversal techniques.

**Includes:**

* Tree data structure
* Tree traversal
* Inorder, preorder, and postorder traversal

### Graphs

Fundamental graph representation and traversal techniques.

**Includes:**

* Adjacency matrix
* Breadth-First Search (BFS)
* Depth-First Search (DFS)

---

## Repository Structure

```text
DSA-Using-C/
│
├── arrays/
│   ├── array_operations_1d_2d.c
│   ├── linear_search.c
│   └── binary_search.c
│
├── sorting/
│   ├── bubble_sort.c
│   ├── insertion_sort.c
│   ├── selection_sort.c
│   ├── merge_sort.c
│   ├── quick_sort.c
│   └── radix_sort.c
│
├── stacks_and_queues/
│   ├── stack_operations.c
│   ├── linear_queue.c
│   └── circular_queue.c
│
├── linked_lists/
│   ├── singly_linked_list.c
│   ├── doubly_linked_list.c
│   └── circular_linked_list.c
│
├── trees/
│   ├── tree_data_structure.c
│   └── tree_traversal.c
│
├── graphs/
│   ├── adjacency_matrix.c
│   ├── bfs_graph_traversal.c
│   └── dfs_graph_traversal.c
│
├── LICENSE
└── README.md
```

---

## Compilation and Execution

Each program can be compiled independently with GCC or Clang.

### Example

```bash
cd sorting
gcc quick_sort.c -o quick_sort
./quick_sort
```

On Windows PowerShell:

```powershell
cd sorting
gcc .\quick_sort.c -o quick_sort.exe
.\quick_sort.exe
```

You can replace `quick_sort.c` with any other source file in the repository.

For stricter compilation and better warning detection:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic quick_sort.c -o quick_sort
```

---

## Complexity Reference

| Algorithm      |       Best |    Average |      Worst |
| -------------- | ---------: | ---------: | ---------: |
| Bubble Sort    |       O(n) |      O(n²) |      O(n²) |
| Insertion Sort |       O(n) |      O(n²) |      O(n²) |
| Selection Sort |      O(n²) |      O(n²) |      O(n²) |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort     | O(n log n) | O(n log n) |      O(n²) |
| Radix Sort     |      O(nk) |      O(nk) |      O(nk) |
| Linear Search  |       O(1) |       O(n) |       O(n) |
| Binary Search  |       O(1) |   O(log n) |   O(log n) |
| BFS            |   O(V + E) |   O(V + E) |   O(V + E) |
| DFS            |   O(V + E) |   O(V + E) |   O(V + E) |

The exact memory requirements vary by implementation and data structure.

---

## Requirements

* **C compiler:** GCC or Clang
* **C standard:** C11 recommended
* **Supported environments:** Windows, Linux, and macOS
* **Shell:** PowerShell, CMD, Bash, or Zsh

No external libraries are required.

---

## Contributing

Contributions, corrections, optimisations, and additional DSA implementations are welcome.

For changes:

```bash
git checkout -b feature/your-feature
git add .
git commit -m "feat: improve quick sort implementation"
git push origin feature/your-feature
```

Then open a Pull Request with a clear description of the changes.

---

## Author

**Rudranarayan Jena**

Founder & Lead Researcher, **Voxion Labs**

GitHub: [liambrooks-lab](https://github.com/liambrooks-lab)

---

## License

This project is licensed under the **MIT License**.

See [LICENSE](LICENSE) for the full license text.
