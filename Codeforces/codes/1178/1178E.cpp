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
    string s;
    cin>>s;
    int n = s.length();
    vector< vi > v(n+1, vi(3, 0)), pos(3);
    FOR(i, n){
        v[i+1] = v[i];
        v[i+1][s[i]-'a']++;
        pos[s[i]-'a'].pb(i+1);
    }

    FOR(i, 3){
        string ans = "";
        int cnt = 0, fl=-1;
        int m = pos[i].size();
        if(m<=1) continue;
        FOR(j, m/2){
            if(j == 0){
                ans+='a'+i, cnt++;
                continue;
            }
            int l1 = pos[i][j], r1 = pos[i][m-1-j];
            int l = pos[i][j-1], r = pos[i][m-j];
            int p1 = min(v[l1][(i+1)%3]-v[l][(i+1)%3], v[r][(i+1)%3]-v[r1][(i+1)%3]);
            int p2 = min(v[l1][(i+2)%3]-v[l][(i+2)%3], v[r][(i+2)%3]-v[r1][(i+2)%3]);
            if(p1 < p2){
                FOR(te, p2) ans+='a'+(i+2)%3;
                cnt+=p2;
            }
            else{
                FOR(te, p1) ans+='a'+(i+1)%3;
                cnt+=p1;
            }
            ans+='a'+i, cnt++;
        }
        int l1 = pos[i][m/2-1], r1 = pos[i][(m+1)/2];
        int p1 = (v[r1][(i+1)%3]-v[l1][(i+1)%3]);
        int p2 = (v[r1][(i+2)%3]-v[l1][(i+2)%3]);
        if(p1 < p2){
            FOR(te, p2/2) ans+='a'+(i+2)%3;
            cnt+=p2/2;
            if(p2&1) fl=(i+2)%3;
        }
        else{
            FOR(te, p1/2) ans+='a'+(i+1)%3;
            cnt+=p1/2;
            if(p1&1) fl=(i+1)%3;
        }
        if(2*cnt + (fl!=-1) >= n/2){
            cout<<ans;
            if(fl!=-1) cout<<(char)('a'+fl);
            reverse(all(ans));
            cout<<ans<<endl;
            return 0;
        }
    }
    if(n<=3) {
        cout<<s[0]<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
}