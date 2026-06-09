# Count Triplets With Sum Smaller Than Given Value

## Problem Statement

Given an array `nums[]` and an integer `sum`, count all triplets `(i, j, k)` such that:

i < j < k

and

nums[i] + nums[j] + nums[k] < sum

---

## Brute Force Approach

Generate all possible triplets and check whether their sum is less than the given value.

### Algorithm

1. Use three nested loops.
2. Generate every possible triplet.
3. Check if the triplet sum is smaller than `sum`.
4. Increment the count.

### Time Complexity

O(N³)

### Space Complexity

O(1)

---

## Optimal Approach (Sorting + Two Pointers)

### Idea

1. Sort the array.
2. Fix the first element using index `i`.
3. Use two pointers:
   - `l = i + 1`
   - `h = n - 1`
4. Calculate:

   total = nums[i] + nums[l] + nums[h]

5. If:

   total < sum

   then all elements between `l+1` and `h` will also form valid triplets.

### Why?

Because the array is sorted.

If:

nums[i] + nums[l] + nums[h] < sum

then:

nums[i] + nums[l] + nums[h-1] < sum

nums[i] + nums[l] + nums[h-2] < sum

...

nums[i] + nums[l] + nums[l+1] < sum

will also be valid.

Therefore we can directly add:

count += (h - l)

instead of checking every triplet individually.

---

## Most Important Line

```cpp
cnt += (h - l);
```

### Meaning

We are NOT generating triplets.

We are counting them mathematically.

Suppose:

```text
i = 0
l = 1
h = 4
```

Then:

```text
h - l = 3
```

These 3 triplets are:

```text
(nums[i], nums[l], nums[2])
(nums[i], nums[l], nums[3])
(nums[i], nums[l], nums[4])
```

Instead of visiting all three separately, we count them in O(1) time.

---

## Dry Run

Array:

```text
[1, 2, 3, 4, 5]
```

sum = 10

### Step 1

```text
i = 0
l = 1
h = 4
```

```text
1 + 2 + 5 = 8 < 10
```

Count:

```cpp
cnt += (4 - 1)
cnt += 3
```

Triplets counted:

```text
(1,2,3)
(1,2,4)
(1,2,5)
```

Move:

```cpp
l++
```

---

### Step 2

```text
i = 0
l = 2
h = 4
```

```text
1 + 3 + 5 = 9 < 10
```

Count:

```cpp
cnt += (4 - 2)
cnt += 2
```

Triplets counted:

```text
(1,3,4)
(1,3,5)
```

---

## Time Complexity

### Sorting

O(N log N)

### Two Pointer Traversal

O(N²)

### Total

O(N²)

---

## Space Complexity

O(1)

---

# Important Observation

This algorithm is a counting algorithm.

It does NOT generate all valid triplets.

It only counts them efficiently.

This is the reason it works in O(N²) instead of O(N³).

---

# Where I Was Getting Confused

I was expecting the algorithm to manually visit every valid triplet.

Example:

```text
(1,2,3)
(1,2,4)
(1,2,5)
```

But optimized algorithms often count possibilities without generating them.

This is a common pattern in advanced DSA problems.

---

# Concepts I Must Remember

## 1. Sorted Array Property

Whenever an array is sorted:

- Smaller elements are on the left.
- Larger elements are on the right.

This allows us to make decisions without checking every element.

---

## 2. Two Pointer Technique

Commonly used when:

- Array is sorted.
- Need pairs or triplets.
- Need O(N²) instead of O(N³).

---

## 3. Count Without Generating

A very important DSA concept.

Instead of finding:

```text
A
B
C
D
```

individually,

sometimes we can directly count:

```text
4 elements
```

Examples:

- Count Inversions
- Reverse Pairs
- Count Triplets Smaller Than Sum
- Triangle Counting
- Pair Sum Smaller Than K

---

## 4. Range Counting

Whenever a condition is true for:

```text
l ... h
```

try to count the entire range together.

Example:

```cpp
count += (h - l);
```

instead of:

```cpp
for(...)
    count++;
```

---

## 5. Think Mathematically

Always ask:

"Do I really need to generate every answer?"

or

"Can I count a whole group of answers together?"

This question often leads from O(N³) to O(N²) or from O(N²) to O(N log N).

---

# Interview Takeaway

When working with sorted arrays:

1. Think Two Pointers.
2. Think Range Counting.
3. Think Count Instead of Generate.
4. Look for opportunities to use mathematical counting.
5. Ask whether a whole segment can be processed together.
