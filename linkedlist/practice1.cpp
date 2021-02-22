// Form a linked list by adding an element at the end
//Insertion at a given position

#include <iostream>
using namespace std;

struct listype{
    int data;
    listype* next;
};

class lisch{
    private:
    int n, val, pos;
    listype* rootptr;
    listype* ins_node;
    public:
    lisch();
    void insertion(listype* &rootptr, int val);
    listype* createnode(int val);
    void insertion_at_pos(listype* &rootptr, int pos, int val);
    void print_linklist(listype* rootptr);
    void reverse_linkedlist(listype* &rootptr);
};

listype* lisch :: createnode(int val){
    listype* nnode = new listype;
    nnode->data = val;
    nnode->next = NULL;
    return nnode;
}

void lisch :: insertion(listype* &rootptr, int val){
    if(rootptr==NULL){
        rootptr = createnode(val);
        return;
    }
    listype* temp = rootptr;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = createnode(val);
}

void lisch :: insertion_at_pos(listype* &rootptr, int pos, int val){
    if(rootptr==NULL){
        if(pos!=1){
            cout<<"Insertion not possible";
        }
        else{
            rootptr = createnode(val);

        }
        return;
    }
    listype* temp = rootptr;
    int p = 2;
    while(temp != NULL){
        if(pos==1){
            ins_node = createnode(val);
            ins_node->next=rootptr;
            rootptr=ins_node;
            break;
        }
        if(p==pos){
            ins_node = createnode(val);
            ins_node->next = temp->next;
            temp->next = ins_node;
            break;
        }
        p++;
        temp = temp->next;
    }
    if(temp==NULL){
        cout<<"Position which enetered is beyonf this list's limit"<<endl;
    }
}

void lisch :: print_linklist(listype* rootptr){
    if(rootptr==NULL){
        return;
    }
    listype* temp = rootptr;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void lisch :: reverse_linkedlist(listype* &rootptr){
    if(rootptr==NULL){
        return;
    }
    listype* aftr = rootptr->next;
    listype* bef = rootptr;
    listype* nuller = rootptr;
    while(aftr!=NULL){
        rootptr = aftr;
        aftr = aftr->next;
        rootptr->next = bef;
        bef = rootptr;
    }
    nuller->next = NULL;
}


lisch :: lisch(){
    cout<<"\nEnter the number of elements you want to add into the linked list"<<endl;
    cin>>n;
    rootptr = NULL;
    for(int i=0; i<n; i++){
        cin>>val;
        insertion(rootptr, val);
    }
    cout<<"Enter the position at which you wnt to insert the node: "<<endl;
    cin>>pos;
    cout<<"Enter the value of that node: "<<endl;
    cin>>val;
    insertion_at_pos(rootptr, pos, val);
    cout<<"Print the linked list"<<endl;
    print_linklist(rootptr);

    reverse_linkedlist(rootptr);
    cout<<"Print the linked list"<<endl;
    print_linklist(rootptr);
}

int main(){
    lisch s1[10];
    return 0;
}