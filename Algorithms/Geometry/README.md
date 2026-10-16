# Computational Geometry Algorithms

Geometry problems in competitive programming require robust handling of floating-point precision, orientation primitives, and sweep-line paradigms.

---

## 1. 2D Cross Product & Orientation Primitive

### Mathematical Intuition
Given three points $P_1(x_1, y_1), P_2(x_2, y_2), P_3(x_3, y_3)$, construct two vectors $\vec{u} = \vec{P_1P_2}$ and $\vec{v} = \vec{P_1P_3}$.
The 2D cross product is:
$$\vec{u} \times \vec{v} = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)$$

- **Positive ($> 0$):** Counterclockwise turn ($\vec{v}$ lies to the left of $\vec{u}$).
- **Negative ($< 0$):** Clockwise turn ($\vec{v}$ lies to the right of $\vec{u}$).
- **Zero ($= 0$):** Collinear points ($P_1, P_2, P_3$ lie on the same straight line).

---

## 2. Line Segment Intersection (`2 line intersection check.cpp`)

### Problem
Determine whether line segment $S_1 = P_1Q_1$ and line segment $S_2 = P_2Q_2$ intersect.

### Decision Algorithm
1. Compute the four orientation triplets:
   - $o_1 = \text{orientation}(P_1, Q_1, P_2)$
   - $o_2 = \text{orientation}(P_1, Q_1, Q_2)$
   - $o_3 = \text{orientation}(P_2, Q_2, P_1)$
   - $o_4 = \text{orientation}(P_2, Q_2, Q_1)$

2. **General Intersection Case:**
   Segments intersect if $P_2$ and $Q_2$ lie on opposite sides of $P_1Q_1$, AND $P_1$ and $Q_1$ lie on opposite sides of $P_2Q_2$:
   $$(o_1 \ne o_2) \land (o_3 \ne o_4)$$

3. **Collinear Special Case (Bounding Box Check):**
   If any $o_i == 0$, check if the collinear endpoint lies inside the other segment's 1D projection bounding box:
   $$\min(x_1, x_2) \le x \le \max(x_1, x_2) \quad \land \quad \min(y_1, y_2) \le y \le \max(y_1, y_2)$$

### Complexity
- **Time Complexity:** $O(1)$ constant time arithmetic.
- **Space Complexity:** $O(1)$.

---

## 3. Polygon Area via Shoelace Formula (`areaofpoly.cpp`)

### Problem
Compute the planar area enclosed by an $N$-vertex polygon whose vertices are given in cyclic order $(x_0, y_0), (x_1, y_1), \dots, (x_{N-1}, y_{N-1})$.

### Formula
By Green's Theorem / triangulation from the origin:
$$\text{Area} = \frac{1}{2} \left| \sum_{i=0}^{N-1} (x_i y_{i+1} - x_{i+1} y_i) \right|$$
where $(x_N, y_N) = (x_0, y_0)$ wraps around.

- **Convex and Non-Convex:** Holds for **any** non-self-intersecting simple polygon.
- **Orientation:** If the sum is positive, vertices are ordered counter-clockwise; if negative, clockwise.
- **Complexity:** $O(N)$ time, $O(1)$ auxiliary space.

---

## 4. Closest Pair of Points via Sweep-Line (`line swipping closest point.cpp`)

### Problem
Given $N$ points in a 2D plane, find the minimum Euclidean distance $d$ between any pair of points.

### Sweep-Line Mechanism
1. **Sort Points by X-coordinate:** Process points from left to right.
2. Maintain:
   - $d$: current minimum distance found so far (initialized to $\infty$).
   - An active set of points (within horizontal strip $[x_i - d, x_i]$) ordered by **Y-coordinate** in a balanced BST (`std::set`).
3. For each incoming point $P_i(x_i, y_i)$:
   - **Prune Left:** Remove any points from the active set whose $x$-coordinate is $< x_i - d$.
   - **Query Range:** In the active set, search only for points whose $y$-coordinate falls in $[y_i - d, y_i + d]$ using `std::set::lower_bound`.
   - **Sparsity Bound:** Geometrically, at most 6 points can fit in a $d \times 2d$ bounding box without any pair being closer than $d$. Thus, the inner loop runs at most $O(1)$ times!
   - Update $d = \min(d, \text{dist}(P_i, P_j))$ for tested points.
   - Insert $P_i$ into the active set.

### Complexity
- **Time Complexity:** $O(N \log N)$ (sorting takes $O(N \log N)$; each point is inserted and erased from the BST once in $O(\log N)$).
- **Space Complexity:** $O(N)$ for the active set.
