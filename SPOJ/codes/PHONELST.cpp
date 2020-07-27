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

struct node
{
    node *v[10];
    bool leaf=false;
};

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector< string > v(n);
        int fl=1;
        node *head=new node; 
        FOR(i,n)
        {
            cin>>v[i];
            node *last=head;
            for(int j=0;j<v[i].size();j++)
            {
                char r = v[i][j];
                if(last->v[r-'0']!=NULL && last->v[r-'0']->leaf)
                    fl=0;
                if(last->v[r-'0']==NULL)
                    last->v[r-'0'] = new node;
                else if(j==v[i].size()-1)
                    fl=0;
                last=last->v[r-'0'];
            }
            last->leaf = true;
        }
        cout<<(fl?"YES":"NO");nl;
    }
}