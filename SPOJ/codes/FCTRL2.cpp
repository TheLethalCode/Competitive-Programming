#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define vi vector<int> 
#define vli vector<long long int>
#define rgod(a,b) for(int i=a;i>=b;i--)
#define god(a,b) for(int i=a;i<b;i++)
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
    vector< vi > v(101);
    v[0].pb(1);
    god(1,101)
    {
        int c=0,k=i;
        igod(v[i-1])
        {
            int l=(*it)*i + c;
            v[i].pb(l%10);
            c = l/10;
        }
        while(c!=0)
        {
            v[i].pb(c%10);
            c/=10;
        }
    }
    int t=1;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     rigod(v[n])
        cout<<*it;
    cout<<endl;
    }
 // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}