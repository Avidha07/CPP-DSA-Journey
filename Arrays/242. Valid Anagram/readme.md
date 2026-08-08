# 🔤 Valid Anagram

## 📌 Problem Information

| Property       | Details                                                            |
| -------------- | ------------------------------------------------------------------ |
| **Problem**    | Valid Anagram                                                      |
| **LeetCode**   | [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/) |
| **Difficulty** | Easy                                                               |
| **Topic**      | Hashing, Strings, Frequency Counting                               |
| **Language**   | C++17                                                              |

---

## 📝 Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

An **anagram** is a word or string formed by rearranging the characters of another string.

The characters and their frequencies must be exactly the same.

### Example

```text
s = "anagram"
t = "nagaram"

Output: true
```

Because both strings contain:

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

---

# 💡 Intuition

The first thing we should notice is:

> **For two strings to be anagrams, every character must appear the same number of times in both strings.**

For example:

```text
s = "listen"
t = "silent"
```

Both contain:

```text
l → 1
i → 1
s → 1
t → 1
e → 1
n → 1
```

So they are anagrams.

This tells us that we don't really care about the order of characters.

We only care about their **frequency**.

Therefore, we can use an array or hash map to store character frequencies.

---

# 🔍 Observations

### Observation 1

If the lengths are different, the strings cannot be anagrams.

```text
"abc" → length 3
"abcd" → length 4
```

So immediately return `false`.

### Observation 2

The order of characters does not matter.

```text
"abc"
"bca"
"cab"
```

All contain the same characters.

### Observation 3

Character frequency must be exactly the same.

```text
"abb"
"abc"
```

Both have length 3, but their frequencies are different.

So the answer is `false`.

---

# 🐢 Brute Force Approach — Sorting

One simple approach is to sort both strings.

For example:

```text
s = "anagram"
t = "nagaram"

After sorting:

s = "aaagmnr"
t = "aaagmnr"
```

If both sorted strings are equal, they are anagrams.

### Code

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
```

### Complexity

```text
Time:  O(n log n)
Space: O(n)
```

Sorting takes `O(n log n)` time.

---

# 🚀 Optimal Approach — Frequency Counting

Instead of sorting, we can directly count how many times each character appears.

Since the problem uses lowercase English letters, we only need an array of size `26`.

```cpp
int freq[26] = {0};
```

### Step 1

Increase the frequency for every character in `s`.

### Step 2

Decrease the frequency for every character in `t`.

### Step 3

If all frequencies become `0`, both strings contain exactly the same characters.

---

## 🔎 Dry Run

Consider:

```text
s = "abb"
t = "bab"
```

Start:

```text
freq = all 0
```

Process `s`:

```text
a → +1
b → +1
b → +1
```

So:

```text
a = 1
b = 2
```

Process `t`:

```text
b → -1
a → -1
b → -1
```

Now:

```text
a = 0
b = 0
```

All frequencies are zero.

Therefore:

```text
true
```

---

# ⚡ Optimal Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }
};
```

---

# 🧠 Why Does This Work?

Suppose:

```text
s = "aabb"
t = "bbaa"
```

For `s`:

```text
a → +2
b → +2
```

For `t`:

```text
a → -2
b → -2
```

Final:

```text
a → 0
b → 0
```

Every character has the same frequency.

Therefore, the strings are anagrams.

If even one frequency is not `0`, the strings are not anagrams.

---

# 📊 Complexity Comparison

| Approach           |         Time |      Space | Idea             |
| ------------------ | -----------: | ---------: | ---------------- |
| Sorting            | `O(n log n)` |     `O(n)` | Sort and compare |
| Frequency Counting |   **`O(n)`** | **`O(1)`** | Count characters |

### Best Approach

```text
Frequency Counting
       ↓
    O(n) Time
       ↓
    O(1) Space
```

Because the frequency array always has only `26` positions.

---

# ⚠️ Edge Cases

### 1. Both strings are empty

```text
s = ""
t = ""
```

Output:

```text
true
```

---

### 2. Different lengths

```text
s = "abc"
t = "abcd"
```

Output:

```text
false
```

---

### 3. Same characters but different order

```text
s = "abc"
t = "bca"
```

Output:

```text
true
```

---

### 4. Same length but different frequency

```text
s = "aab"
t = "abb"
```

Output:

```text
false
```

---

### 5. Repeated characters

```text
s = "aabbcc"
t = "ccbbaa"
```

Output:

```text
true
```

---

# ❌ Common Mistakes

### Mistake 1: Comparing strings directly

```cpp
return s == t;
```

This is wrong because the order doesn't matter.

```text
"abc" != "bca"
```

But they are anagrams.

---

### Mistake 2: Forgetting the length check

If lengths are different, they cannot be anagrams.

```cpp
if (s.length() != t.length())
    return false;
```

---

### Mistake 3: Using sorting unnecessarily

Sorting works, but it takes:

```text
O(n log n)
```

Frequency counting gives:

```text
O(n)
```

---

# 🎯 Interview Explanation

If the interviewer asks:

**"How would you solve Valid Anagram?"**

You can say:

> First, I check if the lengths of the two strings are different. If they are, they cannot be anagrams. Otherwise, I count the frequency of every character in the first string and decrease the frequency while processing the second string. Finally, if all frequencies are zero, both strings contain exactly the same characters with the same frequency, so they are anagrams.

---

# 🔥 Pattern Recognition

When you see a problem asking:

* Are two strings made of the same characters?
* Do two strings have the same frequency?
* Count occurrences of elements.
* Find elements appearing the same number of times.
* Group strings based on their characters.

Think:

```text
        Frequency?
            ↓
        Hashing
            ↓
   Frequency Counting
```

For **Valid Anagram**, the main pattern is:

> **Hashing + Frequency Counting**

It is **not primarily a Two Pointers problem**.

---

# 🔗 Related Problems

After solving Valid Anagram, practice:

1. **Contains Duplicate** — Hash Set
2. **Two Sum** — Hash Map
3. **Group Anagrams** — Hashing + Frequency
4. **Top K Frequent Elements** — Hashing + Frequency
5. **Find All Anagrams in a String** — Hashing + Sliding Window
6. **Longest Substring Without Repeating Characters** — Hashing + Sliding Window

---

# 💡 Key Learnings

* Anagrams depend on **frequency**, not order.
* Hashing provides fast lookup and counting.
* A frequency array can be better than a hash map when the character range is known.
* Always check the string lengths first.
* Frequency counting can improve the solution from `O(n log n)` to `O(n)`.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        // Count characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Remove characters using t
        for (char c : t) {
            freq[c - 'a']--;
        }

        // Check if all frequencies are zero
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }
};
```

---

# 📝 Revision Notes

### Remember this one line:

> **Anagram = Same characters + Same frequency + Order doesn't matter**

### Pattern:

```text
String
  ↓
Need character frequency
  ↓
Frequency Array / Hash Map
  ↓
Compare frequencies
```

### Complexity:

```text
Time  → O(n)
Space → O(1)
```

---

# 📌 Revision Tracker

* [ ] Understand what an anagram means
* [ ] Understand frequency counting
* [ ] Understand `freq[c - 'a']`
* [ ] Know why length check is required
* [ ] Understand sorting approach
* [ ] Understand optimal hashing approach
* [ ] Solve without looking at the solution
* [ ] Explain the approach in an interview
* [ ] Practice Group Anagrams next
