# 74. Search a 2D Matrix

## Problem Statement

Given an `m x n` integer matrix and an integer `target`, return `true` if `target` exists in the matrix, otherwise return `false`.

The matrix satisfies:

* Each row is sorted in increasing order.
* Each column is sorted in increasing order.

---

## Brute Force Approach

### Intuition

Traverse every element in the matrix and compare it with the target.

If any element matches the target, return `true`.

Otherwise, after checking all elements, return `false`.

### Algorithm

1. Traverse all rows.
2. Traverse all columns of each row.
3. Compare each element with the target.
4. Return `true` if found.
5. Return `false` after complete traversal.

### Time Complexity

* **O(N × M)**

### Space Complexity

* **O(1)**

### Code

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

---

## Optimal Approach (Staircase Search)

### Intuition

Since:

* Rows are sorted from left to right.
* Columns are sorted from top to bottom.

Start from the **top-right corner**.

At any position:

* If the current element equals the target → return `true`.
* If the current element is greater than the target → move left.
* If the current element is smaller than the target → move down.

This eliminates one row or one column in every step.

### Algorithm

1. Start at `(0, m-1)` (top-right corner).
2. While indices remain inside the matrix:

   * If current element equals target → return `true`.
   * If current element is greater than target → move left.
   * Otherwise → move down.
3. If traversal ends, return `false`.

### Dry Run

Matrix:

```text
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14   17
```

Target = `6`

```text
Start at 11
6 < 11 → move left

At 7
6 < 7 → move left

At 4
6 > 4 → move down

At 5
6 > 5 → move down

At 6
Target found
```

### Time Complexity

* **O(N + M)**

### Space Complexity

* **O(1)**

### Code

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = m - 1;

        while(i >= 0 && i < n && j >= 0 && j < m) {

            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return false;
    }
};
```

---

## Comparison

| Approach         | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Brute Force      | O(N × M)        | O(1)             |
| Staircase Search | O(N + M)        | O(1)             |

---

## Key Observation

Starting from the **top-right corner** gives two choices:

* Move **left** to decrease values.
* Move **down** to increase values.

This property allows us to eliminate one row or one column in every step, leading to an efficient **O(N + M)** solution.



*************_-----------------------------------------------------------------_****************************

## Interview Explanation

### 1. Understand the Matrix Properties

The matrix has two important properties:

* Each row is sorted in increasing order.
* Each column is sorted in increasing order.

Because of these properties, I can eliminate a row or a column at every step instead of checking every element.

---

### 2. Discuss the Brute Force Approach

A straightforward approach is to traverse every element in the matrix and compare it with the target.

* Time Complexity: **O(N × M)**
* Space Complexity: **O(1)**

Since the matrix is sorted, we should try to use that information to do better.

---

### 3. Derive the Optimal Approach

To utilize the sorted nature of the matrix, I start from the **top-right corner**.

At any position:

* All elements on the left are smaller.
* All elements below are larger.

This gives me enough information to eliminate part of the matrix after every comparison.

---

### 4. Explain the Decision Making

Suppose the current element is `matrix[i][j]`.

#### Case 1: Current element equals target

If `matrix[i][j] == target`, I've found the target and return `true`.

#### Case 2: Current element is greater than target

If `matrix[i][j] > target`, then everything below in that column will be even larger because columns are sorted.

Therefore, the target cannot exist in this column.

So I move left (`j--`).

#### Case 3: Current element is smaller than target

If `matrix[i][j] < target`, then everything to the left in that row will be smaller.

Therefore, the target cannot exist in this row.

So I move down (`i++`).

---

### 5. Explain Why It Works

In every comparison, I eliminate either one complete row or one complete column.

Therefore, I never revisit any cell, and the search space continuously shrinks.

---

### 6. Complexity Analysis

Each move either decreases the column index or increases the row index.

At most:

* N downward moves
* M left moves

Therefore:

* **Time Complexity:** O(N + M)
* **Space Complexity:** O(1)

---

## 30-Second Interview Answer

Since every row and column is sorted, I start from the top-right corner of the matrix.

If the current element is equal to the target, I return `true`.

If it is greater than the target, I move left because all elements below are even larger.

If it is smaller than the target, I move down because all elements on the left are smaller.

In each step, I eliminate one entire row or column, giving a time complexity of **O(N + M)** and a space complexity of **O(1)**.
