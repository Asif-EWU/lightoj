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
#define sync            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
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

int coin[55], num_of_coin[55], dp[55][1005];

int fun(int pos, int n)
{
    if(n==0) return 1;
    if(pos==-1) return 0;
    if(dp[pos][n]!=-1) return dp[pos][n];

    int a=0;
    for(int i=0; i<=num_of_coin[pos]; i++)
        if(i*coin[pos]<=n) a+=fun(pos-1,n-(i*coin[pos]));
    return dp[pos][n]=a;
}


int32_t main()
{
    sync;
    int test, n, k;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof(dp));

        cin >> n >> k;
        for(int i=0; i<n; i++) cin >> coin[i];
        for(int i=0; i<n; i++) cin >> num_of_coin[i];

        cout << "Case " << t << ": " << fun(n-1,k) << endl;
    }

    return 0;
}
