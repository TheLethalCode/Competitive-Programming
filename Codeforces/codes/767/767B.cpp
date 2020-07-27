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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %
#define xors ^

lli powmod(lli n, lli p)
{
    if(!p) return 1;
    if(p perc 2) return powmod(n,p-1)*n perc mod;
    lli t = powmod(n,p/2);
    return t*t perc mod;
}

int main(int argc, char **argv)
{
    crap;
    lli st, fi, t;
    cin>>st>>fi>>t;
    int n;
    cin>>n;
    if(!n)
        cout<<st<<endl;
    else
    {
        vpal v(n);
        set<lli> k;
        FOR(i,n)
        {
            cin>>v[i].fi;
            v[i].se = 0;
            k.insert(v[i].fi);
        }

        for(lli te : k)
            v.pb({te-1,1});

        for(pal te : v)
            if((te.fi == fi - t) && (te.se == 1))
                goto take;

        v.pb({fi-t,1});
        take:;

        sort(all(v));
        
        lli ans = 1e14, res;
        lli cur = st;
        FOR(i,v.size())
        {
            if(!v[i].se)
            {
                if(v[i].fi < cur)
                    cur += t; 
                else
                    cur = v[i].fi + t;
            }
            else
            {
                if(ans > max(0LL,cur - v[i].fi) && (v[i].fi + t <= fi) && (cur + t <= fi))
                    res = v[i].fi, ans = max(0LL,cur - v[i].fi);
            }
        }
        cout<<res<<endl;
    }    
    return 0;
}