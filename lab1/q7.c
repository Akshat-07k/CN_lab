#include<stdio.h>

struct pkt{
	unsigned char ch1;
	unsigned char ch2[2];
	unsigned char ch3;
};

int main(){

	int num;
	scanf(" %d",&num);
	unsigned char *temp = (char*)&num;

	struct pkt obj;
	obj.ch1 = *(temp);
	obj.ch2[0]  = *(temp+1); 
	obj.ch2[1]  = *(temp+2); 
	obj.ch3 = *(temp+3);

	printf(" %d %d %d %d \n" , obj.ch3, obj.ch2[1], obj.ch2[0] , obj.ch1);

	return 0;
}
