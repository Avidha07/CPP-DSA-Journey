# 1456. Maximum Number of Vowels in a Substring of Given Length

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Medium |
| Topic | Strings |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/ |
| GeeksforGeeks | N/A |
| Companies | Amazon, Microsoft, Google, Meta, Adobe |

---

# 📝 Problem Statement

Given a string `s` and an integer `k`, find the maximum number of vowels present in any substring of length `k`.

The vowels are:

```
a, e, i, o, u
```

Return the maximum count of vowels among all possible substrings of size `k`.

---

# 💡 Intuition

Since every valid substring has a **fixed length `k`**, this is a classic **Fixed Size Sliding Window** problem.

Instead of counting vowels from scratch for every substring, we maintain the vowel count of the current window.

- Add the new character entering the window.
- Remove the character leaving the window.
- Update the maximum vowel count.

This allows us to solve the problem in linear time.

---

# 👀 Observations

- Every valid substring has exactly `k` characters.
- Only vowels contribute to the answer.
- Adjacent windows overlap by `k - 1` characters.
- We only need to update the count for the entering and leaving characters.

---

# 📋 Constraints

- `1 <= s.length <= 10^5`
- `1 <= k <= s.length`
- String contains only lowercase English letters.

Since `n` can be as large as **100000**, an **O(n × k)** solution will lead to TLE. We need an **O(n)** solution.

---

# 🐢 Approach 1 — Brute Force

## Idea

Generate every substring of length `k`.

For each substring:

- Traverse all `k` characters.
- Count vowels.
- Update the maximum count.

---

## Algorithm

1. Generate every substring of size `k`.
2. Count vowels in the substring.
3. Update the maximum.
4. Return the answer.

---

## Dry Run

```
s = "abciiidef"
k = 3

abc -> 1 vowel

bci -> 1 vowel

cii -> 2 vowels

iii -> 3 vowels

iid -> 2 vowels

ide -> 2 vowels

def -> 1 vowel

Maximum = 3
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

Many characters are counted repeatedly because consecutive substrings overlap.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Maintain a running count of vowels inside the current window.

Whenever:

- A new character enters:
  - Increase the count if it is a vowel.
- The window reaches size `k`:
  - Update the answer.
- Before sliding:
  - Remove the left character if it is a vowel.

Thus, every character is processed only once.

---

## Algorithm

1. Initialize two pointers `i` and `j`.
2. Expand the window.
3. Increase the vowel count if `s[j]` is a vowel.
4. When the window size becomes `k`:
   - Update the maximum.
   - Remove `s[i]` if it is a vowel.
   - Slide the window.

---

## Dry Run

### Input

```
s = "abciiidef"
k = 3
```

### Window 1

```
abc

Vowels = 1

Maximum = 1
```

Slide

```
bci

Vowels = 1
```

Slide

```
cii

Vowels = 2

Maximum = 2
```

Slide

```
iii

Vowels = 3

Maximum = 3
```

Slide

```
iid

Vowels = 2
```

Slide

```
ide

Vowels = 2
```

Slide

```
def

Vowels = 1
```

Final Answer

```
3
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

Instead of recounting vowels in every window, we simply update the current count.

```
New Count

=

Previous Count

+ Entering Character

- Leaving Character
```

Each character:

- Enters the window once.
- Leaves the window once.

Therefore, the total complexity becomes **O(n)**.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-k+1) × k) | O(1) |
| Optimal | O(n) | O(1) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = s.length()`
- String contains no vowels.
- String contains only vowels.
- Single character string.
- Consecutive vowels.

---

# ❌ Common Mistakes

### Mistake 1

Forgetting to remove the left vowel before sliding.

```cpp
cnt--;
```

This should happen only if the outgoing character is a vowel.

---

### Mistake 2

Updating the answer before the window reaches size `k`.

Correct condition:

```cpp
if (j - i + 1 == k)
```

---

### Mistake 3

Checking vowels using multiple comparisons repeatedly.

Instead, you can create a helper function.

```cpp
bool isVowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
```

This improves readability.

---

# 🎤 Interview Explanation

> Since the substring length is fixed, I use the Fixed Size Sliding Window technique. I maintain the count of vowels inside the current window. Whenever a new character enters the window, I increase the count if it is a vowel. When the window size becomes `k`, I update the maximum vowel count. Before sliding the window, I remove the contribution of the leftmost character if it is a vowel. Since every character enters and leaves the window exactly once, the solution runs in O(n) time with O(1) extra space.

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Fixed Size Sliding Window
- ✅ Two Pointers
- ✅ String Traversal

---
# 📚 Key Learnings

- Fixed-size sliding window avoids recomputing values.
- Maintain only the current vowel count.
- Add the entering character.
- Remove the leaving character.
- Each character is processed only once.
- Always update the answer after the window size becomes `k`.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {

        int n = s.length();

        int i = 0, j = 0;

        int cnt = 0;
        int maxi = INT_MIN;

        while (j < n) {

            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
                s[j] == 'o' || s[j] == 'u') {
                cnt++;
            }
            if (j - i + 1 == k) {

                maxi = max(maxi, cnt);

                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                    s[i] == 'o' || s[i] == 'u') {
                    cnt--;
                }

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
- Maintain the count of vowels in the current window.
- Add the entering character.
- Remove the leaving character.
- Update the answer when the window size becomes `k`.
- Time → **O(n)**
- Space → **O(1)**

---
