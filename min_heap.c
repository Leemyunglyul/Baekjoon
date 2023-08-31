#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int key;
}element;

typedef struct {
	element heap[100000];
	int size;
}Heap;

void min_heap_insert(Heap* h, element item)
{
	int i;
	i = ++(h->size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;	
	}
	h->heap[i] = item;
}

element min_heap_delete(Heap* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->size)--];
	parent = 1;
	child = 2;

    while (child <= h->size) {
        /* ���� �ڽ� ���� ������ �ڽ� ��� �� �� ū �ڽ� ���*/
        if ((child < h->size) && ((h->heap[child].key) > h->heap[child + 1].key)) {
            child++;    // ������ �ڽ� ��� ����
        }

        /* ������ ��尡 �ڽ� ��庸�� ũ�� ���� */
        if (temp.key <= h->heap[child].key) {
            break;
        }

        /* �θ���� �ڽĳ�� ��ȯ */
        h->heap[parent] = h->heap[child];

        /* �� ���� �Ʒ��� �̵� */
        parent = child;
        child *= 2;
    }

    /* ������ ��带 �缳���� ��ġ�� ���� */
    h->heap[parent] = temp;

    /* �ִ� ��� ��ȯ */
    return item;
}

int main()
{
    int n, i, x;
    scanf("%d", &n);
    Heap min_heap;
    min_heap.size = 0;
    element item;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (min_heap.size == 0)
                printf("0\n");
            else
                printf("%d\n", min_heap_delete(&min_heap));
        }
        else
        {
            item.key = x;
            min_heap_insert(&min_heap, item);
        }
    }
}