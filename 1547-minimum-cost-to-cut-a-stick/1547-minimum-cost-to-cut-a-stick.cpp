class Solution {
public:
    
    int solve(int i, int n, map<pair<int,int>,int>& mp, vector<int> &cuts)
    {
        pair<int,int> s = {i,n};
        if(mp.find(s) != mp.end()) return mp[s];
        int res = INT_MAX;
        for(int j=0;j<cuts.size();j++)
        {
            if(cuts[j] > i && cuts[j] < n)
            res = min(res,solve(i,cuts[j],mp,cuts)+solve(cuts[j],n,mp,cuts)+n-i);            
        }
        return mp[s] = (res == INT_MAX)?0:res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        map<pair<int,int>,int> mp;
        return solve(0,n,mp,cuts);
    }
};