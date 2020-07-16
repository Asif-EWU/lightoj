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
#define M               100005
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

int arr[M], mn, mx, a, b;

void binarySearch1(int left, int right)
{
    int mid;

    if(left<=right)
    {
        mid=(left+right)/2;

        if(arr[mid]>=a)
        {
            mn=min(mn,mid);
            binarySearch1(left,mid-1);
        }

        if(arr[mid]<a)
        {
            binarySearch1(mid+1,right);
        }
    }
}

void binarySearch2(int left, int right)
{
    int mid;

    if(left<=right)
    {
        mid=(left+right)/2;

        if(arr[mid]<=b)
        {
            mx=max(mx,mid);
            binarySearch2(mid+1,right);
        }

        if(arr[mid]>b)
        {
            binarySearch2(left,mid-1);
        }
    }
}


int main()
{
    int test, n, q, res;
    fs(test);
    for(int t=1; t<=test; t++)
    {
        printf("Case %d:\n",t);

        fs(n), fs(q);
        for(int i=1; i<=n; i++) fs(arr[i]);
        for(int i=1; i<=q; i++)
        {
            fs(a), fs(b);
            mn=INT_MAX;
            mx=0;
            binarySearch1(1,n);
            binarySearch2(1,n);

            res=mx-mn+1;
            printf("%d\n",max(res,0));
        }
    }

    return 0;
}
