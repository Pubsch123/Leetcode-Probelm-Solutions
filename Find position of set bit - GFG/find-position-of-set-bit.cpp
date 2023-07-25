//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int flag = false;
        int ans = -1;
        for(int i=0;i<32;i++)
        {
            int x = 1<<i;
            if(x&N){
                ans = i+1;
                if(flag) return -1;
                flag = true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends