#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

class FenwickTree {
    int n = 1e7+1;
    map<int,int> sums;
    
public:
    FenwickTree(){
        sums.clear();
    }
    
    void update(int i) {
        while (i <= n) {
            sums[i]++;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
};

void solve(int tc = 1){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    FenwickTree ft;

    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());
    vector<ll> res;

    for(auto &z: arr){
        // cout << z.second << " ";
        ll cnt = ft.query(z.second);
        cout << z.second - cnt - 1 << " ";
        // cout << z.second << endl;
        ft.update(z.second);
    }

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