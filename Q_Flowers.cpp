#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// dp[x] will store the max beauty which can be formed till this index...
// 1  4  3
// 10 20 30
// 10 30 40

// we want both h, dp in increasing order

struct f
{
    int h, b;
};

int solve(vector<f> &a, int n)
{
    vi dp(n+1); // max beauty in lis ending at that place...
    map<int,int> mp; // height, dp
    dp[1]=a[1].b;
    mp[a[1].h]=a[1].b;
    int ans=dp[1];

    for(int i=2; i<=n; i++)
    {
        dp[i]=a[i].b; // each and every dp will have atleast that much beauty...
        auto it = mp.lower_bound(a[i].h+1);
        if(it!=mp.begin()) // if there exists some element before it...
        {
            it--;
            dp[i]+=it->second;
        }// so we can use this dp value to eliminate values with higher height and lower dp value..
        mp[a[i].h]=dp[i]; // now we will delete all values with more height and less dp value...
        it=mp.upper_bound(a[i].h);
        while(it!=mp.end() && it->second<=dp[i])
        {
            auto t=it;
            t++;
            mp.erase(it);
            it=t;
        }
        ans=max(ans, dp[i]);
    }

    return ans;
}

int32_t main()
{
    int n; cin>>n;
    vector<f> a(n+1);
    rep(i, 1, n+1) cin>>a[i].h;
    rep(i, 1, n+1) cin>>a[i].b;
    cout<<solve(a, n)<<endl;
}

// O(n* log(n))