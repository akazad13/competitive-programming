# AVL Tree (Self-Balancing Binary Search Tree)

An **AVL Tree** (named after Adelson-Velsky and Landis) is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one.

---

## 1. Balance Factor & Height Invariant

For every node $u$ in an AVL tree:
$$\text{Balance Factor}(u) = \text{height}(u \to \text{left}) - \text{height}(u \to \text{right})$$
An AVL tree maintains the invariant:
$$\text{Balance Factor}(u) \in \{-1, \; 0, \; +1\}$$
If at any point after an insertion or deletion a node's balance factor becomes $\ge 2$ or $\le -2$, a **tree rotation** is performed to restore balance.

---

## 2. Tree Rotations

### Case 1: Left-Left (LL) Heavy $\implies$ Right Rotation
```
       z                                y
      / \                             /   \
     y   T4   -- Right Rotate(z) --> x     z
    / \                             / \   / \
   x   T3                          T1 T2 T3 T4
  / \
 T1  T2
```

### Case 2: Right-Right (RR) Heavy $\implies$ Left Rotation
```
     z                                y
    / \                             /   \
   T1  y      -- Left Rotate(z) --> z     x
      / \                          / \   / \
     T2  x                        T1 T2 T3 T4
        / \
       T3 T4
```

### Case 3: Left-Right (LR) Heavy $\implies$ Left Rotate Child, then Right Rotate Parent
- Left-rotate child $y$ (transforms into LL case).
- Right-rotate parent $z$.

### Case 4: Right-Left (RL) Heavy $\implies$ Right Rotate Child, then Left Rotate Parent
- Right-rotate child $y$ (transforms into RR case).
- Left-rotate parent $z$.

---

## 3. Order-Statistic Tree (`AVL-tree-to-find-nth-min/nth min.cpp`)

### Concept
An augmented AVL tree where each node maintains the count of elements in its left subtree (`l_count`) and right subtree (`r_count`).

### Finding the $K$-th Smallest Element
1. At node $u$, let $C = \text{size}(u \to \text{left}) + 1$.
2. If $K == C$: current node $u$ is the $K$-th minimum element!
3. If $K < C$: search in left subtree for the $K$-th element.
4. If $K > C$: search in right subtree for the $(K - C)$-th element.

- **Complexity:** $O(\log N)$ to find the $K$-th element, and $O(\log N)$ to insert/delete while updating counts.
- **Comparison:** C++ `std::set` does not support $O(\log N)$ order queries (its `std::advance` is $O(N)$). An Order-Statistic Tree (or GCC `pb_ds` tree) provides $O(\log N)$ rank and selection.
