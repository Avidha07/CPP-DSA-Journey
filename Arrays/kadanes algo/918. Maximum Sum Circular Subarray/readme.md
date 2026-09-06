# Maximum Sum Circular Subarray (LeetCode 918) – Quick Revision

## 1. Two Cases

* **Normal Maximum Subarray** → Kadane's Algorithm
* **Circular Maximum Subarray** → `Total Sum - Minimum Subarray Sum`

> **Final Formula:** `max(maxSum, total - minSum)`

---

## 2. Run Two Kadane Algorithms Together

Update these in the same loop:

* `currMax`, `maxSum` → Maximum Kadane
* `currMin`, `minSum` → Minimum Kadane
* `total` → Total array sum

---

## 3. Initialize Correctly

```cpp
currMax = 0;
currMin = 0;
maxSum = INT_MIN;
minSum = INT_MAX;
```

Avoid initializing `currMax` with `INT_MIN` and `currMin` with `INT_MAX`.

---

## 4. Handle All Negative Elements

```cpp
if (maxSum < 0)
    return maxSum;
```

This prevents returning `0` when every element is negative.

---

## 5. Calculate Circular Answer After the Loop

```cpp
int circular_max = total - minSum;
return max(maxSum, circular_max);
```

Use the **final total sum of the entire array**, not a partial sum inside the loop.
