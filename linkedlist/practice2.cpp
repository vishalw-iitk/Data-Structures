//Form a singly linkedlist and then Reverse it
#include <iostream>
using namespace std;

struct listnode{
    int data;
    listnode* next;
};

class linked_list{
    private:
    int n, ele;
    public:
    linked_list();
    void get_a_list(int ele, listnode* &head, listnode* &tail);
    listnode* createnode(int val);
    void printlist(listnode* head);
    void reverse_list(listnode* &head);
};

listnode* linked_list :: createnode(int val){
    listnode* newnode = new listnode();
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void linked_list :: get_a_list(int ele, listnode* &head, listnode* &tail){
    if(head == NULL){
        head = createnode(ele);
        tail = head;
        return;
    }
    tail->next = createnode(ele);
    tail = tail->next;
}

void linked_list :: printlist(listnode* head){
    if(head == NULL){
        return;
    }
    listnode* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void linked_list :: reverse_list(listnode* &head){
    if(head == NULL){
        return;
    }
    listnode* temp = head;
    listnode* n1 = temp->next;
    temp->next = NULL;
    while(n1 != NULL){
        head = n1;
        n1 = n1->next;
        head->next = temp;
        temp = head;
    }     
}

linked_list :: linked_list(){
    cout<<"Enter the number of elements you want to add in the singly linkedlist:  ";
    cin>>n;
    // listnode* ourlist = NULL;
    listnode* head = NULL;
    listnode* tail = NULL;
    for(int i=0; i<n; i++){
        cin>>ele;
        get_a_list(ele, head, tail);
    }
    cout<<"Linked list :  ";
    printlist(head);
    reverse_list (head);
    cout<<"Reversed linked list :  ";
    printlist(head);
}

int main(){
    linked_list r[1];
    return 0;
}