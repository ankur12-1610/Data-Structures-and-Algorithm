class Solution {
public:

int tabulation(string t1, string t2)
{
    vector<int>curr(t2.length()+19,0);
    vector<int>next(t2.length()+19,0);
 
    for(int i = t1.length()-1;i>=0;i--)
    {
        for(int j =t2.length()-1;j>=0;j--)
        {
            int ans =0;
            if(t1[i]==t2[j])
            {
                ans=1+next[j+1];
            }
            else
            {
                ans=max(next[j],curr[j+1]);
            }
            curr[j]=ans;
        } 
        next=curr;
    }
    return curr[0];
}

    int longestPalindromeSubseq(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        return tabulation(s,str);
    }
};
