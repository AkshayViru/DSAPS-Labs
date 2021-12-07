#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    int n, k;
    cin >> n >> k;
    vector<ll> price(n), cnt(n);
    for(ll &i: price)
        cin >> i;
    for(ll &i: cnt)
        cin >> i;

    int dp[2][k+1];
    memset(dp, 0, sizeof dp);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j>=price[i-1]){
                dp[1][j] = max(1ll*dp[0][j],cnt[i-1]+dp[0][j-price[i-1]]);
            }
            else{
                dp[1][j] = dp[0][j];
            }
        }
        for(int j=1; j<=k; j++){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][k] << endl;
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