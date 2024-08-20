#include <stdio.h>

int main(void) {
	int a,b,x,y,chef;
	scanf("%d %d %d %d",&a,&b,&x,&y);
	if(x>y){
	    chef=a;
	}else{
	    chef=b;
	}
	printf("%d",chef);

}