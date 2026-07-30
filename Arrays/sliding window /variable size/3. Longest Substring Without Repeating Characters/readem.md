# 3. Longest Substring Without Repeating Characters

> **LeetCode #3**  
> **Difficulty:** Medium  
> **Topics:** Hash Table, String, Sliding Window, Two Pointers  
> **Company Tags:** Amazon, Google, Microsoft, Adobe, Bloomberg, Meta, Apple

---

# 📌 Problem Information

### Problem Name
Longest Substring Without Repeating Characters

### Problem Link
https://leetcode.com/problems/longest-substring-without-repeating-characters/

---

# 📝 Problem Statement

Given a string `s`, return the **length of the longest substring** that contains **no repeating characters**.

A **substring** is a contiguous sequence of characters.

---

# 💡 Intuition

Whenever a problem asks for:

- Longest substring
- Contiguous characters
- No duplicate/repeating characters

it immediately suggests using the **Sliding Window** technique.

The idea is:

- Expand the window by moving the right pointer.
- If a duplicate character appears, shrink the window from the left until the window becomes unique again.
- Keep track of the maximum window size.

---

# 🔍 Observations

- We only care about **contiguous characters**.
- Duplicate characters make the current window invalid.
- A Hash Set efficiently checks whether a character already exists inside the current window.
- Every character is inserted and removed at most once.

---

# 📊 Constraints

- `0 <= s.length <= 10^5`
- `s` consists of:
  - English letters
  - Digits
  - Symbols
  - Spaces

An **O(n²)** solution will result in **TLE**, so an **O(n)** solution is expected.

---

# 🚀 Brute Force Approach

### Idea

Generate every possible substring.

For each substring:

- Check whether all characters are unique.
- Update the maximum length.

### Complexity

**Time:** O(n² × n)

(or O(n³) depending on uniqueness checking)

**Space:** O(n)

### Why it fails?

For `n = 100000`, generating every substring is computationally impossible.

---

# 🚀 Better Approach (Hashing for Every Start)

For every starting index:

- Expand until a duplicate character appears.
- Use a Hash Set to detect duplicates.

Although duplicate detection becomes efficient,

the outer loop still makes the solution **O(n²)**.

---

# ⭐ Optimal Approach (Sliding Window + Hash Set)

### Core Idea

Maintain a window containing only unique characters.

For every new character:

- If it is not already present:
  - Add it to the window.
- Otherwise:
  - Remove characters from the left until the duplicate disappears.
- Update the maximum window size.

---

# 🧠 Algorithm

1. Initialize:
   - `left = 0`
   - `right = 0`
   - Hash Set
   - `maxLength = 0`

2. Expand the window by moving `right`.

3. If the current character already exists:
   - Remove characters from the left.
   - Continue until the duplicate is removed.

4. Insert the current character.

5. Update the maximum window length.

6. Continue until the string ends.

---

# ✨ Dry Run

### Input

```
s = "abcabcbb"
```

Initial

```
Window = ""
Answer = 0
```

Insert 'a'

```
"a"
Length = 1
Answer = 1
```

Insert 'b'

```
"ab"
Length = 2
Answer = 2
```

Insert 'c'

```
"abc"
Length = 3
Answer = 3
```

Next character = 'a'

Duplicate found.

Remove characters until duplicate disappears.

```
Remove 'a'

Window = "bc"
```

Insert 'a'

```
"bca"
Length = 3
```

Continue similarly.

Maximum length remains

```
3
```

---

# 📈 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Insert into Hash Set | O(log n)* |
| Remove from Hash Set | O(log n)* |
| Each character processed at most twice | O(n log n)* |

\*Since this solution uses `set<char>`, insert and erase operations take **O(log n)**.

### Overall (Current Solution)

**Time Complexity**

```
O(n log n)
```

**Space Complexity**

```
O(n)
```

---

# ⚡ Optimization

If we replace `set<char>` with `unordered_set<char>`:

- Insert → O(1)
- Remove → O(1)

Then the overall complexity becomes:

**Time:** O(n)

**Space:** O(n)

This is the commonly expected interview solution.

---

# 📊 Complexity Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n³) | O(n) |
| Better | O(n²) | O(n) |
| Sliding Window + `set` | **O(n log n)** | **O(n)** |
| Sliding Window + `unordered_set` | **O(n)** | **O(n)** |

---

# ⚠️ Edge Cases

### Case 1

```
s = ""
```

Answer = 0

---

### Case 2

```
s = "a"
```

Answer = 1

---

### Case 3

```
s = "aaaa"
```

Answer = 1

---

### Case 4

```
s = "abcdef"
```

Entire string is unique.

Answer = 6

---

### Case 5

```
s = "abba"
```

Duplicate characters appear in between.

Need to shrink carefully.

Answer = 2

---

# ❌ Common Mistakes

### Mistake 1

Using a substring instead of a sliding window.

This leads to unnecessary copying and increases complexity.

---

### Mistake 2

Updating the answer before removing duplicates.

Always make the window valid first.

---

### Mistake 3

Removing only one character when a duplicate is found.

Continue removing until the duplicate disappears.

```cpp
while(st.find(s[j]) != st.end())
```

---

### Mistake 4

Using `unordered_map` incorrectly without updating frequencies.

---

### Mistake 5

Confusing **substring** with **subsequence**.

Substrings are always contiguous.

---

# 🎤 Interview Explanation

> "Since we need the longest contiguous substring with unique characters, I use a variable-size sliding window. A Hash Set stores the characters currently inside the window. As I expand the right pointer, I insert new characters. If a duplicate appears, I shrink the window from the left until the duplicate is removed. After every valid window, I update the maximum length. Each character enters and leaves the window at most once, giving an O(n) solution with an unordered_set."

---

# 🧩 Pattern Recognition

This problem is one of the most famous **Variable Size Sliding Window** problems.

### Keywords

- Longest Substring
- Unique Characters
- No Duplicates
- Contiguous
- Two Pointers
- Hash Set

Whenever you see these keywords,

think:

> **Sliding Window + Hash Set / Hash Map**

---

# 🔗 Related Problems

1. LeetCode 159 - Longest Substring with At Most Two Distinct Characters
2. LeetCode 340 - Longest Substring with At Most K Distinct Characters
3. LeetCode 424 - Longest Repeating Character Replacement
4. LeetCode 904 - Fruit Into Baskets
5. LeetCode 1695 - Maximum Erasure Value
6. LeetCode 1004 - Max Consecutive Ones III

---

# 📚 Key Learnings

- Variable Size Sliding Window.
- Hash Set for duplicate detection.
- Shrink the window only when necessary.
- Each character enters and exits the window once.
- Distinguish between substring and subsequence.
- Prefer `unordered_set` over `set` for O(n) performance.

---

# 💻 C++17 Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int i = 0;
        int j = 0;

        int maxi = 0;

        set<char> st;

        while (j < n) {

            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};
```

---

# ⭐ Interview Optimized Version (O(n))

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

---

# 📝 Revision Notes

✅ Variable Size Sliding Window

✅ Unique characters

✅ Hash Set

✅ Shrink until duplicate disappears

✅ Update maximum window length

**Pattern to Remember**

```
Expand Window
        ↓
Duplicate?
        ↓
Shrink Window
        ↓
Insert Character
        ↓
Update Answer
```

---

# 🔄 Revision Tracker

| Revision | Date | Notes |
|----------|------|-------|
| 1 | ______ | Learned Sliding Window |
| 2 | ______ | Practiced Dry Run |
| 3 | ______ | Solved Without Help |
| 4 | ______ | Interview Revision |

---

# ⭐ Takeaway

This is one of the **most fundamental Sliding Window interview problems**. The key insight is to maintain a window with **only unique characters** and shrink it only when a duplicate appears. With an `unordered_set`, every character is processed at most twice, resulting in an efficient **O(n)** solution.
