#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    ll n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);

    for(int i=0; i<m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    ll res = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            for(int k=0; k<n; k++){
                if(k == i || k == j)
                    continue;
                if(adj[i].count(k) && adj[j].count(k) && adj[i].count(j)){
                    res++;
                }
            }
        }
    }

    cout << res/6 << endl;
}
 
signed main(){
    init();
    int t = 1;
    //cin >> t;
 
    for(int i=1; i<=t; i++){
        solve(i);
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}