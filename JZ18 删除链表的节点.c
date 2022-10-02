/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-02 23:44:05
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-02 23:44:28
 * @FilePath: /CCODE/剑指offer/JZ18 删除链表的节点.c
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
 * @param head ListNode类 
 * @param val int整型 
 * @return ListNode类
 */
struct ListNode* deleteNode(struct ListNode* head, int val ) 
{
    struct ListNode* curPre = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        if(cur->val == val)
        {
            //删除
            //1.删除头结点
            if(cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            //2.删除中间的节点
            else{
                curPre->next = cur->next;
                free(cur);
                cur = curPre->next;
            }
            return head;
        }
        else
        {
            //继续迭代
            curPre = cur;
            cur = cur->next;
        }
    }
    return head;
    // write code here
}
