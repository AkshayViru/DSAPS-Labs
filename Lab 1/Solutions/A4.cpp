#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
int MAX = 1e6+1;

vector<bool> isprime(1e6+1, true);

int cnt[(int)1e6+1];
int prefix[11][(int)1e6+1];

void solve(){
    int a, b, n;
    int res = 0;
    cin >> a >> b >> n;

    
    cout << prefix[n][b] - prefix[n][a-1] << endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("tests.in", "r", stdin);
    int t = 1;
    cin >> t;

     memset(cnt, 0, sizeof cnt);
     memset(prefix, 0, sizeof prefix);

     isprime[0] = 0;
     isprime[1] = 0;

     for(int i=2; i<MAX; i++){
         if(isprime[i]){
             cnt[i]++;
             for(int j=i+i; j<MAX; j+=i){
                 isprime[j] = 0;
                 cnt[j]++;
             }
         }
     }

     for(int i=1; i<MAX; i++){
         for(int j=0; j<=10; j++){
             if(j == cnt[i]){
                 prefix[j][i] = 1 + prefix[j][i-1];
             }
             else
                 prefix[j][i] = prefix[j][i-1];
         }
     }

    while(t--){
        solve();
    }
}