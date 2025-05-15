
struct Data {
    int from, to;
} Data;

int comp(const void *a, const void *b)
{
    struct Data A = *(struct Data*)a;
    struct Data B = *(struct Data*)b;

    if(A.from > B.from) {
        return 1;
    } else if (A.from == B.from) {
        return B.to - A.to;
    } else {
        return -1;
    }
}

struct Heap {
    struct Data node[262145];
    int size;
} Heap;

struct Heap heap;

void heap_init();
void push(struct Data d);
struct Data pop();
struct Data top();
int is_heapable(struct Data child, struct Data parent);
void swap(struct Data* a, struct Data* b);

int main()
{
    struct Data arr[202020];
    int n, count = 0;
    int i = -1;
    struct Data dummy = {0, 0};
    struct Data next;

    scanf("%d", &n);
    while(++i < n) {
        scanf("%d %d", &arr[i].from, &arr[i].to);
    }
    qsort(arr, n, sizeof(struct Data), comp);
    
    heap_init();
    push(dummy);

    i = -1;

    while(++i < n) {
        next = arr[i];
        if(top().to <= next.from) {
            next.from = pop().from;
        }
        push(next);
    }
    printf("%d\n", heap.size);
    
    return 0;
}



void heap_init()
{
    heap.size = 0;
}


void push(struct Data d)
{
    int prt_idx, chd_idx;
    heap.node[++heap.size] = d;
    prt_idx = heap.size/2;
    chd_idx  = heap.size;

    while(prt_idx >= 1 && is_heapable(heap.node[chd_idx], heap.node[prt_idx]) == 0) {
        swap(&heap.node[prt_idx], &heap.node[chd_idx]);
        chd_idx = prt_idx;
        prt_idx = chd_idx/2;
    }
}
struct Data top()
{
    return heap.node[1];
}


struct Data pop()
{
    struct Data popped = heap.node[1];
    int parent = 1;
    int current = 1;
    int left, right;
    heap.node[1] = heap.node[heap.size--];

    while(1) {
        left = current * 2;
        right = current * 2 + 1;
        current = parent;

        if(left <= heap.size && is_heapable(heap.node[left], heap.node[current]) == 0) {
            current = left;
        }

        if(right <= heap.size && is_heapable(heap.node[right], heap.node[current]) == 0) {
            current = right;
        }

        if(current == parent) {
            break;
        }

        swap(&heap.node[current], &heap.node[parent]);
        parent = current;
    }

    return popped;
}

int is_heapable(struct Data child, struct Data parent)
{
    return parent.to < child.to;
}

void swap(struct Data* a, struct Data* b)
{
    struct Data tmp = *a;
    *a = *b;
    *b = tmp;
}
