# Sorting

## 1. Insertion Sort

+ change until we find the someone is smaller.
+ $T(N)=O(N^2)$
+ the best $T(N)=O(N)$

## 2. Bubble Sort

+ $T(N)=O(N^2)$ all the time.

## 3. Selection Sort

+ choose the minimum, from head to tail, if something is smaller, change the minimum.
+ $T(N)=O(N^2)$

## 4. Shell Short

```
Sort by 5, 3, 1.
```

+ $T(N)=O(N)$~$O(N^2)$
+ Improved by Insertion Sort
+ choose the number that is prime to avoid the worst case. like 2^k^ - 1

## 5. Heap Sort

+ $T(N)=O(NlogN)$

+ Find the top node, and maintain the heap.

## 6. Mergesort

+ Divide one to two lists

+ Merge two sorted lists.
  
  + use two pointer to merge two sorted lists. $T(N)=O(logN)$
  
  + functions: Msort, Merge $T(N)=O(NlogN)$

## 7. Quicksort

+ use two pointers

+ Search from left to right, aiming to find the right place of the chosen number.

+ **Possible improvement**: use patrition to divide the two arrays.

+ $T(N)=O(NlogN)$


