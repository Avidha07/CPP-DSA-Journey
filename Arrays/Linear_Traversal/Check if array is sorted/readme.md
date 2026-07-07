# ✅ Check if Array is Sorted

> Determine whether a given array is sorted in **non-decreasing order**.

---

# 📌 Problem Information

| Property          | Details                                                                  |
| ----------------- | ------------------------------------------------------------------------ |
| **Difficulty**    | Easy                                                                     |
| **Topic**         | Arrays                                                                   |
| **Pattern**       | Linear Traversal                                                         |
| **Platform**      | GeeksforGeeks                                                            |
| **LeetCode**      | No direct equivalent                                                     |
| **GeeksforGeeks** | https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1 |
| **Asked In**      | Amazon, Microsoft, Google, Adobe                                         |

---

# 📝 Problem Statement

Given an array of integers, determine whether it is sorted in **non-decreasing order**.

Return:

* `true` if the array is sorted.
* `false` otherwise.

---

# 💡 Intuition

For an array to be sorted in non-decreasing order, every element should be **greater than or equal to** its previous element.

Instead of checking whether the array is sorted, it's easier to check **when it is not sorted**.

The moment we find an element smaller than its previous element, we can immediately return `false`.

---

# 👀 Observations

* Compare every element with its previous element.
* Only adjacent elements need to be compared.
* One incorrect pair is enough to conclude the array is not sorted.
* No extra space is required.

---

# 📋 Constraints

* Array may contain duplicate elements.
* Elements may be positive, negative, or zero.
* A single-element or empty array is considered sorted.

---

# 🐢 Approach 1 — Brute Force

## Idea

Compare every possible pair of elements to verify the ordering.

### Algorithm

1. Compare each element with every element after it.
2. If any earlier element is greater than a later element, return `false`.
3. Otherwise, return `true`.

### Time Complexity

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

### Why is it not optimal?

Many unnecessary comparisons are performed because only adjacent elements are sufficient to determine whether the array is sorted.

---

# 🚀 Approach 2 — Optimal (Linear Traversal)

## Idea

Traverse the array once and compare every element with its previous element.

If any element is smaller than its previous element, the array is not sorted.

### Algorithm

1. Traverse the array from index `1`.
2. Compare `arr[i]` with `arr[i-1]`.
3. If `arr[i-1] > arr[i]`, return `false`.
4. If the loop finishes, return `true`.

---

## Dry Run

Input

```text
[1, 2, 2, 4, 5]
```

| Previous | Current | Sorted? |
| -------- | ------- | ------- |
| 1        | 2       | ✅       |
| 2        | 2       | ✅       |
| 2        | 4       | ✅       |
| 4        | 5       | ✅       |

Output

```text
true
```

---

### Dry Run (Unsorted Array)

Input

```text
[1, 5, 3, 4]
```

| Previous | Current | Sorted? |
| -------- | ------- | ------- |
| 1        | 5       | ✅       |
| 5        | 3       | ❌       |

Immediately return

```text
false
```

---

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(1)
```

---

## Why does this work?

If an array is sorted, every adjacent pair must satisfy:

```text
arr[i-1] <= arr[i]
```

The first pair that violates this condition proves that the array is not sorted.

Since every adjacent pair is checked exactly once, the algorithm correctly determines whether the array is sorted.

---

# ⚖️ Complexity Comparison

| Approach         | Time     | Space    |
| ---------------- | -------- | -------- |
| Brute Force      | O(n²)    | O(1)     |
| Linear Traversal | **O(n)** | **O(1)** |

---

# ⚠️ Edge Cases

| Input       | Output  |
| ----------- | ------- |
| `[]`        | `true`  |
| `[5]`       | `true`  |
| `[5,5,5]`   | `true`  |
| `[1,2,2,3]` | `true`  |
| `[3,2,1]`   | `false` |
| `[1,5,3]`   | `false` |

---

# ❌ Common Mistakes

### 1. Comparing the wrong elements

Incorrect

```cpp
if(arr[i] > arr[i + 1])
```

This may access an invalid index when `i` reaches the last element.

Correct

```cpp
if(arr[i - 1] > arr[i])
```

---

### 2. Using unnecessary `continue`

Instead of

```cpp
if(arr[i - 1] <= arr[i])
{
    continue;
}
else
{
    return false;
}
```

Prefer

```cpp
if(arr[i - 1] > arr[i])
{
    return false;
}
```

This is simpler and easier to read.

---

### 3. Forgetting that duplicates are allowed

For non-decreasing order:

```text
1 2 2 3
```

is **sorted**.

If the problem asks for **strictly increasing**, the condition changes to:

```cpp
arr[i - 1] >= arr[i]
```

---

# 🎤 Interview Explanation

> A brute-force approach would compare every pair of elements, resulting in O(n²) time complexity.
>
> However, this is unnecessary because an array is sorted if and only if every adjacent pair is in non-decreasing order.
>
> Therefore, I traverse the array once and compare each element with its previous element. If I find any element smaller than its predecessor, I immediately return `false`. Otherwise, after the traversal completes, I return `true`.
>
> This approach takes **O(n)** time and **O(1)** extra space.

---

# 🎯 Interview Follow-up Questions

* What is the difference between **sorted** and **strictly increasing**?
* Why are adjacent comparisons sufficient?
* Why is an empty array considered sorted?
* Can this be solved recursively?
* What changes if the array is sorted in descending order?

---

# 🔍 Pattern Recognition

* ✅ Arrays
* ✅ Linear Traversal
* ✅ Adjacent Element Comparison
* ✅ Early Return

---

# 🔄 Related Problems

### Easy

* Largest Element in an Array
* Second Largest Element in an Array
* Remove Duplicates from Sorted Array
* Check if Array is Sorted and Rotated

### Medium

* Monotonic Array
* Non-decreasing Array

---

# 📚 Key Learnings

* Always compare adjacent elements when checking sorted order.
* Check the failure condition instead of the success condition.
* Use early return to simplify the code.
* Distinguish between **non-decreasing** and **strictly increasing** arrays.
* One traversal is sufficient.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    bool isSorted(vector<int>& arr) {

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }

        return true;
    }
};
```

---

# ⭐ Revision Notes

* Pattern → Linear Traversal
* Compare adjacent elements
* Check the failure condition
* Early return improves readability
* Non-decreasing allows duplicates
* Strictly increasing does not allow duplicates
* Time Complexity → **O(n)**
* Space Complexity → **O(1)**
