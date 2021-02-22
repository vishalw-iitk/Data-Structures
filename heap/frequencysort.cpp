// Frequency sort
// Sort the given array based on the frequency of the elements(decreasing frequencies)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class freqsort{
    private:
    int size;
    unordered_map<int, int> mp;
    priority_queue <pair<int,int>> pqmax;
    public:
    freqsort();
    unordered_map<int, int> form_the_map(int arr[]);
    priority_queue <pair<int,int>> solve(unordered_map<int, int> mp);
    void print_dec_freqsorted(priority_queue <pair<int,int>> pqmax);
};

unordered_map<int, int> freqsort :: form_the_map(int arr[]){
    for(int i = 0; i<size; i++){
        mp[arr[i]]++;
    }
    return mp;
}

priority_queue <pair<int,int>> freqsort :: solve(unordered_map<int, int> mp){
    //thinking of the max heap so that the most frequent elements comes at the top
    for(auto i = mp.begin(); i!=mp.end(); i++){
        pqmax.push({i->second, i->first});
    }
    return pqmax;
}

void freqsort :: print_dec_freqsorted(priority_queue <pair<int,int>> pqmax){
    // cout<<"size: "<<pqmax.size()<<endl;
    while(pqmax.size()>0){
        // cout<<"\nfrequency, element "<<pqmax.top().first<<" "<<pqmax.top().second<<endl;
        for(int j = 0; j<pqmax.top().first; j++){
                cout<<pqmax.top().second<<" ";
        }
        pqmax.pop();
    }
}


freqsort :: freqsort(){
    cout<<"\n\nEnter the size of the array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    mp = form_the_map(arr);
    pqmax = solve(mp);
    cout<<"\nArray printed based on the decreasing frequencies of the elements: "<<endl;
    print_dec_freqsorted(pqmax);
}

int main(){
    freqsort f1, f2;

    return 0;
}