#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *a;
    int F, R, size;
} Queue;

void init(Queue *q, int size)
{
    q->a = (int*)malloc(size * sizeof(int));
    q->F = q->R = -1;
    q->size = size;
}

int underflow(Queue *q)
{
    if (q->F == -1)
        return 1;
    return 0;
}

int overflow(Queue *q)
{
    if (q->R == q->size - 1)
        return 1;
    return 0;
}

void display(Queue *q)
{
    if (underflow(q))
    {
        printf("Empty\n");
        return;
    }
    for (int i = q->F; i <= q->R; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

void display1(Queue *q)
{
    if (underflow(q))
    {
        printf("Underflow\n");
        return;
    }
    for (int i = q->F; i <= q->R; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

void insert(Queue *q, int x)
{
    if (overflow(q))
    {
        printf("Overflow\n");
        return;
    }
    if (underflow(q))
    {
        q->F = q->R = 0;
        q->a[q->R] = x;
                
        return;
    }
    q->R++;
    q->a[q->R] = x;
}

int delete(Queue *q)
{
    if (underflow(q))
    {
        printf("underflow\n");
        return 0;

    }
    int x = q->a[q->F];
    if (q->F == q->R)
    {
        q->F = q->R = -1;
        return x;
    }
    q->F++;
    return x;
}

int main() {
    int size;
    scanf("%d", &size);
    Queue q;
    init(&q, size);
    int M,ch,ele;
    scanf("%d",&M);
    while(M--){
        scanf("%d",&ch);
        if (ch == 1){
            scanf("%d",&ele);
            
            if (overflow(&q) == 0){
                insert(&q,ele);
                display(&q);
            }
            else{
                insert(&q,ele);
            }
                    
        }
        else if (ch==2){
            if (underflow(&q) == 1){
                delete(&q);
            }
            else{
                delete(&q);
                display1(&q);
            }
            
        }
        else if (ch==3){
            display(&q);
        }
        
    }
    return 0;
}