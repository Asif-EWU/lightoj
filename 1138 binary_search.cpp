/*
........................................................
........................................................
তুমি ছেলেহারা মা জাহানারা ইমামের একাক্তরের দিনগুলি
তুমি জসিম উদদীনের নকশী কাথার মাঠ, মুঠো মুঠো সোনার ধুলি
তুমি তিরিশ কিংবা তার অধিক লাখো শহীদের প্রাণ
তুমি শহীদ মিনারের প্রভাতফেরী, ভাইহারা একুশের গান
........................................................
........................................................
*/

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
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause");
#define MOD             1000000007
#define M               1000000000
#define MX              50005

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

int cal(int x)
{
    ll a;
    int b=0;

    for(int i=1; ; i++)
    {
        a=x/pow(5,i);
        if(a==0) break;
        b+=a;
    }

    return b;
}

int n, mn;

void binarySearch(int l, int r)
{
    int mid, res;

    if(l<=r)
    {
        mid=(l+r)/2;
        res=cal(mid);

        if(res>=n)
        {
            if(res==n) mn=min(mn,mid);
            binarySearch(l,mid-1);
        }
        if(res<n) binarySearch(mid+1,r);
    }
}


int main()
{
    int test;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        fs(n);
        mn=INT_MAX;
        binarySearch(1,M);

        if(mn==INT_MAX) printf("Case %d: impossible\n",t);
        else printf("Case %d: %d\n",t,mn);
    }

    return 0;
}
