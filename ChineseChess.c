#include <stdio.h>
#define HALF_BITS_LENGHT 	4
#define FULLMASK			255
#define LMASK				(FULLMASK<<HALF_BITS_LENGHT)
//LMASK 11110000

#define RMASK				(FULLMASK>>HALF_BITS_LENGHT)
//RMAKS 00001111

#define RSET(b, n)			((LMASK&b|n))
#define LSET(b, n)			((RMASK & b) | ((n) << HALF_BITS_LENGHT))

#define	RGET(b)				(RMASK&b)
#define LGET(b)				((LMASK&b)>>HALF_BITS_LENGHT)
#define GRIDW				3

int main() {
	unsigned char b = 0;
	printf("%d\n", sizeof(b));
	RSET(b, 2);
	printf("%d\n", RSET(b, 2));
	for(LSET(b, 1); LGET(b)<=GRIDW*GRIDW; LSET(b, (LGET(b)+1))) {
		printf("%d\n", b);
		for(RSET(b, 1); RGET(b) <= GRIDW*GRIDW; RSET(b, (RGET(b)+1)))
			// printf("%d\n", b);
			if(LGET(b)%GRIDW != RGET(b)%GRIDW)
				printf("A = %d, B = %d\n", LGET(b), RGET(b));
	}

	return 0;
}