#ifndef __GAME_24_H__
#define __GAME_24_H__

#include <stdbool.h>

#define SIZE 4

typedef struct {
  double value;
  char *expression;
} Card;

/*
 * 牌堆中计算24点
 *
 *   card  牌堆
 *   size  个数
 */
bool game24( Card *card, int size );

#endif
