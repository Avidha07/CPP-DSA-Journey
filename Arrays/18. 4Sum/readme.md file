# 18. 4Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return all unique quadruplets:

```text
[nums[a], nums[b], nums[c], nums[d]]
```

such that:

```text
nums[a] + nums[b] + nums[c] + nums[d] == target
```

The solution set must not contain duplicate quadruplets.

---

# Brute Force Approach

Generate every possible quadruplet using four nested loops.

```cpp
for(i)
    for(j)
        for(k)
            for(l)
```

Check whether:

```text
nums[i] + nums[j] + nums[k] + nums[l] == target
```

If yes, store the quadruplet.

### Time Complexity

```text
O(N⁴)
```

### Space Complexity

```text
O(1)
```

### Drawback

Very slow for large inputs and may exceed time limits.

---

# Optimal Approach (Sorting + Two Pointers)

## Intuition

This problem is an extension of:

```text
2Sum → Two Pointers
3Sum → One Fixed Element + Two Pointers
4Sum → Two Fixed Elements + Two Pointers
```

Instead of checking all quadruplets, we:

1. Sort the array.
2. Fix the first element (`i`).
3. Fix the second element (`j`).
4. Use two pointers (`low`, `high`) to find the remaining two elements.

This reduces the complexity from `O(N⁴)` to `O(N³)`.

---

# Algorithm

### Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```

Sorting allows us to:

* Use the two-pointer technique.
* Skip duplicates efficiently.

---

### Step 2: Fix the First Element

```cpp
for(int i = 0; i < n - 3; i++)
```

Skip duplicate first elements:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

---

### Step 3: Fix the Second Element

```cpp
for(int j = i + 1; j < n - 2; j++)
```

Skip duplicate second elements:

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

---

### Step 4: Apply Two Pointers

```cpp
int low = j + 1;
int high = n - 1;
```

Calculate:

```cpp
long long sum =
(long long)nums[i] +
nums[j] +
nums[low] +
nums[high];
```

---

### Step 5: Compare with Target

#### Case 1

```cpp
sum == target
```

Store the quadruplet.

```cpp
ans.push_back({
    nums[i],
    nums[j],
    nums[low],
    nums[high]
});
```

Skip duplicates for low and high.

Move both pointers:

```cpp
low++;
high--;
```

---

#### Case 2

```cpp
sum < target
```

Need a larger sum.

```cpp
low++;
```

---

#### Case 3

```cpp
sum > target
```

Need a smaller sum.

```cpp
high--;
```

---

# Why Duplicate Checks Are Needed

Without duplicate handling, the same quadruplet may appear multiple times.

### Duplicate Check for i

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

Prevents processing the same first element repeatedly.

---

### Duplicate Check for j

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

Prevents processing the same second element repeatedly.

---

### Duplicate Check for low

```cpp
while(low < high &&
      nums[low] == nums[low + 1])
{
    low++;
}
```

---

### Duplicate Check for high

```cpp
while(low < high &&
      nums[high] == nums[high - 1])
{
    high--;
}
```

---

# Complexity Analysis

### Time Complexity

Sorting:

```text
O(N log N)
```

Outer loop:

```text
O(N)
```

Inner loop:

```text
O(N)
```

Two pointers:

```text
O(N)
```

Overall:

```text
O(N³)
```

---

### Space Complexity

Ignoring the answer vector:

```text
O(1)
```

---

# Interview Explanation

If an interviewer asks:

### "How does your solution work?"

You can answer:

> First, I sort the array so that I can efficiently use the two-pointer technique and skip duplicates.
>
> Then I fix the first two elements using nested loops `i` and `j`.
>
> After fixing these two elements, the problem becomes finding two more numbers whose sum equals:
>
> `target - nums[i] - nums[j]`
>
> I use two pointers:
>
> * `low = j + 1`
> * `high = n - 1`
>
> If the current sum equals the target, I store the quadruplet.
>
> If the sum is smaller than the target, I move the left pointer.
>
> If the sum is greater than the target, I move the right pointer.
>
> To avoid duplicate quadruplets, I skip repeated values for `i`, `j`, `low`, and `high`.
>
> This gives a time complexity of `O(N³)` and space complexity of `O(1)` excluding the output array.

---

# Common Mistakes

### Mistake 1: Wrong Duplicate Check

Wrong:

```cpp
if(nums[i] == nums[i + 1])
```

Correct:

```cpp
if(nums[i] == nums[i - 1])
```

---

### Mistake 2: Forgetting Duplicate Handling for j

Wrong:

```cpp
if(j > 0 && nums[j] == nums[j - 1])
```

Correct:

```cpp
if(j > i + 1 && nums[j] == nums[j - 1])
```

---

### Mistake 3: Integer Overflow

Wrong:

```cpp
int sum
```

Correct:

```cpp
long long sum
```

---

### Mistake 4: Infinite Loop

If neither pointer moves, the loop never ends.

Always ensure:

```cpp
low++;
```

or

```cpp
high--;
```

happens every iteration.

---

# Where I Was Lagging While Solving This Problem

### 1. Duplicate Handling

I initially struggled with correctly skipping duplicates for:

* `i`
* `j`
* `low`
* `high`

This is one of the most common sources of bugs in 3Sum and 4Sum problems.

---

### 2. Pointer Movement

I had cases where pointers were not moving after processing a condition, which could lead to infinite loops.

---

### 3. Dry Running

I relied on coding before fully tracing examples.

A better approach is to manually track:

```text
i
j
low
high
sum
```

for a small test case.

---

### 4. Overflow Awareness

When multiple integers are added together, I should immediately consider using:

```cpp
long long
```

instead of:

```cpp
int
```

---

### 5. Pattern Recognition

I should recognize that:

```text
2Sum
↓
3Sum
↓
4Sum
↓
K-Sum
```

follow a common pattern.

Understanding this pattern helps solve similar problems much faster.

---

# Key Takeaways

* Sort first.
* Fix two elements.
* Use two pointers for the remaining two elements.
* Skip duplicates carefully.
* Use `long long` for safety.
* Always move pointers.
* Time Complexity: `O(N³)`
* Space Complexity: `O(1)` (excluding output)

This is the standard optimal solution for the 4Sum problem asked in coding interviews.
