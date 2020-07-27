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
int n, k;
int query(int i, int j){
    
    if(i>j) return -1;
    
    cout<<"? "<<j-i+1<<" ";
    for(int k=i;k<=j;k++) cout<<k<<" ";
    cout<<endl<<flush;
    
    int a;
    cin>>a;
    return a;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int m, a;
        cin>>n>>k;
        vector< vi > v(k);
        FOR(i, k){
            cin>>m;
            FOR(j, m) {
                cin>>a;
                v[i].pb(a);
            }
            sort(all(v[i]));
        }
        int ma = query(1, n);
        int st = 1;
        for(int i=9;i>=0;i--){
            if(query(st+(1<<i), n) == ma)
                st += 1<<i;
        }
        int fl=-1;
        FOR(i, k){
            if(binary_search(all(v[i]), st)){
                fl=i;
                break;
            }
        }
        if(fl == -1){
            cout<<"! ";
            FOR(i, k) cout<<ma<<" ";
            cout<<endl<<flush;
        }
        else{
            vi temp;
            FOR(i, n) {
                if(binary_search(all(v[fl]), i+1)) continue;
                temp.pb(i+1);
            }
            cout<<"? "<<temp.size()<<" ";
            FOR(i, temp.size()) cout<<temp[i]<<" ";
            cout<<endl<<flush;
            int ans;
            cin>>ans;
            
            cout<<"! ";
            FOR(i, k){
                if(i!=fl) cout<<ma<<" ";
                else cout<<ans<<" ";
            }
            cout<<endl<<flush;
        }
        string s;
        cin>>s;
        if(s=="Incorrect"){
            return 0;
        }
    }
    
}