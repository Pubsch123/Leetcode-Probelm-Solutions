class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int p = 2;
        int j = k+1;
        ans[0] = 1;
        for(int i=k+1;i<n;i++)
            ans[i] = i+1;
        for(int i=1;i<k+1;i++)
        {
            if(i&1){
                ans[i] = j;
                j--;
            }
            else
                ans[i] = p++;
        }
        return ans;
    }
};