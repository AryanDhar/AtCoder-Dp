#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;


int32_t main()
{
    int n, a, b, c; cin>>n>>a>>b>>c;
    vector<vector<int>> dp(3, vector<int>(n, 0));
    dp[0][0]=a, dp[1][0]=b, dp[2][0]=c;
    rep(i, 1, n)
    {
        cin>>a>>b>>c;
        dp[0][i]+=a+max(dp[1][i-1], dp[2][i-1]);
        dp[1][i]+=b+max(dp[0][i-1], dp[2][i-1]);
        dp[2][i]+=c+max(dp[0][i-1], dp[1][i-1]);
    }
    cout<<max({dp[0][n-1], dp[1][n-1], dp[2][n-1]})<<endl;
}

// O(n)