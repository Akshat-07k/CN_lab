#include<stdio.h>
int main(){
	
	unsigned int num = 0x102b3c4d;
	unsigned char *p = (char*)&num;
	
	if( *p == 0x4d )
	printf(" L.E.F ");
	else
	printf(" B.E.F ");
	
	
	return 0;

}
