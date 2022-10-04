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
// struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) 
// {
//     struct ListNode* cur1 = pHead1;
//     struct ListNode* cur2 = pHead2;
//     struct ListNode* pHead = NULL;
//     if(pHead1 == NULL)
//     {
//         return pHead2;
//     }
//     else if (pHead2 == NULL)
//     {
//         return pHead1;
//     }
//     //找到新链表的pHead
//     if(pHead1->val > pHead2->val)
//     {
//         pHead =pHead2;
//         cur2 = cur2->next;
//     }
//     else
//     {
//         pHead = pHead1;
//         cur1 = cur1->next;
//     }
//     struct ListNode* cp = pHead;
//     //谁小，谁加入新链表
//     while(cur1 && cur2)
//     {
//         if(cur1->val < cur2->val)
//         {
//             cp->next = cur1;
//             cur1 = cur1->next; 
//         }
//         else
//         {
//             cp->next = cur2;
//             cur2 = cur2->next;
//         }
//         cp = cp->next;

//     }
//     //把剩下的串进来
//     if(cur1)
//     {
//         cp->next = cur1;
//     }
//     if(cur2)
//     {
//         cp->next = cur2;
//     }
//     return pHead;
//     // write code here
// }

struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) 
{
    //新建一个哑结点，返回它的next
    struct ListNode* pHead =(struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode* cur = pHead;
    
    if(pHead1 == NULL)
    {
        return pHead2;
    }
    if (pHead2 == NULL)
    {
        return pHead1;
    }
    //谁小，谁加入新链表
    while(pHead1 && pHead2)
    {
        if(pHead1->val < pHead2->val)
        {
            cur->next = pHead1;
            pHead1 = pHead1->next; 
        }
        else
        {
            cur->next = pHead2;
            pHead2 = pHead2->next;
        }
        cur = cur->next;
    }
    //把剩下的串进来
    if(pHead1)
    {
        cur->next = pHead1;
    }
    if(pHead2)
    {
        cur->next = pHead2;
    }
    return pHead->next;
    // write code here
}
