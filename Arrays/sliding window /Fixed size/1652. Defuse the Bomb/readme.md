# 1652. Defuse the Bomb

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Easy |
| Topic | Arrays |
| Pattern | Sliding Window, Circular Array |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/defuse-the-bomb/ |
| GeeksforGeeks | N/A |
| Companies | Amazon, Microsoft |

---

# 📝 Problem Statement

You are given a **circular array** `code` and an integer `k`.

Replace every element simultaneously according to the following rules:

- If `k > 0`, replace each element with the sum of the **next `k` elements**.
- If `k < 0`, replace each element with the sum of the **previous `|k|` elements**.
- If `k == 0`, replace every element with `0`.

Since the array is circular, moving past the last element continues from the beginning.

Return the decrypted array.

---

# 💡 Intuition

The array is circular, so we cannot use a normal sliding window directly.

Instead:

- Find the first window depending on the value of `k`.
- Compute its sum.
- Slide the window around the circular array using modulo (`% n`).
- Reuse the previous window sum instead of recalculating it every time.

This makes the solution much more efficient.

---

# 👀 Observations

- If `k == 0`, every answer is `0`.
- If `k > 0`, we need the next `k` elements.
- If `k < 0`, we need the previous `|k|` elements.
- Since the array is circular, modulo (`% n`) helps wrap around.
- Adjacent windows overlap heavily, making Sliding Window an ideal approach.

---

# 📋 Constraints

- `1 <= n <= 100`
- `1 <= code[i] <= 100`
- `-(n-1) <= k <= n-1`

Although `n` is small, an optimized solution demonstrates a good understanding of Sliding Window on circular arrays.

---

# 🐢 Approach 1 — Brute Force

## Idea

For every element:

- Traverse the next or previous `|k|` elements.
- Compute their sum.
- Store the answer.

---

## Algorithm

1. Traverse every index.
2. Depending on `k`, move forward or backward.
3. Use modulo to wrap around.
4. Store the sum.

---

## Dry Run

```
code = [5,7,1,4]
k = 3

Index 0

7 + 1 + 4 = 12

Index 1

1 + 4 + 5 = 10

Index 2

4 + 5 + 7 = 16

Index 3

5 + 7 + 1 = 13
```

Answer

```
[12,10,16,13]
```

---

## Time Complexity

```
O(n × |k|)
```

---

## Space Complexity

```
O(n)
```

---

## Why is it inefficient?

For every element, we repeatedly sum the same values, even though consecutive windows overlap.

---

# 🚀 Approach 2 — Optimal (Sliding Window + Circular Array)

## Idea

Instead of recomputing every window:

- Compute the first window sum once.
- Store it.
- Remove one element.
- Add one new element.
- Continue sliding around the circular array.

Modulo arithmetic allows the window to wrap around seamlessly.

---

## Algorithm

1. If `k == 0`, return an array of zeros.
2. Decide the first window:
   - `k > 0`
     - `start = 1`
     - `end = k`
   - `k < 0`
     - `start = n - |k|`
     - `end = n - 1`
3. Compute the first window sum.
4. For every index:
   - Store the current sum.
   - Remove the outgoing element.
   - Add the incoming element.
   - Move both pointers.

---

## Dry Run

### Input

```
code = [5,7,1,4]
k = 3
```

Initial Window

```
7 1 4

Sum = 12
```

Answer

```
res[0] = 12
```

Slide

```
Remove 7
Add 5

1 + 4 + 5 = 10

res[1] = 10
```

Slide

```
Remove 1
Add 7

4 + 5 + 7 = 16

res[2] = 16
```

Slide

```
Remove 4
Add 1

5 + 7 + 1 = 13

res[3] = 13
```

Final Answer

```
[12,10,16,13]
```

---

## Time Complexity

```
O(n)
```

---

## Space Complexity

```
O(n)
```

---

## Why does this approach work?

Adjacent windows differ by only one outgoing and one incoming element.

Instead of summing `k` elements every time:

```
New Sum

=

Previous Sum

- Outgoing Element

+ Incoming Element
```

Each element enters and leaves the window only once, giving an **O(n)** solution.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n × |k|) | O(n) |
| Optimal | O(n) | O(n) |

---

# ⚠️ Edge Cases

- `k = 0`
- `k = 1`
- `k = -1`
- `k = n-1`
- `k = -(n-1)`
- Array size = 1
- Circular wrap-around
- Positive and negative `k`

---

# ❌ Common Mistakes

### Mistake 1

Forgetting to handle `k == 0`.

```cpp
if(k == 0)
    return vector<int>(n,0);
```

Without this case, the window initialization becomes invalid.

---

### Mistake 2

Not using modulo while accessing circular indices.

Wrong

```cpp
code[end + 1]
```

Correct

```cpp
code[(end + 1) % n]
```

---

### Mistake 3

Incorrect initialization for negative `k`.

For previous elements,

```cpp
start = n - abs(k);
end = n - 1;
```

---

### Mistake 4

Recomputing the sum for every position.

Instead, update the window sum using Sliding Window.

---

# 🎤 Interview Explanation

> Since the array is circular, I cannot use a normal sliding window directly. I first determine the initial window depending on whether `k` is positive or negative. After calculating the first window sum, I slide the window by removing the outgoing element and adding the incoming element using modulo arithmetic to wrap around the array. This avoids recalculating sums repeatedly and reduces the complexity from O(n × |k|) to O(n).

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Sliding Window
- ✅ Circular Array
- ✅ Simulation
- Circular fixed-size window.

---


# 📚 Key Learnings

- Sliding Window can also be applied to circular arrays.
- Modulo (`% n`) is essential for wrap-around indexing.
- Reusing the previous window sum reduces time complexity.
- Handle positive and negative window directions separately.
- Always check the `k == 0` case first.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        vector<int> res(n, 0);

        if (k == 0)
            return res;

        int start = 1;
        int end = k;

        if (k < 0) {
            start = n - abs(k);
            end = n - 1;
        }

        int sum = 0;

        for (int i = start; i <= end; i++)
            sum += code[i];

        for (int i = 0; i < n; i++) {

            res[i] = sum;

            sum -= code[start % n];
            sum += code[(end + 1) % n];

            start++;
            end++;
        }

        return res;
    }
};
```

---

# ⭐ Revision Notes

- Circular Array + Sliding Window.
- Handle `k == 0` separately.
- Initialize the first window.
- Positive `k` → next elements.
- Negative `k` → previous elements.
- Use modulo (`% n`) for circular traversal.
- Update the window using:
  - Remove outgoing element.
  - Add incoming element.
- Time → **O(n)**
- Space → **O(n)**

---
