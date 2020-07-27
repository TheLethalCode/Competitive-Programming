#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int> 
#define vli vector<long long int>
#define rgod(i,a,b) for(int i=a;i>=b;i--)
#define god(i,a,b) for(int i=a;i<b;i++)
#define igod(v) for(auto it=v.begin();it!=v.end();it++)
#define rigod(v) for(auto it=v.rbegin();it!=v.rend();it++)
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long int
#define fi first
#define se second
#define pb push_back
#define pa pair<int,int>
#define ma make_pair
#define ulli unsigned lli
 
lli pom(lli n){ if(n==0)return 1;else{if(n%2)return (2*pom(n-1))%mod; else{lli t=pom(n/2); return (t*t)%mod;}}}
 
vli v(1e7+1);
 
void solve()
{
    v[0]=0;
    v[1]=1;
    v[2]=2;
    v[3]=3;
    v[4]=4;
    god(i,5,1e7+1)
    {
        int k=v[i/2] + v[i/3] + v[i/4];
        k>i?v[i]=k:v[i]=i;
    }
}
 
lli resolve(lli n)
{
    if(n<=1e7)
    return v[n];
    else
    return resolve(n/2)+resolve(n/3)+resolve(n/4);
}
 
int main()
{       
    crap;
    solve();
    lli n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<resolve(n)<<endl;
    }
    return 0;
}