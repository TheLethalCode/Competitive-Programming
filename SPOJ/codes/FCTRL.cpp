#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int> 
#define vli vector<long long int>
#define rgod(i,a,b) for(int i=a;i>=b;i--)
#define god(i,a,b) for(int i=a;i<b;i++)
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long int
#define fi first
#define se second
#define pb push_back
#define pa pair<int,int>
#define ma make_pair
#define ulli unsigned lli
 
lli modi(int n){  lli i=mod/n + 1; while(i<=1e9)if(((n*i)-1)%mod==0)return i;return 0;}
 
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
 
lli pom(lli n){ if(n==0)return 1;else{if(n%2)return (2*pom(n-1))%mod; else{lli t=pom(n/2); return (t*t)%mod;}}}
 
 
int main()
{       
    crap;
    int t=1;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     lli ans=0;
     lli f=5;
     while(n/f)
     {
         ans+=n/f;
         f*=5;
     }
     cout<<ans<<endl;
    }
 // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}