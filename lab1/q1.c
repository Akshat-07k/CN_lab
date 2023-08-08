#include<stdio.h>
int main(){
	
	unsigned int num = 0x102b3c4d;
	unsigned char *p = (char*)&num;
	
	printf(" first bit : %d and last bit : %d", *p, *(p+3));
	
	return 0;

}
