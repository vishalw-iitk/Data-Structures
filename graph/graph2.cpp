//DFS AND BFS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class graphy{
    private:
    int nodes, edges, source, destination, start_node;
    public:
    graphy();
    void print_bfs(vector<int> gr[], int start_n, vector<int> &vis);
    void print_dfs(vector<int> gr[], int start_n, vector<int> &vis);
    // void insertion(int n, int e, vector<int> &gr[]);
};

// void graphy :: insertion(int n, int e, vector<int> &gr[]){
//     int ed = e;
//     while(ed!=0){
//         cin>>
//         gr[]
//     }
// }

void graphy :: print_bfs(vector<int> gr[], int start_n, vector<int> &vis){
    if(gr[start_n].size()==0){
        return;
    }
    else{
        if(vis[start_n]==0){
            cout<<start_n<<" ";
            vis[start_n]=1;
        }
        int temp = gr[start_n][0];
        gr[start_n].erase(gr[start_n].begin()+0);
        remove(gr[temp].begin(), gr[temp].end(), start_n);
        print_bfs(gr, temp, vis);
    }
    // while(gr[start_n].size()!=0){
    //     if(vis[start_n]==0){
    //         cout<<start_n<<" ";
    //         vis[start_n]=1;
    //     }
    //     int temp = gr[start_n][0];
    //     gr[start_n].erase(gr[start_n].begin()+0);
    //     remove(gr[temp].begin(), gr[temp].end(), start_n);
    //     print_bfs(gr, temp, vis);
    // }
}

void graphy :: print_dfs(vector<int> gr[], int start_n, vector<int> &vis){
    if(gr[start_n].size()==0){
        return;
    }
    if(s.top()==NULL){
        return;
    }
    if(s.empty()==true)
        s.push(start_n);
    if(vis[start_n]==0){
        vis[start_n]=1;
        s.push(start_n);
    }
    else if(s.empty()==false && vis[start_n]==1){
        while()
    }
    temp = 
    print_dfs(gr, temp, vis);
    
}

graphy :: graphy(){
    cout<<"Enter the number of nodes and edges : "<<endl;
    cin>>nodes>>edges;
    vector<int> gr[nodes+1];
    int ed = edges;
    while(ed!=0){
        cin>>source>>destination;
        gr[source].push_back(destination);
        gr[destination].push_back(source);
        ed--;
    }
    cout<<"Enter the node wrt which you want to print DFS"<<endl;
    cin>>start_node;
    vector<int> vis;
    for(int i=0; i<nodes+1; i++){
        sort(gr[i].begin(), gr[i].end());
        vis.push_back(0);
    }
    print_dfs(gr, start_node, vis);
    // print_bfs(gr, start_node, vis);
    // insertion(nodes, edges, gr);

}

int main(){
    graphy s[1];
    return 0;
}