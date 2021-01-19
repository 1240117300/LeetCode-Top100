struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
   struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
   struct ListNode* result = node;
   node->val=0;
   node->next=NULL;
   int addMore=0;
   int v1=l1->val;
   int v2=l2->val;
   while(1)
   {
       node->val=node->val+v1+v2;//当node移动到下一个结点时，相当于进位标志与两个数相加
       if(node->val>=10)
       {
           node->val=node->val%10;
           addMore=1;
       }
       else
            addMore=0;
        if(l1!=NULL)
        {
            l1=l1->next;
            if(l1!=NULL)
                v1=l1->val;
            else
                v1=0;
        }
        if(l2!=NULL)
        {
            l2=l2->next;
            if(l2!=NULL)
                v2=l2->val;
            else
                v2=0;
        }
        if(l1==NULL&&l2==NULL&&addMore==0)//这里的addMore==0解决了最后一个数可能大于10的情况。
            break;
        else
        {
            struct ListNode* s=(struct ListNode*)malloc(sizeof(struct ListNode));
            s->val=addMore;//这里存储的是代表是否进位的0和1。
            s->next=NULL;
            node->next=s;
        }
        node=node->next;
   }
   return result;
}
