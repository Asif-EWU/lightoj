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
#define M               1000000000000
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

struct st
{
    int x1, y1, x2, y2, x3, y3;
    st(int a, int b, int c, int d, int e, int f)
    {
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        x3=e;
        y3=f;
    }
};

char arr[12][12];
int n, a1, b1, a2, b2, a3, b3;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

bool visited[11][11][11][11][11][11];
int level[11][11][11][11][11][11];

int bfs()
{
    queue<st>q;
    int a, b, c, d, e, f;
    int ta, tb, tc, td, te, tf;
    int wa, wb, wc, wd, we, wf;

    visited[a1][b1][a2][b2][a3][b3]=true;
    level[a1][b1][a2][b2][a3][b3]=0;
    q.push(st(a1, b1, a2, b2, a3, b3));

    while(!q.empty())
    {
        st p=q.front();
        q.pop();

        a=p.x1;
        b=p.y1;
        c=p.x2;
        d=p.y2;
        e=p.x3;
        f=p.y3;

        for(int i=0; i<4; i++)
        {
            wa=a+fx[i];
            wb=b+fy[i];
            if(wa>=0 && wb>=0 && wa<n && wb<n && arr[wa][wb]!='#')
            {
                ta=wa;
                tb=wb;
            }
            else ta=a, tb=b;

            wc=c+fx[i];
            wd=d+fy[i];
            if(wc>=0 && wd>=0 && wc<n && wd<n && arr[wc][wd]!='#')
            {
                tc=wc;
                td=wd;
            }
            else tc=c, td=d;

            we=e+fx[i];
            wf=f+fy[i];
            if(we>=0 && wf>=0 && we<n && wf<n && arr[we][wf]!='#')
            {
                te=we;
                tf=wf;
            }
            else te=e, tf=f;

            while(1)
            {
                if(ta==tc && tb==td)
                {
                    if(ta==a && tb==b) tc=c, td=d;
                    else ta=a, tb=b;
                    continue;
                }
                if(ta==te && tb==tf)
                {
                    if(ta==a && tb==b) te=e, tf=f;
                    else ta=a, tb=b;
                    continue;
                }
                if(tc==te && td==tf)
                {
                    if(tc==c && td==d) te=e, tf=f;
                    else tc=c, td=d;
                    continue;
                }
                break;
            }

            if(visited[ta][tb][tc][td][te][tf]) continue;
            if((ta==tc && tb==td) || (ta==te && tb==tf) || (te==tc && tf==td)) continue;
            visited[ta][tb][tc][td][te][tf]=1;
            level[ta][tb][tc][td][te][tf]=level[a][b][c][d][e][f]+1;
            q.push(st(ta,tb,tc,td,te,tf));

            if(arr[ta][tb]=='X' && arr[tc][td]=='X' && arr[te][tf]=='X') return level[ta][tb][tc][td][te][tf];
        }
    }

    return -1;
}

int main()
{
    int test;

    cin >> test;
    for(int t=1; t<=test; t++)
    {
        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));

        cin >> n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j]=='A') a1=i, b1=j;
                if(arr[i][j]=='B') a2=i, b2=j;
                if(arr[i][j]=='C') a3=i, b3=j;
            }
        }

        int res=bfs();
        if(res==-1) printf("Case %d: trapped\n",t);
        else printf("Case %d: %d\n",t,res);
    }

    return 0;
}
