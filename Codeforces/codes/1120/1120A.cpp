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
    int n, m, k, s;
    cin>>m>>k>>n>>s;
    vi v(m), req(5*1e5+1, 0), cur(5*1e5+1, 0), end(m, -1);
    set<int> lef;
    FOR(i, m) cin>>v[i];
    FOR(i, s) {
        int a;cin>>a;
        req[a]++, lef.insert(a);
    }
    int i=0, j=0, fl=-1;
    while(i<m){
        while(j<m && !lef.empty()){
            cur[v[j]]++;
            if(req[v[j]] == cur[v[j]]) lef.erase(v[j]);
            j++;
        }
        if(!lef.empty()) break;
        while(lef.empty()){
            end[i]=j-1, cur[v[i]]--;
            if(i%k + max(0, (j-i-k)) <= m-n*k) fl=i;
            if(cur[v[i]]<req[v[i]]) lef.insert(v[i]);
            i++;
        }
    }
    
    if(fl==-1) cout<<-1<<endl;
    else{

        cout<<fl%k + max(0, (end[fl]-fl+1-k))<<endl;
        
        FOR(i, fl%k) cout<<i+1<<" ";
        int cnt = end[fl]-fl+1-k;
        for(int i=fl;i<=end[fl] && cnt>0;i++){
            if(!req[v[i]]) cout<<i+1<<" ", cnt--;
            else req[v[i]]--;
        }
        cout<<endl;
    }
}