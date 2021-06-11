struct trie
{
    map <char, struct trie *> reference;
    int count = 0;
};

void build(struct trie * root, string s)
{
    struct trie * crawler = root;
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(crawler -> reference[c] == NULL)
        {
            crawler -> reference[c] = new trie;
        }
        crawler = crawler -> reference[c];
        crawler -> count = crawler -> count + 1;
    }
}

int query(struct trie * root, string s)
{
    struct trie * crawler = root;
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(crawler -> reference[c] == NULL)
            return 0;
        crawler = crawler -> reference[c];
    }
    
    if(crawler)
        return crawler -> count;
    return 0;
}

vector<int> Solution::solve(vector<int> &a, vector<string> &b) {
    
    struct trie * root = new trie;
    
    vector <int> ans;
    int i;
    
    for(i = 0; i < a.size(); i++)
    {
        if(a[i] == 0)
            build(root, b[i]);
        else
            ans.push_back(query(root, b[i]));
    }
    
    return ans;
}
