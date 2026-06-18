# 75. Sort Colors

**Difficulty:** Medium
**Topic / Pattern:** Two Pointers, Dutch National Flag Algorithm, Array
**Language:** C++

---

# 1. Problem Statement

Given an array `nums` containing only `0`, `1`, and `2`, sort the array **in-place** so that all:

* `0`s (Red) come first
* `1`s (White) come next
* `2`s (Blue) come last

You must solve the problem without using the built-in sorting function.

### Example

```text
Input:  [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

---

# 2. Brute Force Approach

The simplest approach is to sort the array using any standard sorting algorithm such as Bubble Sort, Selection Sort, or Merge Sort.

### Steps

1. Sort the entire array.
2. Since the array contains only `0`, `1`, and `2`, sorting automatically places them in the required order.

### Brute Force Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```

---

# 3. Complexity of Brute Force

| Operation | Complexity |
| --------- | ---------- |
| Sorting   | O(n log n) |
| Space     | O(1)       |

---

# 4. Better Approach

Since the array contains only three distinct values (`0`, `1`, `2`), we can count the frequency of each value and overwrite the array.

### Steps

1. Count the number of `0`s, `1`s, and `2`s.
2. Fill the array:

   * First all `0`s
   * Then all `1`s
   * Then all `2`s

### Better Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for(int num : nums) {
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two++;
        }

        int index = 0;

        while(zero--) nums[index++] = 0;
        while(one--) nums[index++] = 1;
        while(two--) nums[index++] = 2;
    }
};
```

---

# 5. Complexity of Better Approach

| Operation       | Complexity |
| --------------- | ---------- |
| Traversal       | O(n)       |
| Rewriting Array | O(n)       |
| Total Time      | O(n)       |
| Space           | O(1)       |

---

# 6. Key Observation

The array contains only three possible values:

```text
0, 1, 2
```

Instead of sorting the entire array, we can partition it into three regions:

```text
[0s] [1s] [Unknown] [2s]
```

Using three pointers:

* `low` → boundary of 0s
* `mid` → current element
* `high` → boundary of 2s

This is the famous **Dutch National Flag Algorithm** proposed by Edsger Dijkstra.

---

# 7. Optimal Approach with Code

### Idea

Maintain three regions:

```text
0 ... low-1      -> all 0s
low ... mid-1    -> all 1s
mid ... high     -> unexplored
high+1 ... n-1   -> all 2s
```

### Rules

#### Case 1: nums[mid] == 0

Place it in the left region.

```cpp
swap(nums[mid], nums[low]);
low++;
mid++;
```

#### Case 2: nums[mid] == 1

Already in the correct region.

```cpp
mid++;
```

#### Case 3: nums[mid] == 2

Place it in the right region.

```cpp
swap(nums[mid], nums[high]);
high--;
```

Notice:

We do **not** increment `mid` here because the newly swapped element needs to be examined.

### Optimal Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

---

# 8. Complexity of Optimal Approach

| Operation        | Complexity |
| ---------------- | ---------- |
| Single Traversal | O(n)       |
| Space            | O(1)       |

### Why O(n)?

Each element is processed at most once.

### Why O(1) Space?

Only three pointers are used.

---

# 9. Dry Run (Step-by-Step Trace)

### Input

```text
nums = [2,0,2,1,1,0]
```

Initial:

```text
low = 0
mid = 0
high = 5
```

### Iteration 1

```text
nums[mid] = 2
```

Swap with high.

```text
[0,0,2,1,1,2]

low=0
mid=0
high=4
```

---

### Iteration 2

```text
nums[mid] = 0
```

Swap with low.

```text
[0,0,2,1,1,2]

low=1
mid=1
high=4
```

---

### Iteration 3

```text
nums[mid] = 0
```

Swap with low.

```text
[0,0,2,1,1,2]

low=2
mid=2
high=4
```

---

### Iteration 4

```text
nums[mid] = 2
```

Swap with high.

```text
[0,0,1,1,2,2]

low=2
mid=2
high=3
```

---

### Iteration 5

```text
nums[mid] = 1
```

```text
mid=3
```

---

### Iteration 6

```text
nums[mid] = 1
```

```text
mid=4
```

Now:

```text
mid > high
```

Stop.

### Final Array

```text
[0,0,1,1,2,2]
```

---

# 10. Edge Cases

### Case 1

```text
[0]
```

Output:

```text
[0]
```

---

### Case 2

```text
[2]
```

Output:

```text
[2]
```

---

### Case 3

```text
[0,0,0]
```

Output:

```text
[0,0,0]
```

---

### Case 4

```text
[2,2,2]
```

Output:

```text
[2,2,2]
```

---

### Case 5

```text
[1,1,1]
```

Output:

```text
[1,1,1]
```

---

### Case 6

```text
[2,1,0]
```

Output:

```text
[0,1,2]
```

---

# 11. Interview Explanation (How to Narrate It)

"I first considered sorting the array directly, which would take O(n log n) time.

Since the array contains only three values (0, 1, and 2), a counting approach can solve it in O(n) time and O(1) space.

However, the interviewer usually expects an in-place one-pass solution. For that, I use the Dutch National Flag Algorithm.

I maintain three pointers:

* low → next position for 0
* mid → current element
* high → next position for 2

If I encounter:

* 0 → swap with low and move both pointers
* 1 → move mid
* 2 → swap with high and reduce high

This partitions the array into 0s, 1s, and 2s in a single traversal, achieving O(n) time and O(1) space."

---

# 12. Follow-up Questions with Answers

### Q1. Why don't we increment `mid` when we encounter a `2`?

Because after swapping with `high`, the new element at `mid` has not been processed yet.

Example:

```text
[2,0,1]
```

After swapping:

```text
[1,0,2]
```

The new `1` at index `mid` still needs inspection.

---

### Q2. Why do we increment both `low` and `mid` when we encounter `0`?

Because:

* The swapped position before `low` is guaranteed to be correctly placed.
* The element at `mid` is also processed.

Hence both pointers move forward.

---

### Q3. Can this be solved in one pass?

Yes.

The Dutch National Flag Algorithm completes the sorting in a single traversal.

```text
Time: O(n)
Space: O(1)
```

---

### Q4. What if the array contains four colors instead of three?

The Dutch National Flag Algorithm works specifically for three categories.

For four or more categories:

* Counting Sort can be used.
* Multi-partitioning techniques may be required.

---

### Q5. Is this a stable sorting algorithm?

No.

Swapping elements can change the relative order of equal elements.

Therefore, the Dutch National Flag Algorithm is **not stable**.

---

### Q6. What famous algorithm is used here?

The **Dutch National Flag Algorithm** by **Edsger Dijkstra**.

It partitions an array into three sections in one traversal.

---

### Q7. Why is this considered a Two Pointer problem?

Because the algorithm uses multiple moving boundaries (`low`, `mid`, `high`) to partition the array efficiently without extra space.

---

## Takeaway

* Brute Force → Sorting → **O(n log n)**
* Better → Counting Frequencies → **O(n)**
* Optimal → Dutch National Flag Algorithm → **O(n), O(1)**
* One-pass, in-place solution expected in interviews.
