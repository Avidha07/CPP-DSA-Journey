# 2090. K Radius Subarray Averages

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Medium |
| Topic | Arrays |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/k-radius-subarray-averages/ |
| Companies | Amazon, Google, Microsoft |

---

# 📝 Problem Statement

You are given an integer array `nums` and an integer `k`.

For every index `i`, compute the **average** of the subarray centered at `i` with radius `k`.

The subarray is:

```
[i-k ... i+k]
```

whose length is:

```
2*k + 1
```

If there are not enough elements on either side, the answer for that index is `-1`.

Return the resulting array.

---

# 💡 Intuition

A valid average requires exactly:

```
2*k + 1
```

elements.

Since this window size remains constant, we can use a **Fixed Size Sliding Window**.

Instead of recalculating the sum for every center, maintain the sum of the current window and slide it one step at a time.

---

# 👀 Observations

- Window size is always:

```
2*k + 1
```

- If the window size exceeds the array length, every answer is `-1`.
- Each average corresponds to the **center** of the current window.
- Integer division automatically truncates the decimal part.

---

# 📋 Constraints

- `1 <= n <= 10^5`
- `0 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`

Since `n` can be as large as `100000`, an **O(n²)** solution is not feasible.

---

# 🐢 Approach 1 — Brute Force

## Idea

For every index:

- Check if `k` elements exist on both sides.
- If yes, sum all `2*k+1` elements.
- Compute the average.
- Otherwise, store `-1`.

---

## Algorithm

1. Traverse every index.
2. Verify whether a complete window exists.
3. Compute the sum.
4. Store the average.

---

## Dry Run

```
nums = [7,4,3,9,1,8,5,2,6]

k = 3

Center = 3

Window

7 4 3 9 1 8 5

Sum = 37

Average = 37 / 7 = 5
```

---

## Time Complexity

```
O(n × (2k+1))
```

---

## Space Complexity

```
O(1)
```

---

## Why is it inefficient?

The overlapping elements are summed repeatedly for every center.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Since every window has the same size:

```
2*k + 1
```

- Compute the first window sum.
- Store its average at index `k`.
- Slide the window one position.
- Update the sum by:
  - Removing the outgoing element.
  - Adding the incoming element.

Each window is processed in constant time.

---

## Algorithm

1. Calculate window size:

```
window = 2*k + 1
```

2. If the window size exceeds the array length, return all `-1`.
3. Compute the first window sum.
4. Store the average at index `k`.
5. Slide the window:
   - Add the next element.
   - Remove the oldest element.
   - Store the average at the new center.
6. Return the result.

---

## Dry Run

### Input

```
nums =

[7,4,3,9,1,8,5,2,6]

k = 3
```

Window Size

```
7
```

First Window

```
7 4 3 9 1 8 5

Sum = 37

Average = 5

res[3] = 5
```

Slide

```
Remove 7

Add 2

Window

4 3 9 1 8 5 2

Sum = 32

Average = 4

res[4] = 4
```

Slide

```
Remove 4

Add 6

Window

3 9 1 8 5 2 6

Sum = 34

Average = 4

res[5] = 4
```

Final Output

```
[-1,-1,-1,5,4,4,-1,-1,-1]
```

---

## Time Complexity

```
O(n)
```

---

## Space Complexity

```
O(1)
```

*(Ignoring the output array.)*

---

## Why does this approach work?

Adjacent windows overlap by:

```
Window Size - 1
```

elements.

Instead of recomputing the entire sum:

```
New Sum

=

Previous Sum

- Outgoing Element

+ Incoming Element
```

Each element enters and leaves the window only once, resulting in an **O(n)** solution.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n × (2k+1)) | O(1) |
| Optimal (Sliding Window) | O(n) | O(1) |

---

# ⚠️ Edge Cases

- `k = 0`
- `window size > n`
- `window size = n`
- Single element array.
- All elements are the same.
- Large values (use `long long` for sum).

---

# ❌ Common Mistakes

### Mistake 1

Using `int` for the window sum.

Wrong:

```cpp
int sum;
```

Correct:

```cpp
long long sum;
```

Large values can overflow an `int`.

---

### Mistake 2

Placing the average at the wrong index.

Correct:

```cpp
res[k] = sum / window;
```

The average belongs to the **center** of the window.

---

### Mistake 3

Forgetting the special case:

```cpp
window > n
```

Return all `-1`.

---

### Mistake 4

Using the wrong window size.

Correct:

```cpp
2*k + 1
```

---

# 🎤 Interview Explanation

> The required subarray always has a fixed length of `2*k + 1`, so I use a Fixed Size Sliding Window. I first compute the sum of the initial window and place its average at the center index. Then I slide the window by adding the incoming element and removing the outgoing element, updating the sum in O(1) time. Since each element is processed only once, the overall complexity is O(n).

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Fixed Size Sliding Window
- ✅ Running Sum
- ✅ Array Traversal
-  Prefix Sum + Sliding Window.

---


# 📚 Key Learnings

- Radius `k` means a window size of `2*k + 1`.
- Maintain a running sum instead of recomputing it.
- Store the average at the **center** of the window.
- Use `long long` to avoid integer overflow.
- Sliding Window reduces the complexity to **O(n)**.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> res(n, -1);

        int window = 2 * k + 1;

        if (window > n)
            return res;

        long long sum = 0;

        for (int i = 0; i < window; i++)
            sum += nums[i];

        res[k] = sum / window;

        for (int i = window; i < n; i++) {

            sum += nums[i];
            sum -= nums[i - window];

            res[i - k] = sum / window;
        }

        return res;
    }
};
```

---

# ⭐ Revision Notes

- Window size = `2*k + 1`.
- Compute the first window sum.
- Store the average at the center.
- Slide the window by adding and removing one element.
- Use `long long` for the running sum.
- Return `-1` when the window cannot fit.
- Time → **O(n)**
- Space → **O(1)** *(excluding output array)*

---
