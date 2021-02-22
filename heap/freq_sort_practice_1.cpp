//less freqents to the higher frequents
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> typ;

class freq_sort{
    private:
    int size;
    unordered_map<int,int> mp;
    typ pqmin;
    public:
    freq_sort();
    void solve(int arr[]);
};

void freq_sort :: solve(int arr[]){
    for(int i=0; i<size; i++){
        mp[arr[i]]++;
    }
    for(auto i=mp.begin(); i!=mp.end(); i++){
        pqmin.push({i->second, i->first});
    }
    for(int i=0; i<mp.size(); i++){
        for(int j=0; j<pqmin.top().first; j++){
            cout<<pqmin.top().second<<" ";
        }
    pqmin.pop();
    }
}


freq_sort :: freq_sort(){
    cout<<"\n\nEnter the size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"frequency sorted array : "<<endl;
    solve(arr);
}

int main(){
    freq_sort s1;
    return 0;
}