#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    int n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    for(auto &i: arr)
        cin >> i.second;
    for(auto &i: arr)
        cin >> i.first;

    sort(arr.begin(), arr.end());
    vector<ll> dp(n, 0);
    dp[0] = arr[0].second;
    ll res = dp[0];

    for(int i=1; i<n; i++){
        dp[i] = arr[i].second;
        for(int j=0; j<i; j++){
            if(arr[j].second<=arr[i].second){
                dp[i] = max(dp[i], arr[i].second+dp[j]);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
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