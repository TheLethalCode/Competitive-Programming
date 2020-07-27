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

#define mod1 1000000007
#define mod2 1000000009
#define a1 31
#define a2 53

vli pw1(4*1e6+1,1);
vli pw2(4*1e6+1,1);

void pre()
{   
    FOR(i, 4*1e6)
        pw1[i+1]=pw1[i]*a1, pw1[i+1]%=mod1;
    FOR(i, 4*1e6)
        pw2[i+1]=pw2[i]*a2, pw2[i+1]%=mod2;
}

lli fu(string s, lli a, lli m, vli &pw)
{
    lli ans = 0;
    int n = s.size();
    FOR(i, n)
        ans += (s[i]-'0'+1)*pw[i], ans%=m;
    return ans; 
}

pal hash1(string s)
{
    lli h1 = fu(s, a1, mod1, pw1), h2 = fu(s, a2, mod2, pw2);
    return {h1, h2};
}

// %
int main(int argc, char **argv)
{
    crap;
    pre();

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector< string > v(n), ne;
        FOR(i, n) cin>>v[i];
        
        vi one, zero, rv;
        set<int> fin;
        map< pair<lli, lli> , int > mp;
        FOR(i, n) {
            if(v[i][0] == v[i].back()){
                if(v[i][0] == '1') one.pb(i);
                else zero.pb(i);
            }
            else {
                fin.insert(i);
                string te = v[i];reverse(all(te));
                pal ha = hash1(v[i]), har = hash1(te);
                if(mp.count(har)) rv.pb(i), rv.pb(mp[har]), fin.erase(mp[har]), fin.erase(i);
                else mp[ha] = i;
            }
        }
        vector< vi > st(2);
        for(int k:fin) st[v[k][0]-'0'].pb(k);
        
        int a = one.size(), b=zero.size(), c=rv.size(), d=fin.size();
        if(c + d){
            if(!d) cout<<0<<endl<<endl;
            else {
                int y = st[0].size(), z = st[1].size(), ans = abs(y-z)/2;
                cout<<ans<<endl;
                FOR(i, ans) cout<<st[(y<z)][i]+1<<" ";
                cout<<endl;
            }
        }
        else if(a && b) cout<<-1<<endl;
        else cout<<0<<endl<<endl;
    }
}