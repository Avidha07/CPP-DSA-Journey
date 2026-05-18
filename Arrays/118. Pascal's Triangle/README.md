# 118. Pascal's Triangle

## Problem Statement

Given an integer `numRows`, return the first `numRows` of **Pascal's Triangle**.

> In Pascal's triangle, each number is the **sum of the two numbers directly above it**.

**Example:**
```
numRows = 5

Output:
[
  [1],
  [1, 1],
  [1, 2, 1],
  [1, 3, 3, 1],
  [1, 4, 6, 4, 1]
]
```

---

## Algorithm (Simple Explanation for Interview)

```
1. Create an empty list called `triangle`.

2. Loop from row 0 to numRows - 1:
   a. Create a new row filled with 1s of size (i + 1).
      → First and last element of every row is always 1.

   b. For each inner element (index j from 1 to i-1):
      → row[j] = triangle[i-1][j-1] + triangle[i-1][j]
         (sum of the two elements directly above it)

   c. Push the row into triangle.

3. Return triangle.
```

**Key Insight:** Every row starts and ends with `1`. All inner values come from adding the two values above them in the previous row.

---

## Visual Walkthrough

```
Row 0:         [1]
Row 1:        [1, 1]
Row 2:       [1, 2, 1]         ← 2 = 1+1
Row 3:      [1, 3, 3, 1]       ← 3 = 1+2, 3 = 2+1
Row 4:     [1, 4, 6, 4, 1]     ← 4 = 1+3, 6 = 3+3, 4 = 3+1
```

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            // Initialize row with all 1s
            vector<int> row(i + 1, 1);

            // Fill inner elements
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

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | O(numRows²) — we fill each cell once |
| **Space** | O(numRows²) — to store the entire triangle |

---

## Interview Tips

- **Why initialize with 1s?** — It handles the edges automatically; we only need to update the interior.
- **Why inner loop starts at j=1 and ends at j<i?** — Index `0` and index `i` are always `1` (edges), so we skip them.
- **Edge case:** `numRows = 1` returns `[[1]]` — the loop handles this correctly since the inner loop never runs.

---

## Tags

`Array` · `Dynamic Programming` · `Simulation`  
**Difficulty:** Easy  
**LeetCode #:** 118
