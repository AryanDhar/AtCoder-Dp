#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// dp[i][j]=length of lis till index i in s1, index j in s2...

// subseuquence is like a subset where relative ordering matters..it should be same...

int32_t main()
{
    string s, t; cin>>s>>t;
    int n=s.size(), m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // first row(0, j), first col(i, 0) = 0 
    rep(i, 1, n+1)
    {
        rep(j, 1, m+1)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int ans=dp[n][m];
    string str(ans, ' ');
    int i=n, j=m;
    while(i>0&&j>0)
    {
        if(s[i-1]==t[j-1])
        {
            str[ans-1]=s[i-1];
            i--, j--, ans--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    cout<<str<<endl;
}

// O(n^2)