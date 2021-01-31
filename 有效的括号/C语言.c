/*下面是本人解法，用了栈这个数据结构，如果遇到(,[,{就放到栈中，如果遇到),],}就与栈顶元素进行匹配，如果不匹配就一定是错误的*/
/*代码的执行速度是0ms,内存消耗5.4MB*/
typedef struct Stack
{
    char data[5000];
    int top;
}Stack;

void InitStack(Stack* S)
{
    S->top=-1;
}

bool isValid(char * s)
{
    int length=strlen(s);
    if( length%2 != 0 )
        return false;
    Stack stack;
    InitStack(&stack);
    if(s[0]==']'||s[0]==')'||s[0]=='}')
        return false;
    for(int i=0;i<length;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            stack.top++;
            stack.data[stack.top]=s[i];
            continue;
        }
        if(s[i]==']'&&stack.data[stack.top]=='[')
        {
            stack.top--;
        }
        else if(s[i]==')'&&stack.data[stack.top]=='(')
        {
            stack.top--;
        }
        else if(s[i]=='}'&&stack.data[stack.top]=='{')
        {
            stack.top--;
        }
        else 
            return false;
        if(stack.top==-1&&(s[i+1]==']'||s[i+1]==')'||s[i+1]=='}'))
            return false;
        if(stack.top==-1&&i==length-1)
        {
            return true;
        }

    }

    return false;
}

/*这个是官方解法，用到了哈希表*/
