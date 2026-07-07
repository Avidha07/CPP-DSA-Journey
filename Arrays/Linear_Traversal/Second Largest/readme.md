# 🥈 Second Largest Element in an Array

> Find the second largest distinct element present in the array. If no such element exists, return **-1**.

---

# 📌 Problem Information

| Property          | Details                                                     |
| ----------------- | ----------------------------------------------------------- |
| **Difficulty**    | Easy                                                        |
| **Topic**         | Arrays                                                      |
| **Pattern**       | Linear Traversal                                            |
| **Platform**      | GeeksforGeeks                                               |
| **LeetCode**      | No direct equivalent                                        |
| **GeeksforGeeks** | https://www.geeksforgeeks.org/problems/second-largest3735/1 |
| **Asked In**      | Amazon, Microsoft, Google, Adobe                            |

---

# 📝 Problem Statement

Given an array of positive integers, return the **second largest distinct element**.

If the array does not contain a second largest element, return **-1**.

---

# 💡 Intuition

The problem requires finding the **largest** and **second largest** distinct elements.

A straightforward approach is to first find the largest element and then search again for the largest element smaller than it.

However, since every element is already being visited, we can maintain both the largest and second largest values simultaneously in a single traversal.

---

# 👀 Observations

* The second largest element must be **strictly smaller** than the largest.
* Duplicate maximum values should not be considered as the second largest.
* The array needs to be traversed at least once.
* Two variables are sufficient to maintain the required information.

---

# 📋 Constraints

* `2 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`
* Elements are positive integers.
* Return **-1** if no second largest element exists.

---

# 🐢 Approach 1 — Brute Force (Sorting)

## Idea

Sort the array and find the first element smaller than the largest.

### Algorithm

1. Sort the array.
2. Store the largest element.
3. Traverse backwards.
4. Return the first element smaller than the largest.
5. If none exists, return `-1`.

### Time Complexity

```text
O(n log n)
```

### Space Complexity

```text
O(1)
```

### Why is it not optimal?

Sorting performs unnecessary work because only two values are required.

---

# ⚡ Approach 2 — Better (Two Traversals)

## Idea

Find the largest element in the first traversal.

In the second traversal, find the largest element strictly smaller than the maximum.

### Algorithm

1. Find the maximum element.
2. Initialize `secondLargest = -1`.
3. Traverse the array again.
4. Update `secondLargest` whenever:

```cpp
arr[i] > secondLargest && arr[i] < maxElement
```

5. Return `secondLargest`.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(1)
```

---

# 🚀 Approach 3 — Optimal (Single Traversal)

## Idea

Maintain both the **largest** and **second largest** elements while traversing the array only once.

Whenever a new largest element is found:

* The previous largest becomes the second largest.
* Update the largest.

Otherwise, if the current element lies between them:

* Update only the second largest.

### Algorithm

1. Initialize

```cpp
largest = -1
secondLargest = -1
```

2. Traverse the array.

3. If

```cpp
arr[i] > largest
```

then

```cpp
secondLargest = largest;
largest = arr[i];
```

4. Else if

```cpp
arr[i] > secondLargest && arr[i] < largest
```

then

```cpp
secondLargest = arr[i];
```

5. Return `secondLargest`.

---

## Dry Run

Input

```text
[4, 8, 2, 10, 6]
```

| Current | Largest | Second Largest |
| ------- | ------: | -------------: |
| 4       |       4 |             -1 |
| 8       |       8 |              4 |
| 2       |       8 |              4 |
| 10      |      10 |              8 |
| 6       |      10 |              8 |

**Answer = 8**

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

At every iteration:

* `largest` stores the maximum element seen so far.
* `secondLargest` stores the largest element smaller than `largest`.

These two variables always represent the correct answer for the processed portion of the array.

---

# ⚖️ Complexity Comparison

| Approach         | Time       | Space    |
| ---------------- | ---------- | -------- |
| Sorting          | O(n log n) | O(1)     |
| Two Traversals   | O(n)       | O(1)     |
| Single Traversal | **O(n)**   | **O(1)** |

---

# ⚠️ Edge Cases

| Input     | Output |
| --------- | ------ |
| `[10]`    | `-1`   |
| `[5,5,5]` | `-1`   |
| `[3,2,1]` | `2`    |
| `[2,1,2]` | `1`    |
| `[1,2]`   | `1`    |

---

# ❌ Common Mistakes

### 1. Allowing equality with the largest element

```cpp
arr[i] <= largest
```

This incorrectly considers duplicate maximum values.

Correct:

```cpp
arr[i] < largest
```

---

### 2. Initializing `secondLargest` with `arr[0]`

Fails when the first element is already the maximum.

Example:

```text
[3,2,1]
```

---

### 3. Using two independent `if` statements

```cpp
if (...)
{
}

if (...)
{
}
```

Prefer:

```cpp
if (...)
{
}
else if (...)
{
}
```

This avoids checking the second condition when the first one has already been satisfied.

---

### 4. Ignoring Problem Constraints

For this GFG problem:

```text
1 <= arr[i] <= 10^5
```

Initializing with `-1` is valid because `-1` can never be an array element.

In a general interview problem where negative numbers are allowed, consider using `INT_MIN` or clarify the constraints with the interviewer.

---

# 🎤 Interview Explanation

> A simple approach is to sort the array and return the largest distinct element before the maximum, but sorting requires **O(n log n)** time.
>
> A better solution is to find the maximum in one pass and the second largest in another, achieving **O(n)** time.
>
> The optimal approach maintains two variables, `largest` and `secondLargest`, during a single traversal. Whenever a larger element is found, the current largest becomes the second largest. Otherwise, if the current element lies strictly between them, only the second largest is updated. This solves the problem in **O(n)** time with **O(1)** extra space.

---

# 🎯 Interview Follow-up Questions

* Why must the second largest be strictly smaller than the largest?
* Why is `else if` preferred over two separate `if` statements?
* Why is `-1` safe for this GFG problem?
* Would `-1` still work if negative numbers were allowed?
* Can this be solved in a single traversal?
* What changes if duplicates are allowed as the second largest?

---

# 🔍 Pattern Recognition

* ✅ Arrays
* ✅ Linear Traversal
* ✅ Maintaining Two Running Values
* ✅ One-Pass Optimization

---

# 🔄 Related Problems

### Easy

* Largest Element in an Array
* Check if Array is Sorted
* Find Maximum Consecutive Ones
* Move Zeroes

### Medium

* Best Time to Buy and Sell Stock
* Maximum Product Subarray

### Hard

* Trapping Rain Water

---

# 📚 Key Learnings

* Always identify whether multiple values can be maintained during a single traversal.
* Read the problem constraints before choosing sentinel values.
* Use `else if` when conditions are mutually exclusive.
* Handle duplicate maximum values carefully.
* Aim to optimize from multiple traversals to a single traversal when possible.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {

        int largest = -1;
        int secondLargest = -1;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest && arr[i] < largest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};
```

---

# ⭐ Revision Notes

* Pattern → Linear Traversal
* Maintain **largest** and **secondLargest**
* Second largest must be **strictly less** than the largest
* Read constraints before choosing sentinel values
* Prefer `else if` over two independent `if` statements
* Time Complexity → **O(n)**
* Space Complexity → **O(1)**
