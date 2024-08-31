//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int large=-1;
	    int second_large=-1;
	    for(int i=0;i<arr.size();i++)
	    {
	        if(arr[i]>large)
	        {
	        second_large=large;
	        large=arr[i];
	        }
	        if(arr[i]<large && arr[i]>second_large )
	        {
	            second_large=arr[i];
	        }
	    }
	    return second_large;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends