#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

int32_t main()
{
    int n, m; cin>>n>>m;
    vector<vector<char>> grid(n+1, vector<char>(m+1, 0));
    rep(i, 1, n+1)
    {
        string s; cin>>s;
        rep(j, 1, m+1) grid[i][j]=s[j-1];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[n][m]=1;
    for(int i=n; i>=1; i--)
    {
        for(int j=m; j>=1; j--)
        {
            if(i==n && j==m) continue;
            if(grid[i][j]=='#')
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=(((i==n)?0:dp[i+1][j])%mod+((j==m)?0:dp[i][j+1])%mod)%mod;
        }
    }
    cout<<dp[1][1]<<endl;
}

// O(n^2)