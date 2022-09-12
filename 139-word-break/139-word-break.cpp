class Solution {
public:
    
    struct Node{
        Node* links[26];
        bool flag = false;
        Node(){
            for(int i=0;i<26;i++) links[i] = NULL;
        }
        void setflag()
        {
            flag = true;
        }
        bool getflag()
        {
            return flag;
        }
        Node* getNode(char ch)
        {
            return links[ch-'a'];
        }
        void addNode(char ch, Node* newNode)
        {
            links[ch-'a'] = newNode;
        }  
        bool contains(char ch)
        {
            return links[ch-'a'] != NULL;
        }
    };
    
    
    class Trie{
        private: Node* root;
        public:
        Trie(){
            root = new Node();
        }
        Node* getroot()
        {
            return root;
        }
        
        void create(string s)
        {
            Node* node = root;
            for(int i=0;i<s.size();i++)
            {
                if(!node->contains(s[i]))
                    node->addNode(s[i],new Node());
                node = node->getNode(s[i]);
            }
            node->setflag();
        }
        
        int findsubstr(string s)
        {
            Node* node = root;
            for(int i=0;i<s.size();i++)
            {
                if(!node->contains(s[i])) return false;
                node = node->getNode(s[i]);
            }
            return node->getflag();
        }
        
        // bool strcheck(string s)
        // {
        //     if(s.size() == 0) return true;
        //     for(int i=1;i<=s.size();i++)
        //         if(findsubstr(s.substr(0,i)) && strcheck(s.substr(i,s.size()))) 
        //             return true;
        //     return false;
        // }
        
         bool findString(int i, string s, vector<int>& res){
            if(s.size() == 0){
                return true;
            }
            if(res[i]==0) return false;
            if(res[i]==1) return true;
            for(int j=1;j<=s.length();j++){
                if(this->findsubstr(s.substr(0, j)) && findString(i+j, s.substr(j), res)){
                    res[i] = 1;
                    return true;
                }
            }
            res[i] = 0;
            return false;
        }
        
    };

    
    bool wordBreak(string s, vector<string>& Dict) {
        Trie t;
        for(int i=0;i<Dict.size();i++)
            t.create(Dict[i]);
        vector<int>res(s.length()+1, -1);
        return t.findString(0, s, res);
        // return t.strcheck(s);
    }
};