//DFS
//BFS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class grp{
    private:
    int v, e;
    unordered_map<int, vector<int>> mp;
    unordered_map<int, vector<int>> sorted_mp;
    stack<int> stk;
    queue<int> q;
    vector<int> visited;
    public:
    grp();
    unordered_map<int, vector<int>> create_graph(int v, int e);
    unordered_map<int, vector<int>> sort_map(unordered_map<int, vector<int>> mp);
    void DFS(unordered_map<int, vector<int>> &mp, vector<int> &visited, stack<int> &stk);
    vector<int> create_visited(int v);
    void BFS(unordered_map<int, vector<int>> &mp, vector<int> &visited, queue<int> &stk);
};

unordered_map<int, vector<int>> grp :: create_graph(int v, int e){
    int s, d;
    unordered_map<int, vector<int>> mp;
    cout<<"Create your undirected graph. Provide the edge connections :  ";
    for(int i=0; i<e; i++){
        cin>>s>>d;
        mp[s].push_back(d);
        mp[d].push_back(s);
    }
    return mp;
}

unordered_map<int, vector<int>> grp :: sort_map(unordered_map<int, vector<int>> mp){
    for(auto i=mp.begin(); i!=mp.end(); i++){
        sort(mp[i->first].begin(), mp[i->first].end());
    }
    return mp;
}

vector<int> grp :: create_visited(int v){
    vector<int> vs;
    for(int i=0; i<v; i++){
        vs.push_back(0);
    }
    return vs;
}

void grp :: DFS(unordered_map<int, vector<int>> &mp, vector<int> &visited, stack<int> &stk){
    if(visited[stk.top()] == 0){
        cout<<stk.top()<<" ";
        visited[stk.top()] = 1;
        for(int i=0; i<mp[stk.top()].size(); i++){
            if(visited[mp[stk.top()][i]] == 0){
                stk.push(mp[stk.top()][i]);
                DFS(mp, visited, stk);
            }
        }
        stk.pop();
    }
}

void grp :: BFS(unordered_map<int, vector<int>> &mp, vector<int> &visited, queue<int> &q){
    while(visited[q.front()] == 1){
        // cout<<"qfront already visited"<<endl;
        q.pop();
    }
    if(q.empty() == true){
        // cout<<"q is empty"<<endl;
        return;
    }
    if(visited[q.front()] == 0){
        cout<<q.front()<<" ";
        visited[q.front()] = 1;
        for(int i=0; i<mp[q.front()].size(); i++){
            if(visited[mp[q.front()][i]] == 0){ 
                q.push(mp[q.front()][i]);
            }
        }
        q.pop();
        BFS(mp, visited, q);
    }
}

grp :: grp(){
    cout<<"Enter the number of vertices for your graph : ";
    cin>>v;
    cout<<"Enter the number of edges for your graph : ";
    cin>>e;

    mp = create_graph(v, e);
    
    sorted_mp = sort_map(mp);

    
    visited = create_visited(v);

    int dfs_start_node;
    cout<<"Enter the first dfs node : ";
    cin>>dfs_start_node;
    stk.push(dfs_start_node);
    DFS(sorted_mp, visited, stk);

    visited = create_visited(v);
    int bfs_start_node;
    cout<<"\nEnter the first bfs node : ";
    cin>>bfs_start_node;
    q.push(bfs_start_node);
    BFS(sorted_mp, visited, q);
}

int main(){
    grp g[1];
    return 0;
}