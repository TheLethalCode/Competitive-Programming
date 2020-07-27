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
    int n, m, mi = 1e9, ma=-1e9, ans=-1;
    cin>>n>>m;
    vi v(n), st(m), en(m);
    vpa ar(m);
    FOR(i, n) cin>>v[i], mi=min(mi, v[i]), ma=max(ma, v[i]);
    FOR(i, m) cin>>ar[i].fi>>ar[i].se, ar[i].fi--, ar[i].se--;
    
    iota(all(en), 0), sort(all(en), [&](int i, int j){
        return ar[i].se < ar[j].se;
    });
    iota(all(st), 0), sort(all(st), [&](int i, int j){
        return ar[i].fi < ar[j].fi;
    });

    vi valE(m+1, mi), temp = v;
    int Xmi=mi;
    FOR(i, m){
        for(int j=ar[en[i]].fi;j<=ar[en[i]].se;j++) temp[j]--, Xmi=min(Xmi, temp[j]);
        valE[i+1] = Xmi;
    }

    vi valS(m+1, mi);
    temp = v, Xmi=mi;
    for(int i=m-1;i>=0;i--){
        for(int j=ar[st[i]].fi;j<=ar[st[i]].se;j++) temp[j]--, Xmi=min(Xmi, temp[j]);
        valS[i] = Xmi;
    }

    FOR(i, n){
        int j = 0, k = m-1;
        while(j<m && ar[en[j]].se < i) j++;j--;
        while(k>=0 && ar[st[k]].fi > i) k--;k++;
        int tMi = min(valE[j+1], valS[k]);
        if(ma - mi < v[i] - tMi) ans=i, ma=v[i], mi=tMi;
    }
    cout<<ma-mi<<endl;
    if(ans == -1) cout<<0<<endl<<endl;
    else{
        int j = 0, k = m-1;
        vi fin;
        while(j<m && ar[en[j]].se < ans) fin.pb(en[j]), j++;
        while(k>=0 && ar[st[k]].fi > ans) fin.pb(st[k]), k--;
        cout<<sz(fin)<<endl;
        FORR(x, fin) cout<<x+1<<" ";
        cout<<endl;
    }
}