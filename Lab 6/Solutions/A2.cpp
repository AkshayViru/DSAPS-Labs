#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();
ll n, k;

ll calc(ll cur){
    ll next = cur+1;
    ll res = 0;

    while(cur <= n){
        res += min(n-cur+1, next-cur);
        cur *= 10;
        next *= 10;
    }

    return res;
}
 
void solve(int tc = 1){
    cin >> n >> k;

    ll cur = 1;
    k--;

    while(k){
        ll steps = calc(cur);
        if(steps <= k){
            cur++;
            k -= steps;
        }
        else{
            cur *= 10;
            k--;
        }
    }

    cout << cur << endl;
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