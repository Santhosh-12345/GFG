//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>dp;
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(dp.size()<n+1)
        dp.resize(n+1,-1);
        if(n==1)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int left=minimumEnergy(height,n-1)+abs(height[n-1]
        -height[n-2]);
        int right=INT_MAX;
        if(n>2)
        right=minimumEnergy(height,n-2)+
        abs(height[n-1]-height[n-3]);
        return dp[n]=min(left,right);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends