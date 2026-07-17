# 1052. Grumpy Bookstore Owner

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Medium |
| Topic | Arrays |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/grumpy-bookstore-owner/ |
| Companies | Amazon, Microsoft, Google, Adobe |

---

# 📝 Problem Statement

A bookstore owner serves customers throughout the day. Some minutes the owner is **grumpy**, causing customers during those minutes to become unsatisfied.

The owner can use a secret technique **exactly once** to stay calm for `minutes` consecutive minutes.

Find the maximum number of customers that can be satisfied after using this technique optimally.

---

# 💡 Intuition

Some customers are **already satisfied** because the owner is not grumpy.

The only thing we need to optimize is:

> Which window of length `minutes` should we choose to convert the **unsatisfied customers into satisfied customers**?

This makes the problem a **Fixed Size Sliding Window** problem.

---

# 👀 Observations

- Customers during non-grumpy minutes are always satisfied.
- The secret technique affects only grumpy minutes.
- We need to maximize the additional satisfied customers.
- Window size is fixed (`minutes`).

---

# 📋 Constraints

- `1 <= minutes <= n <= 2 × 10^4`
- `0 <= customers[i] <= 1000`
- `grumpy[i]` is either `0` or `1`.

Since `n` can be up to `20000`, an **O(n²)** solution is inefficient. We need an **O(n)** approach.

---

# 🐢 Approach 1 — Brute Force

## Idea

Try every possible window of size `minutes`.

For each window:

- Count customers already satisfied.
- Add all grumpy customers inside that window.
- Keep the maximum answer.

---

## Algorithm

1. Compute customers already satisfied.
2. Try every window.
3. Count recoverable customers inside the window.
4. Update the answer.

---

## Dry Run

```
customers = [1,0,1,2,1,1,7,5]
grumpy    = [0,1,0,1,0,1,0,1]
minutes = 3

Try every possible window.

Best window = last 3 minutes

Recovered = 5

Answer = 16
```

---

## Time Complexity

```
O(n × minutes)
```

---

## Space Complexity

```
O(1)
```

---

## Why is it inefficient?

For every window, the recoverable customers are recalculated from scratch.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Split the answer into two parts:

1. **Already satisfied customers**
   - Whenever `grumpy[i] == 0`.

2. **Extra satisfied customers**
   - Customers in grumpy minutes inside a window of size `minutes`.

Use a sliding window to find the maximum recoverable customers.

Final Answer:

```
Already Satisfied + Maximum Recoverable
```

---

## Algorithm

1. Compute customers already satisfied.
2. Maintain a sliding window of size `minutes`.
3. Add customers only if `grumpy[j] == 1`.
4. Remove outgoing grumpy customers while sliding.
5. Track the maximum recoverable customers.
6. Return:

```
alreadySatisfied + maxRecovered
```

---

## Dry Run

### Input

```
customers = [1,0,1,2,1,1,7,5]

grumpy =

[0,1,0,1,0,1,0,1]

minutes = 3
```

Already satisfied:

```
1 + 1 + 1 + 7 = 10
```

Sliding Window (Recovered Customers)

```
Window 1

0 1 0

Recovered = 0

----------------

Window 2

1 0 1

Recovered = 3

----------------

Window 3

0 1 0

Recovered = 3

----------------

Window 4

1 0 1

Recovered = 3

----------------

Window 5

0 1 0

Recovered = 1

----------------

Window 6

1 0 1

Recovered = 6
```

Maximum Recoverable

```
6
```

Final Answer

```
10 + 6 = 16
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

Customers who are already satisfied never change.

The sliding window only computes the **additional customers** that can be recovered by using the secret technique.

Each customer enters and leaves the window exactly once, giving an **O(n)** solution.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n × minutes) | O(1) |
| Optimal | O(n) | O(1) |

---

# ⚠️ Edge Cases

- `minutes = 1`
- `minutes = n`
- All `grumpy = 0`
- All `grumpy = 1`
- Single customer
- Customers with value `0`

---

# ❌ Common Mistakes

### Mistake 1

Adding every customer into the sliding window.

Wrong:

```cpp
window += customers[j];
```

Correct:

```cpp
if(grumpy[j] == 1)
    window += customers[j];
```

---

### Mistake 2

Forgetting to remove the outgoing grumpy customer.

```cpp
if(grumpy[i] == 1)
    window -= customers[i];
```

---

### Mistake 3

Counting already satisfied customers twice.

Always calculate:

```
Already Satisfied

+

Recovered Customers
```

---

# 🎤 Interview Explanation

> I first count the customers who are already satisfied when the owner is not grumpy. Then I use a fixed-size sliding window of length `minutes` to calculate how many additional customers can be satisfied if the owner uses the secret technique during that interval. The window only counts customers from grumpy minutes. The maximum recoverable customers plus the already satisfied customers gives the final answer. Since each element is processed once, the complexity is O(n).

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Fixed Size Sliding Window
- ✅ Arrays
- ✅ Running Sum
- Prefix idea
- Fixed window

---


# 📚 Key Learnings

- Separate the fixed contribution from the variable contribution.
- Use Sliding Window only on the recoverable part.
- Maintain a running sum for the window.
- Fixed-size Sliding Window reduces complexity to **O(n)**.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        int satisfied = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
        }

        int extra = 0;
        int maxExtra = 0;

        int i = 0;

        for (int j = 0; j < n; j++) {

            if (grumpy[j] == 1)
                extra += customers[j];

            if (j - i + 1 > minutes) {
                if (grumpy[i] == 1)
                    extra -= customers[i];
                i++;
            }

            if (j - i + 1 == minutes)
                maxExtra = max(maxExtra, extra);
        }

        return satisfied + maxExtra;
    }
};
```

---

# ⭐ Revision Notes

- Window size = `minutes`.
- Compute already satisfied customers first.
- Sliding window tracks only grumpy customers.
- Keep maximum recoverable customers.
- Final Answer = Already Satisfied + Maximum Recoverable.
- Time → **O(n)**
- Space → **O(1)**

---
