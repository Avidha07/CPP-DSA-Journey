# 📚 Concepts Behind — Product of Array Except Self

> This file explains the **core concepts** you need to deeply understand this problem.
> Not just *how* to solve it — but *why* the solution works.

---

## 1. What is a Prefix?

A **prefix** means everything that comes **before** a given index.

```
nums  =  [ 1,  2,  3,  4 ]
index =    0   1   2   3

For index 2:
  prefix = all elements before index 2 = [1, 2]
  prefix product = 1 * 2 = 2
```

### Prefix Product Array

`prefix[i]` = product of all elements **before** index `i`

```
nums     = [ 1,  2,  3,  4 ]

prefix[0] = 1          → nothing before index 0, so 1 (identity for multiplication)
prefix[1] = 1          → only nums[0] = 1
prefix[2] = 1 * 2 = 2  → nums[0] * nums[1]
prefix[3] = 1 * 2 * 3 = 6  → nums[0] * nums[1] * nums[2]

prefix   = [ 1,  1,  2,  6 ]
```

### How to Build It

```
prefix[0] = 1                          ← base case (empty product)
prefix[i] = prefix[i-1] * nums[i-1]   ← extend previous prefix by one element
```

```
i=1: prefix[1] = prefix[0] * nums[0] = 1 * 1 = 1
i=2: prefix[2] = prefix[1] * nums[1] = 1 * 2 = 2
i=3: prefix[3] = prefix[2] * nums[2] = 2 * 3 = 6
```

---

## 2. What is a Suffix?

A **suffix** means everything that comes **after** a given index.

```
nums  =  [ 1,  2,  3,  4 ]
index =    0   1   2   3

For index 1:
  suffix = all elements after index 1 = [3, 4]
  suffix product = 3 * 4 = 12
```

### Suffix Product Array

`suffix[i]` = product of all elements **after** index `i`

```
nums     = [ 1,  2,  3,  4 ]

suffix[3] = 1              → nothing after index 3, so 1
suffix[2] = 4              → only nums[3] = 4
suffix[1] = 4 * 3 = 12     → nums[3] * nums[2]
suffix[0] = 4 * 3 * 2 = 24 → nums[3] * nums[2] * nums[1]

suffix   = [24, 12,  4,  1 ]
```

### How to Build It

```
suffix[n-1] = 1                          ← base case (empty product)
suffix[i]   = suffix[i+1] * nums[i+1]   ← extend previous suffix by one element
```

```
i=2: suffix[2] = suffix[3] * nums[3] = 1  * 4 = 4
i=1: suffix[1] = suffix[2] * nums[2] = 4  * 3 = 12
i=0: suffix[0] = suffix[1] * nums[1] = 12 * 2 = 24
```

---

## 3. Why Prefix × Suffix = Answer?

This is the **heart of the problem**.

For any index `i`, we want the product of **all elements except `nums[i]`**.

That means:
- Everything to the **left** of `i`  → that's the **prefix product** at `i`
- Everything to the **right** of `i` → that's the **suffix product** at `i`

```
answer[i] = prefix[i] × suffix[i]
```

### Visual Proof

```
nums   = [ 1,  2,  3,  4 ]
index  =   0   1   2   3

For index i=1 (nums[1] = 2):
  We want: 1 * 3 * 4 = 12

  prefix[1] = product of elements BEFORE index 1 = 1         → [1]
  suffix[1] = product of elements AFTER  index 1 = 3 * 4 = 12 → [3, 4]

  answer[1] = prefix[1] * suffix[1] = 1 * 12 = 12  ✅
```

```
Full table:

index  |  nums  |  prefix  |  suffix  |  answer (p × s)
-------|--------|----------|----------|-----------------
  0    |   1    |    1     |   24     |   1  × 24 = 24
  1    |   2    |    1     |   12     |   1  × 12 = 12
  2    |   3    |    2     |    4     |   2  ×  4 =  8
  3    |   4    |    6     |    1     |   6  ×  1 =  6
```

---

## 4. What is the Identity Element?

You'll notice `prefix[0] = 1` and `suffix[n-1] = 1`.

Why `1` and not `0`?

Because **1 is the identity element for multiplication**:

```
any_number × 1 = any_number
```

When there are no elements to the left (or right), multiplying by `1` means
"there's nothing here — don't affect the result."

If we used `0`, every answer would become `0` — which is wrong.

```
prefix[0] = 1  → "no elements before index 0, so multiply by 1 (do nothing)"
suffix[3] = 1  → "no elements after index 3, so multiply by 1 (do nothing)"
```

---

## 5. Why Not Just Use Division?

The most intuitive idea:
```
totalProduct = 1 * 2 * 3 * 4 = 24
answer[i]    = totalProduct / nums[i]
```

**This fails when zeros are present.**

### Case 1 — One Zero
```
nums = [1, 0, 3, 4]
totalProduct = 0

answer[1] = totalProduct / nums[1] = 0 / 0  ❌ Division by zero!
```

### Case 2 — Two or More Zeros
```
nums = [1, 0, 0, 4]
totalProduct = 0

answer[1] = 0 / 0  ❌
answer[2] = 0 / 0  ❌
```

The **prefix × suffix** approach handles zeros **automatically** with no special cases:
```
nums     = [ 1,  0,  3,  4 ]

prefix   = [ 1,  1,  0,  0 ]
suffix   = [ 0, 12,  4,  1 ]

answer   = [ 0, 12,  0,  0 ]
           ↑
           prefix[0] * suffix[0] = 1 * 0 = 0  ✅ correct
```

---

## 6. Space Optimization — Running Suffix Variable

### The Problem with Two Arrays

Both `prefix` and `suffix` arrays need O(n) extra space.

**Key insight:** We don't need to store the full suffix array.
We only ever use `suffix[i]` once — when computing `answer[i]`.

So instead of storing all suffix values upfront, we can:
1. Store prefix products in the `ans` array (reuse it)
2. Traverse right to left with a **single integer** that accumulates the suffix product on the fly

### How the Running Suffix Works

```
suffix variable starts at 1

Traversing from right to left:

Before visiting index i:
  suffix = product of all elements to the RIGHT of i

At index i:
  ans[i] (already has prefix[i]) *= suffix
  then update: suffix *= nums[i]  ← grow the suffix leftward
```

### Dry Run

```
nums = [1, 2, 3, 4]

After prefix pass:
  ans = [1, 1, 2, 6]

Suffix pass (right to left, suffix starts = 1):

  i=3: ans[3] = 6 * 1  = 6   → suffix = 1  * 4 = 4
  i=2: ans[2] = 2 * 4  = 8   → suffix = 4  * 3 = 12
  i=1: ans[1] = 1 * 12 = 12  → suffix = 12 * 2 = 24
  i=0: ans[0] = 1 * 24 = 24  → suffix = 24 * 1 = 24

Final ans = [24, 12, 8, 6]  ✅
```

> We eliminated the suffix array entirely — just one integer variable.

---

## 7. Two-Pass Technique

This problem is a classic example of the **Two-Pass Technique**:

```
Pass 1 → Left to Right  : collect prefix information into ans[]
Pass 2 → Right to Left  : collect suffix information on the fly, combine with ans[]
```

This pattern appears in many problems:

| Problem | What you collect |
|--------|-----------------|
| Product Except Self | prefix products, suffix products |
| Trapping Rain Water | max height from left, max height from right |
| Sum of Subarray Ranges | prefix max/min |
| Daily Temperatures | traverse with a stack (variation) |

Whenever you see **"for each index, consider everything to its left AND right"** — think Two-Pass.

---

## 8. Concept Summary

| Concept | One-Line Definition |
|---------|---------------------|
| **Prefix Product** | Product of all elements before index `i` |
| **Suffix Product** | Product of all elements after index `i` |
| **Identity Element** | `1` for multiplication — used as the base case |
| **Two-Pass Technique** | Left-to-right pass + Right-to-left pass to avoid O(n²) |
| **Running Variable** | Replace an O(n) array with a single variable updated on the fly |
| **Why no division** | Division breaks when zeros are present in the array |

---

## 9. Mental Model — Think of It as a Split

For any index `i`, imagine splitting the array into two parts:

```
[ ... left side ... ] | i | [ ... right side ... ]
        ↓                          ↓
   prefix product             suffix product
        ↓                          ↓
              multiply both
                   ↓
              answer[i]
```

The element at `i` itself is **excluded** from both sides — that's exactly what we want.
