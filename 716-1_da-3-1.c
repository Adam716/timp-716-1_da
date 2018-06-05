#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
        int value;
        struct node *next;
        struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

int isEmpty()
{
        if (head == NULL && tail == NULL)
                return 1;
        return 0;
}

//вставка элемента после текущего
int append (int index, int value)
{
        if(isEmpty()==1)
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                head = tmp;
                tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
        }
        else
        {
                node *crnt = head;
                node *tmp = malloc (sizeof(node));
                while(index !=1)
                {
                        crnt=crnt->next;
                        index--;
                        //if (*crnt == NULL) return NULL;
                }
                tmp->value = value;
                tmp->prev = crnt;
                if (crnt == tail)
                {
                        tail = tmp;
                        tmp->next = NULL;
                        crnt->next = tmp;
                }
                else
                {
                        tmp->next = crnt->next;
                        crnt->next = tmp;
                        crnt = crnt->next;
                        crnt->next->prev = crnt->prev;
                }
        }

}

int prepend(int index, int value)
{
        if(isEmpty()==1)
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                head = tmp;
                tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
        }
        else
        {
                node *crnt = head;
                node *tmp = malloc (sizeof(node));
                while(index !=1)
                {
                        crnt=crnt->next;
                        index--;
                }
                tmp->value = value;
                if (crnt == head)
                {
                        tmp->prev = NULL;
                        tmp->next = crnt;
                        crnt->prev = tmp;
                        head = tmp;
                }
                else
                {
                        tmp->prev = crnt->prev;
                        tmp->next = crnt;
                        crnt->prev = tmp;
                        crnt = crnt->prev;
                        crnt->prev->next = crnt;
                }
        }

}

int DelByNumber (int index)
{
        node *crnt = head;
        while (index !=1)
        {
                crnt = crnt->next;
                index--;
        }
        if (crnt == head)
        {
                crnt->next->prev = NULL;
                head = crnt->next;
                free(crnt);
                return 1;
        }
        else if (crnt == tail)
        {
                crnt->prev->next = NULL;
                tail = crnt->prev;
                free(crnt);
                return 1;
        }
        else
        {
                crnt->prev->next = crnt->next;
                crnt->next->prev = crnt->prev;
                free(crnt);
                return 1;
        }
}

int DelByValue (int value)
{
        node *crnt = head;
        while (crnt->value != value )
        {
                crnt = crnt->next;
        }
        if (crnt == head)
        {
                crnt->next->prev = NULL;
                head = crnt->next;
                free(crnt);
                return 1;
        }
        else if (crnt == tail)
        {
                crnt->prev->next = NULL;
                tail = crnt->prev;
                free(crnt);
                return 1;
        }
        else
        {
                crnt->prev->next = crnt->next;
                crnt->next->prev = crnt->prev;
                free(crnt);
                return 1;
        }
}

void print()
{
        node *crnt = head;
        while (crnt != NULL)
        {
                printf("%d ", crnt->value);
                crnt = crnt->next;
        }
        printf("\n");
}

void pushback (int value)
{
        if (isEmpty())
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                head = tmp;
                tail = tmp;
                tmp->next = NULL;
                tmp->prev = NULL;
        }
        else
        {
                node *tmp = malloc (sizeof(node));
                tmp->value = value;
                tmp->next = NULL;
                tmp->prev = tail;
                tail->next = tmp;
                tail = tmp;
        }
}

int main ()
{
        int data;
        scanf ("%d", &data);
        for (int i=0; i<data; i++)
        {
                int value;
                scanf("%d", &value);
                //append(i, value);
                pushback(value);
        }

        print();

        scanf("%d", &data);
        DelByNumber(data);

        print();

        scanf("%d", &data);
        DelByValue(data);

        print();

        int a,b;
        scanf("%d", &a);
        scanf("%d", &b);
        append(a, b);

        print();

        scanf("%d", &a);
        scanf("%d", &b);
        prepend(a,b);

        print();
        return 0;
}

