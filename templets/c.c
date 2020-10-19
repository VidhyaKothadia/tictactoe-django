#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};

    FILE *fp,*np;
char operators[25] = {'+','-','*','/','%','|','~','^','!'};
char special_symbol[21]={'(',')','{','}',';',':',',','.','$','&','@','?'};
//char operators[25] ={'*','/','-','+'};
void operator_identofier(char ch,char next){
    int temp=0,i;
    if((ch=='+' && next == '=') ||(ch=='-' && next == '=') ||(ch=='*' && next == '=') ||(ch=='/' && next == '=') ||(ch=='+' && next == '+') ||(ch=='-' && next == '-')
       ||(ch=='|' && next == '|') ||(ch=='&' && next == '&') ||(ch=='<' && next == '<') ||(ch=='>' && next == '>') ){
        printf("%c%c --operator\n",ch,next);
        next=fgetc(np);
  //      return ch;
//


    }
    for(i = 0; i < 21; ++i){
            if(ch == operators[i]){
                printf("%c is operators symbol\n", ch);
               // return ch;
                break;
            }

        }



}
int main(){
    char ch, compare[50],op[3],next;

int singleCmt=0;
    int multiCmt=0;
    int i,j=0,flag,o=0;
    fp = fopen("kk.c","r");
    np = fopen("kk.c","r");

    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }



    next=fgetc(np);
    while((ch = fgetc(fp)) != EOF){
       // printf("%c",ch);
        next=fgetc(np);

        if(ch=='/' && next=='/'){
            singleCmt=1;
        }else if(singleCmt==1 && (ch=='\n')){
            singleCmt=0;
            ch=fgetc(fp);
            continue;
        }else if(ch=='/' && next=='*'){
            multiCmt=1;
        }else if(multiCmt==1 && (ch=='*' && next=='/')){
            multiCmt=0;
            ch=fgetc(fp);
            continue;
        }


        if(multiCmt==0 && singleCmt==0){
            operator_identofier(ch,next);
            if(isalnum(ch)){
            compare[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){
                compare[j] = '\0';
                j = 0;
                flag=0;

                for(i=0;i<32;++i){
                    if(strcmp(keywords[i], compare) == 0){
                        flag=1;

                        break;
                    }
                }
                if(flag == 1)
                    printf("%s is keyword\n", compare);
                else if(isalpha(compare[0]) || compare[0]=='_'){
                                printf("%s is indentifier\n", compare);
                }else if(flag ==3)
                    printf("%s is special\n", compare);

            }
        }

        }




    fclose(fp);

    return 0;
}
