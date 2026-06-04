# 287. Find the Duplicate Number

## Problem Statement

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only one repeated number in `nums`, return this repeated number.

You must solve the problem:

* Without modifying the array.
* Using only constant extra space.
* With a runtime complexity better than `O(n²)`.

---

## Example

### Input

```text
nums = [1,3,4,2,2]
```

### Output

```text
2
```

---

# Key Observation

The values in the array can be treated as pointers to the next index.

For example:

```text
nums = [1,3,4,2,2]

Index: 0 1 2 3 4
Value: 1 3 4 2 2
```

Representation:

```text
0 → 1
1 → 3
3 → 2
2 → 4
4 → 2
```

Notice:

```text
2 → 4 → 2 → 4 ...
```

A cycle is formed.

Since one number appears more than once, multiple indices point to the same location, which guarantees the existence of a cycle.

Therefore, this problem can be converted into a **Linked List Cycle Detection** problem.

---

# Approach: Floyd's Tortoise and Hare Algorithm

The algorithm consists of two phases:

## Phase 1: Find an Intersection Point

Initialize two pointers:

```cpp
int slow = nums[0];
int fast = nums[0];
```

Move:

```cpp
slow = nums[slow];
fast = nums[nums[fast]];
```

* Slow moves one step at a time.
* Fast moves two steps at a time.

Since a cycle exists, they must eventually meet somewhere inside the cycle.

### Important

The first meeting point is NOT necessarily the duplicate number.

It is simply a point inside the cycle.

---

## Phase 2: Find the Entrance of the Cycle

After the first meeting:

```cpp
fast = nums[0];
```

Now move both pointers one step at a time:

```cpp
slow = nums[slow];
fast = nums[fast];
```

The next position where they meet is the entrance of the cycle.

The entrance of the cycle represents the duplicate number.

---

# Why Does This Work?

Let:

* `x` = Distance from the start to the cycle entrance.
* `y` = Distance from the cycle entrance to the first meeting point.
* `c` = Length of the cycle.

When slow and fast meet:

```text
Slow Distance = x + y
Fast Distance = x + y + k × c
```

Since fast moves twice as fast:

```text
2(x + y) = x + y + k × c
```

Therefore:

```text
x + y = k × c
```

Rearranging:

```text
x = k × c - y
```

This means:

* One pointer starting from the beginning.
* One pointer starting from the first meeting point.

will meet exactly at the cycle entrance if both move one step at a time.

Since the cycle entrance is created because of the duplicate value, that meeting point is the duplicate number.

---

# Dry Run

## Input

```text
nums = [1,3,4,2,2]
```

### Graph Representation

```text
0 → 1
1 → 3
3 → 2
2 → 4
4 → 2
```

Cycle:

```text
2 → 4 → 2
```

---

## Phase 1

Initial:

```text
slow = 1
fast = 1
```

Iteration 1:

```text
slow = 3
fast = 2
```

Iteration 2:

```text
slow = 2
fast = 2
```

First meeting point found.

---

## Phase 2

Reset:

```text
fast = nums[0] = 1
```

Move both one step:

```text
slow = 4
fast = 3
```

Move again:

```text
slow = 2
fast = 2
```

Both meet at:

```text
2
```

Duplicate Number:

```text
2
```

---

# C++ Solution

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
```

---

# Complexity Analysis

## Time Complexity

### Phase 1

Finding the intersection point:

```text
O(n)
```

### Phase 2

Finding the cycle entrance:

```text
O(n)
```

Overall:

```text
O(n)
```

---

## Space Complexity

Only two pointers are used:

```text
O(1)
```

---

# Interview Explanation

"We can treat the array as a linked list where each value represents the next index to visit. Because one number is duplicated, a cycle is guaranteed to exist. Using Floyd's Cycle Detection Algorithm, we first find an intersection point inside the cycle using slow and fast pointers. Then we reset one pointer to the beginning and move both pointers one step at a time. The point where they meet again is the entrance of the cycle, which corresponds to the duplicate number."

---

# Key Takeaways

✅ Array is treated as a linked list.

✅ Duplicate number creates a cycle.

✅ First meeting point is not necessarily the duplicate.

✅ Second meeting point gives the cycle entrance.

✅ Cycle entrance equals the duplicate number.

✅ Time Complexity: `O(n)`

✅ Space Complexity: `O(1)`
