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
        
        void strcheck(string cur, vector<string>& res, string s)
        {
            if(s.size() == 0) {
                res.push_back(cur.substr(1));
                return;
            }
            for(int i=1;i<=s.size();i++)
            {
                string str = s.substr(0,i);
                if(findsubstr(str))
                {
                    strcheck(cur + " " + str, res, s.substr(i));
                }
            }
        }        
    };

    
    vector<string> wordBreak(string s, vector<string>& Dict) {
        Trie t;
        for(int i=0;i<Dict.size();i++)
            t.create(Dict[i]);
        string str = "";
        vector<string> res;
        t.strcheck(str,res,s);
        return res;
    }
};