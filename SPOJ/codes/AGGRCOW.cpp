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
 
lli pom(lli n,lli p){ if(!p)return 1;else if(p%2)return (pom(n,p-1)*(n%mod))%mod;else{lli te=pom(n,p/2);return (te*te)%mod;}}
 
vi v;
int n, c;
 
bool fit(int x)
{
    int ic=1;
    int i=1,ip=0;
    while(i<n)
    {
        if(v[i]-v[ip] >= x){
            ic++;
            ip=i;
        }
        i++;
    }
    if(ic>=c)return true;
    else return false;
    // ic>=c?return true:return false;
}
 
int b_search()
{
    int beg=1, last=v[n-1]-v[0], mid=(beg+last)/2;
    while(last>beg){
        mid=(beg+last)/2;
        if(mid == beg || mid == last) break;
        // cout<<last<<" "<<mid<<" "<<beg<<endl;
        if(fit(mid)) beg=mid;
        else last=mid;
    }
    return mid;
}
 
int main()
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        god(i,0,n) {
            int a;
            cin>>a;
            v.pb(a);
        }
        sort(v.begin(),v.end());
        cout<<b_search()<<endl;
        v.clear();
    }
    return 0;
}