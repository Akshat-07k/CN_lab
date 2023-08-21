#include<stdio.h>
int main(){
	
	unsigned int num = 0x102b3c4d;
	unsigned char *p = (char*)&num;
	
	for(int i=0;i<4;i++){
		printf(" %d | %p is value at %x \n" , i, p+i, *(p+i));
	
	}
	
	return 0;

}
