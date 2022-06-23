#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL){}
};

ListNode* reverseList(ListNode *head){
    ListNode *new_head = NULL;
    while (head)
    {
        ListNode *next = head->next;    //保存当前链结点的后继
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}


int main(){
    // 创建单链表
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    cout << "单链表逆序前:";
    ListNode *head = a;
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    cout << "单链表逆序后:";
    ListNode *new_head = reverseList(a);
    while(new_head){
        cout << new_head->data << " ";
        new_head = new_head->next;
    }
    cout << endl;

    return 0;
}
