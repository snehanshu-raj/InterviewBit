struct trie
{
    map <char, struct trie *> reference;
    int count = 0;
};

void build(struct trie *root, string s)
{
    struct trie * trie_traverser = root;
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(trie_traverser -> reference[c] == NULL)
        {
            trie_traverser -> reference[c] = new trie;
        }
        trie_traverser = trie_traverser -> reference[c];
        trie_traverser -> count = trie_traverser -> count + 1;
    }
}

string query(struct trie *root, string s)
{
    struct trie * trie_traverser = root;
    string prefix = "";
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        prefix += c;
        
        trie_traverser = trie_traverser -> reference[c];
        if(trie_traverser -> count == 1)
            return prefix;
    }
    
    return prefix;
}

vector<string> Solution::prefix(vector<string> &a) {
    
    vector <string> ans;
    struct trie * root = new trie;
    
    int i;
    for(i = 0; i < a.size(); i++)
        build(root, a[i]);
    
    for(i = 0; i < a.size(); i++)
        ans.push_back(query(root, a[i]));
    
    return ans;
}
