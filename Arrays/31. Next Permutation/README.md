Problem Statement
Given an array of integers, find the next permutation in lexicographically increasing order.
If the current permutation is the last (i.e., sorted in descending order), return the first permutation (sorted in ascending order).

Approach: Brute Force
Idea

Generate all permutations of the array in sorted order.
Linear search through all permutations to find the current one.
Return the next permutation right after it.
If the current is the last permutation, return the first one.

Steps
Step 1: Sort the array to start from the lexicographically smallest permutation.
Step 2: Generate all N! permutations using next_permutation (STL).
Step 3: Store all permutations in a list.
Step 4: Find the index of the current permutation via linear search.
Step 5: Return permutation at index + 1 (or index 0 if it's the last).

Note: C++ STL provides next_permutation() which directly generates the next permutation without brute force. The above uses it only to pre-generate all permutations for demonstration purposes.

📊 Complexity Analysis
ComplexityTime Complexity : O(N! × N)
Space Complexity : O(N!)
Why so expensive?

For an array of size N, there are N! permutations.
We generate and store all of them, then do a linear search.

N         N!Permutations
5         120
10        3,628,800
15        ≈ 1.3 × 10¹²
20        ≈ 2.4 × 10¹⁸
For N = 15, we'd generate over 1 trillion permutations — clearly not practical!

❌ Why Brute Force is Avoided

Generating N! permutations is computationally infeasible for large N.
Memory required is also O(N!), which blows up quickly.
For N = 15, approximately 10¹² permutations must be generated and searched — making it practically unusable.

############################################################################################################################

# 🔢 Next Permutation — Optimal Approach

## 📌 Problem Statement

Given an array of integers, find the **next permutation** in lexicographically increasing order.  
If the current permutation is the **last** (sorted in descending order), return the **first** permutation (sorted in ascending order).  
The replacement must be **in-place** using only constant extra memory.

---

## 💡 Key Observation

To get the **next** permutation with the **smallest possible increase**, we need to:

- Find a digit that can be **slightly increased**
- Rearrange everything to its right to be the **smallest possible**

This means finding the **longest suffix** that is already the largest it can be (descending), then making a minimal change just before it.

---

## 🧠 Algorithm (Step-by-Step)

### Step 1 — Find the Breaking Point

Traverse from the **right**, find the first index `ind` where:

```
nums[ind] < nums[ind + 1]
```

This is where the descending suffix ends — the element at `ind` can be increased.

```
Example:  [2, 1, 5, 4, 3]
                 ↑
          ind = 1  (nums[1]=1 < nums[2]=5)
```

---

### Step 2 — Edge Case: No Breaking Point

If no such `ind` exists, the entire array is **descending** → it's the last permutation.  
Simply **reverse** the whole array to get the smallest permutation.

```
[5, 4, 3, 2, 1]  →  [1, 2, 3, 4, 5]
```

---

### Step 3 — Find the Best Swap Candidate

From the right, find the **first element greater than `nums[ind]`** — this is the smallest element greater than it (since the suffix is sorted descending).

**Swap** it with `nums[ind]`.

```
[2, 1, 5, 4, 3]
      ↑        ↑
   ind=1    swap with nums[4]=3  (first > 1 from right)

After swap: [2, 3, 5, 4, 1]
```

---

### Step 4 — Reverse the Suffix

Reverse everything **to the right of `ind`** to make it the smallest possible arrangement.

```
[2, 3, 5, 4, 1]
         ------
         reverse suffix from ind+1

Result: [2, 3, 1, 4, 5]  ✅
```
---

## 📊 Complexity Analysis

| | Complexity |
|---|---|
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

- Finding the breaking point → `O(N)`
- Finding the swap candidate → `O(N)`
- Reversing the suffix → `O(N)`
- No extra data structures used → `O(1)` space

---

## 🧪 Dry Run Example

**Input:** `[2, 1, 5, 4, 3]`

| Step | Action | Array State |
|------|--------|-------------|
| Start | Original array | `[2, 1, 5, 4, 3]` |
| Step 1 | Breaking point at `ind = 1` (1 < 5) | `[2, 1, 5, 4, 3]` |
| Step 3 | Swap `nums[1]=1` with `nums[4]=3` (first > 1 from right) | `[2, 3, 5, 4, 1]` |
| Step 4 | Reverse suffix from `ind+1=2` to end | `[2, 3, 1, 4, 5]` |

**Output:** `[2, 3, 1, 4, 5]` ✅

---

## 🧪 Edge Case: Last Permutation

**Input:** `[3, 2, 1]`

| Step | Action | Array State |
|------|--------|-------------|
| Start | Original array | `[3, 2, 1]` |
| Step 1 | No breaking point found (`ind = -1`) | `[3, 2, 1]` |
| Step 2 | Reverse entire array | `[1, 2, 3]` |

**Output:** `[1, 2, 3]` ✅

---

## ⚖️ Brute Force vs Optimal

| | Brute Force | Optimal |
|---|---|---|
| **Idea** | Generate all N! permutations, find next | In-place rearrangement |
| **Time** | `O(N! × N)` | `O(N)` |
| **Space** | `O(N!)` | `O(1)` |
| **Feasible for N=15?** | ❌ ~10¹² operations | ✅ 15 operations |

---

## 📁 Related Topics

- Arrays
- Two Pointers
- Greedy
- In-place Algorithms

---

## 🏷️ Tags

`Array` `Greedy` `Two Pointers` `In-place` `Permutation` `C++`
