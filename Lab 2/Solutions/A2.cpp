#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

vector<vector<int>> mux(vector<vector<int>>& a, vector<vector<int>>& b){
    int n = a.size();
    vector<vector<int>> res(n, vector<int> (n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[i][j] = 0;
            for(int k=0; k<n; k++){
                res[i][j] = (res[i][j]+(a[i][k]*b[k][j])%M)%M;
            }
        }
    }

    return res;
}

vector<vector<int>> mat_exp(vector<vector<int>> a, int b){
    int n = a.size();
    vector<vector<int>> res(n, vector<int> (n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i==j)
                res[i][j] = 1;

    while(b){
        if(b&1)
            res = mux(res, a);
        a = mux(a,a);
        b >>= 1;
    }

    return res;
}


void solve(){
    vector<vector<int>> mat(26, vector<int>(26, 0));
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            cin >> mat[i][j];

    int q;
    cin >> q;

    while(q--){
        char ch;
        int l;
        cin >> ch >> l;

        vector<vector<int>> res = mat_exp(mat, l-1);
        int cnt = 0;

        for(int i=0; i<26; i++)
            cnt = (cnt+res[i][ch-97])%M;

        cout << cnt << endl;
    }
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