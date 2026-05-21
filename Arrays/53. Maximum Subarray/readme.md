# Maximum Subarray Sum — Kadane’s Algorithm

## Problem Statement

Given an integer array `nums`, find the contiguous subarray that has the largest sum and return that sum.

### Example

```cpp
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation:
Subarray [4,-1,2,1] has the largest sum = 6
```

---

# Approach 1 — Brute Force (O(N³))

## Intuition

Generate all possible subarrays and calculate their sums.

We use:

* First loop → starting index
* Second loop → ending index
* Third loop → calculate subarray sum

Since we repeatedly calculate the same sums again and again, this approach becomes very slow.

---

## Algorithm

1. Traverse all starting indices `i`
2. Traverse all ending indices `j`
3. Calculate sum from index `i` to `j`
4. Update the maximum sum

---

## Time & Space Complexity

* **Time Complexity:** `O(N³)`
* **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:
   
    int maxSubArray(vector<int>& nums) {

        int maxi = INT_MIN; 

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i; j < nums.size(); j++) {

                int sum = 0; 

                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                maxi = max(maxi, sum);
            }
        }

        return maxi; 
    }
};
```

---

# Approach 2 — Better Approach (O(N²))

## Intuition

In brute force, we repeatedly calculate the same subarray sums.

Instead of recalculating:

```cpp
nums[i] + nums[i+1] + nums[i+2]
```

again and again, we maintain a running sum.

This removes the third loop.

---

## Algorithm

1. Fix starting index `i`
2. Initialize `sum = 0`
3. Extend subarray using index `j`
4. Add `nums[j]` to running sum
5. Update maximum sum

---

## Time & Space Complexity

* **Time Complexity:** `O(N²)`
* **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            int sum = 0;

            for(int j = i; j < nums.size(); j++) {

                sum += nums[j];

                maxi = max(sum, maxi);
            }
        }

        return maxi;
    }
};
```

---

# Approach 3 — Optimal Approach (Kadane’s Algorithm) — O(N)

## Intuition

### Key Observation

If the current sum becomes negative, it will always decrease the future subarray sum.

So there is no benefit in carrying a negative sum forward.

Therefore:

```cpp
if(sum < 0)
    sum = 0;
```

---

## Algorithm

1. Initialize:

   * `sum = 0`
   * `maxi = nums[0]`
2. Traverse the array
3. Add current element to `sum`
4. Update maximum sum
5. If `sum < 0`, reset `sum = 0`
6. Return `maxi`

---

## Time & Space Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(1)`

---

## Code

```cpp
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        
        int maxi = nums[0];
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
             
            sum += nums[i];

            maxi = max(sum, maxi);

            if(sum < 0) {
                sum = 0;
            }
        }
            
        return maxi;
    }
};
```

---

# Dry Run of Kadane’s Algorithm

```cpp
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

| Element | Current Sum     | Maximum Sum |
| ------- | --------------- | ----------- |
| -2      | -2 → reset to 0 | -2          |
| 1       | 1               | 1           |
| -3      | -2 → reset to 0 | 1           |
| 4       | 4               | 4           |
| -1      | 3               | 4           |
| 2       | 5               | 5           |
| 1       | 6               | 6           |
| -5      | 1               | 6           |
| 4       | 5               | 6           |

Final Answer = `6`

---

# Interview Explanation

## Brute Force

> “Initially, I generated all possible subarrays and calculated their sums using three loops.
> This gives a time complexity of O(N³).”

---

## Better Approach

> “Then I observed that we repeatedly calculate the same sums.
> So instead of recalculating, I maintained a running sum while extending the subarray.
> This removed one loop and improved the complexity to O(N²).”

---

## Optimal Approach — Kadane’s Algorithm

> “Finally, I realized that if the running sum becomes negative, it will only reduce future subarray sums.
> So whenever the sum becomes negative, I reset it to zero.
> This gives an optimal O(N) solution known as Kadane’s Algorithm.”

---

# Important Edge Case

## Why initialize `maxi = nums[0]` instead of `0`?

Because the array can contain all negative numbers.

### Example

```cpp
nums = [-5,-2,-8]
```

If we initialize:

```cpp
maxi = 0
```

the answer becomes incorrect.

So we initialize:

```cpp
maxi = nums[0]
```

---

# Complexity Comparison

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Brute Force        | O(N³)           | O(1)             |
| Better Approach    | O(N²)           | O(1)             |
| Kadane’s Algorithm | O(N)            | O(1)             |

---

# Key Learning

* Brute Force teaches subarray generation
* Better Approach teaches running sum optimization
* Kadane’s Algorithm teaches greedy optimization

This is a very important interview problem because it demonstrates:

* Problem-solving progression
* Optimization thinking
* Greedy approach understanding
* Time complexity reduction
