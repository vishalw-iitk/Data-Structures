//Go on inserting the nodes in AVL tree
//We can insert 'n' nodes in AVL tree
//We can print the inorder traversal of the tree
//We tell how many nodes we want to delete
//So, for tis many time we provide the key value of node and go on deleting, don't dlelete if the key is not found
//Print the inoder travsersal

#include <iostream>
using namespace std;

class avltype{
    public:
    int data;
    avltype* left;
    avltype* right;
    int height;
};

class AVL{
    private:
    int n, ele;

    public:
    AVL();
    avltype* avl_insertion(avltype* avlroot, int ele);
    avltype* createnode(int ele);
    int get_height(avltype* avlroot);
    int get_balance(avltype* avlroot);
    avltype* rotate_right(avltype* avlroot);
    avltype* rotate_left(avltype* avlroot);
    void print_inorder(avltype* avlroot);
};

avltype* AVL :: createnode(int ele){
    avltype* node = new avltype();
    node->data = ele;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int AVL :: get_height(avltype* avlroot){
    if(avlroot == NULL){
        return 0;
    }
    else{
        return avlroot->height;
        // return 1 + max(get_height(avlroot->left), get_height(avlroot->right));
    }
}

avltype* AVL :: rotate_right(avltype* top){
    if(top == NULL){
        return top;
    }
    avltype* mid = top->left;
    avltype* T = mid->right;
    
    mid->right = top;
    top->left = T;

    mid->height = 1 + max(get_height(mid->left), get_height(mid->right));
    top->height = 1 + max(get_height(top->left), get_height(top->right));

    return mid;

}
avltype* AVL :: rotate_left(avltype* top){
    if(top == NULL){
        return top;
    }
    avltype* mid = top->right;
    avltype* T = mid->right;

    mid->left = top;
    top->right = T;

    mid->height = 1 + max(get_height(mid->left), get_height(mid->right));
    top->height = 1 + max(get_height(top->left), get_height(top->right));

    return mid;
}


int AVL :: get_balance(avltype* avlroot){
    if(avlroot == NULL){
        return 0;
    }
    return get_height(avlroot->left) - get_height(avlroot->right);
}

avltype* AVL :: avl_insertion(avltype* avlroot, int ele){
    if(avlroot == NULL){
        avlroot = createnode(ele);
        // cout<<avlroot->data<<"^^^";
        return avlroot;
    }
    // cout<<1111<<"  ";
    if(ele < avlroot->data){
        avlroot->left = avl_insertion(avlroot->left, ele);
    }
    else if(ele > avlroot->data){
        avlroot->right = avl_insertion(avlroot->right, ele);
    }
    else{ //duplicate values not allowed in AVL trees
        return avlroot;
    }

    avlroot->height =  1 + max(get_height(avlroot->left), get_height(avlroot->right));

    // cout<<2222<<"  ";
    int balance = get_balance(avlroot);

    if(balance > 1 && ele < avlroot->left->data){ //left left case
        return rotate_right(avlroot);
    }
    if(balance < -1 && ele > avlroot->right->data){ // right right case
        return rotate_left(avlroot);
    }
    if(balance > 1 && ele > avlroot->left->data){ //left right case
        avlroot->left = (avlroot->left);
        return rotate_right(avlroot);
    }
    if(balance < -1 && ele < avlroot->right->data){ //right left case
        avlroot->right = rotate_right(avlroot->right);
        return rotate_left(avlroot);
    }
    return avlroot;

}

void AVL :: print_inorder(avltype* avlroot){
    if(avlroot == NULL){
        // cout<<444<<"  ";
        return;
    }
    // cout<<"  ";
    print_inorder(avlroot->left);
    cout<<avlroot->data<<" ";
    print_inorder(avlroot->right);
}

AVL :: AVL(){
    cout<<"Enter the number of nodes that you want to insert in an AVL tree: ";
    cin>>n;
    avltype* avlroot = NULL;
    for(int i=0; i<n; i++){
        cin>>ele;
        avlroot = avl_insertion(avlroot, ele);
    }
    // cout<<avlroot->data<<"$$$";
    cout<<"Inorder print: ";
    print_inorder(avlroot);
}


int main(){
    AVL a[1];
    return 0;
}