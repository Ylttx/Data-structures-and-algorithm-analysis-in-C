#include "test_stack.h"
#include <stdio.h>
#include <stdlib.h>

void TestStack()
{
    printf("test stack\n");
    Stack S;
    S = CreateStack(10);
    IsSignBalanced(S) ? printf("wrong\n") : printf("right\n");
    DisposeStack(S);
}

/* 3.18.b 平衡符号检测  */
int IsSignBalanced( Stack S )
{
    char ch;
    printf("input characters end with #\n");

    while ((ch = getchar()) != '#')
    {
        if (ch == '(' || ch == '[' || ch == '{') // 开放符号
            Push(ch, S);
        else if (ch == ')' || ch == ']' || ch == '}') // 封闭符号
        {
            if (IsEmptyStack(S))
                FatalError("stack is empty");
            else
            {
                switch (ch)
                {
                case ')':
                    if (Top(S) != '(')
                        FatalError("not match");                   
                    break;
                case ']':
                    if (Top(S) != '[')
                        FatalError("not match");                   
                    break;
                case '}':
                    if (Top(S) != '{')
                        FatalError("not match");                   
                    break;
                }
                Pop(S);
            }
        }
    }

    if (!IsEmptyStack(S))
        FatalError("the stack is not empty last");
    else
        return 0;  // 成功
}
