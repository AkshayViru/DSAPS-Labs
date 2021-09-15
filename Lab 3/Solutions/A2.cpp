#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

vector<int> par, rk;

int find(int x){
    if(x == par[x])
        return x;
    return par[x] = find(par[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(rk[x] > rk[y]){
        par[y] = x;
        rk[x] += rk[y];
    }
    else{
        par[x] = y;
        rk[y] += rk[x];
    }
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    par.assign(n, 0);
    rk.assign(n, 1);

    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
        par[i] = i;
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        if(i != arr[i].second && find(i) != find(arr[i].second)){
            uni(i, arr[i].second);
        }
    }

    set<int> st;
    int res = 0;
    for(int i=0; i<n; i++){
        if(st.find(find(i)) == st.end()){
            res += (rk[find(i)]-1);
            st.insert(find(i));
        }
    }

    cout << res << endl;
}
 
signed main(){
    init();
    int t = 1;
    //cin >> t;
 
    while(t--){
        solve();
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