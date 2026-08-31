

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d = new ListNode(0);
        ListNode* cur = d;
        int c = 0;

        while(l1 || l2 || c) {
            int x = 0;

            if(l1) {
                x += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                x += l2->val;
                l2 = l2->next;
            }

            x += c;
            c = x / 10;

            cur->next = new ListNode(x % 10);
            cur = cur->next;
        }

        return d->next;
    }
};
            