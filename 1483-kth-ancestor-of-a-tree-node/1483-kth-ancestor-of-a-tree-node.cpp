class TreeAncestor {
public:
    
    // BINARY LIFTING
    
    int max = 17;
    int matrix[17][50002];
    
    void build(vector<int>& parent, int& n)
    {
        for(int i=0;i<n;i++)
            matrix[0][i] = parent[i];
        for(int i=1;i<max;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i-1][j] != -1)
                matrix[i][j] = matrix[i-1][matrix[i-1][j]];
                else matrix[i][j] = -1;
            }
    }
    
    
    TreeAncestor(int n, vector<int>& parent) {
        build(parent,n);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<max;i++)
        {
            int mask = (1<<i);
            if(k&mask)
            {
                if(matrix[i][node] == -1)
                   {node = -1; break;}
                node = matrix[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */