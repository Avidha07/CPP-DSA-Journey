# 438. Find All Anagrams in a String

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Medium |
| Topic | Strings, Hashing |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/find-all-anagrams-in-a-string/ |

---

# 📝 Problem Statement

Given two strings `s` and `p`, return all the starting indices of substrings in `s` that are anagrams of `p`.

An anagram contains the same characters with exactly the same frequency but possibly in a different order.

---

# 💡 Intuition

An anagram must have:

- Same length as `p`
- Same frequency of every character

Instead of sorting every substring (which is expensive), we can maintain a **fixed-size sliding window** of length `m = p.length()` and compare its character frequencies with the pattern frequency.

Since there are only **26 lowercase letters**, frequency comparison takes constant time.

---

# 👀 Observations

- Every valid substring has length exactly `m`.
- Order of characters doesn't matter.
- Character frequencies determine whether two strings are anagrams.
- Sliding Window avoids recomputing frequencies from scratch.

---

# 📋 Constraints

- `1 <= s.length(), p.length() <= 3 × 10^4`
- Both strings contain lowercase English letters.

These constraints require an **O(n)** solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

Generate every substring of length `m`.

For each substring:

- Count frequencies (or sort).
- Compare with the pattern.

---

## Algorithm

1. Iterate over every possible starting index.
2. Extract substring of length `m`.
3. Count frequencies.
4. Compare with pattern frequency.

---

## Dry Run

```
s = "cbaebabacd"
p = "abc"

Substring "cba" → Valid

Substring "bae" → Invalid

...

Substring "bac" → Valid

Answer = [0,6]
```

---

## Time Complexity

```
O((n-m+1) × m)
```

or

```
O((n-m+1) × m log m)
```

if sorting.

---

## Space Complexity

```
O(26)
```

---

## Why is it inefficient?

We repeatedly calculate frequencies (or sort) for overlapping substrings.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Maintain a sliding window of size `m`.

- Store frequency of pattern.
- Store frequency of current window.
- When window size becomes `m`, compare both frequency arrays.
- Remove left character and continue.

Since alphabet size is fixed (26), comparing two arrays is effectively **O(1)**.

---

## Algorithm

1. Compute frequency of `p`.
2. Expand window using `j`.
3. Add current character into window frequency.
4. When window size becomes `m`:
   - Compare both frequency arrays.
   - If equal, store index.
   - Remove left character.
   - Slide window.

---

## Dry Run

### Input

```
s = "abab"
p = "ab"
```

Pattern Frequency

```
a :1
b :1
```

### Window 1

```
ab

Matches

Answer = [0]
```

Slide

```
Remove 'a'
```

Window

```
ba

Matches

Answer = [0,1]
```

Slide

```
ab

Matches

Answer = [0,1,2]
```

---

## Time Complexity

```
O(n)
```

---

## Space Complexity

```
O(26)
```

---

## Why does this approach work?

Each character enters the window once and leaves once.

The frequency arrays always represent exactly one window of size `m`.

Comparing two arrays of length 26 is constant time.

Hence total complexity is linear.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-m+1) × m) | O(26) |
| Optimal | O(n) | O(26) |

---

# ⚠️ Edge Cases

- `p` longer than `s`
- Strings of length 1
- Duplicate characters
- Entire string is an anagram
- Multiple overlapping anagrams
- No anagram exists

---

# ❌ Common Mistakes

### Mistake 1

Forgetting to remove the leftmost character.

```cpp
windowFreq[s[i]-'a']--;
```

Without this, frequencies keep increasing and comparisons become incorrect.

---

### Mistake 2

Checking frequency before window reaches size `m`.

Always compare only when

```cpp
j - i + 1 == m
```

---

### Mistake 3

Using sorting for every window.

Sorting each substring increases complexity to

```
O(n × m log m)
```

---

# 🎤 Interview Explanation

> Since every anagram must have the same length as `p`, I use a fixed-size sliding window of length `m`. I maintain two frequency arrays—one for the pattern and one for the current window. As the window slides, I add the new character and remove the outgoing character. Whenever the two frequency arrays match, I record the starting index. Because each character is processed only once and frequency comparison is over only 26 letters, the overall complexity is O(n).

---

# 🔍 Pattern Recognition

- ✅ Fixed Size Sliding Window
- ✅ Hashing (Frequency Array)
- ✅ Two Pointers

---


# 📚 Key Learnings

- Fixed-size sliding window is ideal when substring length is fixed.
- Frequency arrays are faster than sorting.
- Frequency comparison is O(1) because alphabet size is constant.
- Always remove the leftmost element before sliding.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<int> res;

        vector<int> windowFreq(26, 0);
        vector<int> patternFreq(26, 0);

        for (int i = 0; i < m; i++)
            patternFreq[p[i] - 'a']++;

        int i = 0, j = 0;

        while (j < n) {

            windowFreq[s[j] - 'a']++;

            if (j - i + 1 == m) {

                if (windowFreq == patternFreq)
                    res.push_back(i);

                windowFreq[s[i] - 'a']--;
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

- Fixed window size = `p.length()`
- Store pattern frequency.
- Store window frequency.
- Compare when window size becomes `m`.
- Remove left character.
- Slide window.
- Time → **O(n)**
- Space → **O(26)**

---

# 🧠 Sliding Window Flow

```
Expand Window
      ↓
Window Size < m ?
      ↓
Yes → Expand

No
      ↓
Compare Frequencies
      ↓
Store Index (if equal)
      ↓
Remove Left Character
      ↓
Slide Window
```
