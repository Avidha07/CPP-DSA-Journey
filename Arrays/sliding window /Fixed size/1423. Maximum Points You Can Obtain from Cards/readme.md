# 1423. Maximum Points You Can Obtain from Cards

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Medium |
| Topic | Arrays |
| Pattern | Sliding Window, Prefix & Suffix |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ |
| Companies | Amazon, Google, Microsoft, Adobe |

---

# 📝 Problem Statement

You are given an array `cardPoints`, where each element represents the points on a card.

You must pick **exactly `k` cards**, and in each move, you can choose a card **only from the beginning or the end** of the array.

Return the **maximum score** that can be obtained.

---

# 💡 Intuition

At first glance, choosing from both ends seems complicated.

Instead of deciding which cards to take, think about **which cards are left behind**.

If we take exactly `k` cards, then **`n - k` consecutive cards remain untouched**.

Another equivalent approach (used in your solution) is:

- Initially take all `k` cards from the **right end**.
- Gradually replace one right card with one left card.
- Keep track of the maximum score.

This transforms the problem into a **Sliding Window** problem.

---

# 👀 Observations

- We can only pick cards from the two ends.
- Every valid selection consists of:
  - Some cards from the left.
  - Remaining cards from the right.
- There are only `k + 1` possible combinations.
- Sliding Window allows us to evaluate each combination in **O(1)** time after initialization.

---

# 📋 Constraints

- `1 <= cardPoints.length <= 10^5`
- `1 <= cardPoints[i] <= 10^4`
- `1 <= k <= n`

Since `n` can be as large as `100000`, an **O(n²)** approach is not feasible. We need an **O(n)** or better solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

Try every possible way to take:

- `0` cards from the left and `k` from the right.
- `1` from the left and `k-1` from the right.
- `2` from the left and `k-2` from the right.
- ...
- `k` from the left and `0` from the right.

For every combination, compute the score from scratch.

---

## Algorithm

1. Generate every possible split.
2. Compute the total score.
3. Keep the maximum score.

---

## Dry Run

```
cardPoints = [1,2,3,4,5,6,1]
k = 3

Take:

0 Left + 3 Right = 12

1 Left + 2 Right = 8

2 Left + 1 Right = 4

3 Left + 0 Right = 6

Maximum = 12
```

---

## Time Complexity

```
O(k²)
```

---

## Space Complexity

```
O(1)
```

---

## Why is it inefficient?

The score is recomputed for every combination, leading to unnecessary repeated calculations.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Start with all `k` cards taken from the **right side**.

Then repeatedly:

- Remove one card from the right.
- Add one card from the left.

This efficiently explores every possible combination of taking cards from both ends.

Maintain the maximum score throughout.

---

## Algorithm

1. Compute the sum of the last `k` cards.
2. Store it as the initial answer.
3. Repeat `k` times:
   - Remove one card from the right.
   - Add one card from the left.
   - Update the maximum score.
4. Return the maximum.

---

## Dry Run

### Input

```
cardPoints = [1,2,3,4,5,6,1]
k = 3
```

Initial

```
Take last 3 cards

[5,6,1]

Sum = 12

Maximum = 12
```

Slide

```
Remove 5

Add 1

Sum = 8
```

Slide

```
Remove 6

Add 2

Sum = 4
```

Slide

```
Remove 1

Add 3

Sum = 6
```

Maximum

```
12
```

---

## Time Complexity

```
O(k)
```

Since `k ≤ n`, the worst-case complexity is **O(n)**.

---

## Space Complexity

```
O(1)
```

---

## Why does this approach work?

There are exactly **`k + 1`** possible ways to choose cards from both ends.

Instead of recomputing each score:

```
New Score

=

Previous Score

- Right Card

+ Left Card
```

Each card is added and removed at most once, making the solution efficient.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(k²) | O(1) |
| Optimal (Sliding Window) | O(k) *(Worst Case O(n))* | O(1) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = n`
- All cards have the same value.
- Single card.
- Maximum value cards on one side.
- Maximum value cards split between both ends.

---

# ❌ Common Mistakes

### Mistake 1

Forgetting to handle:

```cpp
k == n
```

In this case, all cards are selected.

```cpp
if (k == n)
    return totalSum;
```

---

### Mistake 2

Incorrect initial window.

The first window should contain the **last `k` cards**.

```cpp
start = n - k;
```

---

### Mistake 3

Updating pointers in the wrong order.

Correct order:

```cpp
sum -= cardPoints[start];
sum += cardPoints[left];
```

Then move pointers.

---

### Mistake 4

Trying every combination recursively.

This leads to exponential complexity.

---

# 🎤 Interview Explanation

> Although the problem allows taking cards from both ends, there are only `k + 1` possible ways to split the selection between the left and right sides. I first take all `k` cards from the right and compute their sum. Then, one by one, I replace a card from the right with a card from the left, updating the score in O(1) time. By evaluating all possible splits, I obtain the maximum score. The algorithm runs in O(k) time and uses O(1) extra space.

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Sliding Window
- ✅ Prefix & Suffix
- ✅ Two Pointers

---

# 📚 Key Learnings

- Problems involving picking from both ends often have an equivalent sliding window solution.
- Think in terms of **left picks + right picks**.
- Initialize with one extreme case and slide toward the other.
- Maintain a running sum instead of recomputing scores.
- Time complexity depends on `k`, not `n`.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int start = n - k;
        int end = n - 1;

        int sum = 0;

        for (int i = start; i <= end; i++)
            sum += cardPoints[i];

        if (k == n)
            return sum;

        int maxi = sum;

        int left = 0;

        while (left < k) {

            sum -= cardPoints[start];
            sum += cardPoints[left];

            maxi = max(maxi, sum);

            start++;
            left++;
        }

        return maxi;
    }
};
```

---

# ⭐ Revision Notes

- Picking from both ends = `k + 1` possible combinations.
- Start with all `k` cards from the right.
- Replace one right card with one left card.
- Maintain a running sum.
- Update the maximum score.
- Time → **O(k)** *(Worst Case O(n))*
- Space → **O(1)**

---
