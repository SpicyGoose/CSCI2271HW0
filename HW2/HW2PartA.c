#include <stdio.h>
#include <stdlib.h>
char *getCharBlock(int *size){
  int index=0;
  char *p;
  char item;
  /////////////////////////////////////////// this part is adjusted and uses realloc to assign momery space
  p=(char*) malloc(sizeof(char));
    printf("Enter a line here!\n");
      item=getchar();
    //start here
  while (item!='\n'){
      *(p+index)=item;
      index++;
      p=(char*)realloc(p,sizeof(char)*(index+1));
      item=getchar();}

    *(p+index)='\0';
    *size=index;
      return p;

  }

  //this while function need to be adjusted

//////////////////////////////////////////////////////////////////

int findMatch(char *text,int sizeText, char *pattern, int sizePattern){
  //text， text size, pattern, pattern size
    int i1;
    int i2=0;
    int count=0;
    int result;
    for(i1=0;i1<sizeText;i1++){
        if(*(text+i1)==*(pattern+i2)){
          i2++;
          if(i2==sizePattern){
            count++;
            i1=i1-i2+1;
            i2=0;
          }
        }
        else if (*(text+i1)!=*(pattern+i2)){
          i2=0;
          if(*(text+i1)==*(pattern+i2)){
            i2++;
          }
        }
    }
      printf("There are %d patterns\n", count);

    return result;
}
///////////////////////////////////////////////////////////////
void printIt(char *ptr, int size){//why do we need index here?
  int i;
  for(i=0;i<size;i++){
    printf("%c",*(ptr+i));
  }
  printf("\n" );
}

//////////////////////////////////////////////////////////////////
int main(){
char *text, *pattern; //pointers for the characters you will read
char *p,*q,*r; //some pointer variables
int size,size1,x,y; //some integers
printf("give me your TEXT strings\n" );
text= getCharBlock(&size);
printf("the TEXT char is\n");
printIt( text,size);
printf("give me your PATTERN strings\n" );
pattern=getCharBlock(&size1);
printf("the PATTERN char is\n");
printIt(pattern,size1);
printf("So, let's see if we can find the pattern: \t" );
findMatch(text,size,pattern,size1);

//int findMatch(char *text,int sizeText, char *pattern, int sizePattern)
free(text);
free(pattern);
}
