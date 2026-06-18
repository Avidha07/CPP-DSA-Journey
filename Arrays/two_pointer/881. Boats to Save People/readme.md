# 881. Boats to Save People

**Difficulty:** Medium
**Topic / Pattern:** Greedy, Two Pointers, Sorting
**Language:** C++

---

# Problem Statement

You are given an array `people` where `people[i]` represents the weight of the `i-th` person and an integer `limit` representing the maximum weight a boat can carry.

Each boat can carry **at most two people** at a time, provided the sum of their weights does not exceed `limit`.

Return the **minimum number of boats** required to rescue everyone.

### Example 1

```text
Input: people = [1,2], limit = 3
Output: 1
```

### Example 2

```text
Input: people = [3,2,2,1], limit = 3
Output: 3
```

### Example 3

```text
Input: people = [3,5,3,4], limit = 5
Output: 4
```

---

# Brute Force Approach

For every heaviest remaining person:

1. Search all remaining people.
2. Find the heaviest possible partner that can fit within the weight limit.
3. Mark both as used.
4. Continue until everyone is assigned a boat.

This approach repeatedly searches for valid partners and becomes expensive for larger inputs.

---

# Complexity of Brute Force

### Time Complexity

```text
O(n²)
```

For each person, we may need to scan the remaining people to find a valid partner.

### Space Complexity

```text
O(n)
```

Used array or bookkeeping structure.

---

# Key Observation

The heaviest person is always the most difficult person to place.

* If the heaviest person cannot pair with the lightest person, then they cannot pair with anyone else.
* Therefore, the heaviest person must go alone.
* If the heaviest and lightest person can fit together, pairing them is always optimal.

This naturally suggests:

* Sort the array.
* Use two pointers:

  * One at the lightest person.
  * One at the heaviest person.

---

# Optimal Approach with code

### Algorithm

1. Sort the weights.
2. Place one pointer at the beginning (`i`) and one at the end (`j`).
3. If `people[i] + people[j] <= limit`:

   * Pair them together.
   * Move both pointers.
4. Otherwise:

   * Send the heaviest person alone.
   * Move only `j`.
5. Count each boat used.

### C++ Code

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int i = 0;
        int j = n - 1;
        int cnt = 0;

        while (i <= j) {
            int sum = people[i] + people[j];

            if (sum <= limit) {
                cnt++;
                i++;
                j--;
            } else {
                cnt++;
                j--;
            }
        }

        return cnt;
    }
};
```

---

# Complexity of Optimal Approach

### Time Complexity

```text
O(n log n)
```

* Sorting takes `O(n log n)`.
* Two-pointer traversal takes `O(n)`.

Overall:

```text
O(n log n)
```

### Space Complexity

```text
O(1)
```

Ignoring the space used by the sorting algorithm.

---

# Dry Run (step-by-step trace)

### Input

```text
people = [3,2,2,1]
limit = 3
```

### Step 1: Sort

```text
[1,2,2,3]
```

```text
i = 0
j = 3
boats = 0
```

---

### Step 2

```text
1 + 3 = 4 > 3
```

3 goes alone.

```text
boats = 1
j = 2
```

---

### Step 3

```text
1 + 2 = 3 <= 3
```

Pair them.

```text
boats = 2
i = 1
j = 1
```

---

### Step 4

Only one person left.

```text
2 goes alone
boats = 3
```

---

### Final Answer

```text
3
```

---

# Edge Cases

### Case 1: Single Person

```text
people = [5]
limit = 5

Answer = 1
```

---

### Case 2: Nobody Can Pair

```text
people = [4,4,4,4]
limit = 4

Answer = 4
```

---

### Case 3: Everyone Can Pair

```text
people = [1,1,1,1]
limit = 2

Answer = 2
```

---

### Case 4: Exactly Equal to Limit

```text
people = [1,2]
limit = 3

Answer = 1
```

---

### Case 5: Odd Number of People

```text
people = [1,1,2]
limit = 3

Answer = 2
```

---

# Interview Explanation (how to narrate it)

> Since each boat can carry at most two people, the main challenge is deciding who should be paired together.
>
> The heaviest person is the hardest person to place. After sorting, I try to pair the heaviest person with the lightest available person.
>
> If they fit within the limit, I place them together because that utilizes the boat efficiently.
>
> If they do not fit, then the heaviest person cannot pair with anyone else, since everyone else is heavier than the lightest person. Therefore, the heaviest person must go alone.
>
> Using this greedy observation, I sort the array and apply a two-pointer approach, resulting in an `O(n log n)` solution.

---

# Follow-up Questions with Answers

### 1. Why do we always try to pair the heaviest person with the lightest person?

Because if the lightest person cannot fit with the heaviest person, nobody else can. Therefore the heaviest person must go alone.

---

### 2. Why does sorting help here?

Sorting allows us to efficiently access:

* Lightest person → left pointer
* Heaviest person → right pointer

This enables optimal greedy decisions.

---

### 3. Can this problem be solved without sorting?

Not efficiently.

Without sorting, finding suitable partners repeatedly would require extra searching, leading to `O(n²)` complexity.

---

### 4. Why is this a Greedy problem?

At every step, we make the locally optimal decision:

* Pair the heaviest with the lightest whenever possible.

This local decision leads to the global optimum.

---

### 5. What happens when `i == j`?

Only one person remains.

That person requires one separate boat.

---

### 6. Why is the loop condition `i <= j` instead of `i < j`?

When `i == j`, one unassigned person is still left.

We must process that person as well.

---

### 7. What if each boat could carry three people instead of two?

The current greedy strategy would no longer be sufficient.

The problem becomes significantly harder and may require different techniques such as greedy heuristics, backtracking, or advanced optimization approaches.

---

### 8. Is this problem similar to Two Sum?

Partially.

Both use sorting and two pointers, but here we are minimizing the number of boats rather than finding a single pair.

---

### 9. What is the most important interview insight?

> If the lightest person cannot fit with the heaviest person, then the heaviest person cannot fit with anyone.

This observation is the foundation of the optimal solution.

---

### 10. Can we achieve better than `O(n log n)`?

Not generally.

Sorting dominates the runtime, making `O(n log n)` the optimal practical solution for arbitrary inputs.
