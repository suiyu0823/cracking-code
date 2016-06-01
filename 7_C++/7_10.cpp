// 13.9 Implement a memory-aligned malloc(), which returns a block of memory, and the address of the first byte is a multiple of a power of 2.
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void *aligned_malloc(size_t required_bytes, size_t alignment) {
    void *p1;
    void **p2;
    int offset= alignment-1 + sizeof(void*);
    p1 = malloc(required_bytes + offset);
    p2=(void**)(((size_t)(p1)+offset)& ~(alignment-1));
    p2[-1]=p1; //line 6
    return p2;
}
void aligned_free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
    free(((void **)ptr)[-1]);
}

int main()
{
    void *p1 = aligned_malloc(100, 64);
    void *p2 = malloc(100);
    
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    aligned_free(p1);
    free(p2);
    
    return 0;
}