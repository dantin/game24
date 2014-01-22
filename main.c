#include <stdio.h>

#include "game24.h"

int main( void )
{
  int i, poke;
  Card card[SIZE];

  for( i = 0; i < SIZE; i++ ) {
    scanf( "%d", &poke );
    card[i].value = ( double )poke;
    sprintf( card[i].expression, "%d", poke );
  }

  if( game24( card, SIZE ) ) {
    printf( "Done\n");
  } else {
    printf( "No Answer\n" );
  }

  return 0;
}
