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
    int n,m;
    cin>>n>>m;
    vector< vi > v(n,vi(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    
    int rows[n],cols[m],row_to[n][m],col_to[n][m];

    for(int i=0;i<n;i++)
    {
        set<int> k;
        for(int j=0;j<m;j++)
            k.insert(v[i][j]);
        rows[i]=k.size();

        vi t;
        for(int r:k)
            t.push_back(r);

        for(int j=0;j<m;j++)
            row_to[i][j] = lower_bound(t.begin(),t.end(),v[i][j]) - t.begin();
        // cout<<"hi"<<flush;
    }

    for(int j=0;j<m;j++)
    {
        set<int> k;
        for(int i=0;i<n;i++)
            k.insert(v[i][j]);
        cols[j]=k.size();

        vi t;
        for(int r:k)
            t.push_back(r);

        for(int i=0;i<n;i++)
            col_to[i][j] = lower_bound(t.begin(),t.end(),v[i][j]) - t.begin();
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int val;
            if(row_to[i][j] == col_to[i][j])
                cout<<max(rows[i],cols[j]);
            else if(row_to[i][j] < col_to[i][j])
                cout<<max(cols[j],rows[i]+(col_to[i][j] - row_to[i][j]));
            else
                cout<<max(cols[j]-(col_to[i][j] - row_to[i][j]),rows[i]);
            cout<<" ";
        }
        cout<<endl;
    }
}