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
 * @param listNode ListNode类 
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
 /*--------------------------------------------------
 //思路1：
 void reverse(int* num,int len)
 {
     int left = 0;
     int right = len - 1;
     while(left < right)
     {
         int tmp = num[left];
         num[left] = num[right];
         num[right] = tmp;
         left++;
         right--; 
     } 
 }

int* printListFromTailToHead(struct ListNode* listNode, int* returnSize )
{
    //时间复杂度：O(n+n/2) 空间复杂度：O(n)
    struct ListNode* cur = listNode;
    int* num = (int*)malloc(sizeof(int)*10000);
    int len = 0;
    //1.遍历链表，放入数组
    while(cur)
    {
        num[len++] = cur->val ;
        cur = cur->next;
    }
    //2.翻转数组
    reverse(num,len);

    *returnSize = len;
    return num;
}
----------------------------------------------------------*/
//思路2：递归  O(n) O(n)
//返回数组总感觉有问题¡¡
int num[10000];
int i = 0;
int* printListFromTailToHead(struct ListNode* listNode, int* returnSize )
{
    
    if(listNode != NULL)
    {
        printListFromTailToHead(listNode->next, returnSize);
        num[i++] = listNode->val;
        (*returnSize)++;
    }

    return num;
}
/*-----------------------------------------------------*/
//思路3：栈

