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
#define pb push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int n;

void func(vpa &A, vpa &B){
    
    vector< pair< pa, int> > events;
    FOR(i, n) events.pb({{A[i].fi, 1}, i}), events.pb({{A[i].se+1, 0}, i});
    sort(all(events));
    
    multiset< int > sm, bi;
    for(auto eve : events){
        if(!eve.fi.se){
            sm.erase(sm.find(B[eve.se].se));
            bi.erase(bi.find(B[eve.se].fi));
        }
        else{
            int i = eve.se;
            if(!sm.empty() && (B[i].fi > *sm.begin() || B[i].se < *bi.rbegin())){
                cout<<"NO"<<endl;
                exit(0);
            }
            bi.insert(B[i].fi), sm.insert(B[i].se);
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    vpa A(n), B(n);
    FOR(i, n) cin>>A[i].fi>>A[i].se>>B[i].fi>>B[i].se;
    func(A, B), func(B, A);
    cout<<"YES"<<endl;
    return 0;
}