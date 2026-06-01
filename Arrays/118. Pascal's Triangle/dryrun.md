# Pascal's Triangle — LeetCode #118

> **Difficulty:** Easy &nbsp;|&nbsp; **Topic:** Array, Dynamic Programming

---

## Problem Statement

Given an integer `numRows`, return the first `numRows` of **Pascal's Triangle**.

In Pascal's Triangle, each number is the sum of the two numbers directly above it.

```
Input:  numRows = 4
Output: [[1],[1,1],[1,2,1],[1,3,3,1]]
```

```
    [1]
   [1,1]
  [1,2,1]
 [1,3,3,1]
```

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            // Create a row of size (i+1), all filled with 1
            vector<int> row(i + 1, 1);

            // Fill in the middle elements (skip first and last — they stay 1)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
```

---

## Line-by-Line Explanation

| Line | Code | What it does |
|------|------|--------------|
| 1 | `vector<vector<int>> triangle;` | Declare an empty 2D vector to store all rows. |
| 2 | `for (int i = 0; i < numRows; i++)` | Iterate over each row index `i` (0-based). |
| 3 | `vector<int> row(i + 1, 1);` | Create a row of size `i+1`, every element initialised to `1`. Covers the left and right edges automatically. |
| 4 | `for (int j = 1; j < i; j++)` | Iterate only over the **interior** indices (skip first and last, which are always 1). |
| 5 | `row[j] = triangle[i-1][j-1] + triangle[i-1][j];` | Set each interior element to the sum of the two elements directly above it from the previous row. |
| 6 | `triangle.push_back(row);` | Append the completed row to the triangle. |
| 7 | `return triangle;` | Return the full Pascal's Triangle. |

---

## Dry Run — numRows = 4

### i = 0 (Row 0)
- `row = [1]` (size 1, all 1s)
- Inner loop: `j < 0` → **skipped**
- `triangle = [[1]]`

### i = 1 (Row 1)
- `row = [1, 1]` (size 2, all 1s)
- Inner loop: `j < 1` → **skipped**
- `triangle = [[1], [1,1]]`

### i = 2 (Row 2)
- `row = [1, 1, 1]` (size 3, all 1s)
- Inner loop: `j = 1` only
  - `row[1] = triangle[1][0] + triangle[1][1] = 1 + 1 = 2`
- `row = [1, 2, 1]`
- `triangle = [[1], [1,1], [1,2,1]]`

### i = 3 (Row 3)
- `row = [1, 1, 1, 1]` (size 4, all 1s)
- Inner loop: `j = 1, 2`
  - `j=1`: `row[1] = triangle[2][0] + triangle[2][1] = 1 + 2 = 3`
  - `j=2`: `row[2] = triangle[2][1] + triangle[2][2] = 2 + 1 = 3`
- `row = [1, 3, 3, 1]`
- `triangle = [[1], [1,1], [1,2,1], [1,3,3,1]]`

---

## Key Observations

1. **Edges are always 1** — handled by initialising the entire row with `1`.
2. **Inner loop starts at j=1 and ends at j<i** — this skips the first and last elements intentionally.
3. **Always read from `triangle[i-1]`**, never from `row` itself — this ensures we use the completed previous row.
4. **No extra space trick** — each row is built fresh from scratch using the previous row.

---

## Complexity Analysis

| | Complexity | Explanation |
|--|--|--|
| **Time** | O(n²) | Each of the `n` rows has up to `n` elements to compute. |
| **Space** | O(n²) | The output itself stores all `n` rows totalling `n(n+1)/2` elements. |

---

## Example Output

```
numRows = 5

[1]
[1, 1]
[1, 2, 1]
[1, 3, 3, 1]
[1, 4, 6, 4, 1]
```

---

## Related Problems

- [LeetCode 119 — Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) (return only the k-th row using O(k) space)

---

## Tags

`Array` `Dynamic Programming` `Simulation`
