#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(){
    int N, K;
    cin >> N;
    vector<int> A(N);
    for(int &i: A) {
        cin >> i;
    }
    cin >> K;

    deque<int> d;
    int res = N+1;
    for (int i = 0; i < N; i++) {
        if (i > 0)
            A[i] += A[i - 1];
        if (A[i] >= K)
            res = min(res, i + 1);
        while (d.size() > 0 && A[i] - A[d.front()] >= K)
            res = min(res, i - d.front()), d.pop_front();
        while (d.size() > 0 && A[i] <= A[d.back()])
            d.pop_back();
        d.push_back(i);
        //cout << i << " " << res << endl;
    }

    if(res == N+1)
        res = -1;
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
        //freopen("tests.in", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}