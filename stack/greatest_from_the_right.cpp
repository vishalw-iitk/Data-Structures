// Given the array, for every element get the nearest array-element itself from the right of the current number
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class stackitnow{
    private:
    int size;
    int start;
    vector<int> v;
    stack<int> s;

    public:
    stackitnow();
    vector<int> solveit(int arr[], vector<int> v, stack<int> s, int start);
};

vector<int> stackitnow :: solveit(int arr[], vector<int> v, stack<int> s, int start){
    if(start == -1){
        reverse(v.begin(), v.end());
        return v;
    }
    if(s.size()==0){
        v.push_back(-1);
    }
    
    if(s.size()!=0 && s.top()>arr[start]){
        v.push_back(s.top());
    }
    else if(s.size()!=0 && s.top()<=arr[start]){
        while(s.size()!=0 && s.top()<=arr[start]){
            s.pop();
        }
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.top()>arr[start]){
            v.push_back(s.top());
        }

    }
    s.push(arr[start]);
    start-=1;
    
    return solveit(arr, v, s, start);
    
}

stackitnow :: stackitnow(){
    cout<<"\nEnter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the "<<size<<" elements of the array : "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    start = size - 1;
    v = solveit(arr, v, s, start);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    stackitnow s1, s2;

    return 0;
}