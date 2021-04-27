#include <stdio.h>
#include <stdlib.h>

typedef int Index;
struct _Peer
{
    Index index;
    struct _Peer * next;
    struct _Peer * prev;
};
typedef struct _Peer * Ring, * PtrPeer;
typedef struct _Peer Peer;

Ring initRing(int n)
{
    int i;
    PtrPeer new;
    Ring ring;
    ring= NULL;
    for (i=0; i<n; i++)
    {        
        new = (PtrPeer)malloc(sizeof(Peer));
        if (new==NULL)
        {
            printf("allocation error...\n");
            exit(-1);
        }
        new->index = i+1;
        if (ring==NULL)
        {
            ring = new;
            ring->next = ring;
            ring->prev = ring;
        }
        else
        {
            new->next = ring->next;
            ring->next = new;
            new->prev = ring;
            new->next->prev = new;
            ring = new;
        }
    }
    ring = ring->next;
    return ring;
}

void startGame(Ring * R, Index index, int death)
{
    int i, c;
    c = 0;
    PtrPeer ptr, temp;
    for (ptr=*R; ptr->next!=*R; ptr=ptr->next)
    {
        if (ptr->index == index)
            break;
    }
    if (ptr->index != index)
    {
        printf("index error\n");
        return;
    }
    for (i=1; i<=death; i++)
    {
        if (ptr->next == ptr)
        {
            printf("=============\n%d is the winner\n", ptr->index);
            free(ptr);
            *R = NULL;
            break;
        }
        if (i==death)
        {
            temp = ptr->next;
            printf("NO.%03d  ------ %d is killed...\n", ++c, ptr->index);
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            ptr = temp;
            i=0;
        }
        else 
        {
            ptr = ptr->next;
        }
    }
}

int main(void)
{
    Ring initRing(int);
    void startGame(Ring *, Index, int);
    int num;
    Ring ring;
    printf("participated peole's number:");
    scanf("%d", &num);
    ring = initRing(num);
    startGame(&ring, 1, 3);
    return 0;
}