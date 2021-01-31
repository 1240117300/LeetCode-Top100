/*我的思路：
第一步：求出链表长度length，
第二步：寻找待删除结点的前一个结点，并将该前一个的next指向待删除结点的next
第三步：释放这个待删除结点
第四步：加一个判断，如果length=n，则删除掉头结点即可。
*/


 //Definition for singly-linked list.
  struct ListNode
  {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int length=0;
    int  i=1;
    struct ListNode* p;
    struct ListNode* q;
    p=head;
    while(p)
    {
        p=p->next;
        length++;
    }
    if(length == n)
    {
        if(n == 1)
            return NULL;
        else
        {
            p=head;
            head=head->next;
            return head;
        }
    }
    printf("%d\n",length);
    p=head;
    while(i<=length-n-1)
    {
        p=p->next;
        i++;
    }
    printf("%d",i);
    if(p!=NULL&&p->next!=NULL)
    {
        q=p->next;
        p->next = q->next;
        free(q);
    }
    
    return head;
}

/*官方解题思路：快慢指针
第一步：创建一个哑结点(dummy)，该结点的元素为0，next指向头结点。
第二步：创建两个指针fir和sec,让fir指向head，让sec指向dummy。
第三步：先让fir遍历链表n步，再让sec开始遍历链表，当fir遍历到NULL时，sec恰好位于待删除结点的前一个结点。
第四步：更改链表指向，并释放掉哑结点。

注意：官方答案中并没有释放掉待删除结点，理论上应该释放掉

*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;dummy->next=head;
    struct ListNode* second=dummy;
    struct ListNode* first=head;
    while(n)
    {
        first=first->next;
        n--;
    }
    while(first)
    {
        second=second->next;
        first=first->next;
    }
    second->next=second->next->next;
    struct ListNode* ans=dummy->next;//这里一开始以为不需要定义ans，结尾直接返回head即可，但是当链表只有一个结点且n=1，理应返回空指针，若返回head，则会返回该结点，所以要定义此ans
    free(dummy);
    return ans;
}
