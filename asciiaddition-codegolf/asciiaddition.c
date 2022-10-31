#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ascii;

char* decode(char* str) {
		int len = strlen(str);
		char* decoded = (char*)malloc(len+1);
		char* ptr = decoded;
		while (*str) {
			if (*str == 35) { // # control code
				*ptr++ = *++str - 38;
			} else if (*str == 36) { // $ control code
				*ptr++ = *++str + (89 + 89);
			} else if (*str == 37) { // % control code
				*ptr++ = *++str + 89;
			} else {
				*ptr++ = *str;
			}
			++str;
		}
		*ptr = 0;
		return decoded;
}

int read(int i) {
	return ascii[i/8] >> (i%8) & 1;
}

print(char*s){int e=strlen(s);for(int y=0;y<7;y++){for(int x=0;x<e;x++){int i=s[x]-'0';for(int c=0;c<6-(x>e-2);c++)putchar((read((i*7+y)*5+c)&&c<5)?'x':46);}puts("");}}

int main() {
	ascii = decode("?%m#>$1%.#6B#.$/%.$>%.$>?%+#E%i#Ec$J#6%i#E%i%.$>$M#6~%3$MC#.#G%+?%m#E$1$M1~#.?#F$2#9#(");

	//char q=3;
	//q&=1;
	//printf("%d",q);
	//exit(0);

	int x,y=0,c,num;
	char* elimination = malloc(999);
	for (int i = 0; i < 999; i++) {
		elimination[i] = 3;
	}
	for(;y<7;y++){
	x=0;
	char* input = (char*)malloc(999);
	gets(input);


	int len = (strlen(input)-7)/35;
	for(c=0;;c++) {
		if (c==5) {
			c=0;
			x++;
			input++;
		}
		for(num=0;num<11;num++){
			elimination[x*11+num] &= (*input=='x') == read((num*7*5)+(y*5)+c);
		}
		input++;
		if(!*input) break;
	}
	}
	for (char*c="0123456789+" ; *c ; c++) {
		printf("%c ",*c);
	}
	puts("");
	for (int i = 0; i < 999; i++) {
		printf("%d ", elimination[i]);
		if (i%11==10) puts("");
	}
	char* output = (char*)malloc(99);
	puts("");
	
	int i=0,j=0;
	while(1){
		int x=elimination[j*11+i];
		if (x) {
			if (x==3){output[j-1]=0;break;}
			output[j] = i+'0';
			//printf("%i ",i);
			i=0;
			j++;
		} else {
			i++;
		}
		if (i==11) {
			break;
		}
	}

	sscanf(output,"%d:%d",&i,&j);
	printf("%s\n%i+%i=%i\n",output,i,j,i+j);
	sprintf(output,"%i",i+j);

	print(output);
}
