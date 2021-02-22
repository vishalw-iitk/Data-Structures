#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class max_area{
    private:
    int m, n, w, amax, amaxnew;
    vector<int> rh, lf;
    vector<vector<int>> mul_vec;
    // stack<pair<int,int>> s;

    public:
    max_area();
    vector<int> smallest_to_the_right(vector<int> v_inner);
    vector<int> smallest_to_the_left(vector<int> v_inner);
    void get_the_array_to_pass(vector<vector<int>> &mul_vec);
    int get_area(vector<int> v);
};


void max_area :: get_the_array_to_pass(vector<vector<int>> &mul_vec){
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(mul_vec[i][j]!=0){
            mul_vec[i][j] = mul_vec[i][j]+mul_vec[i-1][j];
            }
        }
        cout<<endl;
    }

    return;
}

int max_area :: get_area(vector<int> v_inner){
    vector<int> rh;
    vector<int> lf;
    rh = smallest_to_the_right(v_inner);
    lf = smallest_to_the_left(v_inner);

    vector<int> areas;
    vector<int> width;

    for(int i=0; i<rh.size(); ++i){
        width.push_back((rh[i]-lf[i] - 1)*w);
    }
    for(int i=0; i<width.size(); i++){
        areas.push_back(width[i]*v_inner[i]);
    }
    amaxnew = *max_element(areas.begin(), areas.end());

    return amaxnew;
}

//smallest to the right
vector<int> max_area :: smallest_to_the_right(vector<int> v_inner){
    vector<int> v;
    stack<pair<int,int>> s;
    
    for(int i=n-1; i>=0; i--){
        if(s.size()==0){
            v.push_back(n);
        }
        if(s.size()!=0 && v_inner[i]>s.top().first){
            v.push_back(s.top().second);
        }
        else if(s.size()!=0 && v_inner[i]<=s.top().first){
            while(s.size()!=0 && v_inner[i]<=s.top().first){
            s.pop();
            }
            if(s.size()==0){
                v.push_back(n);
            }
            else if(s.size()!=0 && v_inner[i]>s.top().first){
            v.push_back(s.top().second);
            }
        }
        s.push({v_inner[i], i});
    }
    reverse(v.begin(),v.end());
    return v;
}

//smallest to the left
vector<int> max_area :: smallest_to_the_left(vector<int> v_inner){
    vector<int> v;
    stack<pair<int,int>> s;
    
    for(int i=0; i<n; i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        if(s.size()!=0 && v_inner[i]>s.top().first){
            v.push_back(s.top().second);
        }
        else if(s.size()!=0 && v_inner[i]<=s.top().first){
            while(s.size()!=0 && v_inner[i]<=s.top().first){
            s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()!=0 && v_inner[i]>s.top().first){
            v.push_back(s.top().second);
            }
        }
        s.push({v_inner[i], i});
    }
    return v;
}


max_area :: max_area(){
    cout<<"\n\nEnter the dimensions of the array: "<<endl;
    cin>>m>>n;

    // int arr[m][n];
    // int (*p)[n] = arr;
    int** arr = new int*[m];
    for(int i = 0; i < m; ++i)
        arr[i] = new int[n];
    
    cout<<"Enter the width of single elements: "<<endl;
    cin>>w;

    cout<<"Enter the binary matrix of size "<<m<<"*"<<n<<": "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // array to vector
    for(int p=0; p<m; p++){
        vector<int> temp;
        for(int q=0; q<n; q++){
            temp.push_back(arr[p][q]);
        }
        mul_vec.push_back(temp);
    }

    get_the_array_to_pass(mul_vec);

    //print the row-wise summes vectors
    cout<<"check the array to pass"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<mul_vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    amax = 0;

    for(int i=0; i<m; i++){
        vector<int> copyRow(mul_vec[i].begin(), mul_vec[i].end());
        // vector<int> copyRow = mul_vec[m];
        amaxnew = get_area(copyRow);
        if(amaxnew > amax){
            amax = amaxnew;
        }
    }
    cout<<"\nMaximum area : "<<amax<<endl;
}


int main(){
    max_area m1, m2;

    return 0;
}