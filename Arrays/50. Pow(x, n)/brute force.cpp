class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int num = n;
        if(n<0)
        {
            x = 1/x;
            num = -1*1LL*n;

        }
        for(int i = 0; i<num; i++)
        {
            ans = ans*x;
        }
        return ans;
    }
};
