vector<int> Solution::grayCode(int a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i;
    vector <int> ans;
    
    for(i = 0; i < pow(2, a); i++)
    {
        ans.push_back(i ^ ( i >> 1));
    }
    
    return ans;
}
