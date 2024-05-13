# Chapter 4:  The Queue ADT

## 1.  ADT

## 2. Array list implementation of Queues

```C
Struct QueueRecord
{
    int Capacity; //Max size of queue
    int Front;
    int Size; //the current size of queue, distinguish full and empty
    int Rear;
    ElementType *Array;
};
```

Link head and tail:

```c
Rear = Rear % Capacity;
Front = Rear % Capacity;
```

tips:

```c
x % 2 == x & 1; // & is much faster than %
```

---

1. First put Front in 1, and put rear in 0
2. If you push a number into the queue, you can move the rear to the next step.

