# 26. Remove Duplicates from Sorted Array

**Difficulty:** Easy
**Topic / Pattern:** Two Pointers, Array
**Language:** C++

---

# Problem Statement

Given a sorted integer array `nums`, remove the duplicates **in-place** such that each unique element appears only once.

The relative order of the elements must remain the same.

Return the number of unique elements `k`.

After modification:

* The first `k` elements should contain all unique elements in sorted order.
* Elements beyond index `k - 1` are ignored.

### Example 1

```cpp
Input: nums = [1,1,2]

Output: 2

Modified nums = [1,2,_]
```

### Example 2

```cpp
Input: nums = [0,0,1,1,1,2,2,3,3,4]

Output: 5

Modified nums = [0,1,2,3,4,_,_,_,_,_]
```

---

# Brute Force Approach

Since the array is sorted, one straightforward approach is:

1. Insert all elements into a `set`.
2. A set automatically removes duplicates.
3. Copy the unique elements back into the original array.
4. Return the size of the set.

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int> st;

        for(auto it : nums) {
            st.insert(it);
        }

        int index = 0;

        for(auto it : st) {
            nums[index++] = it;
        }

        return index;
    }
};
```

---

# Complexity of Brute Force

| Operation                     | Complexity |
| ----------------------------- | ---------- |
| Inserting n elements into set | O(N log N) |
| Copying unique elements back  | O(N)       |
| Total Time Complexity         | O(N log N) |
| Space Complexity              | O(N)       |

---

# Key Observation

The array is already sorted.

This means:

* Duplicate elements always appear next to each other.
* We do not need an extra data structure.
* We can maintain one pointer for the position where the next unique element should be placed.

This naturally leads to a **Two Pointer** solution.

---

# Optimal Approach with code

### Idea

* Keep the first element as unique.
* Use pointer `i` to track the position where the next unique element should be placed.
* Traverse the array using pointer `j`.
* Whenever `nums[j]` differs from the last unique element (`nums[i-1]`), place it at index `i` and increment `i`.

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())
            return 0;

        int i = 1;

        for(int j = 1; j < nums.size(); j++) {

            if(nums[j] != nums[i - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};
```

---

# Complexity of Optimal Approach

| Metric           | Complexity |
| ---------------- | ---------- |
| Time Complexity  | O(N)       |
| Space Complexity | O(1)       |

Since every element is visited exactly once and no extra space is used.

---

# Dry Run (step-by-step trace)

### Input

```cpp
nums = [0,0,1,1,1,2,2,3,3,4]
```

### Initial State

```cpp
i = 1
```

| j | nums[j] | nums[i-1] | Action             | i |
| - | ------- | --------- | ------------------ | - |
| 1 | 0       | 0         | Duplicate → Skip   | 1 |
| 2 | 1       | 0         | Unique → nums[1]=1 | 2 |
| 3 | 1       | 1         | Duplicate → Skip   | 2 |
| 4 | 1       | 1         | Duplicate → Skip   | 2 |
| 5 | 2       | 1         | Unique → nums[2]=2 | 3 |
| 6 | 2       | 2         | Duplicate → Skip   | 3 |
| 7 | 3       | 2         | Unique → nums[3]=3 | 4 |
| 8 | 3       | 3         | Duplicate → Skip   | 4 |
| 9 | 4       | 3         | Unique → nums[4]=4 | 5 |

### Final Array

```cpp
[0,1,2,3,4,_,_,_,_,_]
```

### Answer

```cpp
k = 5
```

---

# Edge Cases

### Case 1: Single Element

```cpp
nums = [5]

Output = 1
```

---

### Case 2: All Elements Same

```cpp
nums = [2,2,2,2]

Output = 1
```

---

### Case 3: No Duplicates

```cpp
nums = [1,2,3,4]

Output = 4
```

---

### Case 4: Negative Numbers

```cpp
nums = [-3,-3,-2,-1,-1]

Output = 3
```

---

# Interview Explanation (how to narrate it)

"I first notice that the array is already sorted. Because of sorting, all duplicates appear consecutively.

A brute-force solution would be to insert elements into a set and then copy them back, which takes O(N log N) time and O(N) extra space.

To optimize, I use a two-pointer approach. One pointer (`i`) keeps track of where the next unique element should be placed, while another pointer (`j`) scans the array.

Whenever I encounter a value different from the last stored unique value, I place it at index `i` and increment `i`.

This allows me to remove duplicates in-place with O(N) time complexity and O(1) extra space."

---

# Follow-up Questions with Answers

### 1. Why does the two-pointer approach work?

Because the array is sorted, duplicates always appear consecutively. We only need to compare the current element with the last unique element.

---

### 2. Can this approach work for an unsorted array?

No. Without sorting, duplicates are not adjacent. We would need a hash set or sorting first.

---

### 3. Why compare with `nums[i-1]` instead of `nums[j-1]`?

`nums[i-1]` always represents the last unique element stored in the result portion of the array.

---

### 4. What if the array is empty?

Return `0`.

```cpp
if(nums.empty()) return 0;
```

---

### 5. Why is the space complexity O(1)?

Because all modifications are performed directly inside the original array and no extra data structure is used.

---

### 6. Is this a stable operation?

Yes.

The relative order of unique elements remains unchanged.

---

### 7. Which pattern does this problem teach?

* Two Pointers
* In-place Array Modification
* Sorted Array Processing
* Read/Write Pointer Technique
