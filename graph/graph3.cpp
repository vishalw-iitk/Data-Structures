//DFS and BFS
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class search_class{
    private:
    int nodes, edges, dfs_node;
    vector<int> vis, visq;
    stack<int> stk;
    queue<int> que;
    unordered_map<int, vector<int>> mp;
    int s, d;
    public:
    search_class();
    void  DFS(unordered_map<int, vector<int>> mp, vector<int> &vis,  stack<int> &stk);
    void BFS(unordered_map<int, vector<int>> mp, vector<int> &visq, queue<int> &que);
};

void search_class :: DFS(unordered_map<int, vector<int>> mp, vector<int> &vis, stack<int> &stk){

    if(vis[stk.top()-1]==0){ //check that the top of the stack is not visited
        cout<<stk.top()<<" "; //print the top of the stack
        vis[stk.top()-1]=1; //mark this(top of stack) node as visited
        //loop through all the connections(top of stack node -> [1] : [2, 3, 4, 6]) of the top of stack node
        for(int i=0; i<mp[stk.top()].size(); i++){
            //while looping over check whether the connection is visited or not.
            //If the connection is not visited, immediately add it to the top of the stack and make the recursive function call
            if(vis[mp[stk.top()][i]-1]==0){ //if connection not visited
                stk.push(mp[stk.top()][i]); //push into the stack
                DFS(mp, vis, stk); //make the recursive call
            }
        }
        //once you have gone through all the connections, now you can pop the top of the stack node as
        //the DFS work for that node is completed and now you want to check for the nodes below in that stack
        stk.pop();  
    }
}

void search_class :: BFS(unordered_map<int, vector<int>> mp, vector<int> &visq, queue<int> &que){
    if(que.empty()==true){ //if by popping, if que becomes empty
        return; //then just return through the function
    }
    else if(visq[que.front()-1]==1){ //if the front node is visited
        que.pop(); //just pop it
        BFS(mp, visq, que); //and make a recursive call so that we hit either the unvisited node or the empty queue
    }
    else if(visq[que.front() - 1] == 0){//if the node is not visited
        cout<<que.front()<<" "; //print the node
        visq[que.front()-1] = 1; //add it to the queue
        for(int i=0; i<mp[que.front()].size(); i++){ //traverse the connections of that node in this loop
            if(visq[mp[que.front()][i]-1]==0){ //for the connections which are yet to be visited
                que.push(mp[que.front()][i]); //add such connections into the queue at back
            }
        }
        que.pop(); //once this node is covered, we can pop this node from the front by popping
        BFS(mp, visq, que); //make a recursive call with new front node
    }
}

search_class :: search_class(){
    cout<<"\n\nEnter the number of nodes"<<endl;
    cin>>nodes;
    cout<<"Enter the number of edges"<<endl;
    cin>>edges;
    cout<<"Enter source to destination of edges: "<<endl;
    int e = edges;
    //insertion
    while(e!=0){
        cin>>s>>d;
        mp[s].push_back(d);
        sort(mp[s].begin(), mp[s].end());
        mp[d].push_back(s);
        sort(mp[d].begin(), mp[d].end());
        e = e-1;
    }
    cout<<endl;
    //print
    for(auto i=mp.begin(); i!=mp.end(); i++){
        cout<<i->first<<" : ";
        for(int j=0; j<mp[i->first].size(); j++){
            cout<<mp[i->first][j]<<" ";
        }
        cout<<endl;
    }
    //create the unvisited array
    for(int i=0; i<mp.size(); i++){
        vis.push_back(0);
    }
    cout<<"Enter the node with which you want to begin the DFS : "<<endl;
    cin>>dfs_node;
    stk.push(dfs_node);
    DFS(mp, vis, stk);

    //create the unvisited array
    for(int i=0; i<mp.size(); i++){
        visq.push_back(0);
    }
    cout<<"\nEnter the node with which you want to begin the BFS : "<<endl;
    cin>>dfs_node;
    que.push(dfs_node);
    BFS(mp, visq, que);
}

int main(){
    search_class s1;
    return 0;
}