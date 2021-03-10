// Prims and Djkstra algorithm
// positive weigths only
//Prims : Shortest path which connects all the nodes
// Djkstra : shortest path to every other node from the given node
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class prim_and_dj{
    private:
    int v,e;
    int s,d;
    int w;
    int mst_node;
    unordered_map<int, vector<int>> MST_mp;
    public:
    prim_and_dj();
    void create_map(int** mp, int s, int d, int w);
    vector<int> create_distance_vector(int v);
    vector<bool> create_mst_set(int v);
    vector<int> create_parent_vector(int v);
    void make_mst_graph(int** mp, vector<int> &dis, vector<bool> &MST, vector<int> &parent, int mst_node);
    void make_SPG_graph(int** mp, vector<int> &dis, vector<bool> &MST, vector<int> &parent, int mst_node);
    void create_MST_map(int** MST_mp, int pr, int child, int distance);
    void print_MST(int** MST_mp);
};

void prim_and_dj :: create_map(int** mp, int s, int d, int w){
    mp[s][d] = w;
    mp[d][s] = w;
}

vector<int> prim_and_dj :: create_distance_vector(int v){
    vector<int> dis;
    for(int i=0; i<v; i++){
        dis.push_back(INT_MAX);
    }
    return dis;
}

vector<bool> prim_and_dj :: create_mst_set(int v){
    vector<bool> MST;
    for(int i=0; i<v; i++){
        MST.push_back(false);
    }
    return MST;
}

vector<int> prim_and_dj :: create_parent_vector(int v){
    vector<int> parent;
    for(int i=0; i<v; i++){
        parent.push_back(-1);
    }
    return parent;
}

void prim_and_dj :: make_mst_graph(int** mp, vector<int> &dis, vector<bool> &MST, vector<int> &parent, int mst_node){
    int mn = INT_MAX;
    int p = -1;
    int check = -1;
    for(int j=0; j<v; j++){
        if(MST[j] == false && mp[mst_node][j]!=INT_MAX && dis[j] > mp[mst_node][j]){//traversing node not in MST and current distance value of node > distance in map and is in the vicinity of mst_node according to map
            dis[j] = mp[mst_node][j]; //distance updating everytime
            parent[j] = mst_node; //parent updating everytime
            }
        if(MST[j] == false && mp[mst_node][j] < mn){//traversing node not in MST and trying to find the minimum distance among th child nodes
            check = 1; //To make sure that there was atleast one node not included in MST
            mn = mp[mst_node][j]; //Getting the minimum distance from parent node
            p = j; //setting the child node closest to parent node so on this basis we traverse fro next MST node
        }
    }
    if(check == -1){// We return if all nodes are already included in MST as per the above loop
        return;
    }
    else{   
        MST[p] = true; //We mark the upcoming source node and include in the MST
        mst_node = p; // set the value of new MST node
        make_mst_graph(mp, dis, MST, parent, mst_node); //make a recursive call
    }
}

void prim_and_dj :: make_SPG_graph(int** mp, vector<int> &dis, vector<bool> &MST, vector<int> &parent, int mst_node){
    int mn = INT_MAX;
    int p = -1;
    int check = -1;
    for(int j=0; j<v; j++){
        if(MST[j] == false && mp[mst_node][j]!=INT_MAX && dis[j] > dis[mst_node] + mp[mst_node][j]){//traversing node not in MST and current distance value of node > distance in map and is in the vicinity of mst_node according to map
            dis[j] = dis[mst_node] + mp[mst_node][j]; //distance updating everytime
            parent[j] = mst_node; //parent updating everytime
            }
        if(MST[j] == false && mp[mst_node][j] < mn){//traversing node not in MST and trying to find the minimum distance among th child nodes
            check = 1; //To make sure that there was atleast one node not included in MST
            mn = mp[mst_node][j]; //Getting the minimum distance from parent node
            p = j; //setting the child node closest to parent node so on this basis we traverse fro next MST node
        }
    }
    if(check == -1){// We return if all nodes are already included in MST as per the above loop
        return;
    }
    else{   
        MST[p] = true; //We mark the upcoming source node and include in the MST
        mst_node = p; // set the value of new MST node
        make_SPG_graph(mp, dis, MST, parent, mst_node); //make a recursive call
    }
}


void prim_and_dj :: create_MST_map(int** MST_mp, int pr, int child, int distance){
    MST_mp[pr][child] = distance;
    MST_mp[child][pr] = distance;
}


void prim_and_dj :: print_MST(int** MST_mp){
    // for(auto i = MST_mp.begin(); i!=MST_mp.end(); i++){
    //     cout<<i->first<<" "<<MST_mp[i->first][0]<<" "<<MST_mp[i->first][1];
    //     cout<<endl;
    // }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i>j && MST_mp[i][j] != INT_MAX){
                cout<<i<<" "<<j<<" "<<MST_mp[i][j]<<endl;
            }
        }
    }

}

prim_and_dj :: prim_and_dj(){
    cout<<"\nLet's create a graph "<<endl;
    cout<<"Enter the number of vertices in your graph"<<endl;
    cin>>v;
    cout<<"Enter the number of edges in your graph"<<endl;
    cin>>e;
    int** mp = new int*[v];
    for(int i=0; i<v; i++){
        mp[i] = new int[v];
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
        mp[i][j] = INT_MAX;
    }
    for(int i=0; i<e; i++){
        cin>>s>>d>>w;
        create_map(mp, s, d, w);
    }
    vector<int> dis;
    dis = create_distance_vector(v);

    vector<bool> MST;
    MST = create_mst_set(v);

    vector<int> parent;
    parent = create_parent_vector(v);

    cout<<"Enter the starting node to create MST "<<endl;
    cin>>mst_node;

    dis[mst_node] = 0;
    MST[mst_node] = true;
    make_mst_graph(mp, dis, MST, parent, mst_node); //comment this line to run SPG | DJkstra
    // make_SPG_graph(mp, dis, MST, parent, mst_node); //comment this line to run MST | prim

    cout<<"hellos"<<endl;

    for(int i=0; i<v; i++){
        cout<<i<<" "<<parent[i]<<" ";
        cout<<dis[i]<<" ";
        cout<<endl;
    }

    int** MST_mp = new int*[v];
    for(int i=0; i<v; i++){
        MST_mp[i] = new int[v-1];
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++)
        MST_mp[i][j] = INT_MAX;
    }

    int pr = mst_node;
    int child;
    for(int i=0; i<v; i++){
        if(parent[i]!=-1){
            pr = parent[i];
            child = i;
            cout<<pr<<endl;
            create_MST_map(MST_mp, pr , child, dis[child]); //Here MST_map will be in parent : {child, distance} format
        }
    }
    cout<<"Print the MST according to PRIMS or SPG accroding to Djkstra"<<endl;
    print_MST(MST_mp);

    delete(mp);
    delete(MST_mp);
    mp = NULL;
    MST_mp = NULL;

}

int main(){
    prim_and_dj test[1];
    return 0;
}