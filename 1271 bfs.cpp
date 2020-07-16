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
#define PS              system("pause")
#define MOD             100000007
#define M               505
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

vector<int>v[MX];
int parent[MX];

void bfs(int from, int to)
{
    queue<int>q;
    bool mark[MX]={0};

    mark[from]=1;
    parent[from]=0;
    q.push(from);

    while(!q.empty())
    {
        int a=q.front();
        q.pop();

        for(int i=0; i<v[a].size(); i++)
        {
            int b=v[a][i];
            if(!mark[b])
            {
                mark[b]=1;
                parent[b]=a;
                if(b==to) return;
                q.push(b);
            }
        }
    }
}


int main()
{
    int test, n, a, b, c, d;
    vector<int>vec;

    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        vec.clear();

        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            v[a].clear();
            vec.push_back(a);
        }

        for(int i=1; i<n; i++)
        {
            a=vec[i-1];
            b=vec[i];
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i=0; i<n; i++)
        {
            a=vec[i];
            sort(v[a].begin(),v[a].end());
        }

        bfs(vec[0],vec[n-1]);

        b=vec[n-1];
        vec.clear();
        a=b;
        while(parent[b]!=0)
        {
            b=parent[b];
            vec.push_back(b);
        }

        printf("Case %d:\n",t);
        for(int i=vec.size()-1; i>=0; i--)
            printf("%d ",vec[i]);
        printf("%d\n",a);
    }

    return 0;
}
