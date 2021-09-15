#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

bool chk(int mid, vector<int>& arr, int k){
    int cnt = 1, sum = 0;

    for(int &i: arr){
        if(i > mid)
            return false;
        if(i+sum > mid){
            cnt++;
            sum = i;
        }
        else
            sum += i;
    }

    return cnt <= k;
}


void solve(){
    int n, m, r = 0, l=0;
    cin >> n;
    vector<int> arr(n);

    for(int &i: arr){
        cin >> i;
        r += i;
    }
    cin >> m;

    while(l < r){
        int mid = l + (r-l)/2;
        if(chk(mid, arr, m)){
            r = mid;
        }
        else
            l = mid+1;
    }

    cout << r << endl;
}
 
signed main(){
    init();
    int t = 1;
    // cin >> t;
 
    while(t--){
        solve();
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("tests.in", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}