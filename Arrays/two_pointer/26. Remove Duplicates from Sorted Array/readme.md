# 🔄 Remove Duplicates from Sorted Array

> Remove duplicates **in-place** from a sorted array and return the number of unique elements.

---

# 📌 Problem Information

| Property          | Details                                                            |
| ----------------- | ------------------------------------------------------------------ |
| **Difficulty**    | Easy                                                               |
| **Topic**         | Arrays                                                             |
| **Pattern**       | Two Pointers                                                       |
| **Platform**      | LeetCode                                                           |
| **LeetCode**      | https://leetcode.com/problems/remove-duplicates-from-sorted-array/ |
| **GeeksforGeeks** | Similar Problem Available                                          |
| **Asked In**      | Amazon, Microsoft, Google, Meta, Adobe                             |

---

# 📝 Problem Statement

Given a **sorted** integer array `nums`, remove the duplicates **in-place** such that each unique element appears only once.

The relative order of the elements should be preserved.

Return the number of unique elements `k`.

The first `k` elements of `nums` should contain the unique elements.

---

# 💡 Intuition

Since the array is already **sorted**, all duplicate elements appear **consecutively**.

Instead of creating a new array, maintain:

* A pointer pointing to the last unique element.
* Another pointer scanning the remaining array.

Whenever a new unique element is found, overwrite the next available position.

---

# 👀 Observations

* The array is already sorted.
* Duplicate elements are adjacent.
* Only the first occurrence of each element should remain.
* The answer must be generated **in-place**.
* Only the first `k` elements matter after processing.

---

# 📋 Constraints

* `1 <= nums.length <= 3 × 10⁴`
* `-100 <= nums[i] <= 100`
* Array is sorted in **non-decreasing order**.

---

# 🐢 Approach 1 — Brute Force

## Idea

Store all unique elements in a separate data structure and copy them back into the array.

### Algorithm

1. Traverse the array.
2. Store unique elements in another vector or set.
3. Copy them back into the original array.
4. Return the size of the unique collection.

### Time Complexity

```text
O(n)
```

### Space Complexity

```text
O(n)
```

### Why is it not optimal?

The problem explicitly asks for an **in-place** solution with **O(1)** extra space.

---

# 🚀 Approach 2 — Optimal (Two Pointers)

## Idea

Maintain two pointers:

* **Slow Pointer (`i`)** → Points to the last unique element.
* **Fast Pointer (`j`)** → Scans the array.

Whenever `nums[j]` is different from `nums[i]`:

1. Move the slow pointer.
2. Copy the new unique element.
3. Continue scanning.

---

## Algorithm

1. Initialize:

```cpp
int i = 0;
```

2. Traverse using `j` from index `1`.

3. If

```cpp
nums[i] != nums[j]
```

4. Then

```cpp
i++;
nums[i] = nums[j];
```

5. Return

```cpp
i + 1;
```

---

# 🧪 Dry Run

Input

```text
[1,1,2,2,3]
```

Initial

```text
i = 0
j = 1
```

| i | j | Action             | Array     |
| - | - | ------------------ | --------- |
| 0 | 1 | Duplicate → Skip   | 1 1 2 2 3 |
| 0 | 2 | Unique → i++, Copy | 1 2 2 2 3 |
| 1 | 3 | Duplicate → Skip   | 1 2 2 2 3 |
| 1 | 4 | Unique → i++, Copy | 1 2 3 2 3 |

Return

```text
3
```

The first **3** elements become:

```text
[1,2,3]
```

---

# ⚖️ Complexity Comparison

| Approach     | Time     | Space    |
| ------------ | -------- | -------- |
| Extra Array  | O(n)     | O(n)     |
| Two Pointers | **O(n)** | **O(1)** |

---

# ⚠️ Edge Cases

| Input         | Output |
| ------------- | ------ |
| `[1]`         | `1`    |
| `[1,1,1]`     | `1`    |
| `[1,2,3]`     | `3`    |
| `[1,1,2,2,3]` | `3`    |

---

# ❌ Common Mistakes

### 1. Using `swap()`

```cpp
swap(nums[i], nums[j]);
```

Only overwriting is required.

Correct

```cpp
nums[++i] = nums[j];
```

---

### 2. Starting both pointers at `0`

```cpp
i = 0;
j = 0;
```

The first comparison becomes:

```text
nums[0] == nums[0]
```

which is unnecessary.

Correct initialization:

```cpp
i = 0;
j = 1;
```

---

### 3. Forgetting to increment `i`

```cpp
nums[i] = nums[j];
```

Without incrementing `i`, unique elements overwrite the same position.

Correct

```cpp
i++;
nums[i] = nums[j];
```

---

### 4. Returning `i`

The answer is **not** `i`.

`i` stores the **last unique index**.

Return

```cpp
i + 1;
```

because array indexing starts from `0`.

---

# 🎤 Interview Explanation

> Since the array is sorted, duplicate values always appear consecutively.
>
> I maintain two pointers:
>
> * A slow pointer representing the last unique element.
> * A fast pointer scanning the array.
>
> Whenever the fast pointer finds a new unique element, I move the slow pointer forward and overwrite that position with the current element.
>
> This keeps all unique elements at the beginning of the array while using only constant extra space.
>
> The algorithm runs in **O(n)** time with **O(1)** extra space.

---

# 🎯 Interview Follow-up Questions

* Why does this algorithm only work on a sorted array?
* Why do we overwrite instead of swapping?
* Why does `j` start from index `1`?
* Why do we return `i + 1`?
* Can this problem be solved without modifying the array?
* How would you solve it if the array was unsorted?

---

# 🔍 Pattern Recognition

* ✅ Arrays
* ✅ Two Pointers
* ✅ In-Place Modification
* ✅ Slow & Fast Pointer

---

# 🔄 Related Problems

### Easy

* Move Zeroes
* Remove Element
* Merge Sorted Array

### Medium

* Sort Colors
* Partition Labels

### Hard

* Trapping Rain Water

---

# 📚 Key Learnings

* Two pointers reduce unnecessary work.
* Sorted arrays make duplicate detection simple.
* Overwrite instead of swapping when only one value needs updating.
* The slow pointer always marks the end of the unique portion.
* The returned value is the count of unique elements, not the last index.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {

            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
```

---

# ⭐ Revision Notes

* Pattern → Two Pointers
* Slow Pointer = Last Unique Element
* Fast Pointer = Traverses Array
* Array must be sorted
* Overwrite instead of swap
* Return `i + 1`
* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`
