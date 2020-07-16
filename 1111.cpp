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
int cnt[1007];

void bfs(int n)
{
    queue<int>q;
    bool visited[1007]={0};
    int x, y;

    cnt[n]++;
    visited[n]=true;
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
                cnt[y]++;
                q.push(y);
            }
        }
    }
}

int main()
{
    int kase, k, n, m, a, b;

    fs(kase);
    fl(kase)
    {
        arr.clear();
        memset(cnt,0,sizeof(cnt));
        vector<int>people;

        fs(k);fs(n);fs(m);
        for(int j=0; j<k; j++)
        {
            fs(a);
            people.pb(a);
        }

        for(int j=0; j<m; j++)
        {
            fs(a);fs(b);
            arr[a].pb(b);
        }

        for(int j=0; j<people.size(); j++)
            bfs(people[j]);

        int kount=0;
        for(int j=1; j<=1000; j++)
        {
            if(cnt[j]==k)
                kount++;
        }

        pf("Case %d: %d\n",i+1,kount);
    }

    return 0;
}
