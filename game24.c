#include <stdio.h>
#include <math.h>

#include "game24.h"

#define PRECISION 1E-6
#define TARGET 24

bool game24( Card *card, int size )
{
  Card stack[ size - 1 ];

  /*
   * 如果牌堆里只有一张牌，判断是否就是需要的目标
   */
  if( size == 1 ) {
    if( fabs( card[0].value - TARGET ) < PRECISION ) {
      printf( "%d found\n", TARGET );
      return true;
    } else {
      return false;
    }
  }

  /*
   *从牌堆中任选两张牌
   */
  int m, n, i, t;
  for( m = 0; m < size - 1; m++ ) {
    for( n = m + 1; n < size; n++ ) {
      /*
       * 剩余的牌放入新牌堆
       */
      t = 0;
      for( i = 0; i < size; i++ ) {
	if( i != m && i != n ) {
	  stack[t].value = card[i].value;
	  t++;
	}
      }
      /*
       * 选中两张牌的和放入新牌堆
       */
      stack[size - 2].value = card[m].value + card[n].value;
      if( game24( stack, size - 1 ) ) {
	return true;
      }
      /*
       * 选中两张牌的差放入新牌堆
       */
      if( card[m].value > card[n].value ) {
	stack[size - 2].value = card[m].value - card[n].value;
      } else {
	stack[size - 2].value = card[n].value - card[m].value;
      }
      if( game24( stack, size - 1 ) ) {
	return true;
      }
      /*
       * 选中两张牌的积放入新牌堆
       */
      stack[size - 2].value = card[m].value * card[n].value;
      if( game24( stack, size - 1 ) ) {
	return true;
      }
      /*
       * 选中两张牌的商放入新牌堆
       */
      if( card[m].value != 0 ) {
	stack[size - 2].value = card[n].value / card[m].value;
	if( game24( stack, size - 1 ) ) {
	  return true;
	}
      }
      if( card[n].value != 0 ) {
	stack[size - 2].value = card[m].value / card[n].value;
	if( game24( stack, size - 1 ) ) {
	  return true;
	}
      }
    }
  }

  return false;
}
