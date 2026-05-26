#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {

    int i = 0;
    int j = 0;

    int sum = 0;
    int maxi = INT_MIN;

    while(j < arr.size()) {

        // Add current element
        sum += arr[j];

        // Window size less than k
        if(j - i + 1 < k) {
            j++;
        }

        // Window size equal to k
        else if(j - i + 1 == k) {

            // Calculate answer
            maxi = max(maxi, sum);

            // Slide the window
            sum -= arr[i];

            i++;
            j++;
        }
    }

    return maxi;
}
