#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

/*
    a b c d
    a+b c d
    a+b+c d
    a+b+c+d

    a b c d
    a b c+d
    a b+c+d
    a+b+c+d

    a b c d
    a+b c+d f(1) f(2)
    a+b+c+d sum(1, 2)
*/

// f(i, j) = f(i, k)+f(k+1, j)+sum(i, j)
// we will add upto left side slime and right side slime and merge them into one slime...
// we will imagine that is the last step before merging and reverse the process...
// O(n^3)
// KNUTH optmization...

int f(int i, int j, vi &a, vvi &dp, vvi &sum)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1e18;
    for(int k=i; k<j; k++) ans=min(ans, f(i, k, a, dp, sum)+f(k+1, j, a, dp, sum)+sum[i][j]);
    return dp[i][j]=ans;
}

int32_t main()
{
    int n; cin>>n;
    vi a(n+1, 0);
    vvi dp(n+1, vi(n+1, -1)), sum(n+1, vi(n+1, 0));
    rep(i, 1, n+1) cin>>a[i];
    rep(i, 1, n+1) rep(j, 1, n+1) sum[i][j]=a[j]+((i==j)?0:sum[i][j-1]);
    cout<<f(1, n, a, dp, sum)<<endl;
}