/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next=head;

    struct ListNode *trav, *prev;
    trav=head;
    prev=&dummy;
    while(trav!=NULL){
        if (trav->val==val){
            prev->next=trav->next;
        }
        else{
            prev=trav;
        }
        trav=trav->next;
    }
    
    return dummy.next;
}