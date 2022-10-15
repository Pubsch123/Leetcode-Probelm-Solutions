class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "",ptr = "", ctr = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int k = 0;
            for(int j=0;j<strs[i].size() && k < ctr.size();j++,k++)
            {
                if(strs[i][j] == ctr[k])
                    ptr += ctr[k];
                else
                   {ctr = ptr;break;}
            }
            ctr = ptr;
            ptr = "";
        }
        return ctr;
    }
};