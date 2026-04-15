# Lost and Found Object Tracker

## 1. Introduction

A Lost and Found Object Tracker is a system designed to manage items that are reported lost and items that are found within a campus. The system helps in storing item details and matching lost items with found ones efficiently.

## 2. Problem Breakdown

The problem is divided into the following sub-problems:

* Item Insertion (Lost and Found)
* Storage of items
* Searching items by category
* Matching lost and found items
* Assigning unique IDs to each item

## 3. Approaches

### Approach 1: Array-Based Storage

Items are stored in arrays of structures.

**Advantages:**

* Simple implementation
* Fast insertion (O(1))
* Easy to manage

**Disadvantages:**

* Fixed size
* Searching is slow (O(n))

### Approach 2: Hash Table

Items are stored using a hash key (ID or category).

**Advantages:**

* Fast search (O(1) average)
* Efficient matching

**Disadvantages:**

* Complex implementation
* Collision handling required

### Approach 3: Binary Search Tree (BST)

Items are stored in sorted order.

**Advantages:**

* Efficient searching (O(log n))
* Maintains order

**Disadvantages:**

* Complex implementation
* Needs balancing for best performance

## 4. Final Approach Used

The array-based approach is selected because:

* The number of items is limited
* It is easy to implement and debug
* Suitable for a prototype system

## 5. Algorithm

1. Start the program
2. Display menu options
3. Take user input
4. Perform operations:

   * Add lost item
   * Add found item
   * Search items
   * Match items
5. Repeat until user exits
6. End program

## 6. Complexity Analysis

| Operation      | Time Complexity |
| -------------- | --------------- |
| Add Lost Item  | O(1)            |
| Add Found Item | O(1)            |
| Search         | O(n)            |
| Matching       | O(n × m)        |
| Space          | O(n)            |

## 7. Sample Output

* Adding items
* Searching items
* Matching items
  (Attach screenshots here)

## 8. Conclusion

The Lost and Found Tracker successfully manages lost and found items using arrays. It allows users to add, search, and match items efficiently. While the current system is suitable for small datasets, future improvements can include using hash tables or databases for better performance and scalability.
