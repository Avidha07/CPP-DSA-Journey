# 2024. Maximize the Confusion of an Exam

## 📌 Problem Information

| Property | Value |
|----------|--------|
| **Problem Name** | Maximize the Confusion of an Exam |
| **Problem Number** | 2024 |
| **Difficulty** | Medium |
| **Topics** | Sliding Window, Two Pointers, Hash Map, String |
| **Platform** | LeetCode |
| **LeetCode Link** | https://leetcode.com/problems/maximize-the-confusion-of-an-exam/ |

---

# 📝 Problem Statement

A teacher is preparing a True/False exam represented by a string `answerKey`, where:

- `'T'` → True
- `'F'` → False

You can change the answer of **at most `k` questions**.

Your goal is to maximize the length of the **longest consecutive sequence containing the same answer** (all `'T'` or all `'F'`).

Return the maximum possible length.

---

# 💡 Intuition

For every window, we want to know:

> **Can this entire window be converted into one single character using at most `k` flips?**

Inside a window,

- Keep the majority character unchanged.
- Flip every other character.

Therefore,

```
Required Flips = Window Size - Maximum Frequency
```

If the required flips exceed `k`, the current window is invalid and must be shrunk.

---

# 🔍 Observations

- Only two characters exist: `'T'` and `'F'`.
- The majority character should never be flipped.
- The minority characters are the only ones that need changing.
- Sliding Window efficiently finds the longest valid window.

---

# 📌 Constraints

- `1 <= answerKey.length <= 5 × 10⁴`
- `answerKey[i]` is either `'T'` or `'F'`
- `1 <= k <= n`

These constraints require an **O(n)** solution.

---

# ❌ Brute Force Approach

### Idea

Generate every possible substring.

For every substring:

1. Count the number of `'T'`.
2. Count the number of `'F'`.
3. Calculate

```
Required Flips = min(T, F)
```

If the required flips are at most `k`, update the answer.

### Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)`

**Why not optimal?**

Every substring is checked separately, making it too slow for large inputs.

---

# ⚡ Better Approach (Prefix Counts)

Store prefix frequencies of `'T'` and `'F'`.

This speeds up frequency calculation, but every substring is still examined.

### Complexity

- **Time:** `O(n²)`
- **Space:** `O(n)`

Still not efficient enough.

---

# ✅ Optimal Approach (Sliding Window)

Maintain a variable-size sliding window.

For every character:

1. Expand the window.
2. Update the frequency map.
3. Maintain the highest frequency (`maxFreq`).
4. Calculate

```
Window Size - maxFreq
```

If this value exceeds `k`, shrink the window from the left.

The largest valid window is the answer.

---

# 🧠 Why `Window Size - maxFreq`?

Suppose the current window is

```
TTFTTTF
```

Frequency:

```
T = 5
F = 2
```

To make every character equal,

```
TTTTTTT
```

Only the two `'F'` characters need to be changed.

Therefore,

```
Required Flips

= Window Size - Frequency of Majority Character

= 7 - 5

= 2
```

This logic works for every window.

---

# 🪟 Sliding Window Dry Run

### Example

```
answerKey = "TFFT"
k = 1
```

### Step 1

```
Window = T

T = 1
F = 0

Required Flips = 0

Valid
```

Answer = 1

---

### Step 2

```
Window = TF

T = 1
F = 1

Required Flips = 1

Valid
```

Answer = 2

---

### Step 3

```
Window = TFF

T = 1
F = 2

Required Flips = 1

Valid
```

Answer = 3

---

### Step 4

```
Window = TFFT

T = 2
F = 2

Required Flips = 2

Invalid
```

Shrink from the left.

New Window:

```
FFT

T = 1
F = 2

Required Flips = 1

Valid
```

Maximum answer remains **3**.

---

# ❓ Why Don't We Decrease `maxFreq` While Shrinking?

This is a very common interview question.

Suppose

```
TTTTFFFF
```

Initially,

```
maxFreq = 4
```

After shrinking,

Actual frequencies may become

```
T = 2
F = 3
```

Yet `maxFreq` still remains **4**.

Isn't that incorrect?

**No.**

Keeping a stale `maxFreq` never affects the final answer.

Why?

- Every character enters the window once.
- Every character leaves the window once.
- The window eventually shrinks whenever it truly becomes invalid.
- We never miss the optimal answer.

This trick keeps the algorithm **O(n)**.

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Prefix Frequency | O(n²) | O(n) |
| Sliding Window | **O(n)** | **O(1)** |

---

# ⚠️ Edge Cases

### Single Character

```
T
```

Answer = **1**

---

### Entire String Already Same

```
TTTTTT
```

Answer = **6**

---

### Alternate Characters

```
TFTFTF
```

With large `k`, the entire string becomes identical.

---

### No Flip Allowed

```
TTTT
k = 0
```

Answer = **4**

---

### k Greater Than Required Flips

```
TFTFTF
k = 6
```

Entire string can be converted.

Answer = **6**

---

# 🚨 Common Mistakes

### ❌ Forgetting to shrink the window

Always shrink while

```cpp
(windowSize - maxFreq) > k
```

---

### ❌ Updating answer before making the window valid

Update `maxLen` **after** shrinking.

---

### ❌ Recomputing maximum frequency every time

Not required.

A stale `maxFreq` still gives the correct answer.

---

### ❌ Thinking only about converting to `'T'`

The window may become entirely `'T'` **or** entirely `'F'`.

Always choose the cheaper conversion.

---

# 🎤 Interview Explanation

> "I use a variable-size sliding window. For every window, I maintain the frequency of both characters and keep track of the maximum frequency. The number of flips required is `windowSize - maxFreq` because only the minority characters need to be changed. Whenever this exceeds `k`, I shrink the window from the left. Since every character enters and leaves the window at most once, the overall complexity is O(n)."

---

# 🧩 Pattern Recognition

This problem belongs to the **Variable Size Sliding Window** pattern.

Whenever you see:

- Longest substring
- At most K replacements
- Maximum consecutive characters
- Longest valid window

Think of this pattern.

---

# 📚 Key Learnings

- Variable Size Sliding Window.
- Majority frequency determines minimum replacements.
- Required flips = `Window Size - maxFreq`.
- Never recompute `maxFreq` while shrinking.
- Every element is processed at most twice.
- Time Complexity is linear.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();

        int i = 0;
        int maxLen = 0;
        int maxFreq = 0;

        unordered_map<char, int> freq;

        for (int j = 0; j < n; j++) {

            freq[answerKey[j]]++;

            maxFreq = max(maxFreq, freq[answerKey[j]]);

            while ((j - i + 1) - maxFreq > k) {
                freq[answerKey[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
```

---

# 📝 Revision Notes

- Variable Size Sliding Window.
- Maintain character frequencies.
- Keep track of the majority character.
- Required Flips = Window Size − Maximum Frequency.
- Shrink whenever flips exceed `k`.
- Never decrease `maxFreq` while shrinking.
- Similar to **LeetCode 424**.

---

# 🔄 Revision Tracker

## First Revision

- Understand why `Window Size - maxFreq` works.
- Practice the shrinking condition.
- Dry run one example.

---

## Second Revision

- Solve without looking at notes.
- Explain why stale `maxFreq` is valid.
- Explain time complexity.

---

## Third Revision

- Recognize this as a Variable Size Sliding Window problem.
- Compare it with LeetCode 424 and 1004.
- Be able to derive the solution in an interview within 5 minutes.
