# Assignment 03: Arrays & Algorithm Analysis
**Data Structures and Algorithms (TKU211231)**

---

## Student Information

- **Name:** Zahwa Agroli
- **Student ID:** 24/535089/TK/59335

---

## Solutions Description

- **problem2.cpp (DynArray):** Implements a procedural resizable array using a plain `struct DynArray` with 8 free functions (`initArray`, `freeArray`, `pushBack`, `insertAt`, `removeAt`, `getAt`, `setAt`, `printDynArr`). Initial capacity = 2, doubles automatically when full. Each function is annotated with its time complexity.
- **problem3.cpp (Linear & Binary Search):** Implements `linearSearch`, iterative `binarySearch`, and `generateSortedArray` which produces `{0, 2, 4, ..., 2(n-1)}`. Tested on n = 10, 100, 1000 for both existing and non-existing targets, with both algorithms confirmed to return matching results.
- **Analysis.pdf (Written Analysis):** Contains Problem 1 Snippet A, B, and C (step-by-step T(n) derivation, Big-O classification, and best/worst case analysis for each snippet), Problem 3B (complexity comparison table and proof that minimum n = 3), and Problem 4 (12-call amortized trace, geometric series derivation for doubling vs arithmetic series for fixed-increment).

---

## Compilation Commands

```bash
# Problem 2
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem2.cpp -o problem2

# Problem 3
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem3.cpp -o problem3
```

---

## Known Issues & Limitations

- `insertAt` and `removeAt` do not perform bounds checking, passing an out-of-range index results in undefined behavior (as permitted by the assignment constraints).
- `generateSortedArray` returns a heap-allocated pointer, the caller is responsible for calling `delete[]` to avoid memory leaks.
- `binarySearch` does not validate whether the input array is sorted, passing an unsorted array produces unpredictable results.

---

## Time Spent

**Total: 12 hours**
