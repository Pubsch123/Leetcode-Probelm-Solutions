struct Node{
    Node* links[26];
    bool flag = false;
    bool contains(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    
    void putnode(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void setflag()
    {
        flag = true;
    }
    
    bool getflag()
    {
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string &word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->contains(word[i]))
            {
                node->putnode(word[i],new Node());
            }
            node = node->getnode(word[i]);
        }
        node->setflag();
    }
    
    bool checkforprefix(string &word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->contains(word[i]))
            {
                node = node->getnode(word[i]);
                if(node->getflag() == false) return false;
            }else return false;
        }
        return true;
    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        string longest = "";
        Trie t;
        for(int i=0;i<words.size();i++)
            t.insert(words[i]);
        for(int i=0;i<words.size();i++)
        {
            if(t.checkforprefix(words[i]) == true) 
            {
                if(longest.size() < words[i].size())
                {
                    longest = words[i];
                }
                else if(longest.size() == words[i].size() && words[i] < longest)
                {
                    longest = words[i];
                }
            }
        }
        return longest;
    }
};