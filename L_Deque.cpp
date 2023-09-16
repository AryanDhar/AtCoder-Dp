#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// i and j are pointers to that sequence...
// f(i, j) = max(a[i]-f(i+1, j), a[j]-f(i, j+1))

int f(int i, int j, vi &a, vvi &dp)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return dp[i][j]=a[i];
    return dp[i][j]=max(a[i]-f(i+1, j, a, dp), a[j]-f(i, j-1, a, dp));
}

int32_t main()
{
    int n; cin>>n; 
    vi a(n);
    rep(i, 0, n) cin>>a[i];
    vvi dp(n, vi(n, -1));
    cout<<f(0, n-1, a, dp)<<endl;
}

// O(n^2)