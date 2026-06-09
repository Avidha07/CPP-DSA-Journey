# How I Would Explain This In An Interview

## Step 1: Understand the Problem

We need to count the number of triplets such that:

nums[i] + nums[j] + nums[k] < sum

where:

i < j < k

The question asks for the count, not the actual triplets.

---

## Step 2: Discuss the Brute Force Approach

A straightforward solution is to generate all possible triplets using three nested loops.

For every triplet:

(i, j, k)

check whether:

nums[i] + nums[j] + nums[k] < sum

If yes, increment the count.

### Complexity

Time Complexity: O(N³)

Space Complexity: O(1)

This works but is inefficient for large inputs.

---

## Step 3: Think About Optimization

Since we only need the count and not the actual triplets, we can avoid checking every combination individually.

If we sort the array, we can use the Two Pointer Technique.

Sorting gives us additional information about the relative order of elements.

---

## Step 4: Optimal Approach

### Idea

1. Sort the array.
2. Fix the first element using index `i`.
3. Use two pointers:
   - `l = i + 1`
   - `h = n - 1`

For every iteration calculate:

total = nums[i] + nums[l] + nums[h]

---

### Case 1

If:

total < sum

then because the array is sorted:

nums[i] + nums[l] + nums[h-1]

nums[i] + nums[l] + nums[h-2]

...

will also be less than `sum`.

Therefore, all positions between:

l+1 to h

form valid triplets.

Instead of counting them one by one, we directly do:

```cpp
cnt += (h - l);
```

and move:

```cpp
l++;
```

---

### Case 2

If:

total >= sum

the sum is too large.

To reduce the sum, move:

```cpp
h--;
```

because decreasing the larger element gives a smaller total.

---

## Why Does cnt += (h - l) Work?

Suppose:

```text
i = 0
l = 1
h = 4
```

and:

```text
nums[i] + nums[l] + nums[h] < sum
```

Since the array is sorted:

```text
nums[h]
nums[h-1]
nums[h-2]
...
nums[l+1]
```

are all valid choices.

Number of choices:

```text
h - l
```

Therefore:

```cpp
cnt += (h - l);
```

counts all valid triplets in O(1) time.

---

## Complexity Analysis

Sorting: O(N log N)

Two Pointer Traversal: O(N²)

Overall Time Complexity: O(N²)

Space Complexity: O(1)

---

## Final Interview Summary (30-Second Answer)

I first considered the brute force solution using three nested loops, which takes O(N³) time.

Since the array can be sorted, I used a Two Pointer approach. For each fixed index `i`, I maintain two pointers `l` and `h`.

If the triplet sum is smaller than the target, then due to the sorted order, all elements between `l+1` and `h` will also form valid triplets. Instead of checking them individually, I directly add `(h - l)` to the count.

If the sum is too large, I move the right pointer leftward to reduce the sum.

This reduces the complexity from O(N³) to O(N²).
