#include<stdio.h>
int main(){
	
	printf(" Enter unsigned int : ");
	unsigned int num;
	scanf(" %u", &num);
	unsigned char *p = (char*)&num;
	printf(" In hexa :  %x \n" ,num); 
	int attempt = 0;	
	while(1){
	
		
		if( *p != *(p+3)){
			attempt++;
			printf(" Enter unsigned int ");
			scanf(" %u", &num);
			printf(" In hexa :  %x \n" ,num );
		}
		else{
			break;
		}
	}
	
	printf(" Number of attempts : %d " , attempt);
	
	return 0;

}
