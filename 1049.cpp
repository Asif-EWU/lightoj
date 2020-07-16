#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             5e18
#define sf              scanf
#define pf              printf
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define nl              printf("\n")
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

int main()
{
    int test;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        int n, a, b, c, sum1=0, sum2=0;
        bool left[105]={0}, right[105]={0};

        fs(n);
        for(int i=0; i<n; i++)
        {
            fs(a);fs(b);fs(c);

            if(!left[a] && !right[b])
            {
                left[a]=right[b]=true;
                sum1+=c;
            }
            else
            {
                left[b]=right[a]=true;
                sum2+=c;
            }
        }

        pf("Case %d: %d\n",t,min(sum1,sum2));
    }

    return 0;
}
