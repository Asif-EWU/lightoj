#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define sync            ios::sync_with_stdio(0); cin.tie(0)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               100000000
#define MX              505

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

int red[25], grn[25], blu[25];
int n;
int dp[25][25];

int fun(int pos, int last)
{
    int x, y, z;
    x=y=z=INT_MAX;

    if(pos==n+1) return 0;
    if(dp[pos][last]!=-1) return dp[pos][last];

    if(last!=1) x=red[pos]+fun(pos+1,1);
    if(last!=2) y=grn[pos]+fun(pos+1,2);
    if(last!=3) z=blu[pos]+fun(pos+1,3);

    return dp[pos][last]=min(x,min(y,z));
}


int main()
{
    int test, a, b, c;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof(dp));

        fs(n);
        for(int i=1; i<=n; i++)
        {
            fs(red[i]);
            fs(grn[i]);
            fs(blu[i]);
        }

        pf("Case %d: %d\n",t,fun(1,0));
    }

    return 0;
}
