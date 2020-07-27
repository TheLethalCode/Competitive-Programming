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

vi se(1e6+1,0);
vi cn(1e6+1,0);
vi pr;

void inc(int n,int x)
{
    for(int a:pr)
    {
        if(a>n)
            break;
        int cnt=n/a,ans=0;
        while(cnt)
            ans+=cnt,cnt/=a;
        cn[a]+=x*ans;
    }
}

lli pom(int n)
{
    lli ans=1;
    for(int a:pr)
    {
        if(a>n)
            break;
        while(cn[a])
            ans*=a,cn[a]--;
    }
    return ans;
}

int main()
{
    crap;
    se[1]=1;
    for(int i=2;i<=1e3;i++)
    {
        for(int j=i*i;j<=1e6;j+=i)
            se[j]=1;
    }
    for(int i=2;i<=1e6;i++)
        if(!se[i])
            pr.push_back(i);
    int t;
    cin>>t;
    while(t--)
    {
        lli n, k;
        cin>>n>>k;
        inc(n-1,1),inc(k-1,-1),inc(n-k,-1);
        cout<<pom(n-1)<<endl;
    }
}