# 🚣 881. Boats to Save People

> **LeetCode:** 881. Boats to Save People  
> **Difficulty:** Medium  
> **Pattern:** Greedy + Two Pointers + Sorting

---

# 📌 Problem Information

- **Problem Name:** Boats to Save People
- **Platform:** LeetCode
- **Difficulty:** Medium
- **Topics:** Greedy, Sorting, Two Pointers

---

# 📝 Problem Statement

You are given an array `people` where `people[i]` represents the weight of the `i-th` person.

Each boat:

- Can carry **at most two people**
- Has a maximum weight capacity of `limit`

Return the **minimum number of boats** required to rescue everyone.

---

# 💡 Intuition

Since every boat can carry **only two people**, we should always try to pair the **heaviest person** with the **lightest possible person**.

Why?

- The heaviest person is the hardest to accommodate.
- If even the lightest person cannot fit with the heaviest, then nobody else can.
- So the heaviest person must go alone.

This observation naturally leads to a greedy solution.

---

# 🔍 Key Observation

Suppose the people are sorted.

```
Lightest ---------------------> Heaviest
      i                        j
```

At every step:

### Case 1

```
people[i] + people[j] <= limit
```

They can share one boat.

Move both pointers.

```
i++
j--
boats++
```

---

### Case 2

```
people[i] + people[j] > limit
```

The heaviest person cannot pair even with the lightest.

Therefore, they **must go alone**.

```
j--
boats++
```

---

# 🚀 Approach

### Step 1

Sort the array.

```
people = [1,2,2,3]
```

---

### Step 2

Initialize

```
i = 0
j = n-1
boats = 0
```

---

### Step 3

While `i <= j`

- Check whether the lightest and heaviest can fit together.
- If yes
  - Pair them.
  - Move both pointers.
- Otherwise
  - Send the heaviest alone.
  - Move only the right pointer.

Increase boat count in both cases.

---

# 🧪 Dry Run

### Example

```
people = [3,2,2,1]
limit = 3
```

After sorting

```
[1,2,2,3]
```

| i | j | Pair | Boats |
|---|---|------|-------|
|1|3|1+3 = 4 ❌|1|
|1|2|1+2 = 3 ✅|2|
|2|2|2 alone|3|

Answer:

```
3
```

---

# ✅ Why Greedy Works?

The heaviest person has the fewest pairing options.

If the lightest person cannot fit with the heaviest,

then no other person can.

So sending the heaviest alone is always optimal.

Otherwise, pairing the heaviest with the lightest saves the maximum remaining capacity for future pairings.

This guarantees the minimum number of boats.

---

# ⏱ Complexity Analysis

### Time Complexity

Sorting

```
O(n log n)
```

Two pointers

```
O(n)
```

Overall

```
O(n log n)
```

---

### Space Complexity

```
O(1)
```

Ignoring the sorting implementation.

---

# ⚠️ Common Mistakes

### ❌ Mistake 1

Using

```cpp
sort(nums.begin(), nums.end());
```

There is no variable named `nums`.

Correct:

```cpp
sort(people.begin(), people.end());
```

---

### ❌ Mistake 2

Forgetting

```cpp
while(i <= j)
```

When one person is left (`i == j`), they still need one boat.

---

### ❌ Mistake 3

Trying to pair the heaviest with someone other than the lightest.

This can increase the number of boats and break the greedy strategy.

---

# 🎯 Pattern Recognition

This problem combines:

- Greedy
- Sorting
- Two Pointers

Whenever you see:

- Pairing elements
- Minimize operations
- Pair smallest with largest

Think about **sorting + two pointers**.

---

# 💬 How to Explain in an Interview

You can explain the solution like this:

> "Since each boat can take at most two people, my goal is to maximize the utilization of every boat.
>
> I first sort the weights so that I can easily access the lightest and heaviest people.
>
> Then I use two pointers. One starts from the lightest person and the other from the heaviest.
>
> At every step, I check whether the lightest and the heaviest can fit in the same boat.
>
> If they can, I pair them together because this is the best use of the boat. Then I move both pointers.
>
> Otherwise, if even the lightest person cannot fit with the heaviest, then the heaviest cannot fit with anyone else, since everyone else is heavier.
>
> Therefore, the heaviest person must go alone. I move only the right pointer.
>
> In both cases, one boat is used.
>
> This greedy strategy is optimal because the heaviest person always has the fewest pairing choices."

---

# ❓ Interview Follow-up Questions

### Why do we sort?

Sorting allows us to efficiently compare the lightest and heaviest person using two pointers.

---

### Why pair the lightest with the heaviest?

Because if the lightest cannot fit with the heaviest, nobody else can.

---

### Why isn't Dynamic Programming needed?

Each decision depends only on the current lightest and heaviest after sorting.

The greedy choice is provably optimal.

---

### Can this be solved without sorting?

Not efficiently.

Sorting enables the two-pointer greedy approach.

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int i = 0;
        int j = people.size() - 1;
        int boats = 0;

        while (i <= j) {

            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }

            boats++;
        }

        return boats;
    }
};
```

---

# 📝 Key Learnings

- Greedy works when a locally optimal choice leads to the global optimum.
- Sorting often simplifies pairing problems.
- Two pointers reduce nested loops to linear traversal.
- Always justify why the greedy choice is safe.

---

# 📖 Revision Notes

✅ Sort the array.

✅ Pair the lightest with the heaviest whenever possible.

✅ If they cannot fit together, send the heaviest alone.

✅ Increment the boat count after every decision.

**Rule to Remember:**

> If the lightest person can't fit with the heaviest, no one can.
```
