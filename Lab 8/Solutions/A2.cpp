#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

string multiple(int s) {
    if(s == 1)
        return "1";
    queue<int> q;
    q.push(1);
    vector<char> mp(s, 'q');
    vector<int> par(s, -1);
    mp[1] = '1';
    par[1] = '-1';

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == 0){
            string res;
            int cur = 0;
            while(cur != 1){
                res += mp[cur];
                cur = par[cur];
            }
            res += '1';
            reverse(res.begin(), res.end());
            return res;
        }
        int r0 = (u*10)%s;
        int r1 = (u*10+1)%s;
        if(mp[r0] == 'q'){
            q.push(r0);
            mp[r0] = '0';
            par[r0] = u;
        }
        if(mp[r1] == 'q'){
            q.push(r1);
            par[r1] = u;
            mp[r1] = '1';
        }
    }

    return "-1";
}

void solve(int tc = 1){
    int n;
    cin >> n;

    cout << multiple(n) << endl;
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