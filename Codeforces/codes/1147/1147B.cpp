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
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    vi ed[n];
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        a--, b--;
        if(a>b)
            swap(a, b);
        if(b-a <= n/2)
            ed[b-a].pb(a);
        else
            ed[a-b+n].pb(b);
    }
    FOR(i, n)
        sort(all(ed[i]));

    set<int> fac; int te = n;
    for(int i=1;i<=sqrt(n);i++){
        if(te%i == 0) {
            fac.insert(i);
            fac.insert(n/i);
        }
    }
    fac.erase(n);
    for(int el : fac){
        int sh = el, fl=0;
        for(int i=1;i<=n/2 && !fl;i++){
            if(ed[i].empty()) continue;
            vi temp = ed[i];
            for(int &te : temp)
                te += sh, te%=n;
            sort(all(temp));
            if(temp != ed[i])
                fl=1;
            if(i==n/2 && sh==n/2)
                fl=0;
        }
        if(!fl){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}