    #include<bits/stdc++.h>
    #define fl(n)           for(int i=0; i<n; i++)
    #define loop(i, a, n)   for(int i=a; i<n; i++)
    #define pb              push_back
    #define pp              pop_back
    #define ll              long long int
    #define ld              long double
    #define inf             5e18
    #define sf              scanf
    #define Sf(a)           scanf("%lf",&a)
    #define pf              printf
    #define Pfc(a)          printf("Case %d: ",a)
    #define Pfl(a)          printf("%lld",a)
    #define Pfi(a)          printf("%d",a)
    #define nl              printf("\n")
    #define Vl              vector<ll>
    #define Vi              vector<int>
    #define fin             freopen("input.txt", "r", stdin)
    #define fout            freopen("outut.txt", "w", stdout)
    #define PI              2*acos(0.0)
    #define F               first
    #define S               second
    #define gcd(x,y)        __gcd(x,y)
    #define lcm(a,b)        (a*b)/gcd(a,b)
    #define PS              system("pause")
    #define BM              bool mark[M+10]
    #define MOD             1000000007
    #define M               1000

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

    int arr[1007];
    void sieve()
    {
        for(int i=1; i<=1000; i++)
        {
            for(int j=i; j<=1000; j+=i)
            {
                arr[j]++;
            }
        }
    }

    struct st
    {
        int a;
        int b;
    };
    bool compare(st x, st y)
    {
        if(x.b==y.b)
        {
            return x.a>y.a;
        }
        return x.b<y.b;
    }


    int main()
    {
        sieve();

        st brr[1007];
        for(int i=1; i<=1000; i++)
        {
            brr[i-1].a=i;
            brr[i-1].b=arr[i];
        }

        sort(brr,brr+1000,compare);

        int t, n;
        fs(t);
        for(int i=1; i<=t; i++)
        {
            fs(n);
            pf("Case %d: %d\n",i,brr[n-1].a);
        }

        return 0;
    }
