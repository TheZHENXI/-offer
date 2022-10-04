/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-04 19:33:18
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-04 19:34:05
 * @FilePath: /CCODE/剑指offer/2.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// /**
//  * struct ListNode {
//  *	int val;
//  *	struct ListNode *next;
//  * };
//  */
// /**
//  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//  *
//  * 
//  * @param pHead ListNode类 
//  * @return ListNode类
//  */
//  //时间复杂度：O(n),遍历两边；空间复杂度：O(n)
// struct ListNode* deleteDuplication(struct ListNode* pHead ) 
// {
//     int* hash = (int*)calloc(1000,sizeof(int));
//     struct ListNode* cur = pHead;
//     struct ListNode* curPre = NULL;
//     while(cur)
//     {
//         hash[cur->val]++;
//         cur = cur->next;
//     }
//     cur = pHead;
//     while(cur)
//     {
//         if(hash[cur->val] > 1)
//         {
//             //删除节点：头节点、非头结点
//             if(cur == pHead)
//             {
//                 pHead = cur->next;
//                 free(cur);
//                 cur = pHead;
//             }
//             else
//             {
//                 curPre->next = cur->next;
//                 free(cur);
//                 cur = curPre->next; 
//             }
//         }
//         else
//         {
//             curPre = cur;
//             cur = cur->next;
//         }
//     }
//     return pHead;
//     // write code here
// }
//思路2：新建哑结点
struct ListNode* deleteDuplication(struct ListNode* pHead ) 
{
    struct ListNode* cpHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    cpHead->next = pHead;
    struct ListNode* cur = cpHead;
    while(cur->next && cur->next->next)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int tmp = cur->next->val;
            while(cur->next != NULL && cur->next->val == tmp)
            {
                cur->next = cur->next->next;
            }
            continue;
        }
        cur = cur->next;
    }
    return cpHead->next;
}
