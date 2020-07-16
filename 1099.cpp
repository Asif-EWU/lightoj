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

struct st
{
    int to, cost;
    st(int _to, int _cost)
    {
        to=_to;
        cost=_cost;
    }
};
bool operator<(st a, st b)
{
    return a.cost > b.cost;
}

map<int,vector<st> >arr;

int dijkstra(int node)
{
    priority_queue<st>pq;
    int dist[5002][2];

    for(int i=1; i<=node; i++)
    {
        dist[i][0]=M;
        dist[i][1]=M;
    }

    dist[1][0]=0;
    dist[1][1]=M;
    pq.push(st(1,0));

    while(!pq.empty())
    {
        st top=pq.top();
        pq.pop();

        for(int i=0; i<arr[top.to].size(); i++)
        {
            st x=arr[top.to][i];

            if(top.cost+x.cost<dist[x.to][0])
            {
                dist[x.to][1]=dist[x.to][0];
                dist[x.to][0]=top.cost+x.cost;
                pq.push(st(x.to,dist[x.to][0]));
            }

            else if((top.cost+x.cost<dist[x.to][1]) && (top.cost+x.cost!=dist[x.to][0]))
            {
                dist[x.to][1]=top.cost+x.cost;
                pq.push(st(x.to,dist[x.to][1]));
            }
        }
    }

    return dist[node][1];
}


int main()
{
    int kase, n, m, a, b, c, ans;

    fs(kase);
    for(int i=1; i<=kase; i++)
    {
        arr.clear();

        fs(n);fs(m);
        for(int j=0; j<m; j++)
        {
            fs(a);fs(b);fs(c);
            arr[a].pb(st(b,c));
            arr[b].pb(st(a,c));
        }

        ans=dijkstra(n);
        pf("Case %d: %d\n",i,ans);
    }
}
