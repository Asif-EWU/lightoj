#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, a, b, c, d;

    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> a >> b >> c >> d;

        a=abs(a-c);
        b=abs(b-d);

        printf("Case %d: ",i);
        cout << __gcd(a,b)+1 << endl;
    }

    return 0;
}
