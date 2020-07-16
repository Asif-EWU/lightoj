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

int main()
{
    int t, n, l, j, left, right, flag;
    string s;

    Sf(t);

    fl(t)
    {
        Sf(n);

        stringstream ss;
        ss << n;
        ss >> s;

        l=s.size();
        flag=1;
        left=0, right=l-1;

        while(left<=right)
        {
            if(s[left]!=s[right])
            {
                flag=0;
                break;
            }
            left++, right--;
        }

        Pfc(i+1);
        if(flag==1)
            pf("Yes");
        else
            pf("No");
        nl;
    }

    return 0;
}
