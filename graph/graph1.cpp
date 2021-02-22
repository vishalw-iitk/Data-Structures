#include <iostream>
#include <vector>
using namespace std;

class graphing{
    private:
    vector<int> vis;
    int n, e, ele, a, b;
    public:
    graphing();
    void dfs(int nod, vector<int> ar[], vector<int> &vis);
};

// graphing :: addnode(){
    // while(n--)
// }

void graphing :: dfs(int nod, vector<int> ar[], vector<int> &vis){
    vis[nod] = 1;
    cout<<nod<<" -> ";
    for(int i=0; i<ar[nod].size(); i++){
        int child = ar[nod][i];
        if(vis[child]==0)
            dfs(child, ar, vis);
    }
}

graphing :: graphing(){
    cout<<"\n\nEnter the number of nodes and edges to be added in the graph : "<<endl;
    cin>>n>>e;
    vector<int> ar[n+1];
    cout<<""<<endl;
    while(e--){
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        cout<<ar[i].size()<<endl;
    }
    
    for(int i=0; i<n; i++){
        vis.push_back(0);
    }
    int k=0;
    dfs(k, ar, vis);
}

int main(){
    graphing s1;

    return 0;
}