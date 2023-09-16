#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int mod=1e9+7;

// 1[s0, s1, s2, s3] -> 2[s0, s1, s2, s3](s0/n) + 3[s0+1, s1-1, s2, s3](s1/n) + 4[s0, s1+1, s2-1, s3](s2/n)+5[s0, s1, s2+2, s3-1](s3/n).
// E(1) - [1+E(2)](s0/n)+[1+E(3)](s1/n)+[1+E(4)](s2/n)+[1+E(5)](s3/n);
// dp[n][n][n][n] -> dp[n][n][n]      *1st OPTIMIZATION*
// s0 = n-s1-s2-s3..

// E(1) - [1+E(1)](p0)+[1+E(3)](p1)+[1+E(4)](p2)+[1+E(5)](p3);
// E(1)[1-p(0)]=states*probabilites..


const int N=301;
double dp[N][N][N];

int32_t main()
{
    int n, C1=0, C2=0, C3=0; cin>>n;
    rep(i, 0, n)
    {
        int x; cin>>x;
        C1+=(x==1);
        C2+=(x==2);
        C3+=(x==3);
    }
    // 2nd optimization... order of loops
    for(int c3=0; c3<=C3; c3++) // 4th optimization  c3<=C3
    {
        for(int c2=0; c2<=n; c2++)
        {
            for(int c1=0; c1<=n; c1++)
            {
                int c0=n-c1-c2-c3;
                if(c1+c2+c3>n) continue;
                if(c0==n)
                {
                    dp[c1][c2][c3]=0;
                    continue;
                }
                double p1=1.0*c1/n, p2=1.0*c2/n, p3=1.0*c3/n;
                // for a particular c1 c2 - c3 is always decreasing...
                // dp[x][x][y][y] -> dp[x][x][y+1][y-1]
                double d3=(c3>0)?dp[c1][c2+1][c3-1]:0;
                double d2=(c2>0)?dp[c1+1][c2-1][c3]:0;
                double d1=(c1>0)?dp[c1-1][c2][c3]:0;
                dp[c1][c2][c3]=(1+d1*p1+d2*p2+d3*p3)/(1-1.0*c0/n);
                // 3rd Opt
                if(c1==C1 && c2==C2 && c3==C3)
                {
                    cout<<fixed<<setprecision(10)<<dp[C1][C2][C3]<<endl;
                    return 0;
                }
                // 5th optimization - dp[c3-1]=prev, dp[c3]=cur..
            }
        }
    }
}
// O(N^3)