# 2269. Find the K-Beauty of a Number

---

# 📌 Problem Information

| Property | Value |
|----------|-------|
| Difficulty | Easy |
| Topic | Strings, Math |
| Pattern | Fixed Size Sliding Window |
| Platform | LeetCode |
| LeetCode | https://leetcode.com/problems/find-the-k-beauty-of-a-number/ |
| GeeksforGeeks | N/A |
| Companies | Google, Amazon |

---

# 📝 Problem Statement

Given an integer `num` and an integer `k`, treat `num` as a string and consider every substring of length `k`.

A substring contributes to the **k-beauty** if:

- Its length is exactly `k`.
- Its integer value is **not zero**.
- It divides `num` exactly.

Return the total number of such substrings.

---

# 💡 Intuition

Since every valid substring has a **fixed length `k`**, we can use a **Fixed Size Sliding Window**.

Instead of generating every substring separately from scratch, we maintain a window of length `k`.

Whenever the window reaches size `k`:

- Convert the substring into an integer.
- Ignore it if it is `0`.
- Otherwise, check if it divides `num`.
- Slide the window by removing the leftmost character.

---

# 👀 Observations

- The number is first converted into a string.
- Every valid substring has exactly `k` characters.
- Leading zeros are allowed.
- `"00"` becomes `0`, which is **not** a valid divisor.
- Every substring needs only one divisibility check.

---

# 📋 Constraints

- `1 <= num <= 10^9`
- `1 <= k <= length(num)`

The number contains at most **10 digits**, so even converting each window into an integer is efficient.

---

# 🐢 Approach 1 — Brute Force

## Idea

Generate every substring of length `k`.

For every substring:

- Convert it into an integer.
- Ignore if the value is `0`.
- Check whether it divides `num`.

---

## Algorithm

1. Convert `num` into a string.
2. Generate every substring of size `k`.
3. Convert it to an integer.
4. Check divisibility.
5. Count valid substrings.

---

## Dry Run

```
num = 240
k = 2

Substrings

24 → divides 240 ✅

40 → divides 240 ✅

Answer = 2
```

---

## Time Complexity

```
O((n-k+1) × k)
```

where `n` is the number of digits.

---

## Space Complexity

```
O(k)
```

---

## Why is it inefficient?

A new substring is created for every window, causing repeated copying of characters.

---

# 🚀 Approach 2 — Optimal (Sliding Window)

## Idea

Maintain a string representing the current window.

For every new character:

- Add it to the window.
- Once the window size becomes `k`:
  - Convert it to an integer.
  - Check divisibility.
  - Remove the leftmost character.
  - Slide forward.

This avoids reconstructing the window from scratch.

---

## Algorithm

1. Convert `num` into a string.
2. Maintain a sliding window string.
3. Append the new character.
4. When the window size becomes `k`:
   - Convert using `stoi()`.
   - Check `digit != 0`.
   - Check `num % digit == 0`.
   - Increment answer if valid.
   - Remove the first character.
5. Continue until the end.

---

## Dry Run

### Input

```
num = 430043
k = 2
```

Window

```
43

43 divides num

Count = 1
```

Slide

```
30

430043 % 30 != 0

Count = 1
```

Slide

```
00

Value = 0

Ignore
```

Slide

```
04

Value = 4

Not divisible
```

Slide

```
43

Divides

Count = 2
```

Final Answer

```
2
```

---

## Time Complexity

```
O(n × k)
```

Since `k ≤ 10`, this is effectively **O(n)**.

---

## Space Complexity

```
O(k)
```

---

## Why does this approach work?

The window always contains exactly `k` characters.

Instead of recreating every substring, we:

- Add one new character.
- Remove one old character.

Each window is processed exactly once.

---

# ⚖️ Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O((n-k+1) × k) | O(k) |
| Optimal (Sliding Window) | O(n × k) | O(k) |

---

# ⚠️ Edge Cases

- `k = 1`
- `k = length(num)`
- Substring value is `0`
- Leading zeros (`"04"`, `"00"`)
- Entire number is the substring
- No substring divides `num`

---

# ❌ Common Mistakes

### Mistake 1

Not checking for zero before division.

```cpp
num % digit
```

If `digit == 0`, this causes a division-by-zero error.

Correct:

```cpp
if (digit != 0 && num % digit == 0)
```

---

### Mistake 2

Forgetting to remove the first character.

```cpp
s.erase(0,1);
```

Without removing it, the window size keeps increasing.

---

### Mistake 3

Using substring creation every time.

```cpp
str.substr(i, k)
```

This repeatedly allocates memory.

Maintaining a sliding window string is cleaner.

---

# 🎤 Interview Explanation

> Since every valid substring has a fixed length `k`, I use the Fixed Size Sliding Window technique. I convert the integer into a string and maintain a window of length `k`. Whenever the window reaches size `k`, I convert it to an integer using `stoi()`. If the value is non-zero and divides the original number, I increment the answer. Then I remove the leftmost character and continue sliding the window. Because each digit enters and leaves the window once, the solution is efficient.

---

# 🔍 Pattern Recognition

This problem belongs to:

- ✅ Fixed Size Sliding Window
- ✅ String Traversal
- ✅ Math

---


### Easy

- 643. Maximum Average Subarray I
- 1456. Maximum Number of Vowels in a Substring of Given Length

### Medium

- 438. Find All Anagrams in a String
- 1052. Grumpy Bookstore Owner

### Hard

- 239. Sliding Window Maximum

---

# 📚 Key Learnings

- Convert integers into strings for substring problems.
- Sliding Window is useful even on strings representing numbers.
- Always check for division by zero.
- Leading zeros are valid while parsing.
- `stoi("04")` correctly returns `4`.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int divisorSubstrings(int num, int k) {

        string str = to_string(num);

        int n = str.length();

        int cnt = 0;
        int i = 0, j = 0;

        string window = "";

        while (j < n) {

            window += str[j];

            if (j - i + 1 == k) {

                int digit = stoi(window);

                if (digit != 0 && num % digit == 0)
                    cnt++;

                window.erase(0, 1);

                i++;
            }

            j++;
        }

        return cnt;
    }
};
```

---

# ⭐ Revision Notes

- Convert number to string.
- Window size = `k`.
- Maintain a sliding window string.
- Convert using `stoi()`.
- Ignore `0`.
- Check divisibility.
- Remove first character before sliding.
- Time → **O(n × k)** *(effectively O(n) since `k ≤ 10`)*
- Space → **O(k)**

---
