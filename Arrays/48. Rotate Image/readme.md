# Rotate Image (LeetCode 48)

## Problem Statement

Given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees clockwise**.

You must rotate the image **in-place**, which means you have to modify the input matrix directly without allocating another matrix.

### Example 1

**Input**

```text
1 2 3
4 5 6
7 8 9
```

**Output**

```text
7 4 1
8 5 2
9 6 3
```

---

### Example 2

**Input**

```text
5  1  9 11
2  4  8 10
13 3  6  7
15 14 12 16
```

**Output**

```text
15 13 2  5
14 3  4  1
12 6  8  9
16 7 10 11
```

---

# Approach 1: Using Extra Space

## Intuition

In a 90-degree clockwise rotation, each element moves to a new position.

For an element located at:

```text
(i, j)
```

its new position becomes:

```text
(j, n - i - 1)
```

where `n` is the size of the matrix.

---

## Visual Representation

### Original Matrix

```text
1 2 3
4 5 6
7 8 9
```

### Position Mapping

```text
matrix[0][0] = 1 → rotated[0][2]
matrix[0][1] = 2 → rotated[1][2]
matrix[0][2] = 3 → rotated[2][2]

matrix[1][0] = 4 → rotated[0][1]
matrix[1][1] = 5 → rotated[1][1]
matrix[1][2] = 6 → rotated[2][1]

matrix[2][0] = 7 → rotated[0][0]
matrix[2][1] = 8 → rotated[1][0]
matrix[2][2] = 9 → rotated[2][0]
```

### Rotated Matrix

```text
7 4 1
8 5 2
9 6 3
```

---

## Algorithm

1. Create a new matrix of size `n × n`.
2. Traverse each element of the original matrix.
3. Place each element at `(j, n - i - 1)` in the new matrix.
4. Copy the new matrix back into the original matrix.

---

## Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> rotated(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = rotated;
    }
};
```

### Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n²) |
| Space      | O(n²) |

---

# Approach 2: In-Place Rotation (Optimal)

## Intuition

Instead of creating another matrix, we can rotate the matrix in-place using two operations:

### Step 1: Transpose

Convert rows into columns.

### Step 2: Reverse Every Row

Reverse all rows to obtain the final rotated matrix.

---

## Why Does This Work?

### Original Matrix

```text
1 2 3
4 5 6
7 8 9
```

---

## Step 1: Transpose

Swap:

```text
matrix[i][j] ↔ matrix[j][i]
```

Result:

```text
1 4 7
2 5 8
3 6 9
```

### Visualization

```text
Before Transpose

1 2 3
4 5 6
7 8 9

After Transpose

1 4 7
2 5 8
3 6 9
```

---

## Step 2: Reverse Each Row

```text
1 4 7  →  7 4 1
2 5 8  →  8 5 2
3 6 9  →  9 6 3
```

Final Matrix:

```text
7 4 1
8 5 2
9 6 3
```

---

# Why Do We Use `j = i + 1`?

Transpose requires swapping:

```cpp
matrix[i][j]
matrix[j][i]
```

If we start from:

```cpp
j = 0
```

then the same pair gets swapped twice.

Example:

```cpp
swap(matrix[0][1], matrix[1][0]);
```

Later:

```cpp
swap(matrix[1][0], matrix[0][1]);
```

The second swap undoes the first swap.

---

## Matrix Regions

```text
D = Diagonal
X = Elements To Visit

D X X
- D X
- - D
```

We only process the **upper triangle**.

Thus:

```cpp
for(int j = i + 1; j < n; j++)
```

ensures:

* Each pair is swapped exactly once.
* No duplicate work.
* Diagonal elements are skipped.
* Better efficiency.

---

## Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n²) |
| Space      | O(1)  |

---

# Key Takeaways

* Brute Force uses an extra matrix and position mapping `(j, n - i - 1)`.
* Optimal solution uses:

  1. Transpose
  2. Reverse each row
* During transpose, start from `j = i + 1` to avoid duplicate swaps.
* Optimal solution achieves:

  * Time Complexity: `O(n²)`
  * Space Complexity: `O(1)`

---

## Tags

`Matrix` `Array` `Simulation` `In-Place Algorithm` `LeetCode 48`
