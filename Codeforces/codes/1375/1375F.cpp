#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int main(int argc, char **argv)
{
    crap;
    int x;
    lli a, b, c;
    cin>>a>>b>>c;
    cout<<"First"<<endl;
    
    cout<<mod<<endl;
    cin>>x;
    if(x==1){
        a+=mod;
        cout<<2*a-b-c<<endl;
        cin>>x;
        cout<<(x==2?a-c:a-b)<<endl;
    }
    else if(x==2){
        b+=mod;
        cout<<2*b-a-c<<endl;
        cin>>x;
        cout<<(x==1?b-c:b-a)<<endl;
    }
    else{
        c+=mod;
        cout<<2*c-b-a<<endl;
        cin>>x;
        cout<<(x==1?c-b:c-a)<<endl;
    }

    cin>>x;
    return 0;
}