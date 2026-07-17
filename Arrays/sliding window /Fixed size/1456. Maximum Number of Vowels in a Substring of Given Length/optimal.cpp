class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0; int j =0;
        int cnt = 0;
        int maxi = INT_MIN;

        while(j<n)
        {
            //string str += s[j];
            if(s[j] == 'a' || s[j] =='e' ||s[j] =='i' || s[j] =='o' || s[j] == 'u')
            {
                cnt++;
            }
            if (j-i+1 == k)
            {
                 maxi = max(cnt , maxi);
                 if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                 {
                    cnt--;
                 }
                 i++;    
            }
            j++;
            
        }
        return maxi;
    }
};
