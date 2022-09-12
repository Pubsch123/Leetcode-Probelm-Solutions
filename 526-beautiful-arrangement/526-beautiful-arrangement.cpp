class Solution {
public:
    
    int vis[16];
    int cnt = 0;
    
    void solve(int n, int pos){
        if(pos > n){
            cnt++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && (i%pos == 0 || pos%i == 0)){
                vis[i] ^= 1;
                solve(n,pos+1);
                vis[i] ^= 1;
            }
        }
    }
    
    int countArrangement(int n) {
        solve(n, 1);
        return cnt;
    }
};