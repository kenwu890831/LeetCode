/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* walkA = headA ;
        ListNode* walkB = headB ;
        while( walkA != NULL ) {
            while( walkB != NULL ) {
                if ( walkA == walkB )
                    return walkA  ;
                walkB = walkB -> next ;
            }

            walkB = headB ;
            walkA = walkA -> next ;
        }

        return NULL ;
    }
};