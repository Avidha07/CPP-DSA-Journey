# 15. 3Sum

## Problem Statement

Given an integer array `nums`, return all the unique triplets `[nums[i], nums[j], nums[k]]` such that:

* `i != j`
* `i != k`
* `j != k`
* `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

### Example

**Input:**

```cpp
nums = [-1,0,1,2,-1,-4]
```

**Output:**

```cpp
[[-1,-1,2],[-1,0,1]]
```

---

# Approach 1: Brute Force

## Idea

Generate every possible triplet using three nested loops.

For each triplet:

1. Calculate the sum.
2. If the sum equals `0`, store the triplet.
3. Sort the triplet before storing it.
4. Use a set to remove duplicate triplets automatically.

---

## Algorithm

1. Run three loops:

   * First element → `i`
   * Second element → `j`
   * Third element → `k`
2. Check whether:

   ```cpp
   nums[i] + nums[j] + nums[k] == 0
   ```
3. Sort the triplet.
4. Insert into a set.
5. Convert set into vector and return.

---

## Complexity Analysis

### Time Complexity

* Three nested loops: `O(N³)`
* Sorting each triplet: `O(1)` (only 3 elements)
* Set insertion: `O(log M)`

Overall:

```cpp
O(N³)
```

### Space Complexity

```cpp
O(M)
```

Where `M` is the number of unique triplets stored.

---

# Observation

In the brute force solution:

* We repeatedly search for the third element.
* Instead of checking every possible third element, we can calculate what value is needed.
* A hash set can help us find that value quickly.

This reduces one loop.

---

# Approach 2: Better Solution (Hashing)

## Idea

Fix the first element.

For every second element:

* Compute the third value needed to make the sum zero.
* Check whether this third value has already appeared using a hash set.

Formula:

```cpp
third = -(arr[i] + arr[j]);
```

If `third` exists in the hash set, we found a valid triplet.

Store triplets in sorted order inside a set to avoid duplicates.

---

## Algorithm

For every index `i`:

1. Create an empty hash set.
2. Iterate `j` from `i+1` to `n-1`.
3. Calculate:

   ```cpp
   third = -(arr[i] + arr[j]);
   ```
4. If `third` exists in hash set:

   * Valid triplet found.
5. Sort triplet.
6. Insert into set.
7. Add current element into hash set.

---

## Complexity Analysis

### Time Complexity

Outer loop:

```cpp
O(N)
```

Inner loop:

```cpp
O(N)
```

Hash lookup:

```cpp
O(1)
```

Overall:

```cpp
O(N²)
```

### Space Complexity

Hash set + answer storage:

```cpp
O(N)
```

---

# Approach 3: Optimal Solution (Sorting + Two Pointers)

## Idea

Sort the array first.

Fix one element and find the remaining two elements using the Two Pointer technique.

After fixing:

```cpp
nums[i]
```

We need:

```cpp
nums[l] + nums[h] = -nums[i]
```

Since the array is sorted:

* If sum is too small → move left pointer right.
* If sum is too large → move right pointer left.
* If sum is zero → store answer and skip duplicates.

---

## Algorithm

1. Sort the array.
2. Fix one element using loop `i`.
3. Skip duplicate first elements.
4. Place:

   ```cpp
   l = i + 1
   h = n - 1
   ```
5. While `l < h`:

   * Calculate sum.
   * If sum == 0:

     * Store triplet.
     * Skip duplicate values.
   * If sum > 0:

     * Move right pointer.
   * Else:

     * Move left pointer.
6. Return answer.

---

## Complexity Analysis

### Time Complexity

Sorting:

```cpp
O(N log N)
```

Two Pointer Traversal:

```cpp
O(N²)
```

Overall:

```cpp
O(N²)
```

---

### Space Complexity

Ignoring output array:

```cpp
O(1)
```

---

# Dry Run

Input:

```cpp
[-1,0,1,2,-1,-4]
```

After sorting:

```cpp
[-4,-1,-1,0,1,2]
```

---

### i = 0 (-4)

```cpp
l = 1
h = 5
```

Sum:

```cpp
-4 + (-1) + 2 = -3
```

Move left pointer.

Continue.

No valid triplet.

---

### i = 1 (-1)

```cpp
l = 2
h = 5
```

Sum:

```cpp
-1 + (-1) + 2 = 0
```

Triplet:

```cpp
[-1,-1,2]
```

Store.

Move pointers.

---

Now:

```cpp
l = 3
h = 4
```

Sum:

```cpp
-1 + 0 + 1 = 0
```

Triplet:

```cpp
[-1,0,1]
```

Store.

---

Final Answer:

```cpp
[[-1,-1,2],[-1,0,1]]
```

---

# Edge Cases

### Case 1

```cpp
nums = []
```

Output:

```cpp
[]
```

---

### Case 2

```cpp
nums = [0]
```

Output:

```cpp
[]
```

---

### Case 3

```cpp
nums = [0,0,0]
```

Output:

```cpp
[[0,0,0]]
```

---

### Case 4

```cpp
nums = [1,2,-2,-1]
```

Output:

```cpp
[]
```

---

### Case 5

```cpp
nums = [-2,0,0,2,2]
```

Output:

```cpp
[[-2,0,2]]
```

---

# Interview Explanation

### Brute Force

"I can generate all possible triplets using three nested loops and check whether their sum is zero. To avoid duplicates, I sort each triplet and store it in a set. This approach takes O(N³) time."

---

### Better Solution

"Instead of checking every third element, I can calculate the required third value and use hashing to find it in O(1) average time. This reduces the complexity to O(N²)."

---

### Optimal Solution

"Since duplicates are important and the array can be sorted, I sort the array and fix one element. Then I use Two Pointers to find the remaining two elements efficiently. This achieves O(N²) time and O(1) extra space."

---

# Follow-Up Questions

### 1. Why do we sort the array?

Sorting enables the Two Pointer technique and makes duplicate removal easy.

---

### 2. Why skip duplicate values of `i`?

To prevent generating the same triplet multiple times.

---

### 3. Why skip duplicate values of `l` and `h` after finding a triplet?

To avoid duplicate answers.

---

### 4. Can 3Sum be solved in O(N)?

No. The accepted optimal solution is O(N²).

---

### 5. What changes if target is not zero?

Replace:

```cpp
sum == 0
```

with

```cpp
sum == target
```

and adjust pointer movements accordingly.
