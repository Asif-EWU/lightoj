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
#define PS              system("pause")
#define MOD             100000007
#define M               1000007
#define MX              505

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

bool is_Prime(int a)
{
    int check = sqrt(a);
    if(a==2)
        return true;
    else if(a==1 || a%2==0)
        return false;
    else
    {
        for(int i=3; i<=check; i+=2)
        {
            if(a%i==0)
                return false;
        }
    }
    return true;
}

int bfs(int x, int y)
{
    queue<int>q;
    bool visited[10005]={0};
    int level[10005];

    visited[x]=true;
    level[x]=0;
    q.push(x);

    while(!q.empty())
    {
        int a=q.front();
        q.pop();

        for(int i=2; i<a; i++)
        {
            int b=a+i;
            if(a%i==0 && !visited[b] && is_Prime(i) && b<=1000)
            {
                visited[b]=true;
                level[b]=level[a]+1;
                q.push(b);
                if(b==y) return level[b];
            }
        }
    }

    return -1;
}

int32_t main()
{
    sync;
    int test, a, b;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        cin >> a >> b;
        if(a==b) cout << "Case " << t << ": " << 0 << endl;
        else cout << "Case " << t << ": " << bfs(a,b) << endl;
    }

    return 0;
}
