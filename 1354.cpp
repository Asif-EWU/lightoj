#include<bits/stdc++.h>
#define fl(n) for(int i=0; i<n; i++)
#define loop(i, a, n) for(int i=a; i<n; i++)
#define pb push_back
#define pp pop_back
#define ll long long int
#define ld long double
#define inf 5e18
#define sf scanf
#define Sf(a) scanf("%d",&a)
#define pf printf
#define Pfc(a) printf("Case %d: ",a)
#define Pfs(a) printf("%lld",a)
#define nl printf("\n")
#define Vi vector<ll>
#define fin freopen("input.txt", "r", stdin)
#define fout freopen("outut.txt", "w", stdout)
#define PI 2*acos(0.0)
#define BM bool mark[M+10]
#define MOD 1000000007
#define M 200009

using namespace std;

bool check(int a, int b)
{
    string s=bitset<8>(a).to_string();
    int a1;

    stringstream ss;
    ss << s;
    ss >> a1;

    if(a1==b)
        return true;
    else
        return false;
}

int main()
{
    int t, a1, b1, c1, d1, a2, b2, c2, d2;
    char c;

    Sf(t);

    fl(t)
    {
        cin >> a1 >> c >> b1 >> c >> c1 >> c >> d1;
        cin >> a2 >> c >> b2 >> c >> c2 >> c >> d2;

        if(check(a1,a2) && check(b1,b2) && check(c1,c2) && check(d1,d2))
        {
            Pfc(i+1); pf("Yes"); nl;
        }
        else
        {
            Pfc(i+1); pf("No"); nl;
        }
    }


    return 0;
}
