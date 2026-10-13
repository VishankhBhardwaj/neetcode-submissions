/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node*&head,Node*&tail,int data){
        Node*new_node=new Node(data);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node*cloneHead=NULL;
        Node*cloneTail=NULL;
        Node*temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        unordered_map<Node*,Node*>OldToNew;
        Node*originalNode=head;
        Node*cloneNode=cloneHead;
        while(originalNode!=NULL&&cloneNode!=NULL){
            OldToNew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;
        while(cloneNode!=NULL){
            cloneNode->random=OldToNew[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};
