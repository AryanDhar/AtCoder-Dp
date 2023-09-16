#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(x) = if some starts with a pile of x stones whether he will win or not...
// f(x) = 1 if for any i f(x-a[i])=0 else 0

string stones(vector<int> &a, int k)
{
    vector<bool> dp(k+1, false);
    for(int i=1; i<=k; i++)
    {
        for(int val: a)
        {
            if(val>i) continue;
            if(dp[i-val]==0) dp[i]=true;
        }
    }
    return dp[k]?"First":"Second";
}

int32_t main()
{
    int n, k; cin>>n>>k;
    vector<int> a(n);
    rep(i, 0, n) cin>>a[i];
    cout<<stones(a, k)<<endl;
}

// O(k^2)