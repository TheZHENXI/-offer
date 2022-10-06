/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
struct ListNode* EntryNodeOfLoop(struct ListNode* pHead ) 
{
    struct ListNode* slow = pHead;
    struct ListNode* fast = pHead;    
    while(fast && fast->next)
    {

        fast = fast->next->next;
        slow = slow->next;        
        if(slow == fast)
            break;
    }
    if(fast == NULL || fast->next == NULL)
        return NULL;

    slow = pHead;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
    // write code here
}
