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
 
int main()
{
  int t,r=0;
  cin>>t;
  while(r++<t)
  {
    lli k,n;
    cin>>k>>n;
    vi v(n);
    god(i,0,n)
    {
      cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    lli sum=0;
    int i=0;
    while(sum<k && i<n)
      sum+=v[i++];
    cout<<"Scenario #"<<r<<":"<<endl;
    if(i==n && sum<k)
    cout<<"impossible";
    else
    cout<<i;
    cout<<endl<<endl;
  }
}
