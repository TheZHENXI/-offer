/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-03 21:55:12
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-03 21:56:39
 * @FilePath: /CCODE/剑指offer/JZ24 反转链表.c
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
 * @param pHead ListNode类 
 * @return ListNode类
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

思路一：三指针
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = n2->next;
    while(n2)
    {
        //翻转
        n2->next = n1;
        //迭代往后走
        n1 = n2;
        n2 = n3;
        if(n3)
            n3= n3->next; 
    }
    return n1;

}
思路二：头插法
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    
    while(cur)
    {
        struct ListNode* after = cur->next;
        //头插
        cur->next = newhead;
        newhead = cur;
        //迭代
        cur = after;
    }
    return newhead;
}
//思路三: 和二一样
struct ListNode* ReverseList(struct ListNode* pHead ) 
{
    if(pHead == NULL)
    {
        return NULL;
    }
    struct ListNode* tmp = NULL;
    struct ListNode* cur = pHead;
    struct ListNode* curPre = NULL;
    while(cur != NULL)
    {
        tmp = cur->next;
        cur->next = curPre;
        curPre = cur;
        cur = tmp;
    }
    return curPre;
    // write code here
}
