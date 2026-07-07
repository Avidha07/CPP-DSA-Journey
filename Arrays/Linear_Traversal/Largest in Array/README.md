# 🔥 Largest Element in an Array

> Find the maximum element present in an array.

---

# 📌 Problem Information

| Property          | Details                                                               |
| ----------------- | --------------------------------------------------------------------- |
| **Difficulty**    | Easy                                                                  |
| **Topic**         | Arrays                                                                |
| **Pattern**       | Linear Traversal                                                      |
| **Platform**      | GeeksforGeeks                                                         |
| **LeetCode**      | No direct equivalent                                                  |
| **GeeksforGeeks** | https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1 |
| **Asked In**      | Amazon, Microsoft, Google, Adobe                                      |

---

# 📝 Problem Statement

Given an array of integers, return the largest element present in the array.

---

# 💡 Intuition

The problem asks only for the **maximum element**, not the complete sorted order.

Sorting the array performs unnecessary work. Instead, we can keep track of the largest element while traversing the array only once.

---

# 👀 Observations

* We need only one value—the maximum element.
* Every element must be examined at least once.
* The answer can be maintained while traversing the array.
* Sorting is unnecessary because the relative ordering of elements is irrelevant.

---

# 📋 Constraints

* Array contains at least one element.
* Elements may be positive, negative, or zero.
* Duplicate values are allowed.

---

# 🐢 Approach 1 — Brute Force (Sorting)

## Idea

Sort the array in ascending order and return the last element.

### Algorithm

1. Sort the array.
2. Return the last element.

### Time Complexity

```text
O(n log n)
```

### Space Complexity

```text
O(1)
```

### Why is it not optimal?

Sorting rearranges the entire array even though we only need one value.

---

# 🚀 Approach 2 — Optimal (Linear Traversal)

## Idea

Maintain the largest element seen so far while traversing the array.

### Algorithm

1. Initialize `maxElement = arr[0]`.
2. Traverse the array from index `1`.
3. If the current element is greater than `maxElement`, update it.
4. Return `maxElement`.

---

## Dry Run

Input

```text
[3, 7, 2, 9, 5]
```

| Current Element | maxElement |
| --------------- | ---------: |
| 3               |          3 |
| 7               |          7 |
| 2               |          7 |
| 9               |          9 |
| 5               |          9 |

**Answer = 9**

---

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(1)
```

### Why does this work?

`maxElement` always stores the largest value encountered so far. After processing every element exactly once, it must contain the largest element in the array.

---

# ⚖️ Complexity Comparison

| Approach         | Time       | Space    |
| ---------------- | ---------- | -------- |
| Sorting          | O(n log n) | O(1)     |
| Linear Traversal | **O(n)**   | **O(1)** |

---

# ⚠️ Edge Cases

| Input            | Output |
| ---------------- | ------ |
| `[10]`           | `10`   |
| `[-8,-3,-10,-1]` | `-1`   |
| `[5,5,5]`        | `5`    |
| `[1,2,3,4,5]`    | `5`    |

---

# ❌ Common Mistakes

### 1. Initializing with `0`

```cpp
int maxElement = 0;
```

Fails for:

```text
[-5,-2,-10]
```

Correct:

```cpp
int maxElement = arr[0];
```

---

### 2. Sorting the array

Sorting increases the complexity from **O(n)** to **O(n log n)** without providing any additional benefit.

---

### 3. Traversing from index `0`

Since `maxElement` is already initialized with `arr[0]`, starting the loop from index `1` avoids one unnecessary comparison.

---

# 🎤 Interview Explanation

> A straightforward approach is to sort the array and return the last element. However, sorting requires **O(n log n)** time and performs unnecessary work because the problem only asks for the maximum value.
>
> A better approach is to maintain a variable called `maxElement`. I initialize it with the first element and traverse the remaining elements once. Whenever I encounter a larger value, I update `maxElement`. This visits each element exactly once, resulting in **O(n)** time complexity and **O(1)** extra space.

---

# 🎯 Interview Follow-up Questions

* Why is sorting unnecessary?
* Why initialize with `arr[0]` instead of `0`?
* What if the array contains only negative numbers?
* What if the array is empty?
* Can this be solved recursively?
* How would you find the second largest element?

---

# 🔍 Pattern Recognition

* ✅ Arrays
* ✅ Linear Traversal
* ✅ Maintaining Running Maximum

---

# 🔄 Related Problems

### Easy

* Second Largest Element in an Array
* Check if Array is Sorted
* Remove Duplicates from Sorted Array
* Move Zeroes

### Medium

* Best Time to Buy and Sell Stock
* Maximum Product Subarray

### Hard

* Trapping Rain Water
* First Missing Positive

---

# 📚 Key Learnings

* Solve the problem with the minimum required work.
* Do not sort unless ordering is required.
* Maintain the answer while traversing.
* Always consider edge cases like negative numbers.
* Explain optimization from brute force during interviews.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int largest(vector<int>& arr) {

        int maxElement = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }

        return maxElement;
    }
};
```

---

# ⭐ Revision Notes

* Pattern → Linear Traversal
* Running Maximum
* Initialize with `arr[0]`
* No sorting required
* Time → **O(n)**
* Space → **O(1)**
