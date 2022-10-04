/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-04 14:42:30
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-04 14:43:06
 * @FilePath: /CCODE/剑指offer/JZ52 两个链表的第一个公共结点.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
 //思路1：双指针遍历list1+list2、list2+list1，结束条件是两指针相等时
 //时间复杂度：O(n+m),空间复杂度：O(1)
// struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2 ) {
//     
//     struct ListNode* cur1 = pHead1;
//     struct ListNode* cur2 = pHead2;
//     //两个没有公共节点时，会在都为NULL时结束循环
//     while(cur1 != cur2 )
//     {
//         cur1 = cur1 ? cur1->next:pHead2;//(表达式)？表达式1：表达式2 
//         cur2 = cur2 ? cur2->next:pHead1;
//     }
//     return cur1;
//     // write code here
// }
//思路2：先求出长度，先移动长链表指针，是的两指针起始位置相同。
//时间复杂度：O(n+m),空间复杂度：O(1)
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    
    struct ListNode* cur1 = pHead1;
    struct ListNode* cur2 = pHead2;
    int len1 = 0;
    int len2 = 0;
    while(cur1)
    {
        cur1 = cur1->next;
        len1++;
    }
    while(cur2)
    {
        cur2 = cur2->next;
        len2++;
    }
    cur1 = pHead1;
    cur2 = pHead2;
    if(len1 > len2)
    {
        for(int i = 0;i < len1-len2;i++)
        {
            cur1 = cur1->next;
        }
    }
    else if(len1 < len2)
    {
        for(int i = 0;i < len2- len1;i++)
        {
            cur2 = cur2->next;
        }
    }
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
    // write code here
}





