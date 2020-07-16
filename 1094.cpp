#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             9223372036854775807
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("outut.txt", "w", stdout)
#define PI              2*acos(0.0)
#define F               first
#define S               second
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

map<int,vector<pair<int,int> > >arr;

int bfs(int a, int k)
{
    queue<int>q;
    bool visited[30007]={0};
    map<int,int>dist;
    int mx=0, ans, x;

    visited[a]=true;
    dist[a]=0;
    q.push(a);

    while(!q.empty())
    {
        x=q.front();
        q.pop();

        for(int i=0; i<arr[x].size(); i++)
        {
            pair<int,int>p=arr[x][i];

            if(!visited[p.F])
            {
                visited[p.F]=true;
                dist[p.F]=p.S+dist[x];
                q.push(p.F);

                if(dist[p.F]>=mx)
                {
                    mx=dist[p.F];
                    ans=p.F;
                }
            }
        }
    }

    if(k==1)
        return ans;
    else
        return mx;
}

int main()
{
    int test, n, a, b, c, res;

    fs(test);
    for(int t=1; t<=test; t++)
    {
        arr.clear();

        fs(n);
        for(int i=0; i<n-1; i++)
        {
            fs(a);fs(b);fs(c);

            arr[a].pb(make_pair(b,c));
            arr[b].pb(make_pair(a,c));
        }

        res=bfs(0,1);
        res=bfs(res,2);

        pf("Case %d: %d\n",t,res);
    }

    return 0;
}
