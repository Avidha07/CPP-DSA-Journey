# 125. Valid Palindrome

## Problem Statement

A phrase is a palindrome if, after converting all uppercase letters to lowercase and removing all non-alphanumeric characters, it reads the same forward and backward.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

---

## Approach 1: Brute Force

### Idea

1. Traverse the string and keep only alphanumeric characters.
2. Convert all letters to lowercase.
3. Store the cleaned characters in a new string.
4. Create a copy of the cleaned string.
5. Reverse the copied string.
6. Compare both strings.

If both strings are equal, the string is a palindrome.

### Algorithm

* Create an empty string `str`.
* Traverse the input string.
* Append lowercase alphanumeric characters to `str`.
* Create another string `str1 = str`.
* Reverse `str1`.
* Compare `str` and `str1`.

### Time Complexity

* Cleaning the string: `O(n)`
* Reversing the string: `O(n)`
* Comparing strings: `O(n)`

**Overall:** `O(n)`

### Space Complexity

* Cleaned string: `O(n)`
* Reversed copy: `O(n)`

**Overall:** `O(n)`

### Brute Force Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')) {
                str += tolower(s[i]);
            }
        }

        string str1 = str;
        reverse(str1.begin(), str1.end());

        return str == str1;
    }
};
```

---

## Approach 2: Better Approach (Two Pointers)

### Idea

Instead of creating a reversed copy of the cleaned string, use the Two Pointer technique.

* One pointer starts from the beginning.
* Another pointer starts from the end.
* Compare characters while moving both pointers toward the center.

This removes the need for an additional reversed string.

### Algorithm

1. Create a cleaned lowercase string.
2. Initialize:

   * `i = 0`
   * `j = str.length() - 1`
3. Compare characters at both pointers.
4. If characters differ, return `false`.
5. Otherwise move both pointers inward.
6. Continue until pointers meet.

### Time Complexity

* Cleaning the string: `O(n)`
* Two Pointer traversal: `O(n)`

**Overall:** `O(n)`

### Space Complexity

* Cleaned string only: `O(n)`

**Overall:** `O(n)`

### Better Approach Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')) {
                str += tolower(s[i]);
            }
        }

        int i = 0;
        int j = str.length() - 1;

        while(i <= j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
```

---

## Optimal Approach

### Idea

Use Two Pointers directly on the original string.

* Skip non-alphanumeric characters.
* Convert characters to lowercase during comparison.
* Avoid creating any extra string.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Interview Explanation

> My first approach was brute force. I cleaned the string by removing non-alphanumeric characters and converting all letters to lowercase. Then I created a reversed copy of the cleaned string and compared both strings. This takes O(n) time and O(n) extra space.

> To improve the solution, I removed the reversed copy and used the Two Pointer technique on the cleaned string itself. This still takes O(n) time but reduces unnecessary memory usage.

> Finally, the optimal solution is to use two pointers directly on the original string while skipping non-alphanumeric characters. This achieves O(n) time and O(1) extra space.

---

## Key Learnings

* String Preprocessing
* Character Manipulation
* Two Pointer Technique
* Palindrome Checking
* Space Optimization

---

## Tags

`String` `Two Pointers` `Palindrome` `Easy`
