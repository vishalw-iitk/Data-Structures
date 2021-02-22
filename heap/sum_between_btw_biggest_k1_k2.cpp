//find the sum of elements between k1th and k2th biggest element in the given array
#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> typeheap;

class sum_k1_k2{
    private:
    int size, k1, k2, sum;
    typeheap pqmin;
    public:
    sum_k1_k2();
    void arrange_the_heap(int arr[], typeheap &pqmin);
    int get_the_sum(typeheap &pqmin);
};

void sum_k1_k2 :: arrange_the_heap(int arr[], typeheap &pqmin){
    if(k1>k2){
        k2 = k2+k1;
        k1 = k2-k1;
        k2 = k2-k1;
    }
    for(int i=0; i<size; i++){
        if(pqmin.size()<=k2){
            pqmin.push(arr[i]);
            if(pqmin.size()==k2+1){
                pqmin.pop();
            }
        }
    }
}

int sum_k1_k2 :: get_the_sum(typeheap &pqmin){
    pqmin.pop();
    sum = 0;
    for(int i=0; i<abs(k2-k1-1); i++){
        sum+=pqmin.top();
        pqmin.pop();
    }
    return sum;
}

sum_k1_k2 :: sum_k1_k2(){
    cout<<"\n\nEnter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Find the sum between k1th and k2th biggest elements in the array: Enter k1 and k2 "<<endl;
    cin>>k1;
    cin>>k2;
    arrange_the_heap(arr, pqmin);
    sum = get_the_sum(pqmin);
    cout<<"The sum between "<<k1<<"th and "<<k2<<"th biggest elements in the array : "<<sum<<endl;
}

 int main(){
     sum_k1_k2 s1, s2;

     return 0;
 }