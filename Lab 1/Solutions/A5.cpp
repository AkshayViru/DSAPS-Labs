#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007

int MAX = 10000001;

vector<bool> isprime(MAX, true);
std::vector<int> primes;

void solve(){
    int a, b;
    cin >> a >> b;

    int left = lower_bound(primes.begin(), primes.end(), a+1)-primes.begin();
    int right = upper_bound(primes.begin(), primes.end(), b-1)-primes.begin();

    cout << right-left << endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("tests.in", "r", stdin);
    int t = 1;
    cin >> t;

    isprime[0] = 0;
    isprime[1] = 0;

    for(int i=2; i<MAX; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i+i; j<MAX; j+=i){
                isprime[j] = false;
            }
        }
    }

    while(t--){
        solve();
    }
}