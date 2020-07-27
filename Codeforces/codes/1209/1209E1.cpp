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
#define mp make_pair

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
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int a[n][m];
        vi b(n*m);
        FOR(i, n) FOR(j, m) cin>>b[i*m+j], a[i][j]=b[i*m+j];
        sort(b.rbegin(), b.rend());
        int ans = 0;
        if(n<4 || m==1)
            FOR(i, n) ans+=b[i];
        else{
            int ans1=0; 
            FOR(i, 4) ans1+=b[i];
            set< int > fo;
            FOR(i, m) FOR(j, n) FOR(k, 4) if(a[j][i]==b[k]) fo.insert(i);
            if(fo.size()!=2) ans=ans1;
            else{
                int l=*fo.begin(), r=*fo.rbegin(), ch[n][m], ma[n], cnt=0;
                FOR(i, m) FOR(j, n) ch[j][i]=0;
                FOR(i, m){
                    if(i==l || i==r) continue;
                    FOR(j, n) ch[j][cnt]=a[j][i];
                    cnt++;
                }
                FOR(i, n) ma[i]=*max_element(ch[i], ch[i]+m);
                FOR(x, 4) FOR(y, 4){
                    int te[n];
                    FOR(i, n) te[i]=max3(ma[i], a[(i+x+1)%4][l], a[(i+y+1)%4][r]);
                    ans=max(ans, te[0]+te[1]+te[2]+te[3]);
                }
            }
        }
        cout<<ans<<endl;
    }
}