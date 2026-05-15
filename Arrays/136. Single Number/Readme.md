# 136. Single Number

## 📝 Problem Statement

Given a **non-empty** array of integers `nums`, every element appears **twice** except for one. Find that single one.

> **Constraints:**
> - You must implement a solution with **linear runtime complexity** — `O(n)`
> - You must use only **constant extra space** — `O(1)`

### Examples

```
Input:  nums = [2, 2, 1]
Output: 1

Input:  nums = [4, 1, 2, 1, 2]
Output: 4

Input:  nums = [1]
Output: 1
```

---

## 🧠 Intuition

Every number appears **exactly twice**, except one lonely number. The trick is to find a way to "cancel out" duplicates without using extra memory.

This is where **XOR (⊕)** shines.

---

## 🔑 Key Insight — XOR Properties

XOR has two magical properties for this problem:

| Property | Rule | Example |
|---|---|---|
| **Self-cancellation** | `a ⊕ a = 0` | `5 ⊕ 5 = 0` |
| **Identity** | `a ⊕ 0 = a` | `5 ⊕ 0 = 5` |
| **Commutative** | `a ⊕ b = b ⊕ a` | order doesn't matter |
| **Associative** | `(a ⊕ b) ⊕ c = a ⊕ (b ⊕ c)` | grouping doesn't matter |

Because XOR is both **commutative** and **associative**, duplicates always cancel each other regardless of their position in the array:

```
a ⊕ b ⊕ a  =  (a ⊕ a) ⊕ b  =  0 ⊕ b  =  b
```

### Walkthrough: `[4, 1, 2, 1, 2]`

```
result = 0
result = 0 ⊕ 4  →  4
result = 4 ⊕ 1  →  5
result = 5 ⊕ 2  →  7
result = 7 ⊕ 1  →  6     ← 1 cancels out
result = 6 ⊕ 2  →  4     ← 2 cancels out

Answer: 4 ✅
```

---

## 🚀 Approaches

### 1️⃣ Brute Force — `O(n²)` Time | `O(1)` Space

For every element, count how many times it appears in the array.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j])
                    count++;
            }
            if (count == 1)
                return nums[i];
        }
        return -1;
    }
};
```

**❌ Why this fails the constraint:** Two nested loops give `O(n²)` time — too slow.

---

### 2️⃣ HashMap — `O(n)` Time | `O(n)` Space

Store the frequency of each element in a hash map, then find the one with count = 1.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for (auto it : mp)
            if (it.second == 1)
                return it.first;
        return -1;
    }
};
```

**❌ Why this fails the constraint:** Linear time ✅ but uses `O(n)` extra space for the map ❌.

---

### 3️⃣ ✅ Optimal — XOR Bit Manipulation | `O(n)` Time | `O(1)` Space

XOR every element together. Duplicates cancel out, leaving only the single number.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};
```

**✅ Meets both constraints:** Linear time, constant space. Elegant and fast.

---

## 📊 Complexity Comparison

| Approach | Time | Space | Meets Constraints? |
|---|---|---|---|
| Brute Force | `O(n²)` | `O(1)` | ❌ Time too slow |
| HashMap | `O(n)` | `O(n)` | ❌ Extra space used |
| XOR (Optimal) | `O(n)` | `O(1)` | ✅ |

---

## 🔬 Why XOR Works — Bit-Level View

XOR operates **bit by bit**. For each bit position, if two numbers are the same, both have the same bit → XOR gives `0`. Only the unpaired number contributes a `1`.

```
Example: nums = [1, 3, 1]

  001   (1)
⊕ 011   (3)
⊕ 001   (1)
-------
  011   (3) ← only the unique number remains
```

---

## 💡 Takeaway

> When a problem involves **finding the odd one out** among pairs, think **XOR**.  
> Pairs cancel. The unique survives.

This pattern (XOR to eliminate duplicates) appears in many follow-up problems:
- [137. Single Number II](https://leetcode.com/problems/single-number-ii/) — every element appears 3× except one
- [260. Single Number III](https://leetcode.com/problems/single-number-iii/) — two elements appear once

---

## 🏷️ Tags

`Bit Manipulation` `Array` `XOR` `Hash Table` `Easy`
