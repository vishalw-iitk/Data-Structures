//Given an integer and an array, print the k-closest elements in the array closest to the given integer
#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

class kclose{
    private:
    int size, x, k;
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pqmax;
    // int* m_array;

    public:
    kclose();
    void solve(priority_queue<pair<int,int>> &pqmax, unordered_map<int,int> mp, int x, int k);
    unordered_map<int,int> form_the_map(int arr[]);
    // int* modified_array(int arr[], int x);
};

// int* kclose :: modified_array(int arr[], int x){


//     return arr;
// }
unordered_map<int,int> kclose :: form_the_map(int arr[]){
    for(int i=0; i<size; i++){
        // cout<<"\nllll"<<abs(arr[i]-x)<<"llll"<<arr[i]<<endl;
        mp.insert({arr[i], abs(arr[i]-x)});
        }
    return mp;
}


void kclose :: solve(priority_queue<pair<int,int>> &pqmax, unordered_map<int,int> mp, int x, int k){
    for(auto i=mp.begin(); i!=mp.end(); i++){
        // cout<<"\n"<<i->first<<"---- "<<i->second<<endl;
        if(pqmax.size()<=k){
            pqmax.push({i->second, i->first});
            if(pqmax.size()==k+1)
                pqmax.pop();
        }
        // else{
        //     pqmax.push({i->second, i->first});
        //     pqmax.pop();
        // }
    }
}

kclose :: kclose(){
    cout<<"\n\nEnter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : "<<endl;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the integer w.r.t which you will print the closest elements in the array : "<<endl;
    cin>>x;
    cout<<"Enter how many closest elements you want to print : "<<endl;
    cin>>k;
    mp = form_the_map(arr);
    // m_array = modified_array(arr, x);
    solve(pqmax, mp, x, k);
    cout<<k<<" closest elements to "<<x<<" are : "<<endl;
    while(pqmax.size()!=0){
        cout<<pqmax.top().second<<" ";
        pqmax.pop();
    }
    // for(auto i=mp.begin(); i!=mp.end(); i++){
    //     cout<<"\n"<<i->first<<"---- "<<i->second<<endl;
    // }

}

int main(){
    kclose k1, k2;

    return 0;
}