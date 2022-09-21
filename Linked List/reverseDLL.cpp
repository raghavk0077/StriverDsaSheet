#include "iostream"
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &end, int d){

    //handling the case if there is no element in Linked List
    if(head == NULL){
        Node* new_node = new Node(d);
        head = new_node;
        end = new_node;
    }
    else{
        Node* new_node = new Node(d);
        end -> next = new_node;
        new_node -> prev = end;
        end = new_node;
    }
}

Node* reverse(Node* head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        curr -> prev = next;

        prev = curr;
        curr = next;
    }

    return prev;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){

    Node* head = NULL;
    Node* end = NULL;
    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 3);
    insertAtEnd(head, end, 4);
    insertAtEnd(head, end, 5);
    insertAtEnd(head, end, 6);

    display(head);

    Node* res = reverse(head);

    display(res);
    
    return 0;
}