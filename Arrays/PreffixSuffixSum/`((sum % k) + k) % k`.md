# Why do we write `((sum % k) + k) % k`?

This is one of the most important lines in problems like **LeetCode 974 (Subarray Sums Divisible by K)**.

```cpp
rem = ((sum % k) + k) % k;
```

Its purpose is simple:

> Always convert the remainder into the range `0` to `k-1`, even when `sum` becomes negative.

---

## Why is this needed?

Different programming languages handle the `%` (modulo) operator differently.

When the dividend is negative, some languages return a negative remainder, while others always return a positive one.

---

## Example

Suppose:

```text
sum = -2
k = 5
```

### C++

```cpp
-2 % 5 = -2
```

### Java

```java
-2 % 5 = -2
```

### JavaScript

```javascript
-2 % 5 = -2
```

A negative remainder creates problems because remainders are used as keys in a hash map.

Instead of storing `-2`, we want the equivalent positive remainder.

---

## Normalization

```cpp
((sum % k) + k) % k
```

Step by step:

| Step | Value |
|------|-------|
| `sum % k` | `-2` |
| `-2 + 5` | `3` |
| `3 % 5` | `3` |

Final remainder:

```text
3
```

Now every remainder stays inside:

```text
0, 1, 2, ..., k-1
```

---

## What about Python?

Python already handles modulo differently.

```python
-2 % 5
```

Output:

```text
3
```

So Python automatically returns the positive equivalent.

No normalization is needed.

---

## Language Comparison

| Language | `-2 % 5` | Need `((x%k)+k)%k`? |
|----------|----------|----------------------|
| C++ | `-2` | Yes |
| Java | `-2` | Yes |
| JavaScript | `-2` | Yes |
| C | `-2` | Yes |
| C# | `-2` | Yes |
| Go | `-2` | Yes |
| Python | `3` | No |
| Ruby | `3` | No |

---

## Rule to Remember

- **C++, Java, JavaScript, C, C#, Go:** Normalize the remainder.
- **Python and Ruby:** No normalization required.

### Interview Tip

If you're solving **LeetCode 974** in C++ or Java, always write:

```cpp
rem = ((sum % k) + k) % k;
```

It prevents negative remainder bugs and ensures all equivalent remainders map to the same hash map key.
