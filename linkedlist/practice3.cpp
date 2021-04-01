// Add the nodes in the linked list at the end and then reverse the whole list
#include<iostream>
using namespace std;

struct lister{
    int data;
    lister* next;
};

class listing{
    private:
    int n;
    int element;
    public:
    listing();
    void createnode(lister* noder);
    void add_after(lister* &noder, lister* &ender, int element);
    lister* createnode(int element);
    void reverse_the_list(lister* &head);
    void print_list(lister* head);
};

lister* listing :: createnode(int element){
    lister* nnode = new lister();
    nnode->data = element;
    nnode->next = NULL;
    return nnode;
}

void listing :: print_list(lister* head){
    lister* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    temp = NULL;
    delete temp;
}

void listing :: add_after(lister* &noder, lister* &ender, int element){
    if(noder == NULL){
        noder = createnode(element);
        ender = noder;
    }
    else{
        ender->next = createnode(element);
        ender = ender->next;
    }
}

void listing :: reverse_the_list(lister* &head){
    if(head == NULL){
        return;
    }
    else{
        lister* temp = head;
        lister* nexter = temp->next;
        temp->next = NULL;
        while(nexter!=NULL){
            head = nexter;
            nexter = nexter->next;
            head->next = temp;
            temp = head;

        }
        // tonull = NULL;


        temp = NULL;
        nexter = NULL;
        delete temp;
        delete nexter;
        // delete tonull;
    }
}

listing :: listing(){
    lister* head = NULL;
    lister* ender = NULL;
    cin>>n;
    // Creation of the linkedlist
    for(int i=0; i<n; i++){
        cin>>element;
        add_after(head, ender, element);
    }

    // print the linkedlist
    cout<<"\nPrinting the linked list"<<endl;
    print_list(head);

    // Reversing the linkedlist
    reverse_the_list(head);

    cout<<"\nPrinting the reverse linked list"<<endl;
    print_list(head);
    
    head = NULL;
    ender = NULL;

    delete head;
    delete ender;

    cout<<endl;

}


int main(){
    listing l[3];

    return 0;
}