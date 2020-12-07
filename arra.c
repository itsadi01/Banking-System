#include <stdio.h>
#include <stdlib.h>

struct array
{
    int arr[100];
    int size;
};

int parent(int i) { return i/2; }
int left(int i) { return (2*i + 0); }
int right(int i) { return (2*i + 1); }

int swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Heapify(struct array *heap, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int smallest = i;
    if (l < heap->size && heap->arr[l] < heap->arr[smallest])
		smallest = l;
	if (r < heap->size && heap->arr[r] < heap->arr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&heap->arr[i], &heap->arr[smallest]);
		Heapify(heap, smallest);
	}
}
void BuildMinHeap(struct array *heap)
{
    for (int i = heap->size / 2; i > 0; i--)
    {
        Heapify(heap, i);
    }
}
void HeapSort(struct array heap)
{
    BuildMinHeap(&heap);
    for (int i = heap.size; i > 1; i--)
    {
        swap(&heap.arr[1],&heap.arr[i]);
        heap.size--;
        Heapify(&heap, 1);
    }
}

void Min_Heap_Insert(struct array heap,int input)
{
    heap.size++;
    heap.arr[heap.size-1] = input;
    printf("arr[%d]=%d\n",heap.size,heap.arr[heap.size]);
    HeapSort(heap);
}
void Heap_Extract_Min(struct array heap)
{
    if(heap.size!=0){
    printf("%d\n",heap.arr[0]);
    heap.arr[0]=heap.arr[heap.size-1];
    heap.size--;
    HeapSort(heap);
    }
    else
    {
        printf("-1\n");
    }
}
void Heap_Decrease_Key(struct array heap,int i,int k)
{
    heap.arr[i] = k;
	while (i != 0 && heap.arr[parent(i)] > heap.arr[i])
	{
	swap(&heap.arr[i], &heap.arr[parent(i)]);
	i = parent(i);
	}
}
void Heap_Get_Min(struct array heap)
{
    if(heap.size!=0){
        printf("%d\n",heap.arr[0]);
    }
    if(heap.size==0)
    {
        printf("-1\n");
    }
}

int main()
{
    struct array heap;
    heap.size=0;
    char opt;
    int flg=1;
    int input,position,newvalue;
    while(flg)
    {
        scanf("%c",&opt);
        switch(opt)
        {
            case 'i':
                scanf("%d",&input);
                Min_Heap_Insert(heap,input);
                break;
            case 'e':
                Heap_Extract_Min(heap);
                break;
            case 'm':
                Heap_Get_Min(heap);
                break;
            case 'd':
                scanf("%d",&position);
                scanf("%d",&newvalue);
                Heap_Decrease_Key(heap,position, newvalue);
                break;
            case 's':
                flg=0;
                break;
        }
    }
}
