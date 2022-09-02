struct Node{
    Node* links[2];
    Node* getnode(int ch)
    {
        return links[ch];
    }
    void putnode(int ch, Node* node)
    {
        links[ch] = node;
    }
    bool contains(int ch)
    {
        return links[ch] != NULL;
    }
};


class Trie{
    private: Node* root;
    public: 
    Trie(){
        root = new Node();
    }
    
    void insert(int val)
    {
        Node* node = root;
        for(int i = 31;i >= 0;i--)
        {
            int c = (val >> i) & 1;
            if(!node->contains(c))
            {
                node->putnode(c,new Node());
            }
            node = node->getnode(c);
        }
    }
    
    int getmax(int val)
    {
        Node* node = root;
        int mx = 0;
        for(int i=31;i>=0;i--)
        {
            int c = (val >> i)&1;
            if(node->contains(1-c))
            {
                mx |= (1 << i);
                node = node->getnode(1-c);
            }
            else
            {
                node = node->getnode(c);    
            }
        }
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int n = nums.size();
        for(int i=0;i<n;i++)
            t.insert(nums[i]);
        int res = 0;
        for(int i=0;i<n;i++)
            res = max(res,t.getmax(nums[i]));
        return res;
    }
};