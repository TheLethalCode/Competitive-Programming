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
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int n,m;

pa edge(int i, int j, int prev)
{
    if(!prev)
        return {i, j+1};
    if(prev == 1)
        return {i+1,j};
    if(prev == 2)
        return {i,j-1};
    return {i-1,j};
}

string tour(int i, int j, vector< vector< vi > > &vis)
{
    int prev=0;
    int sti = i, stj = j;
    string walk = "";
    for(int r=0;r<4;)
    {
        int e = r % 4;
        if(!vis[i][j][e])
        {
            prev = e, walk += '0' + prev, vis[i][j][prev] = 1;
            r = 0,i = edge(i,j,prev).fi, j = edge(i,j,prev).se;
            if(i==sti && j == stj)
                return walk;
        }
        else
            r++;
    }
    return walk;
}

void euler(int i, int j, vector< vector< vi > > &vis, string &ans)
{
    string temp = tour(i,j,vis);
    int n = temp.size();
    for(int r = 0; r<n ; r++)
    {
        pa pos = edge(i,j,temp[r]-'0');
        ans+=temp[r], i = pos.fi, j = pos.se;
        euler(i,j,vis,ans);
    }
}

int main(int argc, char **argv)
{
    crap;
    int k;
    cin>>n>>m>>k;
    if(k > 4*n*m - 2*n - 2*m)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    vector< vector< vi > > vis(n,vector< vi >(m,vi(4,0)));
    for(int i=0;i<n;i++)
        vis[i][0][2] = vis[i][m-1][0] = 1;
    for(int i=0;i<m;i++)
        vis[0][i][3] = vis[n-1][i][1] = 1;

    string tour = "";
    euler(0,0,vis, tour);

    cout<<"YES"<<endl;
    vector< pair< int, string> > ans;

    string fin(tour, 0, k);
    for(auto &k : fin)
        if(k=='0')
            k='R';
        else if(k=='1')
            k='D';
        else if(k=='2')
            k='L';
        else if(k=='3')
            k='U';
        
    int pos = 0;
    while(pos < k)
    {
        set< pair< int, int > > what;

        for(int len = 1; len <= 4; len++)
        {   
            int temppos = pos, tempcnt = 0;
            string init = fin.substr(temppos, len);

            while(temppos + len <= k && fin.substr(temppos, len) == init)
                temppos += len, tempcnt++;

            what.insert({len*tempcnt,len});
        }
        
        pa pa1 = *(what.rbegin());
        ans.pb({pa1.fi/pa1.se, fin.substr(pos, pa1.se)}), pos += pa1.fi;
    }

    cout<<ans.size()<<endl;
    for(auto w:ans)
        cout<<w.fi<<" "<<w.se<<endl;
}