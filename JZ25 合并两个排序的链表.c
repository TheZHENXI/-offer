/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead1 ListNode类 
 * @param pHead2 ListNode类 
 * @return ListNode类
 */
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) 
{
    struct ListNode* cur1 = pHead1;
    struct ListNode* cur2 = pHead2;
    struct ListNode* pHead = NULL;
    if(pHead1 == NULL)
    {
        return pHead2;
    }
    else if (pHead2 == NULL)
    {
        return pHead1;
    }

    if(pHead1->val > pHead2->val)
    {
        pHead =pHead2;
        cur2 = cur2->next;
    }
    else
    {
        pHead = pHead1;
        cur1 = cur1->next;
    }
    struct ListNode* cp = pHead;
    while(cur1 && cur2)
    {
        if(cur1->val < cur2->val)
        {
            cp->next = cur1;
            cur1 = cur1->next; 
        }
        else
        {
            cp->next = cur2;
            cur2 = cur2->next;
        }
        cp = cp->next;

    }
    if(cur1)
    {
        cp->next = cur1;
    }
    if(cur2)
    {
        cp->next = cur2;
    }
    return pHead;
    // write code here
}
