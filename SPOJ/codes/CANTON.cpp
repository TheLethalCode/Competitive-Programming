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
    crap;
    int t=1;
    cin>>t;
    while(t--)
    {
        int k,r;
        cin>>k;
        r=k;
        int i=0;
        while(i*(i+1)/2 <= k)i++;
        i--;
        k-= i*(i+1)/2;
        if(k==0)
        {
            if(i%2)
            cout<<"TERM "<<r<<" IS "<<"1/"<<i;
            else
            cout<<"TERM "<<r<<" IS "<<i<<"/1";
        }
        else
        {
            i++;
            if(i%2)
            cout<<"TERM "<<r<<" IS "<<i-k+1<<"/"<<k;
            else
            cout<<"TERM "<<r<<" IS "<<k<<"/"<<i-k+1;
        }
        cout<<endl;
    }
    return 0;
}