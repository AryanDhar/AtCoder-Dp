#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(i, x) - gives the probability of getting x heads in coins...
// f(i, x) - f(i-1, x-1)*p+f(i-1, x)*(1-p)

long double dp[3001][3001];

int32_t main()
{
    int n; cin>>n;
    vector<long double> p(n);
    rep(i, 0, n) cin>>p[i];
    int x=n/2+1;
    for(int i=0; i<n; i++) dp[i][0]=1;
    rep(i, 1, n+1) rep(j, 1, x+1) dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1-p[i-1]);
    cout<<fixed<<setprecision(10)<<dp[n][x]<<endl;
}

// O(n^2)