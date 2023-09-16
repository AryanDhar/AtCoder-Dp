#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

vi adj[100001];
vvi dp(100001, vi(2, 1));

// dp(u, 1) = pi(dp(c, 0) + dp(c, 1))
// dp(u, 0) = pi(dp(c, 1))

void dfs(int node=0, int par=-1)
{
    for(int child: adj[node])
    {
        if(child!=par)
        {
            dfs(child, node);
            dp[node][0]=(dp[node][0]*dp[child][1])%mod;
            dp[node][1]=(dp[node][1]*(dp[child][1]+dp[child][0])%mod)%mod;
        }
    }
}

int32_t main()
{
    int n; cin>>n;
    for(int i=0, a, b; i<n-1; i++)
    {
        cin>>a>>b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   
    dfs(); // precompute...
    cout<<(dp[0][0]+dp[0][1])%mod<<endl;
}
// O(2*n)