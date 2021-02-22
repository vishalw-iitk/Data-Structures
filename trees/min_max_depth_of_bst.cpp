#include<iostream>
using namespace std;

//insertion through bst method
//also print the tree via inorder to confirm the tree structure
//Once the tree is achieved we can tell the min and max depth

struct treenode{
    int value;
    treenode* left_go;
    treenode* right_go;
};

class depth{
    private:
    int n, ele, diam, res, res1, res2;
    public:
    depth();
    treenode* insertion(treenode* rootptr, int val);
    void inorder(treenode* rootptr);
    int dia_bin_tree(treenode* rootptr, int &res);
    int min_depth_of_tree(treenode* rootptr);
    int max_depth_of_tree(treenode* rootptr);
};

treenode* createnode(int val){
    treenode* newNode = new treenode();
    newNode->value = val;
    newNode->left_go = NULL;
    newNode->right_go = NULL;
    return newNode;
}

treenode* depth :: insertion(treenode* rootptr, int val){
    if(rootptr==NULL){
        rootptr = createnode(val);
        return rootptr;
    }
    if(val < rootptr->value){
        rootptr->left_go = insertion(rootptr->left_go, val);
    }
    else if(val >= rootptr->value){
        rootptr->right_go = insertion(rootptr->right_go, val);
    }
    return rootptr;
}

void depth :: inorder(treenode* rootptr){
    if(rootptr==NULL){
        return;
    }
    inorder(rootptr->left_go);
    cout<<rootptr->value<<" ";
    inorder(rootptr->right_go);
}

int depth :: dia_bin_tree(treenode* rootptr, int &res){
    if(rootptr == NULL){
        return 0;
    }
    int l = dia_bin_tree(rootptr->left_go, res);
    int r = dia_bin_tree(rootptr->right_go, res);
    int temp = 1+ max(l, r);
    int ans = max(temp, 1 + l+ r);
    res = max(res, ans);
    
    return temp;
}

int depth :: min_depth_of_tree(treenode* rootptr){
    if(rootptr == NULL){
        return 0;
    }
    // if(rootptr->left_go == NULL || rootptr->right_go == NULL){
    //     return 1;
    // }
    int l = min_depth_of_tree(rootptr->left_go);
    int r = min_depth_of_tree(rootptr->right_go);
    // int temp1 = 2 + min(l,r);
    
    // int ans1 = min(temp1, 1+min(l, r));

    // res1 = min(res1, ans1);


    return 1+min(l,r);

}

int depth :: max_depth_of_tree(treenode* rootptr){
    if(rootptr == NULL){
        return 0;
    }
    // if(rootptr->left_go == NULL && rootptr->right_go == NULL){
    //     return 1;
    // }
    int l = max_depth_of_tree(rootptr->left_go);
    int r = max_depth_of_tree(rootptr->right_go);
 
    // int temp2 = 1+max(l,r);

    // int ans2 = max(temp2, max(l,r));

    // res2 = max(res2, ans2);

    return 1+max(l,r);

}

void print_bottom_view(treenode* rootptr){
    if(rootptr==NULL){
        return;
    }
    if(rootptr->left_go==NULL || rootptr->right_go==NULL){
        cout<<rootptr->value<<" ";
    }
    print_bottom_view(rootptr->left_go);
    print_bottom_view(rootptr->right_go);
}

void print_left_view(treenode* rootptr){
    if(rootptr==NULL){
        return;
    }
    if(rootptr->left_go!=NULL){
        cout<<rootptr->value<<" ";
        print_left_view(rootptr->left_go);
    }
    else if(rootptr->left_go==NULL && rootptr->right_go!=NULL){
        cout<<rootptr->value<<" ";
        print_left_view(rootptr->right_go);
    }
    else if(rootptr->left_go==NULL && rootptr->right_go==NULL){
        cout<<rootptr->value<<" ";
    }
}

void get_mirror_view(treenode* &rootptr){
    if(rootptr==NULL){
        return;
    }
    get_mirror_view(rootptr->left_go);
    get_mirror_view(rootptr->right_go);
    treenode* temp = rootptr->left_go;
    rootptr->left_go = rootptr->right_go;
    rootptr->right_go = temp;
}

depth :: depth(){
    cout<<"\n\nEnter the number of nodes in the tree : "<<endl;
    cin>>n;
    treenode* rootptr = NULL;
    for(int i=0; i<n; i++){
        cin>>ele;
        rootptr = insertion(rootptr, ele);
    }
    
    inorder(rootptr);
    
    res = INT_MIN;
    dia_bin_tree(rootptr, res);
    cout<<"\nDiameter of the binary tree : "<<res<<endl;

    // inorder(rootptr);

    // res1 = INT_MAX;
    // res2 = INT_MIN;
    res1 = min_depth_of_tree(rootptr);
    res2 = max_depth_of_tree(rootptr);

    cout<<"\nMin depth of the binary tree : "<<res1<<endl;
    cout<<"\nMax depth or height of the binary tree : "<<res2<<endl;

    cout<<"\nPrint the bottom view of the binary tree : "<<endl;
    print_bottom_view(rootptr);

    cout<<"\nPrint the left view of the binary tree : "<<endl;
    print_left_view(rootptr);

    cout<<"\nPrint the mirror view of the binary tree : "<<endl;
    get_mirror_view(rootptr);

    inorder(rootptr);
    get_mirror_view(rootptr);

}

int main(){
    depth s1, s2;

    return 0;
}