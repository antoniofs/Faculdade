#include <stdio.h>
#include <strings.h>


int isPermuta(char*,char*);
int sort(char*);

int main(){

    char s1[] = "ROMA";
    char s2[] = "AMOR";

    if(isPermuta(s1,s2)){
        printf("As strings sao permuta");
    }else{
        printf("As strings nao sao permuta");
    }

}

int isPermuta(char s1[],char s2[]){

    int lenS1 = strlen(s1);
    int lenS2 = strlen(s2);

    int i=0;

    if(lenS1 != lenS2){
        return 0;
    }

    //ordena
    sort(s1);
    sort(s2);

    while(s1[i] == s2[i] && i < lenS1){
        i++;
    }

    if(i == lenS1){
        return 1;
    }

    return 0;

}



int sort(char s[]){
    int i,j,aux;
    int len = strlen(s);
    for(i=0 ; i < len ; i++){
        for(j = i+1 ; j < len ; j++){
            if(s[i] > s[j]){
                aux = s[i];
                s[i] = s[j];
                s[j] = aux;
            }
        }
    }


}
