# 📈 Best Time to Buy and Sell Stock

> **LeetCode #121** | Difficulty: 🟢 Easy | Topic: Arrays, Greedy, Sliding Window

---

## 📌 Problem Statement

Given an array `prices[]` where `prices[i]` is the price of a stock on day `i`, find the **maximum profit** you can achieve by buying on one day and selling on a later day.

- You must buy **before** you sell.
- If no profit is possible, return `0`.

**Example:**
```
Input:  prices = [7, 1, 5, 3, 6, 4]
Output: 5
Explanation: Buy on day 2 (price=1), sell on day 5 (price=6) → profit = 5
```

---

## 💡 One-Line Interview Answer

> *"Track the minimum price seen so far and keep updating the maximum profit as you iterate — it's a single-pass greedy approach."*

---

## 🔴 Approach 1: Brute Force

### Intuition
Try every possible **(buy, sell)** pair and return the maximum profit found.

### Code (C++)
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        for (int i = 0; i < prices.size(); i++) {
            int profit = 0;
            for (int j = i + 1; j < prices.size(); j++) {
                profit = prices[j] - prices[i];
                maxi = max(profit, maxi);
            }
        }
        return maxi;
    }
};
```

### How It Works
- Outer loop → considers every day as a **buy day**
- Inner loop → considers every future day as a **sell day**
- Calculate profit for each **(buy, sell)** pair
- Track the maximum profit seen

### Complexity
| | Complexity |
|---|---|
| ⏱ Time | **O(n²)** — nested loops over all pairs |
| 🗂 Space | **O(1)** — only variables used |

### ❌ Why It's Not Optimal
For large inputs (e.g., n = 10⁵), O(n²) = 10¹⁰ operations → **TLE (Time Limit Exceeded)**.

---

## 🟢 Approach 2: Optimal — Single Pass (Greedy)

### Intuition
Instead of checking every pair, ask two questions at each step:
1. Is today's price the **lowest** we've seen? → update `mini`
2. If we sold today at the best price we could have bought, is it the **best profit** so far? → update `profit`

We simulate a smart investor who always buys at the historically lowest point and evaluates selling every single day.

### Code (C++)
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
```

### Step-by-Step Dry Run
```
prices = [7, 1, 5, 3, 6, 4]

Day 0: price=7, mini=7, cost=0,  profit=0
Day 1: price=1, mini=1, cost=0,  profit=0
Day 2: price=5, mini=1, cost=4,  profit=4
Day 3: price=3, mini=1, cost=2,  profit=4
Day 4: price=6, mini=1, cost=5,  profit=5  ✅
Day 5: price=4, mini=1, cost=3,  profit=5

Answer: 5
```

### Complexity
| | Complexity |
|---|---|
| ⏱ Time | **O(n)** — single pass through the array |
| 🗂 Space | **O(1)** — only two variables used |

---

## ⚔️ Brute Force vs Optimal — Comparison

| | Brute Force | Optimal |
|---|---|---|
| Approach | Try all pairs | Greedy, single pass |
| Time | O(n²) | O(n) |
| Space | O(1) | O(1) |
| Passes on LeetCode | ❌ TLE for large n | ✅ Accepted |
| Intuition | Exhaustive search | Track min & max profit live |

---

## 🧠 Key Learnings

### 1. 🔑 Greedy Thinking
You don't need to check all pairs. Buying at the **global minimum** before selling is always optimal — greedy works here because a past decision (buying low) only helps future decisions (selling higher).

### 2. 🔁 The "Track Min So Far" Pattern
This pattern appears in many array problems:
- Always maintain a running minimum (or maximum) as you scan.
- Use it to compute the best possible outcome at each step.

### 3. 🪟 Sliding Window Mindset
This problem is a gentle introduction to the **sliding window** concept — maintaining a window of useful state (here: the minimum price) while scanning once.

### 4. ⚠️ Edge Cases to Handle
- All prices decreasing → no profit possible → return `0`
- Only one price in array → can't sell → return `0`
- All prices the same → profit = `0`

### 5. 🔗 Related Problems (Level Up)
| Problem | Twist |
|---|---|
| LC #122 — Buy & Sell Stock II | Multiple transactions allowed |
| LC #123 — Buy & Sell Stock III | At most 2 transactions |
| LC #188 — Buy & Sell Stock IV | At most k transactions |
| LC #309 — With Cooldown | Must wait 1 day after selling |
| LC #714 — With Transaction Fee | Fee charged on each transaction |

---

## 🗣️ How to Explain in an Interview

1. **Clarify** → "Can I buy and sell on the same day? No. Only one transaction?"
2. **Brute Force** → "The naive approach checks every pair — O(n²)."
3. **Optimize** → "We can do it in one pass: track the minimum price so far and update max profit at every step."
4. **Trace** → Walk through the dry run above.
5. **Complexity** → "O(n) time, O(1) space."
6. **Edge cases** → "Handled — if prices always drop, profit stays 0."

---

## 📁 Files

```
📂 best-time-to-buy-sell-stock/
├── brute_force.cpp
├── optimal.cpp
└── README.md
```

---

<div align="center">
  <sub>⭐ Star this repo if it helped you | 💬 Open an issue for questions</sub>
</div>
