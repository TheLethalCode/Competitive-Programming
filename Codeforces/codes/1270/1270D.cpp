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
    int n, k;
    cin>>n>>k;
    vi v(n+1, -1);

    int val1, pos1, val2, pos2;
    cout<<"? ";
    FOR(i, k) cout<<i+1<<" ";
    cout<<endl<<flush;
    cin>>pos1>>val1;

    vi temp;
    cout<<"? ";
    FOR(i, k+1) if(i+1!=pos1) cout<<i+1<<" ", temp.pb(i+1);
    cout<<endl<<flush;
    cin>>pos2>>val2;

    int j = 0, m=1;
    while(j<k){
        vi arr = temp;
        if(arr[j] == pos2) {
            j++;
            continue;
        }
        arr[j] = pos1;
        
        int x1, y1;
        cout<<"? ";
        FOR(i, k) cout<<arr[i]<<" ";
        cout<<endl<<flush;
        cin>>x1>>y1;

        if(x1 == pos2) m+=(val1<val2);
        else m+=(val1>val2);
        j++;
    }
    cout<<"! "<<m<<endl<<flush;
}