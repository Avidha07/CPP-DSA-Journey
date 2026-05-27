# Reverse String — Interview Questions & Answers

# Basic Questions

---

## 1. Why is the two-pointer approach optimal?

### Answer
The two-pointer approach is optimal because:
- It reverses the string in-place
- Uses constant extra memory
- Performs swapping efficiently

Complexities:
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---

## 2. Why is brute force not preferred?

### Answer
Brute force is not preferred because it uses extra memory to store another array/vector.

Although its time complexity is `O(n)`, the space complexity becomes `O(n)`.

Interviewers usually prefer optimized in-place solutions.

---

## 3. What is meant by in-place reversal?

### Answer
In-place reversal means modifying the original data structure directly without using extra memory proportional to input size.

In this problem, the same array is modified using swapping.

---

## 4. Why does recursion use extra space?

### Answer
Recursion uses extra space because every recursive function call is stored in the call stack.

Even though no extra vector is used, the recursion stack consumes memory.

---

## 5. What is the stopping condition in the two-pointer approach?

### Answer
The loop stops when:
```cpp id="p4wph4"
left >= right
```

At this point, all required swaps are already completed.

---

# Follow-up Questions

---

## 1. Can you reverse a string without using `swap()`?

### Answer
Yes.

We can manually exchange values using a temporary variable.

```cpp id="6bwhxw"
char temp = s[i];
s[i] = s[j];
s[j] = temp;
```

---

## 2. What happens if the input size is very large?

### Answer
For very large inputs:
- Two-pointer approach is preferred because it uses constant memory
- Recursive solutions may cause stack overflow due to deep recursion

---

## 3. Which approach is preferred in interviews and why?

### Answer
The two-pointer approach is preferred because:
- It is optimized
- Uses `O(1)` extra memory
- Demonstrates understanding of in-place algorithms

Using only STL functions may hide problem-solving ability.

---

## 4. How does STL `reverse()` work internally?

### Answer
Internally, STL `reverse()` uses a two-pointer style approach.

It swaps:
- First element ↔ Last element
- Second element ↔ Second last element

until pointers meet.

---

## 5. Can this be solved using stack data structure?

### Answer
Yes.

We can:
1. Push all characters into a stack
2. Pop them back into the array

However:
- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

So it is not optimal.

---

# Additional Interview Insight

## Why does the loop run only till `i < j`?

### Answer
Because once the pointers cross each other:
- All swaps are already completed
- Further swapping would undo previous operations
```
