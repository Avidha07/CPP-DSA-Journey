# 283. Move Zeroes

**Difficulty:** Easy
**Topic / Pattern:** Two Pointers, Array Manipulation
**Language:** C++

---

# Problem Statement

Given an integer array `nums`, move all `0`s to the end while maintaining the relative order of the non-zero elements.

The operation must be performed **in-place**, meaning no extra array should be used for the final solution.

### Example 1

```cpp
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### Example 2

```cpp
Input: nums = [0]
Output: [0]
```

---

# Brute Force Approach

### Idea

Create a temporary array and store all non-zero elements in it.

After placing all non-zero elements, the remaining positions automatically remain `0`.

Finally, copy the temporary array back into the original array.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n, 0);

        int index = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                temp[index++] = nums[i];
            }
        }

        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
```

---

# Complexity of Brute Force

| Complexity | Value |
| ---------- | ----- |
| Time       | O(N)  |
| Space      | O(N)  |

---

# Key Observation

We do not actually need an extra array.

If we find the first zero position and keep track of it, every non-zero element appearing after that position can be swapped with the zero.

This ensures:

* All non-zero elements move toward the front.
* Relative ordering remains unchanged.
* Extra space is eliminated.

---

# Optimal Approach with code

### Idea

1. Find the first occurrence of zero.
2. Store its index in `j`.
3. Traverse the remaining array.
4. Whenever a non-zero element is found:

   * Swap it with `nums[j]`.
   * Increment `j`.

This continuously pushes zeros toward the end.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int j = -1;

        // Find first zero
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        if(j == -1)
            return;

        for(int i = j + 1; i < n; i++) {

            if(nums[i] != 0) {

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};
```

---

# Complexity of Optimal Approach

| Complexity | Value |
| ---------- | ----- |
| Time       | O(N)  |
| Space      | O(1)  |

---

# Dry Run (step-by-step trace)

### Input

```cpp
nums = [0,1,0,3,12]
```

### Step 1

Find first zero.

```cpp
j = 0
```

### Step 2

```cpp
i = 1
nums[1] = 1
```

Swap:

```cpp
[1,0,0,3,12]
```

```cpp
j = 1
```

### Step 3

```cpp
i = 2
nums[2] = 0
```

Skip.

### Step 4

```cpp
i = 3
nums[3] = 3
```

Swap:

```cpp
[1,3,0,0,12]
```

```cpp
j = 2
```

### Step 5

```cpp
i = 4
nums[4] = 12
```

Swap:

```cpp
[1,3,12,0,0]
```

```cpp
j = 3
```

### Final Answer

```cpp
[1,3,12,0,0]
```

---

# Edge Cases

### Case 1: All Zeros

```cpp
Input: [0,0,0]
Output: [0,0,0]
```

### Case 2: No Zeros

```cpp
Input: [1,2,3]
Output: [1,2,3]
```

The algorithm immediately returns.

### Case 3: Single Element

```cpp
Input: [0]
Output: [0]
```

### Case 4: Zero at End

```cpp
Input: [1,2,3,0]
Output: [1,2,3,0]
```

### Case 5: Multiple Consecutive Zeros

```cpp
Input: [1,0,0,2,3]
Output: [1,2,3,0,0]
```

---

# Interview Explanation (how to narrate it)

"I first considered using an auxiliary array to store all non-zero elements and then fill the remaining positions with zeros. That approach works in O(N) time but requires O(N) extra space.

Since the problem specifically asks for an in-place solution, I optimized it using the Two Pointer technique.

I locate the first zero and store its index. Then I continue traversing the array. Whenever I encounter a non-zero element, I swap it with the element at the zero index and move the zero pointer forward.

This keeps all non-zero elements in their original relative order while shifting zeros toward the end. The solution runs in O(N) time and O(1) extra space."

---

# Follow-up Questions with Answers

### 1. Why does the relative order of non-zero elements remain unchanged?

Because every non-zero element is processed from left to right and moved to the earliest available zero position without changing the order among non-zero elements.

---

### 2. Can this problem be solved without swapping?

Yes.

We can maintain a write pointer and place non-zero elements at the front, then fill the remaining positions with zeros.

---

### 3. Why is Two Pointers suitable here?

One pointer tracks the first available zero position while the other scans the array for non-zero elements.

---

### 4. What if the array contains no zero?

The first search for zero fails (`j = -1`) and the function returns immediately.

---

### 5. What is the main improvement over the brute-force approach?

The optimal solution removes the extra array and reduces space complexity from O(N) to O(1).

---

### 6. Can the time complexity be better than O(N)?

No.

Every element must be inspected at least once, so O(N) is the optimal time complexity.

---

### 7. Which pattern should be identified in interviews?

**Two Pointers + In-Place Array Rearrangement**.
