# 239. Sliding Window Maximum

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Hard |
| Topic | Arrays, Queue |
| Pattern | Sliding Window, Monotonic Deque |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/sliding-window-maximum/ |
| GeeksforGeeks | https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/ |
| Companies | Amazon, Microsoft, Google, Adobe, Meta, Apple, Bloomberg, Uber |

---

# 📝 Problem Statement

Given an integer array `nums` and a window size `k`, find the maximum element in every contiguous subarray (sliding window) of size `k`.

As the window moves one position to the right, return the maximum element for each window.

---

# 💡 Intuition

A straightforward solution is to find the maximum element for every window separately. However, this repeatedly compares the same elements, leading to an inefficient solution.

Instead, we maintain the window's maximum efficiently using a **Monotonic Deque**.

The deque always stores elements in **decreasing order**, so the front of the deque is always the maximum element of the current window.

---

# 👀 Observations

- Window size is fixed (`k`).
- We need the maximum for every window.
- Recomputing the maximum for every window is inefficient.
- Once an element smaller than the current element is behind it, it can never become the maximum again, so it can be removed.
- The deque always keeps the maximum element at the front.

---

# 📋 Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

Since `n` can be as large as `100000`, an **O(n × k)** solution will cause TLE. We need a linear-time solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

For every window of size `k`:

- Traverse all `k` elements.
- Find the maximum.
- Store it.

---

## Algorithm

1. Iterate through every possible window.
2. Traverse all `k` elements.
3. Find the maximum.
4. Store the answer.

---

## Dry Run

```
nums = [1,3,-1]
k = 3

Maximum = 3
```

Repeat this for every window.

---

## Time Complexity

```
O((n-k+1) × k)
```

---

## Space Complexity

```
O(1)
```

---

## Why is it inefficient?

The maximum is recomputed from scratch for every window, even though adjacent windows overlap significantly.

---

# 🚀 Approach 2 — Optimal (Monotonic Deque)

## Idea

Maintain a deque in **decreasing order**.

For every new element:

- Remove all smaller elements from the back because they can never become the maximum while the current element exists.
- Insert the current element.
- The front always stores the maximum.
- Before sliding, remove the front if it is leaving the window.

---

## Algorithm

1. Initialize an empty deque.
2. Traverse the array.
3. Remove all smaller elements from the back.
4. Insert the current element.
5. When window size becomes `k`:
   - Store the front element as the maximum.
   - Remove the front if it is leaving the window.
   - Slide the window.

---

## Dry Run

### Input

```
nums = [1,3,-1,-3,5,3,6,7]
k = 3
```

### Window 1

```
[1,3,-1]

Deque

3 -1

Maximum = 3
```

---

### Window 2

```
[3,-1,-3]

Deque

3 -1 -3

Maximum = 3
```

---

### Window 3

```
[-1,-3,5]

Remove smaller elements

Deque

5

Maximum = 5
```

---

### Window 4

```
[-3,5,3]

Deque

5 3

Maximum = 5
```

---

### Window 5

```
[5,3,6]

Remove smaller elements

Deque

6

Maximum = 6
```

---

### Window 6

```
[3,6,7]

Remove smaller elements

Deque

7

Maximum = 7
```

Output

```
[3,3,5,5,6,7]
```

---

## Time Complexity

```
O(n)
```

---

## Space Complexity

```
O(k)
```

---

## Why does this approach work?

Each element is:

- Inserted into the deque once.
- Removed from the deque at most once.

Therefore, every element is processed at most twice, resulting in an overall **O(n)** time complexity.

The deque always remains in decreasing order, ensuring the front is the current window's maximum.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-k+1) × k) | O(1) |
| Optimal (Deque) | O(n) | O(k) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = n`
- Array contains all equal elements.
- All elements are negative.
- Strictly increasing array.
- Strictly decreasing array.
- Single element array.

---

# ❌ Common Mistakes

### Mistake 1

Not removing smaller elements before inserting the current element.

```cpp
dq.push_back(nums[j]);
```

Without removing smaller elements, the deque is no longer monotonic, and the front may not represent the maximum.

Correct:

```cpp
while(!dq.empty() && dq.back() < nums[j])
    dq.pop_back();

dq.push_back(nums[j]);
```

---

### Mistake 2

Forgetting to remove the outgoing maximum.

```cpp
if(dq.front() == nums[i])
    dq.pop_front();
```

If the maximum leaves the window and isn't removed, the answer becomes incorrect.

---

### Mistake 3

Using values instead of indices (alternative approach).

Many implementations store **indices** instead of values to handle duplicates more naturally.

---

# 🎤 Interview Explanation

> Since the window size is fixed, I use a sliding window. To efficiently find the maximum in every window, I maintain a monotonic decreasing deque. Before inserting a new element, I remove all smaller elements from the back because they can never become the maximum in future windows. The front of the deque always contains the maximum element. When the window slides, I remove the front if it is leaving the window. Since every element is inserted and removed at most once, the overall complexity is O(n).

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Sliding Window
- ✅ Monotonic Queue (Deque)
- ✅ Queue
- ✅ Greedy

---


# 📚 Key Learnings

- Sliding Window alone is not enough for maximum/minimum problems.
- Monotonic deque maintains candidates for the maximum efficiently.
- Every element is pushed and popped at most once.
- Deque ensures O(n) complexity.
- Many interviewers expect the deque solution for this problem.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0, j = 0;

        vector<int> res;
        deque<int> dq;

        while (j < n) {

            while (!dq.empty() && dq.back() < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(nums[j]);

            if (j - i + 1 == k) {

                res.push_back(dq.front());

                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }

                i++;
            }

            j++;
        }

        return res;
    }
};
```

---

# ⭐ Revision Notes

- Fixed window size = `k`.
- Maintain a **monotonic decreasing deque**.
- Remove all smaller elements before insertion.
- Front always stores the maximum.
- Remove front if it leaves the window.
- Every element enters and leaves the deque once.
- Time → **O(n)**
- Space → **O(k)**

---
