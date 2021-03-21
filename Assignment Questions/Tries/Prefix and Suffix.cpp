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

int query(struct trie *root, string pre_suf)
{
    struct trie * trie_traverser = root;
    
    for(int i = 0; i < pre_suf.length(); i++)
    {
        char c = pre_suf[i];
        
        if(trie_traverser -> reference[c] == NULL)
            return 0;
        trie_traverser = trie_traverser -> reference[c];
    }
    
    if(trie_traverser)
        return trie_traverser -> count;
    return 0;
}

vector<int> Solution::solve(vector<string> &a, vector<string> &b) {
    
    struct trie * root = new trie;
    
    int l = b[0].size();
    int i, x, y;
    
    for(i = 0; i < a.size(); i++)
    {
        if(a[i].size() < l)
            continue;
        
        string s = a[i];
        x = 0, y = s.length() - l;
        int f = 0;
        
        while(x < l)
        {
            if(s[x] != s[y])
            {
                f = 1;
                break;
            }
            x++;
            y++;
        }
        
        if(f == 0)
            build(root, s);
    }
    
    vector <int> ans;
    for(i = 0; i < b.size(); i++)
    {
        ans.push_back(query(root, b[i]));
    }
    
    return ans;
}
