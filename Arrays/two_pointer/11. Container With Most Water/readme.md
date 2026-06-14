# 11. Container With Most Water

## Problem Statement

You are given an integer array `height` where each element represents the height of a vertical line.

Find two lines that, together with the x-axis, form a container that holds the maximum amount of water.

Return the maximum amount of water the container can store.

---

# 1. Understand the Problem

Before solving, let's understand what is being asked.

We need to:

* Choose two indices `i` and `j`
* Width = `j - i`
* Height = `min(height[i], height[j])`
* Area = Width × Height

Return the maximum possible area.

---

# 2. Ask Clarifying Questions

In an interview, I would ask:

1. Can the array contain negative heights?

   * Usually No.

2. Can the array be empty?

   * Usually No.

3. Can heights be duplicated?

   * Yes.

4. What is the range of `n`?

   * Helps determine the required complexity.

5. Is there always at least one valid answer?

   * Usually Yes.

---

# 3. Discuss an Example

Input:

```text
height = [1,8,6,2,5,4,8,3,7]
```

Choose:

```text
height[1] = 8
height[8] = 7
```

Width:

```text
8 - 1 = 7
```

Height:

```text
min(8,7) = 7
```

Area:

```text
7 × 7 = 49
```

Output:

```text
49
```

---

# 4. Brute Force Approach

## Idea

Check every possible pair of lines.

For each pair:

```text
Width = j - i
Height = min(height[i], height[j])
Area = Width × Height
```

Keep track of the maximum area.

## Algorithm

1. Iterate through all pairs.
2. Compute area for each pair.
3. Update maximum area.
4. Return answer.

## Complexity

### Time Complexity

```text
O(n²)
```

Two nested loops.

### Space Complexity

```text
O(1)
```

No extra space used.

---

# 5. Observation

The area depends on:

```text
Area = min(height[i], height[j]) × (j - i)
```

Important observation:

The smaller height always limits the area.

Even if one line is extremely tall, the shorter line determines how much water can be stored.

This observation allows us to avoid checking every pair.

---

# 6. Optimal Approach (Two Pointers)

## Idea

Start with the maximum possible width.

Place:

```text
Left Pointer = 0
Right Pointer = n - 1
```

Calculate area.

Move the pointer with the smaller height.

---

## Why Move the Smaller Height?

Suppose:

```text
height[left] = 3
height[right] = 8
```

Current area:

```text
3 × width
```

The height `3` is limiting the area.

If we move the taller height:

* Width decreases.
* Limiting height remains 3.

Area cannot improve.

Therefore, move the smaller height and hope to find a taller line.

This is the key observation behind the optimization.

---

# 7. Optimal Algorithm

1. Place two pointers at both ends.
2. Calculate current area.
3. Update maximum area.
4. Move the pointer with smaller height.
5. Repeat until pointers meet.
6. Return maximum area.

---

# 8. Optimal Complexity

### Time Complexity

```text
O(n)
```

Each pointer moves at most `n` times.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

# 9. Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxArea = 0;

        while(left < right) {

            int area = min(height[left], height[right])
                       * (right - left);

            maxArea = max(maxArea, area);

            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};
```

---

# 10. Dry Run

Input:

```text
[1,8,6,2,5,4,8,3,7]
```

### Iteration 1

```text
left = 0
right = 8

Area = min(1,7) × 8
     = 8
```

Move left pointer.

---

### Iteration 2

```text
left = 1
right = 8

Area = min(8,7) × 7
     = 49
```

Maximum Area = 49

Move right pointer.

Continue until pointers meet.

Final Answer:

```text
49
```

---

# 11. Edge Cases

### Case 1

```text
height = [1,1]
```

Answer:

```text
1
```

---

### Case 2

```text
height = [5,5,5,5]
```

Answer:

```text
15
```

---

### Case 3

Very large input size.

Two-pointer solution still works efficiently in O(n).

---

# 12. Common Follow-Up Questions

## Q1. Why does the two-pointer approach work?

Because the smaller height limits the area.

Moving the taller height only decreases width without increasing the limiting height.

---

## Q2. Why not move both pointers together?

We may skip potential optimal answers.

---

## Q3. Can we do better than O(n)?

No.

Every element may need to be considered at least once.

Therefore O(n) is optimal.

---

## Q4. Why start from both ends?

Because it provides the maximum possible width.

---

## Q5. What technique is used here?

Two Pointer Technique.

---

# Interview Summary

"My first approach was brute force where I checked every pair of lines and calculated the area. This required O(n²) time and O(1) space.

Then I observed that the area is always limited by the smaller height. Using this observation, I applied the Two Pointer technique. I started with the maximum width by placing pointers at both ends and moved only the pointer with the smaller height because moving the taller height cannot improve the area.

This reduced the time complexity from O(n²) to O(n) while keeping the space complexity O(1)."
