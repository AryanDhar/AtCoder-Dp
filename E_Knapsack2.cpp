#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(i, v) - that gives us the min wt req so that value of selected items is v till ith element...

/*
    f(i, v) - if(val[i]>v) f(i-1, v)
              else min(f(i-1, v), wt[i]+f(i-1, v-val[i]))
*/

// ans will be for i=n-1, max value of column such that dp[n-1][j]<=W(knapsack)...

int32_t main()
{
    int n, w; cin>>n>>w;
    vi val(n, 0), wt(n, 0), dp1(n*1e3+1, 1e18), dp2(n*1e3+1, 1e18);
    rep(i, 0, n) cin>>wt[i]>>val[i];
    dp1[0]=0;
    dp1[val[0]]=wt[0]; // only two elements are to be filled in first row..
    rep(i, 1, n)
    {
        rep(j, 0, n*1e3+1)
        {
            if(val[i]>j) dp2[j]=dp1[j];
            else dp2[j]=min({dp2[j], dp1[j], wt[i]+dp1[j-val[i]]});
        }
        dp2.swap(dp1);
        dp2.clear();
    }
    int ans=0;
    rep(i, 0, n*1e3+1) if(dp1[i]<=w) ans=i;
    cout<<ans<<endl;
}

// O(n*v)