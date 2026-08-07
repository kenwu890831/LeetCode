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
    bool hasCycle(ListNode *head) {
        ListNode* walk1 = head ;
        ListNode* walk2 = head ;
        map< int, bool > m ;
        while( walk1 != NULL && walk1 -> next != NULL) {
            walk1 = walk1 -> next -> next ;
            walk2 = walk2 -> next ;

            if ( walk1 == walk2 )
                return true ;
        }

        return false ;
    }
};