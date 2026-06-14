# 16. 3Sum Closest

## Problem Statement

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

### Example

```text
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation:
(-1 + 2 + 1) = 2
2 is the closest sum to the target 1.
```

---

# Brute Force Approach

Generate all possible triplets `(i, j, k)` where:

* `i < j < k`
* Calculate the sum of every triplet.
* Compare its difference from the target.
* Store the triplet sum having the minimum difference.
* If the sum becomes exactly equal to the target, return immediately.

### Algorithm

1. Iterate through all possible triplets using three nested loops.
2. Calculate the current triplet sum.
3. Compute `abs(sum - target)`.
4. If this difference is smaller than the current minimum difference, update the answer.
5. Return the closest sum found.

---

## Complexity of Brute Force

### Time Complexity

```text
O(n³)
```

Three nested loops generate all possible triplets.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

# Observation

The brute-force solution repeatedly checks every possible triplet.

Notice that:

* We only need the sum closest to the target.
* After sorting the array, we can intelligently move pointers based on whether the current sum is too large or too small.
* This eliminates the need to check all triplets.

This observation leads to the Two Pointer approach.

---

# Optimal Approach (Sorting + Two Pointers)

### Idea

1. Sort the array.
2. Fix one element at index `i`.
3. Use two pointers:

   * `left = i + 1`
   * `right = n - 1`
4. Calculate the current sum.
5. Update the closest answer if required.
6. If:

   * `sum < target` → move `left` forward.
   * `sum > target` → move `right` backward.
7. If `sum == target`, return immediately.

---

## Why Two Pointers Work?

After sorting:

* Moving the left pointer increases the sum.
* Moving the right pointer decreases the sum.

This allows us to efficiently move toward the target without checking every triplet.

---

## Complexity of Optimal Approach

### Time Complexity

Sorting:

```text
O(n log n)
```

Two Pointer Traversal:

```text
O(n²)
```

Overall:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

No extra data structure is used.

---

# Dry Run

### Input

```text
nums = [-1, 2, 1, -4]
target = 1
```

### Step 1: Sort

```text
[-4, -1, 1, 2]
```

---

### i = 0

```text
nums[i] = -4

left = 1
right = 3
```

Current Sum:

```text
-4 + (-1) + 2 = -3
```

Difference:

```text
|-3 - 1| = 4
```

Closest Sum:

```text
-3
```

Since:

```text
-3 < 1
```

Move left.

---

Current Sum:

```text
-4 + 1 + 2 = -1
```

Difference:

```text
|-1 - 1| = 2
```

Update closest sum:

```text
-1
```

Move left.

---

### i = 1

```text
nums[i] = -1

left = 2
right = 3
```

Current Sum:

```text
-1 + 1 + 2 = 2
```

Difference:

```text
|2 - 1| = 1
```

Update closest sum:

```text
2
```

Since:

```text
2 > 1
```

Move right.

Loop ends.

---

### Final Answer

```text
2
```

---

# Edge Cases

### 1. Exact Match Exists

```text
nums = [0,1,2]
target = 3

Output = 3
```

Return immediately.

---

### 2. All Numbers Negative

```text
nums = [-8,-5,-3,-1]
target = -7
```

Still works correctly.

---

### 3. All Numbers Positive

```text
nums = [1,2,3,4]
target = 20
```

Largest possible sum is returned.

---

### 4. Duplicate Elements

```text
nums = [0,0,0]
target = 1
```

Output:

```text
0
```

---

### 5. Large Positive/Negative Target

```text
nums = [-1000,-500,200,300]
target = 10000
```

Closest sum is still found.

---

# Interview Explanation

### Brute Force

"My first approach is brute force. I generate every possible triplet using three nested loops and compute its sum. For every sum, I compare its distance from the target and maintain the closest one. This approach takes O(n³) time and O(1) space."

### Optimization

"I observe that we only need the closest sum, not all triplets. After sorting the array, I can fix one element and use Two Pointers to efficiently move toward the target. If the current sum is too small, I move the left pointer; if it is too large, I move the right pointer."

### Optimal Solution

"The optimized solution uses sorting and Two Pointers. Sorting takes O(n log n), and the Two Pointer traversal takes O(n²), resulting in an overall time complexity of O(n²) with O(1) extra space."

---

# Follow-up Questions and Answers

### 1. Why do we sort the array before applying Two Pointers?

Sorting arranges the elements in increasing order. This allows us to predict how the sum changes when moving pointers:

- Moving the left pointer to the right increases the sum.
- Moving the right pointer to the left decreases the sum.

Without sorting, we cannot make these decisions efficiently.

---

### 2. Why can we move the left pointer when the sum is smaller than the target?

If:

sum < target

then we need a larger sum.

Since the array is sorted, moving the left pointer forward selects a larger number, increasing the overall sum and potentially bringing it closer to the target.

---

### 3. Why can we move the right pointer when the sum is larger than the target?

If:

sum > target

then we need a smaller sum.

Since the array is sorted, moving the right pointer backward selects a smaller number, reducing the overall sum and potentially bringing it closer to the target.

---

### 4. What happens when multiple sums have the same minimum difference?

The problem guarantees that exactly one solution exists.

Even if multiple sums have the same difference from the target, our implementation keeps the first one encountered because we only update the answer when:

abs(sum - target) < diff

and not when:

abs(sum - target) <= diff

---

### 5. Can this problem be solved without sorting?

Yes.

A brute-force solution can generate every possible triplet and track the closest sum.

However, its time complexity is:

O(n³)

Sorting is necessary to achieve the optimized O(n²) solution using Two Pointers.

---

### 6. What is the difference between 3Sum and 3Sum Closest?

#### 3Sum

Find all unique triplets whose sum equals zero.

Example:

[-1,0,1]

because:

-1 + 0 + 1 = 0

#### 3Sum Closest

Find a triplet whose sum is closest to the given target.

Example:

target = 1

Closest sum = 2

The goal is not an exact match but the minimum difference from the target.

---

### 7. Why is the optimal solution O(n²) instead of O(n³)?

After sorting:

- One loop fixes an element.
- Two pointers scan the remaining portion of the array.

For each fixed element:

O(n)

work is performed.

Thus:

O(n) × O(n) = O(n²)

which is much better than checking all triplets.

---

### 8. What would change if we needed the actual triplet instead of the sum?

Instead of storing only:

res = sum

we would store:

triplet = {nums[i], nums[left], nums[right]}

Whenever a closer sum is found, we update the stored triplet.

At the end, return the triplet rather than the sum.

---

### 9. Can the Two Pointer technique be applied if the array is not sorted?

No.

Two Pointers rely on the property that:

- Moving left increases values.
- Moving right decreases values.

Without sorting, pointer movement becomes unpredictable and the technique no longer works correctly.

---

### 10. How would you explain this optimization to an interviewer in under one minute?

"My brute-force approach checks every possible triplet, resulting in O(n³) time complexity. Since we only need the sum closest to the target, we can sort the array and use the Two Pointer technique. After fixing one element, we place two pointers on the remaining part of the array. If the current sum is too small, we move the left pointer to increase it; if it is too large, we move the right pointer to decrease it. This reduces the overall complexity to O(n²) while using O(1) extra space."
