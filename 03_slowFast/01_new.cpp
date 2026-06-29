#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


int main(){
    Node* head = new Node(1);
    Node* t = head;

    for(int i = 2; i < 7; i++){
        t->next = new Node(i);
        t = t->next;
    }
    t = head;

    while(t != NULL){
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}