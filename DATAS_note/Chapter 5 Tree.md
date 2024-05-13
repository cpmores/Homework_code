# Chapter 5: Tree

## 1. Definition: 

Some truth:12

```
Subtrees must not connect together.
A distinguished node r, called the root.
There are N-1 edges in a tree with N nodes.
```

---

Degree of a node := number of subtrees of the node.

Degree of a tree := max {degree(node)}.

siblings := children of the same parent.

Depths of n: From the root, Depth(root) = 0

Height of n: From deepest leave, Height(Leave) = 0

## 2. Implementation

+ FirstChild-NextSibling Representation

​	Element: 1. Firstchild ; 2. Other Siblings

 ## 3. Binary Trees

#### Tree Traversals

+ pre_order

```c
if (tree)
{
    visit (tree);
    for (each child c of tree)
        preorder (c);
}
```

+ post_order

```c
if (tree)
{
    for (each child c of tree)
        postorder (c);
    visit (tree);
}
```

+ Level_order

```C
enqueue (tree);
for (queue is not empty)
    T = dequeue();
enqueue (the child of T)
```

---

```
inorder traversal: left, middle, right
postorder traversal: left, right, middle
preorder traversal: middle, left, right
```

#### Threaded Binary Tree

minimize the space you don’t need to use.