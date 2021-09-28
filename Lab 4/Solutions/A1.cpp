#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for(int &i: arr)
        cin >> i;
    cin >> x;

    int res = 0;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; i++){
        int tar = x-arr[i];
        map<int,int> mp;
        for(int j=i+1; j<n; j++){
            if(mp.find(tar-arr[j]) != mp.end())
                res += mp[tar-arr[j]];
            mp[arr[j]]++;
        }
    }

    cout << res << endl;
}
 
signed main(){
    init();
    int t = 1;
    cin >> t;
 
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