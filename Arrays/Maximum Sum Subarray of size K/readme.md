# Sliding Window Technique

The Sliding Window Technique is an optimization approach used mainly for problems involving:

- Arrays
- Strings
- Subarrays
- Substrings

Instead of recalculating values repeatedly, we maintain a **window** and slide it efficiently across the data structure.

---

# 1. What is Sliding Window?

Sliding Window is a technique where we maintain a range (window) using two pointers and move it efficiently to reduce unnecessary computations.

It is mainly used when:

- We need to process contiguous elements
- We have a fixed window size `k`
- We need optimized subarray or substring calculations

---

# 2. Identification of Sliding Window Problems

## Fixed Size Sliding Window Identification

If the problem contains:

- Array or String
- Subarray or Substring
- Fixed Window Size `k`

then we can usually solve it using the **Fixed Size Sliding Window** technique.

---

## Identification Formula

```text
Array/String
+
Subarray/Substring
+
Window Size (Fixed) or Some Condition
```

---

# 3. Problem Statement

## Maximum Sum Subarray of Size K

Given:

```text
arr[] = [2, 5, 1, 8, 2, 9, 1]
k = 3
```

Find:

```text
Maximum sum among all subarrays of size k
```

---

# 4. Understanding the Problem

Possible subarrays of size `3`:

| Subarray | Sum |
|----------|-----|
| [2,5,1] | 8 |
| [5,1,8] | 14 |
| [1,8,2] | 11 |
| [8,2,9] | 19 |
| [2,9,1] | 12 |

Maximum = `19`

---

# 5. Brute Force Approach

## Idea

Generate every subarray of size `k`.

For every subarray:
- Calculate sum
- Update maximum

---

## Brute Force Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {

    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0; i <= n-k; i++) {

        int sum = 0;

        for(int j = i; j < i+k; j++) {
            sum += arr[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}
```

---

# 6. Time Complexity of Brute Force

Outer loop → `O(n)`

Inner loop → `O(k)`

Total Complexity:

```text
O(n * k)
```

---

# 7. Why Sliding Window?

In brute force:

When the window moves forward,
we recalculate common elements again and again.

Example:

```text
[2,5,1] → sum = 8
[5,1,8] → recalculating 5 and 1 again
```

This creates unnecessary repeated work.

---

# 8. Sliding Window Core Idea

Instead of recalculating:

```text
New Window Sum
=
Previous Window Sum
- Removed Element
+ Added Element
```

---

# 9. Window Concept

We maintain two pointers:

```text
i → start
j → end
```

Window size formula:

```text
j - i + 1
```

For a valid fixed-size window:

```text
j - i + 1 == k
```

---

# 10. Important Observation

We only perform calculations when:

```text
window size == k
```

Because only then we get a valid subarray of size `k`.

---

# 11. Sliding Window Process

## Step 1: Expand Window

Move `j` forward:

```cpp
j++;
```

Add current element:

```cpp
sum += arr[j];
```

---

## Step 2: Check Window Size

### Case 1

If:

```text
j - i + 1 < k
```

Window is incomplete.

So move `j`.

---

### Case 2

If:

```text
j - i + 1 == k
```

Now we found a valid window.

Perform calculations:

```cpp
maxi = max(maxi, sum);
```

---

## Step 3: Slide the Window

Remove left element:

```cpp
sum -= arr[i];
```

Move window forward:

```cpp
i++;
j++;
```

---

# 12. Why Do We Remove `arr[i]`?

Because the window is moving ahead.

Example:

Current window:

```text
[2,5,1]
sum = 8
```

Next window:

```text
[5,1,8]
```

We remove `2` and add `8`.

```text
8 - 2 + 8 = 14
```

Efficient and optimized.

---

# 13. Dry Run

## Array

```text
[2,5,1,8,2,9,1]
k = 3
```

---

## Window 1

```text
[2,5,1]
sum = 8
max = 8
```

---

## Window 2

```text
[5,1,8]
sum = 14
max = 14
```

---

## Window 3

```text
[1,8,2]
sum = 11
max = 14
```

---

## Window 4

```text
[8,2,9]
sum = 19
max = 19
```

---

## Window 5

```text
[2,9,1]
sum = 12
max = 19
```

Final Answer:

```text
19
```

---

# 14. Optimal Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {

    int i = 0;
    int j = 0;

    int sum = 0;
    int maxi = INT_MIN;

    while(j < arr.size()) {

        // Add current element
        sum += arr[j];

        // Window size less than k
        if(j - i + 1 < k) {
            j++;
        }

        // Window size equal to k
        else if(j - i + 1 == k) {

            // Calculate answer
            maxi = max(maxi, sum);

            // Slide the window
            sum -= arr[i];

            i++;
            j++;
        }
    }

    return maxi;
}
```

---

# 15. Time Complexity

Each element is visited once.

```text
O(n)
```

---

# 16. Space Complexity

```text
O(1)
```

No extra space is used.

---

# 17. Fixed Size Sliding Window Template

```cpp
while(j < n) {

    // Calculation
    sum += arr[j];

    if(j - i + 1 < k) {
        j++;
    }

    else if(j - i + 1 == k) {

        // Answer calculation

        // Remove unnecessary part
        sum -= arr[i];

        i++;
        j++;
    }
}
```

---

# 18. Fixed vs Variable Sliding Window

| Fixed Size Window | Variable Size Window |
|------------------|----------------------|
| Window size remains constant | Window size changes |
| Example: `k = 3` | Depends on condition |
| Easier to implement | Slightly complex |

---

# 19. Common Sliding Window Problems

## Fixed Size Sliding Window

- Maximum sum subarray of size k
- First negative number in every window
- Count occurrences of anagrams

---

## Variable Size Sliding Window

- Longest substring without repeating characters
- Longest subarray with sum k
- Minimum window substring

---

# 20. Key Takeaways

- Sliding Window avoids unnecessary recalculations
- Best for contiguous data problems
- Uses two pointers (`i`, `j`)
- Reduces complexity from `O(n*k)` to `O(n)`
- One of the most important DSA patterns for interviews

---

# 21. Conclusion

Sliding Window is one of the most powerful optimization techniques in Data Structures and Algorithms.

Mastering:
- Window formation
- Pointer movement
- Window expansion and shrinking

will help solve many interview problems efficiently.
