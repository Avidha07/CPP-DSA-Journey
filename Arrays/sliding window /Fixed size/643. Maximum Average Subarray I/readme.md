# 643. Maximum Average Subarray I

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Easy |
| Topic | Arrays |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/maximum-average-subarray-i/ |

---

# 📝 Problem Statement

Given an integer array `nums` and an integer `k`, find the contiguous subarray of length `k` that has the maximum average value and return that average.

---

# 💡 Intuition

Since the subarray length is **fixed (`k`)**, we don't need to recalculate the sum for every subarray.

Instead, we can:

- Calculate the sum of the current window.
- Slide the window by removing the left element and adding the next element.
- Keep track of the maximum average.

This is a classic **Fixed Size Sliding Window** problem.

---

# 👀 Observations

- Every valid subarray has exactly `k` elements.
- Average = Sum / `k`.
- Since `k` is fixed, maximizing the **sum** automatically maximizes the **average**.
- Recomputing the sum for every window would be inefficient.

---

# 📋 Constraints

- `1 <= k <= n <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

Since `n` can be as large as `100000`, an **O(n²)** solution will result in a Time Limit Exceeded (TLE). We need an **O(n)** solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

Generate every subarray of size `k`.

For each subarray:

- Compute its sum.
- Calculate its average.
- Update the maximum average.

---

## Algorithm

1. Traverse every possible starting index.
2. Calculate the sum of the next `k` elements.
3. Compute average.
4. Update answer.

---

## Dry Run

```
nums = [1,12,-5,-6,50,3]
k = 4

Window 1
1 + 12 -5 -6 = 2
Average = 0.5

Window 2
12 -5 -6 +50 = 51
Average = 12.75

Window 3
-5 -6 +50 +3 = 42
Average = 10.5

Maximum = 12.75
```

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

Many elements are summed repeatedly because adjacent windows overlap.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Maintain the sum of the current window.

Whenever the window size becomes `k`:

- Compute the average.
- Update the maximum.
- Remove the leftmost element.
- Slide the window.

Each element enters and leaves the window exactly once.

---

## Algorithm

1. Initialize two pointers `i` and `j`.
2. Expand the window by adding `nums[j]`.
3. When window size becomes `k`:
   - Compute average.
   - Update maximum average.
   - Remove `nums[i]`.
   - Move `i`.
4. Continue until the array ends.

---

## Dry Run

### Input

```
nums = [1,12,-5,-6,50,3]
k = 4
```

### Window 1

```
[1,12,-5,-6]

Sum = 2
Average = 0.5

Maximum = 0.5
```

Slide

```
Remove 1

Window

[12,-5,-6,50]

Sum = 51
Average = 12.75

Maximum = 12.75
```

Slide

```
Remove 12

Window

[-5,-6,50,3]

Sum = 42
Average = 10.5

Maximum = 12.75
```

Final Answer

```
12.75
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

---

## Why does this approach work?

Instead of recalculating the sum of every window, we reuse the previous window's sum.

```
New Window Sum
=
Previous Window Sum
- Left Element
+ New Right Element
```

Each element is processed only twice:

- Once when entering the window.
- Once when leaving the window.

Hence, the overall complexity becomes **O(n)**.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-k+1) × k) | O(1) |
| Optimal | O(n) | O(1) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = n`
- All negative numbers
- All positive numbers
- Mixed positive and negative numbers
- Single element array

---

# ❌ Common Mistakes

### Mistake 1

Using integer division.

```cpp
avg = sum / k;
```

This performs integer division.

Correct:

```cpp
avg = (double)sum / k;
```

---

### Mistake 2

Initializing maximum as `0`.

```cpp
double maxi = 0;
```

If all averages are negative, this gives the wrong answer.

Correct:

```cpp
double maxi = INT_MIN;
```

or

```cpp
double maxi = -1e18;
```

---

### Mistake 3

Forgetting to remove the leftmost element.

```cpp
sum -= nums[i];
```

Without removing it, the window sum becomes incorrect.

---

# 🎤 Interview Explanation

> Since the window size is fixed (`k`), I use the Fixed Size Sliding Window technique. I maintain the sum of the current window and compute the average whenever the window size reaches `k`. After processing a window, I remove the leftmost element and slide the window forward. This avoids recomputing sums from scratch, resulting in an O(n) solution with O(1) extra space.

---

# 🔍 Pattern Recognition

- ✅ Fixed Size Sliding Window
- ✅ Two Pointers
- ✅ Running Sum

---

# 📚 Key Learnings

- Fixed-size sliding window avoids recomputing sums.
- Max average is equivalent to max sum when `k` is fixed.
- Cast to `double` before division.
- Running sum is a common optimization for window problems.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0, j = 0;
        int sum = 0;

        double maxi = INT_MIN;

        while (j < n) {

            sum += nums[j];

            if (j - i + 1 == k) {

                double avg = (double)sum / k;
                maxi = max(maxi, avg);

                sum -= nums[i];
                i++;
            }

            j++;
        }

        return maxi;
    }
};
```

---

# ⭐ Revision Notes

- Window size is fixed = `k`.
- Maintain running window sum.
- Compute average when window reaches size `k`.
- Remove left element before sliding.
- Cast to `double` before division.
- Time → **O(n)**
- Space → **O(1)**

---

# 🧠 Sliding Window Flow

```
Add nums[j]
      ↓
Window Size < k ?
      ↓
Yes → Expand

No
      ↓
Compute Average
      ↓
Update Maximum
      ↓
Remove nums[i]
      ↓
Slide Window
```
