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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             1000000007
#define M               1000000000
#define MX              200005

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

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

int main()
{
    int test, a;
    string s;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        scanf("%d",&a);
        cin >> s;

        if(s=="Alice")
        {
            if((a-1)%3==0)
                printf("Case %d: Bob\n",t);
            else
                printf("Case %d: Alice\n",t);
        }
        if(s=="Bob")
        {
            if(a%3==0)
                printf("Case %d: Alice\n",t);
            else
                printf("Case %d: Bob\n",t);
        }
    }

    return 0;
}
