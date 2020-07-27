#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n;
    cin>>n;
    char v[n][n];
    vector< pair< pa,int> > pp;
    int rc=0,cc=0;
    vector< pa > ans;
    vector< vector<pa> > r(n),c(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
            if(v[i][j] == '.')
            {
                if(r[i].empty())
                    r[i].pb(mp(i,j)),rc++;
                if(c[j].empty())
                    c[j].pb(mp(i,j)),cc++;
            }
        }
    if(rc<n && cc<n)
        cout<<-1<<endl;
    else if(rc<n)
        for(int i=0;i<n;i++)
            cout<<c[i][0].fi+1<<" "<<c[i][0].se+1<<endl;
    else
        for(int i=0;i<n;i++)
            cout<<r[i][0].fi+1<<" "<<r[i][0].se+1<<endl;
}