#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
FILE *new, *old;
int x;
char c[10000];
if(argc<2){
	printf("You need to enter a suppressions.log file and the name of your final suppression file: example.supp ");
	return 1;
}
old = fopen(argv[1],"r");
x = getc(old);
int i=1;
new = fopen(argv[2],"w");
fprintf(new,"# Suppressions for C / macOS 10.14 Mojave\n############################################\n\n");
while(x != EOF){
	fscanf(old,"%[^\n]", c);
if(c[0] == '='){}
else if(strcmp(c,"   <insert_a_suppression_name_here>")==0){
	sprintf(c,"   <Suppression: %d>",i);
	fprintf(new,"%s\n",c);
	i++;
}else{
fprintf(new,"%s\n",c);
}
strcpy(c,"");
x = getc(old);
}
fclose(new);
fclose(old);
return 0;
}