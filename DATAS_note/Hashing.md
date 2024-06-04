# Hashing

+ Interpolation Search

  if your aiming keyword is 75, then go to find 75% position.

## 1. General Idea

## 2. Hash Function

+ Easy to compute and minimizes the number of collisions.
+ usually used : $f(x)=x$% Table_size (Table_size is a prime)
+ $f(x)=(x[0]+x[1]*27+x[2]*27^2)$%Table_size

## 3. Separate Chaining

+ build an array first
+ check the list chain under the array[i]

```c
struct ListNode
typedef struct ListNode *Position
struct Hashtable
```

## 4. Opening Addressing

+ If the address is occupied, then check the next position.

## 5. Double Hashing

+ $f(i)=i*hash_2(x)$​
+ Hashing twice

## 6. Rehashing

+ Build another table that is about twice as big.
+ Use a new function to hash those elements into a new table.
