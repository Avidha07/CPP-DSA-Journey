# LeetCode 287 - Find the Duplicate Number

## Problem Statement

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, there is only one repeated number in the array.

Return the duplicate number.

### Example

```cpp
Input: nums = [1,3,4,2,2]
Output: 2
```

---

# Approach: Sorting

## Intuition

If we sort the array, all identical numbers will become adjacent to each other.

After sorting, we simply traverse the array and compare every element with its previous element. If two consecutive elements are equal, that element is the duplicate number.

---

## Algorithm

1. Sort the array.
2. Traverse the array from index `1` to `n-1`.
3. Compare the current element with the previous element.
4. If both are equal, return the duplicate number.
5. If no duplicate is found, return `-1`.

---

## Code

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};
```

---

## Dry Run

### Input

```cpp
nums = [1,3,4,2,2]
```

### After Sorting

```cpp
[1,2,2,3,4]
```

### Traversal

| Index | Current | Previous | Duplicate Found |
| ----- | ------- | -------- | --------------- |
| 1     | 2       | 1        | No              |
| 2     | 2       | 2        | Yes             |

Return:

```cpp
2
```

---

## Complexity Analysis

### Time Complexity

#### Sorting

```cpp
O(n log n)
```

#### Traversal

```cpp
O(n)
```

#### Total

```cpp
O(n log n)
```

---

### Space Complexity

```cpp
O(1)
```

Ignoring the space used internally by the sorting algorithm.

---

## Why Does This Work?

After sorting:

```cpp
[1,3,4,2,2]
        ↓
[1,2,2,3,4]
```

The duplicate elements become neighbors.

By checking adjacent elements, we can efficiently identify the duplicate number.

---

## Advantages

* Easy to understand and implement.
* No extra data structures required.
* Constant auxiliary space.

---

## Disadvantages

* Modifies the original array.
* Does not satisfy the optimal time complexity requirement.
* Slower than Floyd's Cycle Detection.

---

## Comparison of Approaches

| Approach                | Time       | Space |
| ----------------------- | ---------- | ----- |
| Brute Force             | O(n²)      | O(1)  |
| Sorting                 | O(n log n) | O(1)  |
| Hash Map                | O(n)       | O(n)  |
| Frequency Array         | O(n)       | O(n)  |
| Floyd's Cycle Detection | O(n)       | O(1)  |

---

## Interview Discussion

If modifying the array is allowed, sorting provides a simple and clean solution.

However, the optimal solution for this problem is Floyd's Cycle Detection because it achieves:

* O(n) Time Complexity
* O(1) Space Complexity
* Does not modify the original array

Therefore, sorting is a good intermediate solution but not the most optimal one.

---

# Key Takeaway

Sorting groups identical elements together. Once the array is sorted, finding the duplicate becomes as simple as checking adjacent elements.

This approach is straightforward, easy to explain in interviews, and serves as a good stepping stone toward more optimal solutions.
