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
#define debug1(x) cout<<#x<<" "<<x;cout<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;cout<<endl;
#define debugA(v) for(int i:v) cout<<i<<" ";cout<<endl;
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define dame pair< pa, int >
#define perc %
#define xors ^
 
struct comp {
    bool operator() (dame lhs, dame rhs) {
        if(lhs.fi.se == rhs.fi.se)
            return lhs.se < rhs.se;
        return lhs.fi.se < rhs.fi.se;
    }
};
 
int main(int argc, char **argv)
{
    crap;
    int n,k;
    cin>>n>>k;
    vector< dame > v(n);
    FOR(i,n) 
    {
        cin>>v[i].fi.fi>>v[i].fi.se;
        v[i].se = i+1;
    }
    sort(all(v));
    set< dame , comp > en;
    en.insert(v[0]);
    int cnt = 1;
    vi ans;
    for(int i = 1;i < n;i++)
    {
        dame temp = *en.begin();
        while(cnt > 0 && temp.fi.se < v[i].fi.fi)
        {
            en.erase(temp),cnt--;
            if(!cnt)
                break;
            temp = *en.begin();
        }
        en.insert(v[i]);
        cnt++;
        if(cnt > k)
        {
            ans.pb((*(en.rbegin())).se);
            en.erase(*en.rbegin());
            cnt--;
        }
    }
    cout<<ans.size()<<endl;
    for(int x:ans)
        cout<<x<<" ";
    cout<<endl;
}