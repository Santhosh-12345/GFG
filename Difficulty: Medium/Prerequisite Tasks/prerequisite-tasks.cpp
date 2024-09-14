//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int numCourses,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        for(auto it:prerequisites)
        {
            adj[it.first].push_back(it.second);
        }
        for(int i=0;i<numCourses;i++){
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
        }
        // for(int i=0;i<numCourses;i++)
        // {
        //     for(auto it:adj[i])
        //     indegree[i]++;
        // }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(ans.size()==numCourses)
        return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends