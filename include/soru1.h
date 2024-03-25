#ifndef SORU1_H
#define SORU1_H

#include <stdint.h>

// sbrk fonksiyonunun prototipi
void *sbrk(intptr_t increment);

// brk fonksiyonunun prototipi
int brk(void *end_data_segment);

// UI türünün tanımı
typedef unsigned long int UI;

#endif /* SORU1_H */
