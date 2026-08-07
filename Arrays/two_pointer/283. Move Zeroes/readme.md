# 283. Move Zeroes

**Difficulty:** Easy  
**Platform:** LeetCode  
**Topic:** Array, Two Pointers

---

# 📌 Problem Statement

Given an integer array `nums`, move all the `0`s to the end of the array while keeping the order of all non-zero elements the same.

You must do this **in-place**, which means you cannot create another array.

### Example

**Input**

```text
nums = [0,1,0,3,12]
```

**Output**

```text
[1,3,12,0,0]
```

---

# 💡 Intuition

We need to:

- Keep all non-zero numbers in the same order.
- Move every zero to the end.
- Do everything inside the same array.

The main idea is:

- Find the first zero.
- After that, whenever we find a non-zero number, swap it with that zero.
- Move the zero pointer one step ahead.

This slowly pushes all zeros toward the end.

---

# 👀 Observation

- Numbers before the first zero are already in the correct position.
- Every time we swap a non-zero number with a zero, one more number reaches its correct place.
- The relative order of non-zero numbers does not change.

---

# 🧠 Approach (Optimal)

### Step 1

Find the first zero in the array.

Store its index in `j`.

If there is no zero, the array is already correct.

### Step 2

Start checking elements after `j`.

- If the current element is non-zero:
  - Swap it with `nums[j]`.
  - Move `j` to the next position.

### Step 3

Continue until the end of the array.

At the end, all zeros will automatically be at the back.

---

# 🪜 Dry Run

### Input

```text
[0,1,0,3,12]
```

### Find first zero

```text
j = 0
```

### i = 1

```text
1 is non-zero

Swap(1,0)

[1,0,0,3,12]

j = 1
```

### i = 2

```text
0

Skip
```

### i = 3

```text
3 is non-zero

Swap(3,0)

[1,3,0,0,12]

j = 2
```

### i = 4

```text
12 is non-zero

Swap(12,0)

[1,3,12,0,0]

j = 3
```

### Final Answer

```text
[1,3,12,0,0]
```

---

# ✅ Algorithm

1. Find the first zero.
2. If no zero is found, return.
3. Traverse the remaining array.
4. Whenever a non-zero number is found:
   - Swap it with the first zero.
   - Move the zero pointer forward.
5. Return the modified array.

---

# ⏱ Complexity Analysis

### Time Complexity

```text
O(n)
```

- One pass to find the first zero.
- One pass to move non-zero elements.

Overall:

```text
O(n)
```

### Space Complexity

```text
O(1)
```

No extra array is used.

---

# ❌ Common Mistakes

### Mistake 1

Creating another array.

The problem asks to modify the same array.

---

### Mistake 2

Changing the order of non-zero elements.

Their order must stay the same.

---

### Mistake 3

Not checking if the array has no zeros.

If there is no zero, simply return.

---

# 🎯 Why This Works

- `j` always points to the first zero that should be replaced.
- `i` looks for the next non-zero element.
- Every swap places one non-zero number in its correct position.
- All zeros naturally move to the end.

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = -1;

        // Find first zero
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                j = i;
                break;
            }
        }

        // No zero found
        if(j == -1) return;

        // Move non-zero elements forward
        for(int i = j + 1; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

---

# 📚 Pattern Used

- Two Pointers
- Array
- In-place Swapping

---

# 🔑 Key Learning

- Use two pointers to solve array problems without extra space.
- Keep one pointer on the first zero.
- Use the second pointer to find the next non-zero element.
- Swapping is enough to move all zeros to the end while keeping the order of non-zero numbers.

---

# ⭐ Interview Explanation (30 Seconds)

"I first find the first zero in the array. Then I continue scanning the remaining elements. Whenever I find a non-zero element, I swap it with the position of the first zero and move the zero pointer forward. This keeps all non-zero elements in the same order and moves all zeros to the end in-place with O(n) time and O(1) space."
