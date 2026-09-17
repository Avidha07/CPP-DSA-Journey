# Pivot Index – Prefix + Suffix Array Approach

## Main Idea

- `prefix` = current index ke left ka sum.
- `suffix[i]` = index `i` se end tak ka sum.
- Isliye current index ke right ka sum hoga `suffix[i+1]`.

## `i+1` kyun?

Hum pivot ko left aur right se compare karte hain, current element ko include nahi karte.

### Example

Input:

```text
[1, 7, 3, 6, 5, 6]
```

### Suffix Array

| Index | Suffix |
|------:|-------:|
| 0 | 28 |
| 1 | 27 |
| 2 | 20 |
| 3 | 17 |
| 4 | 11 |
| 5 | 6 |
| 6 | 0 |

Agar `i = 0` hai:

- Left = `0`
- Right chahiye = `7 + 3 + 6 + 5 + 6 = 27`
- `suffix[0] = 28` (isme current `1` bhi hai ❌)
- `suffix[1] = 27` (sirf right side ka sum ✅)

Isliye hum `suffix[i+1]` use karte hain.

## Code Flow

1. `suffix` array (`n+1`) banao.
2. Right se left jaake suffix sums fill karo.
3. `prefix = 0`.
4. Har index par:
   - `rSum = suffix[i+1]`
   - `prefix == rSum` → return `i`
   - `prefix += nums[i]`

---

# 20-Second Revision Note

## 724. Pivot Index (Prefix + Suffix)

- `suffix[i] = suffix[i+1] + nums[i]`
- `prefix = 0`
- `Right = suffix[i+1]` (current element skip)
- Compare `prefix == Right`
- `prefix += nums[i]`

### Memory Trick

`suffix[i]` current ko include karta hai, `suffix[i+1]` sirf right side ka sum deta hai.

### Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>suffix(n+1 , 0);
        suffix[n] = 0;

        for(int i = n-1; i>=0; i--)
        {
            suffix[i] = suffix[i+1] + nums[i]; 
        }

        int prefix = 0;

        for(int i =0; i<n; i++) 
        {   
            int rSum = suffix[i+1];
            if(prefix == rSum) {
                return i;
            }

            prefix += nums[i];
        }
        return -1;
    }
};
