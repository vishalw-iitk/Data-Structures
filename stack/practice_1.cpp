//Find the nearest next greater element for every element of the array
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class stacks{
    private:
    int size;
    vector<int> v1;
    stack<int> s;
    public:
    stacks();
    vector<int> ngr(int arr[], int n);
};

vector<int> stacks :: ngr(int arr[], int n){
    if(n==-1){
        reverse(v1.begin(), v1.end());
        return v1;
    }
    if(s.empty() == true){
        v1.push_back(-1);
    }
    else if(s.top()>=arr[n]){
        v1.push_back(s.top());
    }
    else if(s.empty() != true && s.top()<arr[n]){
        while(s.empty()!=true && s.top()<arr[n]){
            s.pop();
        }
        if(s.empty()==true){
            v1.push_back(-1);
        }
        else if(s.top()>=arr[n]){
            v1.push_back(s.top());
        }
    }
    s.push(arr[n]);
    return ngr(arr, n-1);
}

stacks :: stacks(){
    cout<<"\n\nEnter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0 ; i< size ; i++){
        cin>>arr[i];
    }
    v1 = ngr(arr, size-1);
    cout<<"NGR array is : "<<endl;
    for(int i=0; i<size; i++){
        cout<<v1[i]<<" ";
    }

}

int main(){
    stacks s1;
    return 0;
}