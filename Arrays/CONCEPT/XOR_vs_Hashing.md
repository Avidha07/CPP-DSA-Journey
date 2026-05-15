# ⚡ XOR vs Hashing — Pattern Recognition Guide

## 🔍 Mini Comparison

| Problem Type | Best Technique |
|---|---|
| Duplicate detection | Hash Set |
| Frequency count | Hash Map |
| Single unique element | XOR |
| Missing number | XOR / Sum |
| Pair lookup | Hashing |

---

## 🧠 Pattern Recognition Rule

### Use XOR When:
- Pairs cancel each other out
- One unique element remains
- Bit manipulation is useful
- Frequency pattern is fixed

### Use Hashing When:
- Need existence check
- Duplicate detection
- Frequency counting
- Quick lookup

---

## 🔧 Quick Examples

### XOR — Find the single unique element
```python
def find_unique(nums):
    result = 0
    for n in nums:
        result ^= n
    return result

# [1, 2, 1] → 2 (pairs cancel, unique remains)
```

### XOR — Find missing number (0 to n)
```python
def missing_number(nums):
    n = len(nums)
    xor = 0
    for i in range(n + 1):
        xor ^= i
    for num in nums:
        xor ^= num
    return xor
```

### Hash Set — Duplicate detection
```python
def has_duplicate(nums):
    seen = set()
    for n in nums:
        if n in seen:
            return True
        seen.add(n)
    return False
```

### Hash Map — Frequency count
```python
def count_frequency(nums):
    freq = {}
    for n in nums:
        freq[n] = freq.get(n, 0) + 1
    return freq
```

### Hash Map — Pair lookup (Two Sum)
```python
def two_sum(nums, target):
    seen = {}
    for i, n in enumerate(nums):
        complement = target - n
        if complement in seen:
            return [seen[complement], i]
        seen[n] = i
```

---

## ⏱️ Complexity at a Glance

| Technique | Time | Space | Best For |
|---|---|---|---|
| XOR | O(n) | O(1) | Fixed-pattern problems |
| Hash Set | O(n) | O(n) | Existence / duplicate check |
| Hash Map | O(n) | O(n) | Frequency / pair lookup |

---

## 💡 Decision Flowchart

```
Is the problem about a SINGLE unique or missing value?
    └── AND input has fixed pair structure?
            YES → XOR  (O(1) space!)
            NO  → Hashing

Do you need to CHECK existence or COUNT occurrences?
    └── Existence only     → Hash Set
        Count / frequency  → Hash Map
        Pair / complement  → Hash Map
```

---

> **Rule of Thumb:** Reach for XOR when constraints are tight and pairs cancel. Reach for Hashing when you need flexibility, frequency, or fast lookup.
