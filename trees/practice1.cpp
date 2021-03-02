//Form the binary tree using BST and level order approach
//Check if the tree is a BST or NOT
//Print the preorder, inorder and postorder form of the tree
//Print the tree in a level order manner

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct treetype{
    int data;
    treetype* left;
    treetype* right;
};

class treebasics{
    private:
    int choice, n, ele;
    public:
    treebasics();
    void get_BST_tree(treetype* &treeroot, int ele);
    treetype* createnode(int val);
    void print_inorder(treetype* &treeroot);
    void print_preorder(treetype* &treeroot);
    void print_postorder(treetype* &treeroot);
    void get_level_order_tree(treetype* &treeroot, queue<treetype*> &q, int ele);
    void inorder_list(treetype* &treeroot, vector<int> &v);
    bool check_BST(treetype* &treeroot);
};

treetype* treebasics :: createnode(int val){
    treetype* newnode = new treetype();
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void treebasics :: get_BST_tree(treetype* &treeroot, int ele){
    if(treeroot == NULL){
        treeroot = createnode(ele);
        return;
    }
    if(ele <= treeroot->data){
        get_BST_tree(treeroot->left , ele);
    }
    else if(ele > treeroot->data){
        get_BST_tree(treeroot->right, ele);
    }
}

void treebasics :: get_level_order_tree(treetype* &treeroot, queue<treetype*> &q, int ele){
    if(treeroot == NULL){
        treeroot = createnode(ele);
        q.push(treeroot);
        return;
    }
    
    treetype* tempnode = createnode(ele);
    if(q.front()->left == NULL){
        q.front()->left = tempnode;
    }
    else if(q.front()->right == NULL){
        q.front()->right = tempnode;
        q.pop();
    }
    q.push(tempnode);
}

void treebasics :: print_inorder(treetype* &treeroot){
    if(treeroot == NULL){
        return;
    }
    print_inorder(treeroot->left);
    cout<<treeroot->data<<" ";
    print_inorder(treeroot->right);
}

void treebasics :: print_preorder(treetype* &treeroot){
    if(treeroot == NULL){
        return;
    }
    cout<<treeroot->data<<" ";
    print_preorder(treeroot->left);
    print_preorder(treeroot->right);
}

void treebasics :: print_postorder(treetype* &treeroot){
    if(treeroot == NULL){
        return;
    }
    print_postorder(treeroot->left);
    print_postorder(treeroot->right);
    cout<<treeroot->data<<" ";
}

//Following function is incorrect because it checks BST locally and not globally. It just checks whether every node has its left small and right greater than the root node. It does not check if the ambiguity is found in the left subtree or right subtree
// bool treebasics :: check_BST(treetype* &treeroot){
//     if(treeroot == NULL){
//         return true;
//     }
//     if(treeroot->left == NULL && treeroot->right == NULL){
//         return true;
//     }
//     if(treeroot->left == NULL && treeroot->right != NULL && treeroot->right->data <= treeroot->data){
//         return false;
//     }
//     if(treeroot->left == NULL && treeroot->left != NULL && treeroot->left->data >= treeroot->data){
//         return false;
//     }
//     else{
//         return check_BST(treeroot->left) && check_BST(treeroot->right);
//     }
// }

void treebasics :: inorder_list(treetype* &treeroot, vector<int> &v){
        if(treeroot == NULL){
            return;
        }
        inorder_list(treeroot->left, v);
        v.push_back(treeroot->data);
        inorder_list(treeroot->right, v);
}

//To check whether the tree is BST or not, we get the inorder print and if the inorder print is ascending then the tree is BST, otherwise not BST
bool treebasics :: check_BST(treetype* &treeroot){
    vector<int> v;
    inorder_list(treeroot, v);
    if(v.size()!=1){
        for(int i=0; i<v.size()-1; i++){
            if(v[i+1] < v[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return true;
    }
}

treebasics :: treebasics(){
    cout<<"Enter 1 to build the tree using BST appraoch\nor\nEnter 2 to build the tree using level order approach"<<endl;
    cin>>choice;
    treetype* treeroot = NULL;
    queue<treetype*> q;
    switch(choice){
        case 1 :
            cout<<"Enter the number of tree nodes you want : ";
            cin>>n;
            cout<<"Enter the "<<n<<" nodes for your tree : ";
            for(int i=0; i<n; i++){
                cin>>ele;
                get_BST_tree(treeroot, ele);
            }
            break;
        case 2 :
            cout<<"Enter the number of tree nodes you want : ";
            cin>>n;
            cout<<"Enter the "<<n<<" nodes for your tree : ";
            for(int i=0; i<n; i++){
                cin>>ele;
                get_level_order_tree(treeroot, q, ele);
            }
            break;
        default :
            cout<<"Invalid choice of the tree";
    }
    cout<<"In-order traversal : ";
    print_inorder(treeroot);
    cout<<"\nPre-order traversal : ";
    print_preorder(treeroot);
    cout<<"\nPost-order traversal : ";
    print_postorder(treeroot);

    cout<<endl;
    if(check_BST(treeroot)){
        cout<<"The tree is a BST"<<endl;
    }
    else{
        cout<<"The tree is NOT a BST"<<endl;
    }
}

int main(){
    treebasics t[1];
    return 0;
}