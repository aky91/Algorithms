// https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/reversed-linked-list-01b722df/
// Easy, Stack

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    Node(int data) : data(data) , next(NULL) {}
};

int main() {
    
    int N, data;
    Node *front = NULL, *rear = NULL;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> data;
        
        if(front == NULL) {
            rear = (front = new Node(data));
        }
        else {
            rear->next = new Node(data);
            rear = rear->next;
        }
    }
    
    stack<int>st;
    
    Node *ptr1 = front, *ptr2;
    while(ptr1) {
        
        if(ptr1->data % 2 == 0) { // even section
            ptr2 = ptr1;
            while(ptr2 && ptr2->data % 2 == 0) {
                st.push(ptr2->data);
                
                ptr2 = ptr2->next;
            }
            while(!st.empty()) {
                ptr1->data = st.top();
                ptr1 = ptr1->next;
                
                st.pop();
            }
        }
        else { ptr1 = ptr1->next; }
    }
    
    ptr1 = front;
    while(ptr1) {
        printf("%d ", ptr1->data);
        ptr1 = ptr1->next;
    }
    printf("\n");
      
    return 0;
}