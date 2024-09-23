//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>dp;
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n=arr.size();
        return func(n-1,arr,k);
    }
    int func(int n,vector<int>&arr,int& k)
    {
        if(dp.size()<n)
        dp.resize(n+1,-1);
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int mini=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            if(n-i>=0)
            {
            int right=func(n-i,arr,k)+abs(arr[n]-arr[n-i]);
            mini= min(mini,right);
            }
        
        }
        return dp[n]=mini;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends