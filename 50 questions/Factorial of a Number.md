# Factorial of a Number

## Problem Statement

Given a number `N`, find the factorial of the number.

The factorial of a number is defined as:

```math
N! = N × (N - 1) × (N - 2) × ... × 2 × 1
```

### Examples

```text
5! = 5 × 4 × 3 × 2 × 1 = 120
0! = 1
```

---

# Approach 1: Iterative Approach

## Intuition

Since factorial is the multiplication of all numbers from `1` to `N`, we can use a loop.

We:
1. Initialize a variable `fact = 1`
2. Run a loop from `1` to `N`
3. Multiply `fact` with every number

At the end, `fact` stores the factorial.

---

## Algorithm

1. Initialize `fact = 1`
2. Loop from `i = 1` to `N`
3. Update:

```cpp
fact = fact * i;
```

4. Return `fact`

---

## Iterative Code (C++)

```cpp
class Solution {
  public:
    int factorial(int n) {

        int fact = 1;

        for(int i = 1; i <= n; i++) {
            fact *= i;
        }

        return fact;
    }
};
```

---

## Dry Run

### Input

```cpp
n = 5
```

| Iteration | i | fact |
|---|---|---|
| Start | - | 1 |
| 1 | 1 | 1 |
| 2 | 2 | 2 |
| 3 | 3 | 6 |
| 4 | 4 | 24 |
| 5 | 5 | 120 |

### Output

```cpp
120
```

---

## Time Complexity

### Iterative Approach
- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Approach 2: Recursive Approach

## Intuition

Factorial can also be defined recursively as:

```math
factorial(N) = N × factorial(N - 1)
```

This means:
- factorial of `N` depends on factorial of `N - 1`

We continue reducing the problem until we reach the base case.

---

## Base Case

```math
0! = 1
```

When `N == 0`, we return `1`.

---

## Recursive Code (C++)

```cpp
class Solution {
  public:
    int factorial(int n) {

        if(n == 0)
            return 1;

        return n * factorial(n - 1);
    }
};
```

---

# Recursion Tree

For `factorial(5)`:

```text
factorial(5)
    |
5 * factorial(4)
        |
    4 * factorial(3)
            |
        3 * factorial(2)
                |
            2 * factorial(1)
                    |
                1 * factorial(0)
                        |
                        1
```

Now recursion starts returning:

```text
1
1 * 1 = 1
2 * 1 = 2
3 * 2 = 6
4 * 6 = 24
5 * 24 = 120
```

---

## Dry Run

### Input

```cpp
n = 4
```

### Function Calls

```cpp
factorial(4)
= 4 * factorial(3)

= 4 * (3 * factorial(2))

= 4 * (3 * (2 * factorial(1)))

= 4 * (3 * (2 * (1 * factorial(0))))

= 4 * (3 * (2 * (1 * 1)))

= 24
```

### Output

```cpp
24
```

---

## Time Complexity

### Recursive Approach
- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`  
  (because of recursion stack)

---

# Comparison of Approaches

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Iterative | O(N) | O(1) |
| Recursive | O(N) | O(N) |

---

# Edge Cases

| Input | Output |
|---|---|
| 0 | 1 |
| 1 | 1 |
| 5 | 120 |
| 7 | 5040 |

---

# Important Notes

- Factorial grows very fast.
- Large factorials may cause integer overflow.
- `int` works only for small values.
- For large values, use:
  - `long long`
  - Big Integer libraries

---

# Interview Questions with Answers

## 1. Why does factorial(0) equal 1?

### Answer
By mathematical definition, `0! = 1`.

It is also required for recursive formulas and combinations to work correctly.

---

## 2. Which approach is better: Iterative or Recursive?

### Answer
The iterative approach is generally better because:
- It uses constant space `O(1)`
- No recursion stack is used
- Faster in practical scenarios

---

## 3. Why does recursion use extra space?

### Answer
Each recursive function call is stored in the call stack.

So for `N` recursive calls, recursion uses `O(N)` stack space.

---

## 4. What is the base condition in recursion?

### Answer

```cpp
if(n == 0)
    return 1;
```

It stops infinite recursive calls.

---

## 5. What happens if the base condition is missing?

### Answer
The recursion will never stop and eventually cause:

```text
Stack Overflow
```

---

## 6. Why is iterative space complexity O(1)?

### Answer
Because only a few variables are used regardless of input size.

---

## 7. Can factorial be calculated for negative numbers?

### Answer
No.

Factorial is defined only for non-negative integers.

---

## 8. Why can factorial overflow quickly?

### Answer
Because factorial grows exponentially fast.

Example:

```text
10! = 3628800
20! = 2432902008176640000
```

---

## 9. What is tail recursion?

### Answer
A recursion where the recursive call is the last operation performed.

Example:

```cpp
return factorial(n - 1, n * ans);
```

Tail recursion can sometimes be optimized by the compiler.

---

## 10. What is the recurrence relation for factorial recursion?

### Answer

```math
T(N) = T(N - 1) + O(1)
```

Which results in:

```text
O(N)
```

---
