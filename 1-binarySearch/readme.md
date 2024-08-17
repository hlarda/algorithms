# Binary Search

## Table of Contents

- [Definition](#definition)

## What is Binary Search?

  Search a sorted array by repeatedly dividing the search interval in half untill the element is found or the interval is empty.

## Conditions to applay Binary Search

- Sorted data structure with constant time to access elements.

## Algorithm

- Divide to find the middle element.
- Compare the middle element with the target value.
  - If the target value is equal to the middle element, return the index of the middle element.
  - If not:
    - If the target value is less than the middle element, repeat the search on the left subarray.
    - If the target value is greater than the middle element, repeat the search on the right subarray.

## In C++, which data structures can be used to apply Binary Search (assuming constant-time access)?

Arrays and vectors can be used to apply binary search because they provide constant-time access to elements by index.

**Note:**

- `std::deque` also provides constant-time access, but binary search is not typically applied to deques because the elements might not be contiguous in memory, which can affect performance. For binary search, contiguous memory is important for efficient access.
- `std::map` provides logarithmic time complexity (O(log n)) for search operations, not constant time, due to its underlying balanced tree structure.
- `std::unordered_map` provides average constant-time complexity (O(1)) for access, but it does not support binary search because it stores elements in an unsorted manner.

## Im`plementation

1. [Iterative](./binary-search-iterative.cpp).
2. [Recursive](./binary-search-recursive.cpp).
