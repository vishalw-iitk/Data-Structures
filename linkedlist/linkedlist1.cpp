//Insertions in a linked list at the first position
//print the linked list
//Insertions in a linked list at the last position
//Deleting the node based on the value
//Insertions in a linked list at the given position
//Deleting the node at a given position
//reverse the linkedlist
//Understanding the dangling pointer

#include <iostream>
using namespace std;

struct linkynode{
    int val;
    linkynode* arrow;
};

class linky{
    private:
    linkynode* hptr;
    int n, ele, pos;
    public:
    linky();
    linkynode* createnode(int ele);
    void insert_in_the_beginning(linkynode* &hptr, int ele);
    void print_the_linked_list(linkynode* hptr);
    void insert_at_the_last(linkynode* &hptr, int ele);
    void search_and_delete(linkynode* &hptr, int ele);
    void insert_at_pos(linkynode* &hptr, int ele, int pos);
    void reverse(linkynode* &hptr);
};

linkynode* linky :: createnode(int ele){
    linkynode* Nnode = new linkynode();
    Nnode->val = ele;
    Nnode->arrow = NULL;
    return Nnode;
}

void linky :: insert_in_the_beginning(linkynode* &hptr, int ele){
    if(hptr == NULL){
        hptr = createnode(ele);
    }
    else{
        linkynode* temp = createnode(ele);
        temp->arrow = hptr;
        hptr = temp;
    }
}

void linky :: print_the_linked_list(linkynode* hptr){
    if(hptr == NULL){
        return;
    }
    else{
        linkynode* temp = hptr;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->arrow;
        }
        cout<<endl;


    }
}

void linky :: insert_at_the_last(linkynode* &hptr, int ele){
    if(hptr == NULL){
        return;
    }
    else{
        linkynode* temp = hptr;
        while(temp->arrow!=NULL){
            temp = temp->arrow;
        }
        temp->arrow = createnode(ele);
    }
}

void linky :: search_and_delete(linkynode* &hptr, int ele){
    if(hptr == NULL){
        cout<<"Null pointer: element not found"<<endl;
        return;
    }
    else{
        linkynode* prev = hptr;
        linkynode* next = hptr->arrow;

        if(hptr->val==ele){
            prev = hptr;
            hptr = hptr->arrow;
            delete prev;
            return;
        }
        
        while(next!= NULL){
            if(next->val == ele){
                prev->arrow = next->arrow;
                delete next;   
                return;             
            }
            prev = prev->arrow;
            next = next->arrow;
        }
        cout<<"Element "<<ele<<" to be deleted not found"<<endl;
        return;
    }
}

void linky :: insert_at_pos(linkynode* &hptr, int ele, int pos){
    if(hptr == NULL){
        return;
    }
    else{
        int trace=2;
        linkynode* posnode = createnode(ele);
        linkynode* temp = hptr;
        if(pos==1){
            posnode->arrow = temp;
            hptr = posnode;
            return;
        }
        else{
            while(temp!=NULL){
                if(trace==pos){
                    posnode->arrow = temp->arrow;
                    temp->arrow = posnode;
                    return;
                }
                trace++;
                temp = temp->arrow;
            }
            cout<<"This position is beyond your last position or is invalid"<<endl;
            return;
        }
    }
}

void linky :: reverse(linkynode* &hptr){
    if(hptr == NULL || hptr->arrow == NULL){
        return;
    }
    else{
        linkynode* curr;
        linkynode* next;
        next = hptr->arrow;
        curr = hptr;
        hptr->arrow = NULL;
        while(next!=NULL){
            curr = next;
            next = next->arrow;
            curr->arrow = hptr;
            hptr = curr;
        }

    }
}

linky :: linky(){
    hptr = NULL;
    cout<<"\n\nEnter the number of elements you want to insert in the beginning"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        insert_in_the_beginning(hptr, ele);
    }

    print_the_linked_list(hptr);

    cout<<"\n\nEnter the number of elements you want to insert at the last position"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        insert_at_the_last(hptr, ele);
    }
    
    print_the_linked_list(hptr);

    cout<<"\n\nEnter how many elements you want to search and delete"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        search_and_delete(hptr, ele);
    }

    print_the_linked_list(hptr);

    cout<<"\n\nEnter how many elements you want to insert at the given positions"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele>>pos;
        insert_at_pos(hptr, ele, pos);
        print_the_linked_list(hptr);
    }

    

    reverse(hptr);
    cout<<"\nReverse linkedlist"<<endl;
    print_the_linked_list(hptr);


}

int main(){
    linky s[1];
    return 0;
}