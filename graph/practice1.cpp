// Write the DFS and BFS for a graph
// Topological sort
// Bipartite or not
// Reverse/Transpose the graph
// Find the strongly connected components (Kosaraju's algorithm)
// Cycle Detection
// Bridge

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class grapher {
    private:
    int v,e;
    int start;
    unordered_map<int,vector<int>> gph, gph_dir;
    vector<int> visited, parent;
    stack<int> stk;
    queue<int> que;
    public:
    grapher();
    void make_a_graph(unordered_map<int,vector<int>> &gph, unordered_map<int,vector<int>> &gph_dir, int v,int e);
    void make_visited(vector<int> &visited, int v);
    void create_parent(vector<int> &parent, int v);
    void perform_dfs(unordered_map<int,vector<int>> gph, stack<int> &stk, vector<int> &visited);
    void perform_bfs(unordered_map<int,vector<int>> gph, queue<int> &que, vector<int> &visited);
    bool cycle_undir(unordered_map<int,vector<int>> gph, vector<int> &parent, vector<int> &visited, stack<int> &stk);
    void topological(unordered_map<int,vector<int>> gph, stack<int> &stk, vector<int> &visited, vector<int> &unvisited, stack<int> &topo_stack);
    void bridge_detection(vector<pair<int,int>> &bridges, unordered_map<int,vector<int>> gph, vector<int> &parent, vector<int> &visited, stack<int> &stk, int &time, vector<int> &low, vector<int> &disc);
};

void grapher :: make_a_graph(unordered_map<int,vector<int>> &gph,  unordered_map<int,vector<int>> &gph_dir, int v,int e){
    int s,d;
    int ed = e;
    cout<<"Enter the sources - destination path of the graph"<<endl;
    while(ed!=0){
        cin>>s>>d;
        gph[s].push_back(d);
        gph[d].push_back(s);
        gph_dir[s].push_back(d);
        ed--;
    }
    while(v!=0){
        sort(gph[v].begin(), gph[v].end());
        sort(gph_dir[v].begin(), gph_dir[v].end());
        v--;
    }
}

void grapher :: make_visited(vector<int> &visited, int v){
    while(visited.size()!=0){
        visited.pop_back();
    }
    for(int i=0; i<v; i++){
        visited.push_back(0);
    }
}

void grapher :: create_parent(vector<int> &parent, int v){
    while(parent.size()!=0){
        parent.pop_back();
    }
    for(int i=0; i<v; i++){
        parent.push_back(-1);
    }
}

void grapher :: perform_dfs(unordered_map<int,vector<int>> gph, stack<int> &stk, vector<int> &visited){
    if(visited[stk.top()]!=1){
        visited[stk.top()] = 1;
        cout<<stk.top()<<" ";
        for(int i=0; i<gph[stk.top()].size(); i++){
            if(visited[gph[stk.top()][i]]!=1){
                stk.push(gph[stk.top()][i]);
                perform_dfs(gph, stk, visited);
            }
        }
        stk.pop();
    }
}

void grapher :: perform_bfs(unordered_map<int,vector<int>> gph, queue<int> &que, vector<int> &visited){
    if(que.empty()==true){
        return;
    }
    else if(visited[que.front()]==1){
        que.pop();
        perform_bfs(gph, que, visited);
    }
    else if(visited[que.front()]!=1){
        visited[que.front()] = 1;
        cout<<que.front()<<" ";
        for(int i=0; i<gph[que.front()].size(); i++){
            if(visited[gph[que.front()][i]]!=1){
                que.push(gph[que.front()][i]);
            }
        }
        que.pop();
        perform_bfs(gph, que, visited);
    }
}

bool grapher :: cycle_undir(unordered_map<int,vector<int>> gph, vector<int> &parent, vector<int> &visited, stack<int> &stk){
    if(visited[stk.top()]!=1){
        visited[stk.top()] = 1;
        for(int i=0; i<gph[stk.top()].size(); i++){
            if(visited[gph[stk.top()][i]]!=1){
                parent[gph[stk.top()][i]] = stk.top();
                stk.push(gph[stk.top()][i]);
                // if(cycle_undir(gph, parent, visited, stk)){ //works
                //     return true;
                // }
                // return res = cycle_undir(gph, parent, visited, stk);
                return cycle_undir(gph, parent, visited, stk);
            }
            else if(gph[stk.top()][i]!=parent[stk.top()]){
                // return true; //works
                // return res = true;
                return true;
            }

        }
        stk.pop();
    }
    // return res;
    return false;
}

void grapher :: topological(unordered_map<int,vector<int>> gph_dir, stack<int> &stk, vector<int> &visited, vector<int> &unvisited, stack<int> &topo_stack){
    if(visited[stk.top()]!=1){
        visited[stk.top()] = 1;
        // unvisited.erase(unvisited.begin() + stk.top());
        unvisited.erase(remove(unvisited.begin(), unvisited.end(), stk.top()), unvisited.end());
        for(int i=0; i<gph_dir[stk.top()].size(); i++){
            if(visited[gph_dir[stk.top()][i]]!=1){
                stk.push(gph_dir[stk.top()][i]);
                topological(gph_dir, stk, visited, unvisited, topo_stack);
            }
        }
        int shift = stk.top();
        topo_stack.push(shift);
        stk.pop();
    }
}

void grapher :: bridge_detection(vector<pair<int,int>> &bridges, unordered_map<int,vector<int>> gph, vector<int> &parent, vector<int> &visited, stack<int> &stk, int &time, vector<int> &low, vector<int> &disc){
    if(visited[stk.top()]!=1){
        visited[stk.top()]=1;
        low[stk.top()] = ++time;
        disc[stk.top()] = ++time;
        for(int i=0; i<gph[stk.top()].size(); i++){
            if(visited[gph[stk.top()][i]]!=1){
                parent[gph[stk.top()][i]] = stk.top();
                stk.push(gph[stk.top()][i]);
                bridge_detection(bridges, gph, parent, visited, stk, time, low, disc);
                low[stk.top()] = min(low[stk.top()], low[gph[stk.top()][i]]);
                if(low[gph[stk.top()][i]] > disc[stk.top()]){
                    bridges.push_back({stk.top(), gph[stk.top()][i]});
                }
            }
            else if(gph[stk.top()][i]!=parent[stk.top()]){
                low[stk.top()] = min(low[stk.top()], disc[gph[stk.top()][i]]);
            }
        }
        stk.pop();
    }
}

grapher :: grapher(){
    cout<<"\nEnter the number of vertices in your graph"<<endl;
    cin>>v;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    make_a_graph(gph, gph_dir, v, e);
    for(int i=0; i<v; i++){
        visited.push_back(0);
    }

    cout<<"Enter the starting vertex of the DFS search"<<endl;
    cin>>start;
    stk.push(start);
    perform_dfs(gph, stk, visited);

    make_visited(visited, v);
    cout<<"\nEnter the starting node from which you want to perform BFS"<<endl;
    cin>>start;
    que.push(start);
    perform_bfs(gph, que, visited);

    //Topological sort for directed graph
    make_visited(visited, v);
    vector<int> unvisited;
    for(int i=0; i<v; i++){
        unvisited.push_back(i);
    }
    cout<<"\nEnter the starting node from which you want to perform topological sort"<<endl;
    cin>>start;
    stk.push(start);
    stack<int> topo_stack;
    topological(gph_dir, stk, visited, unvisited, topo_stack);
    while(unvisited.size()!=0){
        stk.push(unvisited[0]);
        topological(gph_dir, stk, visited, unvisited, topo_stack);
    }
    while(topo_stack.empty()==false){
        cout<<topo_stack.top()<<" ";
        topo_stack.pop();
    }

    //Cycle detection in undirected graph
    create_parent(parent, v);
    make_visited(visited, v);
    cout<<endl;
    stk.push(0);
    bool res = false;
    bool cycle = cycle_undir(gph, parent, visited, stk);
    cycle==true?cout<<"Cycle detected":cout<<"Cycle not detected";


    //Bridge detection
    //low,disc, parent
    int time = 0;
    vector<pair<int,int>> bridges;
    vector<int> low, disc;
    make_visited(visited, v);
    make_visited(low, v);
    make_visited(disc, v);
    create_parent(parent, v);
    while(stk.empty()!=true){
        stk.pop();
    }
    stk.push(0);
    bridge_detection(bridges, gph, parent, visited, stk, time, low, disc);
    cout<<endl;
    cout<<"Bridges are:"<<endl;
    while(bridges.size()!=0){
        cout<<bridges[bridges.size()-1].first<<" - "<<bridges[bridges.size()-1].second<<" | ";
        bridges.pop_back();
    }


}

int main(){
    grapher g[1];
    return 0;
}