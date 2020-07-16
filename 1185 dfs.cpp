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
#define MX              100000

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
    string name;
    int a, b, c, d, e, f;
};

bool cmp(st p, st q)
{
    return p.f < q.f;
}

int main()
{
    vector<st>v;
    int arr[]={60,10,40,30,80};
    srand (time(NULL));


    cout << "Enter male names:\n";

    for(int i=1; i<=39; i++)
    {
        st x;

        getline(cin,x.name);
        x.a = rand() % 3+2015;    //year
        x.b = rand() % 3+1;       //semester
        x.c = rand() % 5;         //department
        x.d = rand() % 6;         //second digit
        x.e = rand() % 9+1;       //third digit
        x.f = rand() % 100000000; //serial number

        v.pb(x);
    }

    cout << "\nEnter female names:\n";
    for(int i=40; i<=100; i++)
    {
        st x;

        getline(cin,x.name);
        x.a = rand() % 3+2015;    //year
        x.b = rand() % 3+1;       //semester
        x.c = rand() % 5;         //department
        x.d = rand() % 6;         //second digit
        x.e = rand() % 9+1;       //third digit
        x.f = rand() % 100000000; //serial number

        v.pb(x);
    }

    sort(v.begin(),v.end(),cmp);

    FILE *fp;
    fp=fopen("project.doc", "a+");

    for(int i=0; i<v.size(); i++)
    {
        st x=v[i];
        fprintf(fp,"%-3d. %-30s %d-%d-%d-0%d%d\n",i+1,x.name.c_str(),x.a,x.b,arr[x.c],x.d,x.e);
    }

    fclose(fp);
    return 0;
}
