#include<bits/stdc++.h>
using namespace std;

void build(string str, vector <string> &tree, int idx, int s, int e)
{
    if(s == e)
    {
        tree[idx] = str[s];
    }
    else
    {
        int m = (s + e) / 2;
        int lc = 2 * idx + 1;
        int rc = 2 * idx + 2;
        
        build(str, tree, lc, s, m);
        build(str, tree, rc, m + 1, e);
        
        tree[idx] += (tree[lc] + tree[rc]);
    }
}

string query(vector <string> &tree, int idx, int s, int e, int l, int r)
{
    if(l > e || s > r)
        return "";
    
    if(l <= s && r >= e)
        return tree[idx];
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    return query(tree, lc, s, m, l, r) + query(tree, rc, m + 1, e, l, r);
}

void update(vector <string> &tree, int idx, int s, int e, int i)
{
    if(i < s || i > e)
        return;
    
    if(s == e)
    {
        //cout << s << " s " << tree[idx] << " idx " << idx << endl;
        if(tree[idx] == "0")
        {
            tree[idx] = "";
            tree[idx] += "1";
            return;
        }
        else
            return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(tree, lc, s, m, i);
    update(tree, rc, m + 1, e, i);
    
    tree[idx] = "";
    tree[idx] += tree[lc] + tree[rc];
    //cout << idx << " " << lc << " " << rc << " " << tree[idx] << " " << tree[lc] << " " << tree[rc] << endl;
}

int main() 
{    
    vector <string> tree;
    vector <int> ans;
    
    string str = "1111001111000010000000011101111001110111001011010111101100000100001100010011101011001001100110101111010111101101110100000000010000001011101010111110101010001001101101101110001100001010110100011011100110010111101110111101111110010101110001110100110000010100101011100011101011000100110010010101101100011010111111110011000110100001000010001111000010011011010001011000011000010011111001001101010011100110011011011000111010001010110111111010011011001100101110100001010011011011001011110101000010000111000011111111011011011111011101100111101000000110001101011110111010011111001011101010111110001111110100100010001110000100110100100110110000000010101001011001100010111001010110001100010100101000100001101110010100110100101001111110000010000110111000010100110111010100000100000011000100011011101111110111000000101011010000010011101100100111001011010101110011101111010010100001011111011000001101111100000011001001011101000111011001010101011000111000110100100010111110101010011000110001011010001011011000110000";
    int i, n = str.length();
   
    for(i = 0; i < 3*n; i++)
        tree.push_back("");
    
    build(str, tree, 0, 0, n - 1);

    // for(i = 0; i < tree.size(); i++)
    //     cout << tree[i] << " ";
    // cout << endl;

    int b[][3] = {
        {0, 153, 456},
        {0, 1, 8},
        {1, 3, -1},
        {0, 1, 8}
    };

    for(i = 0; i < 4; i++)
    {
        if(b[i][0] == 1)
        {
            update(tree, 0, 0, n - 1, b[i][1] - 1);
            ans.push_back(-1);
            // for(int j = 0; j < tree.size(); j++)
            //     cout << tree[j] << " ";
            // cout << endl;
        }
        else
        {
            // long long x;
            // x = stoull( query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1), 0, 2);
            
            string out = "";
            out += query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1);
            long long len = out.length();
            long long val = 0;
            long long power = 1;
            
            for(long long j = len - 1; j >= 0; j--)
            {
                if(out[j] == '1')
                    val = (val + power) % 1000000009;
                power *= 2 % 1000000009;
                cout << val << " ";
            }
            
            cout << val << endl;
            val = val % 3;
            ans.push_back(val);
        }
    }
    
    for(i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
return 0;
}
