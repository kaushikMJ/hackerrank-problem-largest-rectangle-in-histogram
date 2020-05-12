#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;int top;int *S;
};
void create(struct stack *st,int k)
{
    st->size=k;
 st->top=-1;
 st->S=(int *)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->S[st->top]=x;
 }

}
int pop(struct stack *st)
{
 int x=-1;

 if(st->top==-1)
 printf("Stack Underflow\n");
 else
 {
 x=st->S[st->top--];
 }
 return x;
}
int isEmpty(struct stack st)
{
 if(st.top==-1)
 return 1;
 return 0;
}
int stackTop(struct stack st)
{
 if(!isEmpty(st))
 return st.S[st.top];
 return -1;
}

int main()
{
    struct stack st;

    //st.top=-1;
    int k,i,c=0,j,y,max=0;
    scanf("%d",&k);
    create(&st,k);
    int a[k],b[k];
    for(i=0;i<k;i++)
        scanf("%d",&a[i]);
    for(i=0;i<k;i++)
    {
        j=a[i];
        if(isEmpty(st)||j>=a[stackTop(st)])
        {
            push(&st,i);
        }
        else{
            //c=0;
            while(a[stackTop(st)]>j)
            {
                y=pop(&st);c++;
                if(max<(a[y]*c))
                    max=a[y]*c;
            }
            push(&st,i);
        }
    }
    if(stackTop(st)>a[i-1])
    c=0;
    while(!isEmpty(st))
    {
        c++;
        y=pop(&st);
        if((c*a[y])>max)
            max=c*a[y];
    }
    printf("%d",max);
}
