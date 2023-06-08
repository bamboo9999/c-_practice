//
// Created by Freedom on 2023/6/8.
//

#include <cstdio>

// 定义node节点
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

// 不是我写的代码呜呜呜
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 创建虚拟头结点
        ListNode *Head = new ListNode(0);
        Head->next = head;
        ListNode *cur = Head;
        while (cur->next != nullptr){
            if (cur->next->val == val){
                ListNode * temp = cur->next;
                cur->next = cur->next->next;
                // 释放内存
                delete temp;
            } else{
                cur = cur->next;
            }
        }
        // 删除虚拟头结点
        head = Head->next;
        delete Head;
        return head;
    }
};

int main(){
    // 创建输入的head
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution *s = new Solution();
    ListNode *newHead = s->removeElements(head, 4);
    while (newHead != nullptr){
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;
}