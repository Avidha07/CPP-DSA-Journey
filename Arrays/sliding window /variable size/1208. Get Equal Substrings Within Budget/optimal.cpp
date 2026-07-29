class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxil = 0;
        int cnt = 0;
        int j =0; int i =0;

        while(j<n)
        {
            cnt += abs(t[j]- s[j]);

            while(cnt > maxCost)
            {
                  cnt -= abs(t[i]- s[i]);
                  i++;
            }

            maxil = max(maxil , j-i+1);
            j++;
        }

        return maxil;
    }
};
