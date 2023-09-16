#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(i) - minimum cost req to reach from 0th stone to ith stone...

int32_t main()
{
    int n; cin>>n;
    vi h(n, 0), dp(n, 1e9);
    rep(i, 0, n) cin>>h[i];
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    if(n==1)
    {
        cout<<dp[0]<<endl;
        return 0;
    }
    rep(i, 2, n) dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    cout<<dp[n-1]<<endl;
}

// O(n)