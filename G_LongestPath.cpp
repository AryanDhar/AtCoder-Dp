#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;
vector<vector<int>> graph(100001);
vector<int> dp(100001, -1);

int dfs(int src)
{
    if(dp[src]!=-1) return dp[src];
    int res=INT_MIN;
    bool flag=true;
    for(int child: graph[src])
    {
        flag=false;
        res=max(res, 1+dfs(child));
    }
    return dp[src]=flag?0:res;
}

int32_t main()
{
    int n, m; cin>>n>>m;
    while(m--)
    {
        int x, y; cin>>x>>y;
        graph[--x].push_back(--y);
    }
    int ans=INT_MIN;
    rep(i, 0, n) ans=max(ans, dfs(i));
    cout<<ans<<endl;
}

// O(n+m) O(v+e) v is the number of vertices and e is the no of edges...