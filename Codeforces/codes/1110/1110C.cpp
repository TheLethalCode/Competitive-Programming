#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    crap;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int ans=1;
        int val=ceil(log2(n));
        if(n==(1<<val)-1)
        {
            for(int i=2;i<=sqrt(n);i++)
                if(n%i==0)
                {
                    ans=n/i;
                    break;
                }
        }
        else
        {
            if(n==(1<<val))
                ans=(n<<1)-1;
            else
                ans=(1<<val)-1;
        }
        cout<<ans<<endl;
    }
}