# Chapter 3:  The Stack ADT

 ## 1. ADT

Last In First Out (LIFO), the insertions and deletions are made at the top only.

recursive function is kind of stack.

### operations : (important)

| Pop  | Push | Top  |
| :--: | :--: | :--: |



## 2. Implementations

+ Linked List Implementation (with a header node)

```c
Push:
TmpCell->Next = S->Next
S->Next = TmpCell
```

```c
Top:
return S->Next->Element
```

```c
Pop:
FirstCell = S->Next
S->Next = S->Next->Next
free (FirstCell)
```

## 3. Applications

+ Balancing Symbols:

> when opening symbol push
>
> when closing symbol pop

+ Postfix Evaluation:

>An infix expression: a + b * c - d / c
>
>An prefix expression: - + a * b c / d e
>
>An postfix expression: a b c * + d e / -

+ Function Calls(System Stack) :

>
>
>

## 4. Infix to Postfix Conversion

>Precedence: “Not in the stack” ( > * > + > (  “in the stack”
>
>Never pop a ( from the the stack except when processing a ).