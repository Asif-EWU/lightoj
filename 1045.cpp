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
#define Pf(a) printf("Case %d: ",a)
#define mod 1000000007

using namespace std;

int main()
{
    vector<double>arr;
    int t, num, base, ans;

    arr.pb(0);
    for(int i=1; i<=1000000; i++)
    {
        arr.pb(arr[i-1]+log10(i));
    }

    Sf(t);

    fl(t)
    {
        Sf(num); Sf(base);

        ans= floor(arr[num]/log10(base))+1;

        Pf(i+1);
        printf("%d\n",ans);
    }

    return 0;
}
