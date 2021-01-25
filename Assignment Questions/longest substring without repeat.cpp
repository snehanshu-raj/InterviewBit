
int Solution::lengthOfLongestSubstring(string a) {
    int chars[256];
    int i;
    
    for(i = 0; i < 256; i++)
        chars[i] = -1;
    
    int cur_len = 0, max_len = 0;
    
    for(i = 0; i < a.length(); i++)
    {
        if(chars[ a[i] ] == -1 || i - cur_len > chars[ a[i] ])
            cur_len++;
        else
        {
            max_len = max(max_len, cur_len);
            
            cur_len = i - chars[ a[i] ];
        }
        chars[ a[i] ] = i;
    }
    max_len = max(max_len, cur_len);
return max_len;
}
