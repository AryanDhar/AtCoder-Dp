#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// f(i, j) - max profit we can get till the ith item with largest wt j...

int32_t main()
{
    int n, w; cin>>n>>w;
    vector<int> val(n, 0), wt(n, 0), dp1(w+1, 0), dp2(w+1, 0);
    rep(i, 0, n) cin>>wt[i]>>val[i];
    rep(i, 0, n)
    {
        rep(j, 1, w+1)
        {
            if(wt[i]>j) dp2[j]=dp1[j];
            else dp2[j]=max({dp2[j], dp1[j], val[i]+dp1[j-wt[i]]});
        }
        dp2.swap(dp1);
        dp2.clear();
    }
    cout<<dp1[w]<<endl;
}

// O(n*w)