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

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
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
        /* 왼쪽 자식 노드와 오른쪽 자식 노드 중 더 큰 자식 노드*/
        if ((child < h->size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
            child++;    // 오른쪽 자식 노드 선택
        }

        /* 마지막 노드가 자식 노드보다 크면 종료 */
        if (temp.key >= h->heap[child].key) {
            break;
        }

        /* 부모노드와 자식노드 교환 */
        h->heap[parent] = h->heap[child];

        /* 한 레벨 아래로 이동 */
        parent = child;
        child *= 2;
    }

    /* 마지막 노드를 재설정한 위치에 삽입 */
    h->heap[parent] = temp;

    /* 최댓값 노드 반환 */
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