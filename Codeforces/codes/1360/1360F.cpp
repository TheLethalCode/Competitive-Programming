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
int n, m;
string solve(vi ar, int pos, vector< string> &v)
{
    if(pos==m)
        return "";

    vi st; set<char> uq;
    for(int i=0;i<n;i++)
        if(ar[i])
            st.pb(i), uq.insert(v[i][pos]);

    if(st.size() >= 1 && uq.size() > 1)
        return "*";

    if(st.size() >= 1)
    {
        vi temp = ar;
        for(int j=0;j<n;j++)
            if(!temp[j] && v[j][pos] != v[st[0]][pos])
                temp[j]=1;
        string q = "";
        q+=v[st[0]][pos];
        return q + solve(temp, pos+1, v);
    }

    for(int i=0;i<n;i++)
    {
        vi temp = ar;
        for(int j=0;j<n;j++)
            if(!temp[j] && v[j][pos] != v[i][pos])
                temp[j]=1;

        string ans = "";
        ans+=v[i][pos];
        ans+=solve(temp, pos+1, v);
        int fl=0;
        for(auto e : ans)
            if(e=='*')
                fl=1;
        if(!fl)
            return ans;
    }
    return "*";
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector< string > v(n);
        FOR(i, n) cin>>v[i];
        vi cnt(n, 0);
        string ans = solve(cnt, 0, v);
        if(ans == "*")
            cout<<-1;
        else
            cout<<ans;
        cout<<endl;
    }
}