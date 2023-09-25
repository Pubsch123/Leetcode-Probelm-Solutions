//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(string& ans, vector<int> adj[], vector<int>& vis, int cur)
    {
        vis[cur] = 1;
        for(auto i: adj[cur])
        {
            if(vis[i] == 0)
            dfs(ans,adj,vis,i);
        }
        char cr = cur+'a';
        ans = cr + ans;
    }
    
    string findOrder(string dict[], int n, int k) {
         if(n == 1) return "1";
         int i = 0,j = 1;
         int ch;
         vector<int> adj[k+1];
         vector<int> vis(k+1,0);
         while(j < n)
         {
             int k = 0;
             while(k < min(dict[i].size(),dict[j].size()) && dict[i][k] == dict[j][k])
             {
                 k++;
             }
             if(k < min(dict[i].size(),dict[j].size()) && dict[i][k] != dict[j][k])
             {
                 adj[dict[i][k]-'a'].push_back(dict[j][k]-'a');
             }
             i++;j++;
         }
        string ans = "";
        for(int i=0;i<k;i++)
        if(vis[i] == 0)
        dfs(ans,adj,vis,i);
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends