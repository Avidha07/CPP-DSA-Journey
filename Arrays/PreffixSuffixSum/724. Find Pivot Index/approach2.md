# Pivot Index – Formula Approach

## Problem

Find the **pivot index** in an array such that:

> **Left Sum = Right Sum**

The pivot element itself is **not included** in either sum.

---

## Main Idea

Instead of creating a prefix or suffix array, we use:

- `total` → sum of all elements.
- `lSum` → running left sum.
- `rSum` → calculated using a formula.

Since `total` is already known, we can compute the right sum in **O(1)** for every index.

---

## Algorithm

### Step 1: Find Total Sum

```cpp
total += nums[i];
```

- `total` stores the sum of the entire array.
- This helps us calculate the right sum instantly.

### Step 2: Initialize Left Sum

```cpp
lSum = 0;
```

Initially, the left side of index `0` is empty.

### Step 3: Calculate Right Sum

```cpp
rSum = total - nums[i] - lSum;
```

### Why this formula?

`total` contains every element.

- Remove the current element (`nums[i]`).
- Remove the left side (`lSum`).

So,

<math value="\\text{Right} = \\text{Total} - \\text{Current} - \\text{Left}" block />

### Step 4: Compare

```cpp
if (lSum == rSum)
    return i;
```

If both sums are equal, we've found the pivot index.

### Step 5: Update Left Sum

```cpp
lSum += nums[i];
```

The current element becomes part of the left side for the next iteration.

---

## Dry Run

Array:

```text
[1,7,3,6,5,6]
```

Total Sum = **28**

| Index | Left Sum | Right Sum | Result |
|------:|---------:|----------:|:------:|
| 0 | 0 | 27 | ❌ |
| 1 | 1 | 20 | ❌ |
| 2 | 8 | 17 | ❌ |
| 3 | 11 | 11 | ✅ Return `3` |

---

## C++ Solution

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int num : nums)
            total += num;

        int lSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rSum = total - nums[i] - lSum;

            if (lSum == rSum)
                return i;

            lSum += nums[i];
        }

        return -1;
    }
};
```

---

## Memory Trick

> **Total is fixed, Left grows, Right is calculated.**

Remember the formula:

<math value="\\text{Right} = \\text{Total} - \\text{Current} - \\text{Left}" block />

---

## Complexity

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |

---

## Common Mistake

A common mistake is forgetting to subtract `lSum`.

Incorrect thinking:

> Right = Total − Current

This is wrong because `total` already includes the left-side elements.

Correct formula:

<math value="\\text{Right} = \\text{Total} - \\text{Current} - \\text{Left}" block />

Without subtracting `lSum`, the right sum would incorrectly include left-side elements.
