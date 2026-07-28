# 1838. Frequency of the Most Frequent Element

> **Difficulty:** Medium  
> **Topic:** Array, Sorting, Sliding Window, Prefix Sum (Window Sum)  
> **Pattern:** Variable Size Sliding Window  
> **LeetCode:** https://leetcode.com/problems/frequency-of-the-most-frequent-element/

---

# Problem Statement

The frequency of an element is the number of times it appears in the array.

You are given an integer array `nums` and an integer `k`.

In one operation, you may choose any index and increment the value at that index by `1`.

Return the **maximum possible frequency** of an element after performing **at most `k` operations**.

---

# Example

### Example 1

```text
Input:
nums = [1,2,4]
k = 5

Output:
3
```

Explanation

```text
1 -> 4 (3 operations)

2 -> 4 (2 operations)

4 -> 4 (0 operations)

Total = 5 operations
```

Result

```text
[4,4,4]
```

Frequency = **3**

---

# Intuition

At first glance, the problem looks like a simple increment problem.

However, an important observation changes everything.

We **cannot decrease** any element.

We can only **increase** elements.

For example,

```text
8 -> 4 ❌ Impossible

4 -> 8 ✅ Possible
```

This means if we want several numbers to become equal, they must all become equal to **the largest element among them**.

After sorting,

```text
1 2 4 7
```

If our target is `4`, we only need to increase

```text
1 -> 4

2 -> 4
```

This naturally leads to considering **continuous windows** in the sorted array.

---

# Key Observations

## Observation 1

Sort the array.

Without sorting,

```text
8 1 4 13
```

it is difficult to decide which numbers should become equal.

After sorting,

```text
1 4 8 13
```

the rightmost element of every window is always the largest.

---

## Observation 2

The target must always be the rightmost element.

Example

```text
1 2 4
```

Target = 2

```text
4 -> 2
```

Impossible.

Target = 4

```text
1 -> 4

2 -> 4
```

Possible.

Therefore,

**Every valid window always targets `nums[right]`.**

---

## Observation 3

For every valid window,

we need to know

```text
How many operations are required
to make every element equal to nums[right].
```

---

# Brute Force Approach

## Idea

Sort the array.

For every element,

assume it is the final target.

Move towards the left and keep calculating how many operations are required.

Stop whenever operations exceed `k`.

Take the maximum frequency.

---

## Algorithm

1. Sort the array.
2. For every index `i`
3. Consider `nums[i]` as the target.
4. Traverse left.
5. Keep adding

```text
target - nums[j]
```

6. If operations exceed `k`, stop.
7. Store maximum frequency.

---

## Brute Force Dry Run

```text
nums = [1,2,4]

k = 5
```

Target = 4

```text
1 ->4 =3

2 ->4 =2

Total =5
```

Frequency =3

---

Target =2

```text
1 ->2 =1
```

Frequency =2

---

Target =1

Frequency =1

Maximum =3

---

## Brute Force Code

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {

            long long operations = 0;
            int freq = 1;

            for(int j = i - 1; j >= 0; j--) {

                operations += nums[i] - nums[j];

                if(operations <= k)
                    freq++;
                else
                    break;
            }

            ans = max(ans, freq);
        }

        return ans;
    }
};
```

---

## Complexity

Time

```text
O(n²)
```

Space

```text
O(1)
```

---

# Why Brute Force Can Be Optimized?

Notice the repeated calculation.

For target = 4

```text
(4-2)

+

(4-1)
```

For target =7

```text
(7-4)

+

(7-2)

+

(7-1)
```

Again and again,

we compute

```text
target - current
```

This repeated work is the optimization opportunity.

---

# Deriving the Formula

Suppose

```text
Window

2 4 7
```

Target

```text
7
```

Operations

```text
(7-2)

+

(7-4)

+

(7-7)
```

Expand it.

```text
7-2

+

7-4

+

7-7
```

Group similar terms.

```text
7+7+7

-

(2+4+7)
```

Finally,

```text
7×3

-

13
```

General Formula

```text
Required Operations

=

Target × Window Size

-

Window Sum
```

or

```text
required

=

nums[right] × windowSize

-

windowSum
```

This is the most important formula of the problem.

---

# Why Sliding Window?

After sorting,

```text
1 2 4 7
```

Suppose current window is

```text
1 2 4
```

Now right expands.

```text
1 2 4 7
```

The previous work is still useful.

Only one element was added.

Instead of recalculating everything,

maintain

```text
Window Sum
```

This is exactly where Sliding Window helps.

---

# Sliding Window Algorithm

Sort the array.

Maintain

```text
left

right

windowSum
```

For every right pointer,

Add current value.

```cpp
sum += nums[right];
```

Calculate

```text
required

=

nums[right] × windowSize

-

sum
```

If

```text
required > k
```

Shrink the window.

```cpp
sum -= nums[left];

left++;
```

Continue until the window becomes valid.

Update answer.

---

# Dry Run

```text
nums

1 2 4

k=5
```

Window

```text
1
```

Need

```text
1×1−1

=0
```

Answer=1

---

Expand

```text
1 2
```

Need

```text
2×2−3

=1
```

Answer=2

---

Expand

```text
1 2 4
```

Need

```text
4×3−7

=5
```

Still valid.

Answer=3

---

# Optimal Code

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans =1;
        long long sum =0;

        int i =0; int  j =0;
        while(j<n)
        {
            sum += nums[j];

            //long long required = 1LL*nums[j]*(j-i+1) - sum ; ye bhi use kar sakte h 

            while(1LL*nums[j]*(j-i+1) - sum > k)
            {
                sum = sum-nums[i];
                i++;
            }
            
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};
```

---

# Complexity Analysis

Sorting

```text
O(n log n)
```

Sliding Window

```text
O(n)
```

Overall

```text
O(n log n)
```

Space

```text
O(1)
```

---

# Common Mistakes (Very Important)

## Mistake 1

Using `int` for window sum.

Wrong

```cpp
int sum = 0;
```

Correct

```cpp
long long sum = 0;
```

Reason

Maximum value

```text
100000 ×100000

=

10¹⁰
```

which exceeds `int`.

---

## Mistake 2

Integer Overflow

Wrong

```cpp
nums[right] * windowSize
```

Correct

```cpp
1LL * nums[right] * windowSize
```

---

## Mistake 3

Not updating `required`

Wrong

```cpp
while(required > k){

    sum-=nums[left];

    left++;
}
```

Correct

```cpp
while(required > k){

    sum-=nums[left];

    left++;

    required =
    1LL*nums[right]*(right-left+1)-sum;
}
```

---

## Mistake 4

Updating answer before shrinking.

Always update answer **after** the window becomes valid.

---

## Mistake 5

Forgetting to sort.

Without sorting,

Sliding Window does not work.

---

# Edge Cases

### Single element

```text
[5]
```

Answer

```text
1
```

---

### k = 0

```text
1 2 3
```

No increment possible.

Answer

```text
1
```

---

### Already equal

```text
5 5 5
```

Answer

```text
3
```

---

### Very large values

Need `long long`.

---

# Interview Explanation

If the interviewer asks

> **"How did you think of Sliding Window?"**

You can answer:

> I first solved the problem using a brute force approach by considering every element as the target and calculating the total increments required for all previous elements. I noticed that the same calculations were repeated for overlapping ranges. Expanding the expression `(target - a) + (target - b) + ...` gives `target × count - windowSum`. Since both the window sum and window size can be maintained efficiently while expanding and shrinking a window, I optimized the solution using a Variable Size Sliding Window after sorting the array.

---

# Interview Pointers

✅ Mention why sorting is necessary.

✅ Mention why we cannot target smaller elements.

✅ Explain how the formula is derived instead of saying you memorized it.

✅ Explain why Sliding Window works.

✅ Mention why `long long` is required.

✅ Explain why the window is shrunk.

✅ Mention that each element enters and leaves the window only once.

---

# Revision Notes

- Sort first.
- Rightmost element is always the target.
- Maintain window sum.
- Required Operations = Target × Window Size − Window Sum.
- Expand while valid.
- Shrink when invalid.
- Use `long long`.
- Update `required` after shrinking.
- Update answer only after the window becomes valid.

---

# Key Takeaways

- Never memorize the formula.
- Derive it from the brute force expression.
- Sliding Window removes repeated computation.
- Sorting + Variable Sliding Window is the expected optimal solution.
- Always think about maintaining window information instead of recalculating it.

---
**Author Notes**

This problem teaches one of the most important optimization techniques in DSA:

> **Convert repeated brute-force calculations into a maintained window property (sum, count, frequency, etc.), then use a Variable Size Sliding Window to eliminate redundant work.**
