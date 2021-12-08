#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,int start,bool *visited){
    visited[start]=true;
    for(int i=0;i<edges[start].size();i++){
        int next=edges[start][i];
        if(!visited[next]){
            dfs(edges,next,visited);
        }
    }
   
}
void dfss(vector<int>* edges,int start,bool *visited,stack<int>& Stack){
    visited[start]=true;
    for(int i=0;i<edges[start].size();i++){
        int next=edges[start][i];
        if(!visited[next]){
            dfss(edges,next,visited,Stack);
        }
    }
    Stack.push(start);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
    cin >> n;
    vector<int>* edges = new vector<int>[n+1];
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        edges[j].push_back(k );
        
    }
        
    stack<int> flow;
    bool *visited=new bool[n+1];
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfss(edges,i,visited,flow);
            }
        }
        for(int i=1;i<=n;i++){
        visited[i]=false;
    }
        int count=0;
        while(!flow.empty()){
            int el=flow.top();
            flow.pop();
            if(!visited[el]){
                dfs(edges,el,visited);
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
