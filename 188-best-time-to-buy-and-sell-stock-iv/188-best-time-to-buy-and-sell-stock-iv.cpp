class Solution {
public:
    
    int dp[1001][2][101];
    
    int solve(int i, int f, int cnt, vector<int>& p, int &n)
    {
        if(i == n || n == 1) return 0;
        if(dp[i][f][cnt] != -1) return dp[i][f][cnt];
        int c1 = 0, c2 = 0;
        if(cnt > 0)
        {
            if(f == 0)
                c1 = -p[i] + solve(i+1,1,cnt,p,n);
            else if(f == 1)
                c1 = p[i] + solve(i+1,0,cnt-1,p,n);
            c2 = solve(i+1,f,cnt,p,n);
        }
        else if(cnt == 0)
            c2 = solve(i+1,f,cnt,p,n);
        return dp[i][f][cnt] = max(c1,c2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,k,prices,n);
    }
};