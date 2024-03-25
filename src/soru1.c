#include <stdio.h>
#include <unistd.h>
#include <stdint.h> // intptr_t türünü kullanmak için

typedef unsigned long int UI;

int main(int argc, char **argv)
{
    int i;
    intptr_t p = 20000; // intptr_t türünü kullan
    intptr_t f = 4294967295; // intptr_t türünü kullan
    intptr_t *v;
    intptr_t *c; //stack
    intptr_t heap;
    intptr_t global;
    intptr_t stack;
    intptr_t brk_start, brk_end;

    // Mevcut brk değerini al
    brk_start = (intptr_t)sbrk(0);

    // p kadar bellek tahsis et
    brk(p);

    // Yeni brk değerini al
    brk_end = (intptr_t)sbrk(0);

    // v ve c'nin adreslerini al
    v = (intptr_t *)brk_end;
    c = &i;

    // p değerini global değişken boyutu olarak kullan
    global = p;

    // f kadar stack boyutunu hesapla
    stack = (intptr_t)c - f;

    // brk_start ve brk_end arasındaki farkı heap boyutu olarak kullan
    heap = brk_end - brk_start;

    printf("\n");

    printf("Global Variable Başlangıç = ");
    printf(" 0x%lx", (UI)&i);
    printf("   Global Variable Boyutu  = ");
    printf(" %ld Byte", global);
    printf("\n");

    printf("Heap Başlangıç            = ");
    printf(" 0x%lx ", (UI)v);
    printf("  Heap Boyut              =   ");
    printf(" %ld Byte", heap);
    printf("\n");

    printf("Stack Başlangıç           = ");
    printf(" 0x%lx", (UI)c);
    printf("   Stack Boyutu            =  ");
    printf(" %ld Byte", stack);
    printf("\n");

    return 0;
}
