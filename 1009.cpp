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

map<int,vector<int> >arr;
bool visited[20004];
map<int,int>color;
vector<int>clr1, clr2;

void bfs(int n)
{
    queue<int>q;
    int x, y, c1=0, c2=0;

    visited[n]=true;
    color[n]=1;
    c1++;
    q.push(n);

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

                if(color[x]==1)
                {
                    color[y]=2;
                    c2++;
                }
                if(color[x]==2)
                {
                    color[y]=1;
                    c1++;
                }

                q.push(y);
            }
        }
    }

    clr1.pb(c1);
    clr2.pb(c2);
}

int main()
{
    int kase, n, a, b, x;

    fs(kase);
    fl(kase)
    {
        arr.clear();
        color.clear();
        clr1.clear();
        clr2.clear();
        memset(visited,0,sizeof(visited));
        bool exist[20004]= {0};
        x=0;

        fs(n);
        for(int j=0; j<n; j++)
        {
            fs(a);
            fs(b);

            exist[a]=true;
            exist[b]=true;
            arr[a].pb(b);
            arr[b].pb(a);
        }

        for(int j=1; j<=20000; j++)
        {
            if(!visited[j] && exist[j])
                bfs(j);
        }

        for(int j=0; j<clr1.size(); j++)
        {
            x=x+max(clr1[j],clr2[j]);
        }

        pf("Case %d: %d\n",i+1,x);
    }

    return 0;
}
