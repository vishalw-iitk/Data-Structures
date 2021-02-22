// Actual problem- How many consecutive to the left of the current number are greater than the current number(current number included). We can get this by find the smallest nearest element to the left
// Given the array, for every element get the index of the smallest and nearest array-element and the array-element itself from the left of the current number
// Also get, after how many numbers to the left including the current number you get the smallest element
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

class stackitnow{
    private:
    int size;
    int start;
    vector<int> farther; //distance from the smallest in the left side
    vector<pair<int, int>> pos_ele; //position, element
    stack<pair<int, int>> s; //position, element
    
    public:
    stackitnow();
    tuple<vector<int>, vector<pair<int, int>>> solveit(int arr[], int size, int start, vector<int> farther, vector<pair<int, int>> pos_ele, stack<pair<int, int>> s);
};

tuple<vector<int>, vector<pair<int, int>> > stackitnow :: solveit(int arr[], int size, int start, vector<int> farther, vector<pair<int, int>> pos_ele, stack<pair<int, int>> s){
    if(start==size){
        for(int i = 0; i<size; i++){
            farther.push_back(i-pos_ele[i].first);
        }
        return {farther, pos_ele};
    }

    if(s.size()==0){
        pos_ele.push_back({-1,-1});
    }
    
    else if(s.size()!=0 && s.top().second<arr[start]){
        pos_ele.push_back({s.top().first, s.top().second});
    }
    else if(s.size()!=0 && s.top().second>=arr[start]){
        while(s.size()!=0 && s.top().second>=arr[start]){
            s.pop();
        }
        if(s.size()==0){
            pos_ele.push_back({-1,-1});
        }
        else{
            pos_ele.push_back({s.top().first, s.top().second});
        }

    }
    s.push({start,arr[start]});
    start = start+1;
    
    
    return solveit(arr, size, start, farther, pos_ele, s);
}

stackitnow :: stackitnow(){
    cout<<"\nEnter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements of the array : "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    start = 0;
    tie(farther, pos_ele) = solveit(arr, size, start, farther, pos_ele, s);
    cout<<"\nindexes of the smallest from the left : "<<endl;
    for(int i=0; i<size; i++){
        cout<<pos_ele[i].first<<" ";
    }
    cout<<"\nelements smallest from the left :"<<endl;
    for(int i=0; i<size; i++){
        cout<<pos_ele[i].second<<" ";
    }
    cout<<"\nDistance of how farther smallest from the left is found : "<<endl;
    for(int i=0; i<size; i++){
        cout<<farther[i]<<" ";
    }
}



int main(){
    stackitnow s1, s2;
    return 0;
}