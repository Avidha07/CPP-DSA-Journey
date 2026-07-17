# 📌 Fixed Size Sliding Window Pattern

## 📖 When to Use
Use this pattern when:

- The window size `k` is fixed.
- You need to process **every subarray/substring of size `k`**.
- Common tasks include:
  - ✅ Maximum Sum of Size `k`
  - ✅ Minimum Sum of Size `k`
  - ✅ Maximum/Minimum Element
  - ✅ Count of Specific Elements
  - ✅ Average of Every Window
  - ✅ First Negative Number
  - ✅ Frequency-Based Problems

---

# 🚀 Template (C++)

```cpp
int i = 0, j = 0;
int sum = 0;

while (j < n) {

    // Include current element
    sum += arr[j];

    // Window size is smaller than k
    if (j - i + 1 < k) {
        j++;
    }

    // Window size becomes exactly k
    else if (j - i + 1 == k) {

        // ==========================
        // Process the current window
        // ==========================

        // Remove the leftmost element
        sum -= arr[i];

        // Slide the window
        i++;
        j++;
    }
}
```

---

# 🧠 How It Works

### Step 1
Expand the window by moving `j`.

### Step 2
Keep adding elements until the window size becomes `k`.

### Step 3
Once the window size is exactly `k`:

- Process the current window.
- Remove the leftmost element.
- Move both pointers forward.

Repeat until `j` reaches the end.

---

# ⏱️ Complexity

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** *(excluding extra data structures if used)* |

---

# 💡 Common Problems

- Maximum Sum Subarray of Size K
- Maximum Average Subarray I
- Number of Sub-arrays of Size K
- First Negative Integer in Every Window
- Maximum Number of Vowels in a Substring of Length K
- K-Radius Subarray Averages
- Sliding Window Maximum *(uses deque)*

---

# 🎯 Key Idea

> Expand ➜ Reach Size `k` ➜ Process ➜ Remove Left Element ➜ Slide Forward

This pattern ensures each element enters and leaves the window **exactly once**, giving an efficient **O(n)** solution.
