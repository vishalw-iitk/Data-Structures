//insertion in the begininng
//insertion at the end
//insertion at the given position
//deletion based on the value
//delete at a given position
//reverse

#include <iostream>
using namespace std;

struct dbnode{
    int val;
    dbnode* next;
    dbnode* prev;
};

class dobly{
    private:
    int n, ele;
    dbnode* hptr;
    dbnode* tptr;
    public:
    dobly();
    dbnode* createnode(int ele);
    void insert_at_first(dbnode* &hptr, dbnode* &tptr, int ele);
    void insert_at_end(dbnode* &hptr, dbnode* &tptr, int ele);
    void print_forward(dbnode* tptr);
    void print_backward(dbnode* tptr);
    void delete_element_from_start(dbnode* &hptr, dbnode* &tptr, int ele);
    void delete_element_from_end(dbnode* &hptr, dbnode* &tptr, int ele);
    void delete_by_pos_from_start(dbnode* &hptr, dbnode* &tptr, int pos);
    void delete_by_pos_from_end(dbnode* &hptr, dbnode* &tptr, int pos);
};

dbnode* dobly :: createnode(int ele){
    dbnode* nnode = new dbnode();
    nnode->val = ele;
    nnode->prev = NULL;
    nnode->next = NULL;
    return nnode;
}

void dobly :: insert_at_first(dbnode* &hptr, dbnode* &tptr, int ele){
    if(hptr==NULL){
        dbnode* temp = createnode(ele);
        hptr = temp;
        tptr = temp;
        return;
    }
    dbnode* temp = createnode(ele);
    temp->next = hptr;
    hptr->prev = temp;
    hptr = temp;
}

void dobly :: insert_at_end(dbnode* &hptr, dbnode* &tptr, int ele){
    if(tptr==NULL){
        dbnode* temp = createnode(ele);
        hptr = temp;
        tptr = temp;
        return;
    }
    dbnode* temp = createnode(ele);
    temp->prev = tptr;
    tptr->next = temp;
    tptr = temp;
}

void dobly :: print_forward(dbnode* hptr){
    if(hptr==NULL){
        return;
    }
    dbnode* temp = hptr;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

void dobly :: print_backward(dbnode* tptr){
    if(tptr==NULL){
        return;
    }
    dbnode* temp = tptr;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->prev;
    }
}

void dobly :: delete_element_from_start(dbnode* &hptr, dbnode* &tptr, int ele){
    if(hptr==NULL){
        cout<<"NULL list. Can't delete"<<endl;;
        return;
    }

    dbnode* behind = hptr;
    dbnode* ahead = hptr->next;

    if(hptr->val==ele){
        hptr = ahead;
        delete behind;
        behind = NULL;
        return;
    }

    while(ahead!=NULL){
        if(ahead->val == ele){
            if(tptr->val==ele){
                behind->next = ahead->next;
                tptr = tptr->prev;
            }
            else{
                behind->next = ahead->next;
                ahead->next->prev = behind;
                }
            delete ahead;
            ahead = NULL;
            return;
        }
    }
}

void dobly :: delete_element_from_end(dbnode* &hptr, dbnode* &tptr, int ele){
    if(tptr==NULL){
        cout<<"NULL list. Can't delete"<<endl;;
        return;
    }

    dbnode* behind = tptr;
    dbnode* ahead = tptr->prev;

    if(tptr->val==ele){
        tptr = ahead;
        delete behind;
        behind = NULL;
        return;
    }

    while(ahead!=NULL){
        if(ahead->val == ele){
            if(hptr->val==ele){
                behind->next = ahead->next;
                hptr = hptr->next;
            }
            else{
                behind->prev = ahead->prev;
                ahead->prev->next = behind;
                }
            delete ahead;
            ahead = NULL;
            return;
        }
    }
}

void dobly :: delete_by_pos_from_start(dbnode* &hptr, dbnode* &tptr, int pos){
    if(hptr == NULL){
        cout<<"Can't delete. List is null"<<endl;
        return;
    }
    dbnode* behind = hptr;
    dbnode* ahead = hptr->next;
    if(pos==1){
        hptr = ahead;
        delete behind;
        behind = NULL;
        return;
    }
    int trace = 2;
    while(ahead!=NULL){
        if(pos==trace){
            if(ahead->next==NULL){
                behind->next = ahead->next;
                tptr = tptr->prev;
                delete ahead;
                ahead = NULL;
                return;
            }
            behind->next = ahead->next;
            ahead->next->prev = behind;
            delete ahead;
            ahead = NULL;
            return;
        }
        ahead = ahead->next;
        behind = behind->next;
        trace++;
    }

}

void dobly :: delete_by_pos_from_end(dbnode* &hptr, dbnode* &tptr, int pos){
    if(tptr == NULL){
        cout<<"Can't delete. List is null"<<endl;
        return;
    }
    dbnode* behind = tptr;
    dbnode* ahead = tptr->prev;
    if(pos==1){
        tptr = ahead;
        delete behind;
        behind = NULL;
        return;
    }
    int trace = 2;
    while(ahead!=NULL){
        if(pos==trace){
            if(ahead->prev==NULL){
                behind->prev = ahead->prev;
                hptr = hptr->next;
                delete ahead;
                ahead = NULL;
                return;
            }
            behind->prev = ahead->prev;
            ahead->prev->next = behind;
            delete ahead;
            ahead = NULL;
            return;
        }
        ahead = ahead->prev;
        behind = behind->prev;
        trace++;
    }

}

dobly :: dobly(){
    hptr = tptr = NULL;

    cout<<"\n\nEnter the number of elements you want to insert in the beginnig : "<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>ele;
        insert_at_first(hptr, tptr, ele);
    }

    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

    cout<<"\n\nEnter the number of elements you want to insert in the end : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        insert_at_end(hptr, tptr, ele);
    }

    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

    cout<<"\n\nEnter the number of elements you want to delete from the beginning based on the element value : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        delete_element_from_start(hptr, tptr, ele);
    }

    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

    cout<<"\n\nEnter the number of elements you want to delete from the end based on the element value : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        delete_element_from_end(hptr, tptr, ele);
    }

    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

    cout<<"\n\nEnter the number of elements you want to delete from the beginning based on the position from the start : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        delete_by_pos_from_start(hptr, tptr, ele);
    }

    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

    cout<<"\n\nEnter the number of elements you want to delete from the end based on the position from the end : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;
        delete_by_pos_from_end(hptr, tptr, ele);
    }
    
    cout<<"forward print"<<endl;
    print_forward(hptr);
    cout<<"\nbackward print"<<endl;
    print_backward(tptr);

}

int main(){
    dobly d[10];  
    return 0;
}