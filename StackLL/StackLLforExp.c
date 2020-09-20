#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    //char data;
    int data;
    struct Node *next;
}*top = NULL;
//void Push(char x)
void Push(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack Overflow!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    } 
}
//char Pop()
int Pop()
{
    //char x;
    int x = -1;
    struct Node *t;
    if(top == NULL)
        printf("Stack is empty!\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
int IsBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            Push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top == NULL)
                return 0;
            Pop();
        }
    }
    if(top == NULL)
        return 1;
    else
        return 0;
}
int IsBalancedExtended(char *exp)
{
    char x;
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            Push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == NULL) return 0;
            else
            {
                x = Pop();
                if((exp[i] == ')' && x != '(') || (exp[i] == ']' && x != '[') || (exp[i] == '}' && x != '{'))
                    return 0;
            }            
        }        
    }
    if(top == NULL) return 1; 
    else return 0;
}
int Pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
} 
int IsOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
    
}
char * InfixToPostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while(infix[i] != '\0')
    {
        if(IsOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(Pre(infix[i]) > Pre(top->data))
            {
                Push(infix[i++]);
            }
            else
            {
                postfix[j++] = Pop();  
            }         
        }
    }
    while(top != NULL)
        postfix[j++] = Pop();
    postfix[j] = '\0';
    return postfix;
}
int Eval(char *postfix)
{
    int i;
    int x1,x2,r;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(IsOperand(postfix[i]))
            Push(postfix[i] - '0');
        else
        {
            x2 = Pop();
            x1 = Pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '/': r = x1 / x2; break;
                case '*': r = x1 * x2; break;
            }
            Push(r);
        }  
    }
    return top->data;
}
int main()
{
    //char *exp = "{([{a+b]*[c-d])/e}"; 
    //printf("%d ", IsBalancedExtended(exp));
    // char *infix = "a+b*c-d/e"; 
    // Push('\0');
    // //Display();
    // char *postfix1 = InfixToPostfix(infix);
    // printf("%s ", postfix1);
    char *postfix = "234*+82/-";
    printf("The result is %d", Eval(postfix));
    return 0;
}