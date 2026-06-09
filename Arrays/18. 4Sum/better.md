# 18. 4Sum

## Problem Statement

Given an array `nums` of `n` integers, return all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

* `0 <= a, b, c, d < n`
* `a`, `b`, `c`, and `d` are distinct
* `nums[a] + nums[b] + nums[c] + nums[d] == target`

The solution set must not contain duplicate quadruplets.

---

## Approach

### 1. Sort the Array

First, sort the array. Sorting helps in:

* Applying the two-pointer technique efficiently.
* Generating quadruplets in a consistent order.
* Avoiding duplicate combinations.

### 2. Fix the First Two Elements

Use two nested loops:

* `i` selects the first element.
* `j` selects the second element.

For every pair `(i, j)`, find the remaining two numbers using the two-pointer approach.

### 3. Apply Two Pointers

Initialize:

* `l = j + 1`
* `h = n - 1`

Calculate:

```cpp
sum = nums[i] + nums[j] + nums[l] + nums[h];
```

* If `sum == target`, store the quadruplet.
* If `sum > target`, move `h--`.
* If `sum < target`, move `l++`.

### 4. Remove Duplicates

A `set<vector<int>>` is used to automatically store only unique quadruplets.

### 5. Convert Set to Answer Vector

Finally, copy all quadruplets from the set into the result vector.

---

## Why Use long long?

The sum of four integers may exceed the range of `int`.

Example:

```cpp
1000000000 + 1000000000 + 1000000000 + 1000000000
```

To prevent integer overflow:

```cpp
long long sum =
(long long)nums[i] +
(long long)nums[j] +
(long long)nums[l] +
(long long)nums[h];
```

---

## Algorithm

1. Sort the array.
2. Iterate over the first element `i`.
3. Iterate over the second element `j`.
4. Use two pointers `l` and `h`.
5. Calculate the sum of four elements.
6. Store valid quadruplets in a set.
7. Convert the set into the answer vector.
8. Return the result.

---

## Complexity Analysis

### Time Complexity

* Sorting: `O(n log n)`
* Two nested loops: `O(n²)`
* Two-pointer traversal: `O(n)`

Overall:

```text
O(n³)
```

### Space Complexity

* Set stores unique quadruplets.
* Answer vector stores the result.

```text
O(k)
```

where `k` is the number of unique quadruplets.

---

## C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> v;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {

                int l = j + 1;
                int h = n - 1;

                while(l < h) {

                    long long sum =
                        (long long)nums[i] +
                        (long long)nums[j] +
                        (long long)nums[l] +
                        (long long)nums[h];

                    if(sum == target) {
                        v.insert({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        h--;
                    }
                    else if(sum > target) {
                        h--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }

        for(auto it : v) {
            ans.push_back(it);
        }

        return ans;
    }
};
```

---

## Example

### Input

```cpp
nums = [1,0,-1,0,-2,2]
target = 0
```

### Output

```cpp
[
 [-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]
]
```

---

## Key Learning

* Sorting enables efficient two-pointer traversal.
* Fixing two elements reduces the problem to a 2Sum search.
* Using `long long` prevents overflow.
* A `set` guarantees unique quadruplets without additional duplicate checks.
