#include<stdio.h>
#include<math.h>
int main(){
	
	unsigned int num ;
	scanf(" %d",&num);
	unsigned char *p = (char*)&num;
	
	unsigned int arr[4];
	arr[3] = (int)*p;
	arr[2] = (int)*(p+1);
	arr[1] = (int)*(p+2);
	arr[0] = (int)*(p+3);
	
	printf(" %d %d %d %d\n" , arr[0], arr[1], arr[2], arr[3]);
	
	printf(" %.2f ", arr[0]*pow(2,24) + arr[1]*pow(2,16) + arr[2]*pow(2,8) + arr[3]*pow(2,0));
	return 0;

}
