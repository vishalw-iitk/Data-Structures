#include<iostream>
#include<queue>
using namespace std;

struct treenode{
    int value;
    treenode* left_go;
    treenode* right_go;
};

class level_order{
    private:
    int n, ele, created;
    public:
    level_order();
    treenode* insert_levelorder(treenode* rootptr);
    treenode* createnode(int val);
    void levelorder_print(treenode* rootptr);
};

treenode* level_order :: createnode(int val){
    treenode* new_tree_node = new treenode();
    new_tree_node->value = val;
    new_tree_node->left_go = NULL;
    new_tree_node->right_go = NULL;
    return new_tree_node;
}

treenode* level_order :: insert_levelorder(treenode* rootptr){
    if(rootptr==NULL){
        cin>>ele;
        rootptr = createnode(ele);
        created+=1;
    }
    queue<treenode*> q;
    q.push(rootptr);

    while(q.empty()==false){
        treenode* tnode = q.front();
        q.pop();

        if(tnode->left_go!=NULL){
            q.push(tnode->left_go);
        }
        else{
            if(created<n){
                cin>>ele;
                tnode->left_go = createnode(ele);
                created+=1;
                // cout<<"left"<<ele<<" "<<created<<endl;
                q.push(tnode->left_go);
            }
        }
        
        if(tnode->right_go!=NULL){
            q.push(tnode->right_go);
        }
        else{
            if(created<n){
                cin>>ele;
                tnode->right_go = createnode(ele);
                created+=1;
                // cout<<"right"<<ele<<" "<<created<<endl;
                q.push(tnode->right_go);
            }
        }
    }
    return rootptr;
}

void level_order :: levelorder_print(treenode* rootptr){
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

level_order :: level_order(){
    cout<<"\n\nEnter the number of elements to be added in the tree in the level order traversal manner:"<<endl;
    cin>>n;
    created = 0;
    treenode* rootptr = NULL;
    rootptr = insert_levelorder(rootptr);

    cout<<"\nlevel-order print : "<<endl;
    levelorder_print(rootptr);
}

int main(){
    level_order s1, s2;
    return 0;
}