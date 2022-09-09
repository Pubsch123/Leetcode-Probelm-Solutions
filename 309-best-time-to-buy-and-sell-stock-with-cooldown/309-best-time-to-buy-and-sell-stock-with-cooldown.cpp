class Solution {
public:
   int dp[5004][2];
    
    int solve(int i, int f, vector<int>& p, int &n)
    {
        if(n == 1) return 0;
        if(i >= n) return 0;
        if(dp[i][f] != -1) return dp[i][f];
        int c1 = 0, c2 = 0;
        if(f == 0)
            c1 = solve(i+1,1,p,n)-p[i];
        else if(f == 1)
            c1 = solve(i+2,0,p,n)+p[i];
        c2 = solve(i+1,f,p,n);
        return dp[i][f] = max(c1,c2);
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n = prices.size();
        return solve(0,0,prices,n);
    }
};