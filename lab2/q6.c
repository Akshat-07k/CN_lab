#include<stdio.h>
int main(){
	
	unsigned int num ;
	printf(" 3nter the number " );
	scanf(" %u",&num);
	unsigned char *p = (char*)&num;
	
	for(int i=0;i<4;i++){
		printf(" %d | %p is value at %x \n" , i, p+i, *(p+i));
	
	}
	
	printf(" After swaping the valuyes \n");

	
	for(int i=0;i<2;i++){
		unsigned char temp = *p;
		*p= *(p+3-i); 
		*(p+3-i) = temp;
	}
	for(int i=0;i<4;i++){
		printf(" %d | %p is value at %x \n" , i, p+i, *(p+i));
	
	}
	
	return 0;

}
