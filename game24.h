#ifndef __GAME_24_H__
#define __GAME_24_H__

#include <stdbool.h>

#define SIZE 4

/*
 * 最终表达式由四个数、括号、运算符组成，其大小不会超过
 *    5 * ( SIZE - 1 ) + SIZE * 2 + 1
 */
typedef struct {
  double value;
  char expression[ 5 * ( SIZE - 1 ) + SIZE * 2 + 1 ];
} Card;

/*
 * 牌堆中计算24点
 *
 *   card  牌堆
 *   size  个数
 */
bool game24( Card *card, int size );

#endif
