#include <stdio.h>
#include <stdbool.h>
bool checkValidString(char *);

int main(){
    char *s="((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((";
    checkValidString(s);
    return 0;
}
bool checkValidString(char* s) {
    int i = 0,a = 0, b=0,len=0;
    while(1){
        if(s[i] == '\0') break;
        switch (s[i]){
            case '(':
                a++; i++; break;
            case '*':
                b++; i++; break;
            case ')':
                c++; i++; break;

        }
    }
    printf("%d\n",len);
    printf("%d\n",a);
    printf("%d\n",i);
    if(i < 1 || i >100){
        printf("false");
    }
    else if(a == 0 && ){
        printf("true");
    }
    else {
        printf("false");
    }

}
