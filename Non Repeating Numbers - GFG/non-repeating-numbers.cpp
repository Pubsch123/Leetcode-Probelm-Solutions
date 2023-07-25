//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xo= 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        xo ^= nums[i];
        int a = 0, b = 0;
        //finding the rightmost setbit
        xo = xo&(~(xo-1));
        for(int i=0;i<n;i++)
        {
            if(xo&nums[i]) a ^= nums[i];
            else b ^= nums[i];
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        sort(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends