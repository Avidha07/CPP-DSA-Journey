
# Set Matrix Zeroes - Brute Force Approach

## Intuition

Think of the matrix as a chessboard.  
If you see a `0` somewhere, you need to make its entire row and column zero.

The main challenge is:

If we immediately change elements to `0` while traversing, those newly created zeroes may incorrectly affect future operations and cause extra rows and columns to become zero.

To avoid this issue, we use a special marker value like `-1` (or any value that does not exist in the matrix).

Instead of directly placing `0`:
- mark affected cells as `-1`
- complete the traversal
- then convert all `-1` values into `0`

This prevents newly modified cells from interfering with the original matrix traversal.

---

# Algorithm

1. Traverse the entire matrix.
2. If a cell contains `0`:
   - Mark all non-zero elements in its row as `-1`
   - Mark all non-zero elements in its column as `-1`
3. After completing traversal:
   - Traverse the matrix again
   - Replace every `-1` with `0`

---

# Complexity Analysis

## Time Complexity
O(m × n × (m + n))

## Space Complexity
0(1)


*#############################################################################

# Set Matrix Zeroes - Better Approach

## Intuition

Instead of modifying the matrix immediately, we use two extra arrays:

- One array to track which rows should become zero
- One array to track which columns should become zero

Whenever we find a `0` in the matrix:
- mark its row index in the row array
- mark its column index in the column array

After the first traversal is complete, we make a second pass through the matrix.

If either:
- the row is marked
- OR the column is marked

then that cell must become `0`.

This approach avoids accidental over-zeroing because we never modify the matrix during the first traversal.

---

# Algorithm

1. Create:
   - a `row[]` array of size `m`
   - a `col[]` array of size `n`

2. Initialize all values as `false` or `0`.

3. First Pass:
   - Traverse the matrix
   - If `matrix[i][j] == 0`
     - mark `row[i]`
     - mark `col[j]`

4. Second Pass:
   - Traverse the matrix again
   - If:
     - `row[i]` is marked
     - OR
     - `col[j]` is marked
   - set `matrix[i][j] = 0`

---

# Complexity Analysis

## Time Complexity
Both traversals take:
O(m × n)
So total time complexity is:
O(m × n)

Space Complexity
O(m + n)

*##############################################################################*
# Set Matrix Zeroes - Optimal Approach

## Intuition

Instead of using separate arrays, we use the first row and first column of the matrix itself to store whether a row or column needs to be zeroed.

We also maintain two boolean flags:

- `firstRowZero`
  - Indicates whether the first row originally contained a zero.

- `firstColZero`
  - Indicates whether the first column originally contained a zero.

The idea is:

- Use the first row as a marker for columns.
- Use the first column as a marker for rows.

Whenever a zero is found in the matrix:
- mark its row in the first column
- mark its column in the first row

Later, these markers help determine which cells should become zero.

Finally, we separately handle:
- the first row
- the first column

using the stored boolean flags.

This approach is highly space-efficient because the matrix itself is reused for storing marker information.

---

# Algorithm

1. Check whether the first row contains any zero.
   - Store the result in `firstRowZero`.

2. Check whether the first column contains any zero.
   - Store the result in `firstColZero`.

3. Traverse the remaining matrix:
   - If a cell contains `0`
     - mark its row in the first column
     - mark its column in the first row

4. Traverse the matrix again (excluding first row and first column):
   - If either:
     - row marker is `0`
     - OR column marker is `0`
   - set the current cell to `0`

5. Finally:
   - zero out the first row if `firstRowZero` is true
   - zero out the first column if `firstColZero` is true

---

# Complexity Analysis

## Time Complexity
O(m × n)

## space complexity
O(1)
