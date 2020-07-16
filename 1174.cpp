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
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define BM              bool mark[M+10]
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

map<int,vector<int> >arr;
int level1[105];
int level2[105];

int bfs(int node, int from, int a)
{
    bool visited[105]={0};
    queue<int>q;
    int x, y;

    visited[from]=true;
    if(a==1)
        level1[from]=0;
    else
        level2[from]=0;

    q.push(from);

    while(!q.empty())
    {
        x=q.front();
        q.pop();

        for(int i=0; i<arr[x].size(); i++)
        {
            y=arr[x][i];
            if(!visited[y])
            {
                visited[y]=true;
                if(a==1)
                    level1[y]=level1[x]+1;
                else
                    level2[y]=level2[x]+1;

                q.push(y);
            }
        }
    }
}


int main()
{
    int kase, n, m, a, b, from, to, mx;

    fs(kase);
    fl(kase)
    {
        mx=0;
        arr.clear();
        memset(level1,0,sizeof(level1));
        memset(level2,0,sizeof(level2));

        fs(n);fs(m);
        for(int j=0; j<m; j++)
        {
            fs(a);fs(b);
            arr[a].pb(b);
            arr[b].pb(a);
        }

        fs(from);fs(to);

        bfs(n,from,1);
        bfs(n,to,2);

        for(int i=0; i<n; i++)
            mx=max(mx,(level1[i]+level2[i]));

        pf("Case %d: %d\n",i+1,mx);
    }

    return 0;
}
