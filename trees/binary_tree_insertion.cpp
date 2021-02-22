#include <iostream>
#include <queue>
using namespace std;


struct treenode{
    int value;
    treenode* left_go;
    treenode* right_go;
};

class tree_dia{
    private:
    int n, ele;
    public:
    tree_dia();
    treenode* insert_in_tree(treenode* rootptr, int val);
    treenode* createnode(int val);
    void inorder_print(treenode* rootptr);
    void preorder_print(treenode* rootptr);
    void postorder_print(treenode* rootptr);
    void levelorder_print(treenode* rootptr);
};



treenode* tree_dia :: createnode(int val){
    treenode* newNode = new treenode();
    newNode->value = val;
    newNode->left_go = NULL;
    newNode->right_go = NULL;
    // cout<<"create: "<<val<<endl;
    return newNode;
}

treenode* tree_dia :: insert_in_tree(treenode* rootptr, int val){
    if(rootptr == NULL){
        rootptr = createnode(val);
        return rootptr;
    }
    if(val >= rootptr->value){
        // cout<<"right: "<<val<<endl;
        rootptr->right_go = insert_in_tree(rootptr->right_go, val);
    }
    else if(val < rootptr->value){
        // cout<<"left: "<<val<<endl;
        rootptr->left_go = insert_in_tree(rootptr->left_go, val);
    }
    // cout<<val<<endl;
    return rootptr;
}

void tree_dia :: inorder_print(treenode* rootptr){
    // cout<<"ozozo"<<endl;
    if(rootptr == NULL){
        return;
    }
    inorder_print(rootptr->left_go);
    cout<<rootptr->value<<" ";
    inorder_print(rootptr->right_go);
}

void tree_dia :: preorder_print(treenode* rootptr){
    // cout<<"ozozo"<<endl;
    if(rootptr == NULL){
        return;
    }
    cout<<rootptr->value<<" ";
    preorder_print(rootptr->left_go);
    preorder_print(rootptr->right_go);
}

void tree_dia :: postorder_print(treenode* rootptr){
    // cout<<"ozozo"<<endl;
    if(rootptr == NULL){
        return;
    }
    postorder_print(rootptr->left_go);
    postorder_print(rootptr->right_go);
    cout<<rootptr->value<<" ";
}

void tree_dia :: levelorder_print(treenode* rootptr){
    if(rootptr == NULL){
        return;
    }
    queue<treenode*> q;
    q.push(rootptr);

    while(q.empty()==false){
        treenode* tnode = q.front();
        cout<<tnode->value<<" ";
        q.pop();

        if(tnode->left_go!=NULL){
            q.push(tnode->left_go);
        }
        if(tnode->right_go!=NULL){
            q.push(tnode->right_go);
        }

    }

}

tree_dia :: tree_dia(){
    treenode* rootptr=NULL;
    cout<<"\n\nEnter the number of elements you wish to add into the binary search tree"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>ele;
        rootptr = insert_in_tree(rootptr, ele);
    }
    cout<<"\ninorder print : "<<endl;
    inorder_print(rootptr);

    cout<<"\npreorder print : "<<endl;
    preorder_print(rootptr);

    cout<<"\npostorder print : "<<endl;
    postorder_print(rootptr);

    cout<<"\nlevel-order print : "<<endl;
    levelorder_print(rootptr);
}


int main(){
    tree_dia s1, s2;

    return 0;
}