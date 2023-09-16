#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(i, j) - no. of ways to distribute j candies to [1...i] children..
// f(i, j) - f(i-1, j) + f(i-1, j-1) + ... f(i-1, j-a[i]);
// f(1, j) - {1 if j<=a[i], 0 if j>a[i]}

// T.C. - n*k*k...TLE...

// f(i, j) = f(i-1, j) + f(i-1, j-1) .... f(i-1, j-a[i])
// f(i, j-1) = f(i-1, j-1) + f(i-1, j-2) .... f(i-1, j-a[i]) + f(i-1, j-a[i]-1);

// f(i, j) = f(i-1, j) + f(i, j-1) + f(i-1, j-a[i]-1); Transition func is O(1) instead of O(k)...

int solve(vi &a, int n, int k, vvi &dp)
{
    rep(j, 0, k+1) dp[1][j]=(j>a[1])?0:1; // base case
    rep(i, 2, n+1)
        rep(j, 0, k+1)
        {
            if(j==0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod-((j-a[i]-1>=0)?dp[i-1][j-a[i]-1]:0)%mod+mod)%mod;
        }
    return dp[n][k]; 
}

int32_t main()
{
    int n, k; cin>>n>>k;
    vi a(n+1, 0);
    vvi dp(101, vi(100001, 0));
    rep(i, 1, n+1) cin>>a[i];
    cout<<solve(a, n, k, dp)<<endl;
}

// O(n*k)