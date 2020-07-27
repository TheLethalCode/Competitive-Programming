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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi v(n);
        set<int> te;
        FOR(i, n) cin>>v[i], te.insert(v[i]);
        if(te.size() == 1)
        {
            cout<<1<<endl;
            FOR(i, n) cout<<1<<" ";nl;
            continue;
        }
        else if(n & 1)
        {
            int fl=-1;
            FOR(i, n-1)
                if(v[i] == v[i+1])
                    fl=i;
            if(v[n-1] == v[0])
                fl=n-1;
            if(fl!=-1)
            {
                cout<<2<<endl;
                FOR(i,fl+1)
                    cout<<(i&1)+1<<" ";
                for(int i=fl+1;i<n;i++)
                    cout<<(2-(i&1))<<" ";
                cout<<endl;
            }
            else
            {
                cout<<3<<endl;
                FOR(i, n/2)
                    cout<<"1 2 ";
                cout<<3<<endl;
            }
        }
        else
        {
            cout<<2<<endl;
            FOR(i, n/2) cout<<"1 2 ";nl;
        }
    }
}