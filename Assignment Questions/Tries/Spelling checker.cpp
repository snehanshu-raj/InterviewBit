struct trie
{
    map <char, struct trie *> reference;
    bool is_leaf = false;
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
    }
    
    crawler -> is_leaf = true;
}

int query(struct trie * root, string s)
{
    struct trie * crawler = root;
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(crawler -> reference[c] == NULL)
        {
            return 0;
        }
        crawler = crawler -> reference[c];
    }
    
    if(crawler && crawler -> is_leaf == true)
        return 1;
    return 0;
}

vector<int> Solution::solve(vector<string> &a, vector<string> &b) {
    
    struct trie * root = new trie;
    
    int i;
    for(i = 0; i < a.size(); i++)
    {
        build(root, a[i]);
    }
    
    vector <int> ans;
    
    for(i = 0; i < b.size(); i++)
    {
        ans.push_back(query(root, b[i]));
    }
    
    return ans;
}
