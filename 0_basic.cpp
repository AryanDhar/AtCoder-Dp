#include<bits/stdc++.h>
using namespace std;

// Recursion - O(1<<n)

// Memoization(Top Down) - O(n)... We are using an extra O(n) for auxilary stack space..

// Tabulation(Bottom up) - O(n)

// Space Optimization - 

int f(int n)
{
    // if(dp[n]!=-1) return dp[n];
    // return dp[n]=(n<=1)?n:f(n-1, dp)+f(n-2, dp);

    // dp[0]=0, dp[1]=1;
    // for(int i=2; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    // return dp[n];

    int a=0, b=1;
    for(int i=2; i<=n; i++)
    {
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
}

// 0 1 1 2 3 5 8 13...

int main()
{
    int n; cin>>n;
    vector<int> dp(n+1, -1);
    cout<<f(n)<<endl;
}