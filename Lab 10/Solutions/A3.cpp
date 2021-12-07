#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    map<int,int> mp;
    for(int i=0; i<m; i++){
        ll val;
        cin >> val;
        mp[val] = i;
    }

    vector<int> brr(n, INT_MAX);
    for(int i=0;i<n; i++){
        if(mp.count(arr[i])){
            brr[i] = mp[arr[i]];
        }
    }

    vector<int> lis;

    for(int &x: brr){
        if(x == INT_MAX)
            continue;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }

    cout << x*(m-lis.size()) << endl;
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