class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);  // Dummy node to simplify merging
        ListNode* temp = ans;  // Pointer to track current position in merged list
        
        ListNode* left = list1;
        ListNode* right = list2;
        
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;  // Move temp to next node
        }
        
        // Attach any remaining nodes
        if (left != nullptr) {
            temp->next = left;
        }
        if (right != nullptr) {
            temp->next = right;
        }
        
        ListNode* result = ans->next;  // Skip the dummy node
        delete ans;  // Free the dummy node to avoid memory leak
        return result;
    }
};
