#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007


ll exp2(ll a, ll n){
    ll res = 1;

    while(n){
        if(n&1)
            res = (res*a)%M;
        cout << a << endl;
        a = (a*a)%M;
        n = n>>1;
    }

    return res;
}

void solve(){
    ll a, p;
    cin >> a >> p;
    ll mx = 1;

    cout << exp2(a, p) << endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("tests.in", "r", stdin);
    int t = 1;
    cin >> t;
 
    while(t--){
        solve();
    }
}