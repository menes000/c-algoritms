#include <stdio.h>
#define IN 0
#define OUT 1

void main () {
	int kelime,a, b, harf;
	kelime=0;
	for(a=getchar();(a=='\n'||a==' '||a=='\t');a=getchar())1;
	while((a=getchar()) != EOF){
		if (a=='\n'||a==' '||a=='\t'){
			if((b=getchar())==EOF)break;
			else if(b=='\n'||b=='\t'||b==' ')continue;
			else ++kelime, ++harf;		
		}
		else harf++;
	}	

	printf("%d",kelime);

}
