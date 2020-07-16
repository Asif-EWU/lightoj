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
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define err             cout << "OK" << endl;
#define PS              system("pause");
#define MOD             1000000007
#define M               50002
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

vector<int>v[M];
int n, m;

bool fun(int a, int b)
{
    int fx[]={-1,0};
    int fy[]={0,-1};

    queue<pair<int,int> >q;
    map<pair<int,int>,int>level;
    map<pair<int,int>,bool>visited;
    int res=0;

    level[make_pair(a,b)]=0;
    visited[make_pair(a,b)]=1;
    q.push(make_pair(a,b));

    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        int c=p.first;
        int d=p.second;

        for(int i=0; i<2; i++)
        {
            int tx=c+fx[i];
            int ty=d+fy[i];

            if(!visited[make_pair(tx,ty)] && tx>=0 && ty>=0)
            {
                visited[make_pair(tx,ty)]=1;
                level[make_pair(tx,ty)]=level[make_pair(c,d)]+1;
                if(level[make_pair(tx,ty)]%2!=0) res=(res^v[tx][ty]);
                q.push(make_pair(tx,ty));
            }
        }
    }

    if(res) return true;
    return false;
}

int main()
{
    int test, a, ans;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        scanf("%d %d",&n,&m);

        for(int i=0; i<n; i++)
        {
            v[i].clear();
            for(int j=0; j<m; j++)
            {
                scanf("%d",&a);
                v[i].push_back(a);
            }
        }

        ans=fun(n-1,m-1);
        if(ans) printf("Case %d: win\n",t);
        else printf("Case %d: lose\n",t);
    }

    return 0;
}
