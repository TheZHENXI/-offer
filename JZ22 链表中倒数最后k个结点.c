/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-02 23:42:58
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-02 23:43:33
 * @FilePath: /CCODE/剑指offer/JZ22 链表中倒数最后k个结点.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
 * @param k int整型 
 * @return ListNode类
 */
 //快慢指针：fast = k；slow = 0；然后在一起开始遍历，会一起走过n-k步，正好剩下k个节点
 //时间复杂度O(n),空间复杂度O(1)
struct ListNode* FindKthToTail(struct ListNode* pHead, int k ) 
{
    struct ListNode* fast = pHead;
    struct ListNode* slow = pHead;
    while(k)
    {
        if(fast == NULL)
        {
            return NULL;
        } 
        fast = fast->next;
        k--;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
    // write code here
}
