#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

int chk(vector<int>& arr){
    int res = 0, n = arr.size();
    vector<int> pre(n, -1), suf(n, n);
    stack<int> st;

    for(int i=0; i<n; i++){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                pre[i] = st.top();
            st.push(i);
        }
    }

    while(!st.empty())
        st.pop();

    for(int i=n-1; i>=0; i--){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                suf[i] = st.top();
            st.push(i);
        }
        res = max(res, arr[i]*(suf[i]-pre[i]-1));
    }

    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m, 0));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];

    for(int i=1; i<n; i++)
        for(int j=0; j<m; j++)
            if(mat[i][j])
                mat[i][j] += mat[i-1][j];

    int res = 0;

    for(int i=0; i<n; i++){
        vector<int> arr;
        for(int j=0; j<m; j++)
            arr.push_back(mat[i][j]);
        res = max(res, chk(arr));
    }

    cout << res<< endl;
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