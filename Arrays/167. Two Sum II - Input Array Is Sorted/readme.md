# 167. Two Sum II - Input Array Is Sorted

## Problem Statement

Given a **1-indexed sorted array** `numbers` and a target value `target`, find two numbers such that they add up to the target.

Return the indices of the two numbers (1-based indexing).

Constraints:

* Exactly one valid solution exists.
* The same element cannot be used twice.
* Use only constant extra space.

---

## Intuition

Since the array is already sorted in non-decreasing order, we can use the **Two Pointer Technique** instead of a HashMap.

We place:

* `left` pointer at the beginning.
* `right` pointer at the end.

At every step:

* If `numbers[left] + numbers[right] == target`, we found the answer.
* If the sum is smaller than the target, move `left` forward to increase the sum.
* If the sum is greater than the target, move `right` backward to decrease the sum.

Because the array is sorted, these movements are guaranteed to move us closer to the target.

---

## Example

Input:

numbers = [2,7,11,15]
target = 18

Initial pointers:

[2,7,11,15]
L      R

Current sum:

2 + 15 = 17

17 < 18

Move left pointer.

[2,7,11,15]
L    R

Current sum:

7 + 15 = 22

22 > 18

Move right pointer.

[2,7,11,15]
L R

Current sum:

7 + 11 = 18

Target found.

Answer:

[2,3]

---

## Algorithm

1. Initialize two pointers:

   * `left = 0`
   * `right = n - 1`

2. While `left < right`:

   * Calculate:

     sum = numbers[left] + numbers[right]

   * If `sum == target`

     * Return `{left + 1, right + 1}`

   * Else if `sum > target`

     * Decrement `right`

   * Else

     * Increment `left`

3. Return `{-1, -1}` (though the problem guarantees a solution).

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }
            else if(sum > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return {-1, -1};
    }
};
```

---

## Why Two Pointers Work?

The array is sorted.

### Case 1: Sum is too small

If:

numbers[left] + numbers[right] < target

Moving the right pointer left will only decrease the sum further.

Therefore, we move the left pointer right to increase the sum.

### Case 2: Sum is too large

If:

numbers[left] + numbers[right] > target

Moving the left pointer right will increase the sum even more.

Therefore, we move the right pointer left to decrease the sum.

This eliminates one element in every iteration, making the solution efficient.

---

## Complexity Analysis

### Time Complexity

O(n)

Each pointer moves at most `n` times.

### Space Complexity

O(1)

Only two pointers are used.

---

# Interview Explanation

If an interviewer asks:

"Why did you use Two Pointers?"

You can answer:

> Since the array is already sorted, I used the Two Pointer approach instead of a HashMap. I placed one pointer at the beginning and another at the end. If the current sum is smaller than the target, I move the left pointer to increase the sum. If the sum is larger than the target, I move the right pointer to decrease the sum. Because the array is sorted, these pointer movements are guaranteed to move toward the target efficiently. This gives O(n) time complexity and O(1) extra space, which satisfies the problem constraint.

---

# Key Interview Points

* Array is sorted.
* HashMap uses O(n) extra space.
* Problem requires constant space.
* Two pointers utilize the sorted property.
* One pointer movement eliminates one possibility.
* Time Complexity: O(n)
* Space Complexity: O(1)
* Returns 1-based indices.
