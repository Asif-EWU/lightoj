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

int test, n, a;
int arr[205][205];
int dp[205][205];

int fun(int x, int y)
{
    if(x==2*n)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];

    int a=0, b=0;
    if(x<n)
    {
        a=arr[x][y]+fun(x+1,y);
        b=arr[x][y]+fun(x+1,y+1);
    }
    else
    {
        if(arr[x+1][y]!=-1)
            a=arr[x][y]+fun(x+1,y);
        if(y-1>0)
            b=arr[x][y]+fun(x+1,y-1);
    }
    return dp[x][y]=max(a,b);
}


int main()
{
    int i, j, k;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(i=n+1, k=n-1; i<=2*n-1; i++,k--)
        {
            for(j=1; j<=k; j++)
            {
                scanf("%d",&arr[i][j]);
            }
            for( ; j<=n; j++)
            {
                arr[i][j]=-1;
            }
        }

        printf("Case %d: %d\n",t,fun(1,1));
    }

    return 0;
}
