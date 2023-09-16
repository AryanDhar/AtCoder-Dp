#include<bits/stdc++.h>
// #define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

int main()
{
    int n, k; cin>>n>>k;
    vi h(n, 0), dp(n, 1e9);
    rep(i, 0, n) cin>>h[i];
    dp[0]=0;
    rep(i, 1, n)
        rep(j, 1, k+1)
            if(i-j>0) dp[i]=min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    cout<<dp[n-1]<<endl;
}

// O(n*k)