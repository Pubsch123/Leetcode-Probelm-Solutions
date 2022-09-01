class Solution {
public:
    #define ff first
    #define ss second
    #define pb push_back
    static bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        return p1.first<p2.first;
    }
    
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int l=0,r=n-1;
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
            vp.pb({a[i],i});
        sort(vp.begin(),vp.end(),comp);
        vector<int> ans;
        while(l<r)
        {
            if(vp[l].ff + vp[r].ff > target) r--;
            else if(vp[l].ff + vp[r].ff < target) l++;
            else{
                ans.pb(vp[l].ss);
                ans.pb(vp[r].ss);
                r--;
                break;
            }
        }
        return ans;
    }
};