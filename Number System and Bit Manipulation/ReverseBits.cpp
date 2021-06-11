using namespace std;
unsigned int Solution::reverse(unsigned int a) {
    int rev[32] = { 0 };
    int i = 0;
    for(int j = 31; j >= 0; j--)
    {
        if((1 << j & a) > 0)
            rev[i++] = 1;
        else
            rev[i++] = 0;
    }
    
    std::reverse(rev, rev + 32);
    
    unsigned ans = 0;
    
    for(i = 0; i < 32; i++)
    {
        if(rev[i] == 1)
            ans += 1 << (31 - i);
    }
return ans;
}
