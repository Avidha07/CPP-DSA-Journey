#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {

    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0; i <= n-k; i++) {

        int sum = 0;

        for(int j = i; j < i+k; j++) {
            sum += arr[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}
