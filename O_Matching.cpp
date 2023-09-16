#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// M, W
// if we pair ith guy with jth chick...we are left to pair M-{i} with W-{j} women...

// f(i, x) - no of ways to pair men from [i...n] with women left in X.

int solve(int i, int msk, int n, vvi &c, vvi &dp)
{
    if(i==n+1) return((msk==0)?1:0);
    if(dp[i][msk]!=-1) return dp[i][msk];
    int ans=0;
    for(int w=0; w<n; w++)
    {
        bool flag=((1<<w)&msk)?1:0;
        if(flag && c[i][w+1]==1) ans=(ans+solve(i+1, msk^(1<<w), n, c, dp)%mod)%mod;
    }
    return dp[i][msk]=ans;
}

int32_t main()
{
    int n; cin>>n;
    vvi c(n+1, vi(n+1));
    vvi dp(22, vi((1<<22), -1));
    rep(i, 1, n+1) rep(j, 1, n+1) cin>>c[i][j];
    cout<<solve(1, (1<<n)-1, n, c, dp)<<endl;
}

// O(n*(2^n))