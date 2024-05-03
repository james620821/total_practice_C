#include <stdio.h>
#include <stdlib.h>
int calculate(int (*)(int,int));
int add(int, int);
int multiply(int ,int);
void print(int **v, int height, int width)
{
    int i,j;
    for (i=0; i<height; i++)
    {
        for (j=0; j<width; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}
void print_enter_string()
{
    //影片31-2 缺點:不能輸入超過4個字元的單字
    //char str[100][5];
    //char input[5];
    //缺點:浪費記憶體空間
    //char str[100][50];
    //char input[50];
    //影片31-3 優化
    char raw[5000];
    char *str[100];
    char input[50];
    int size = 0;
    int len=0;
    while(1)
    {
        scanf("%s",input);
        if(strcmp(input,"END")==0) break;
        str[len] = &raw[size]; //也可寫成下一句
        //str[len] = raw + size;
        strcpy(str[len], input);
        size += strlen(input) + 1;
        len++;
    }
    printf("----------\n");
    for (int i=0; i<len; i++)
    {
        printf("%s ",str[i]);
    }
    printf("\n(%d, %d)\n",len, size);
}
int main ()
{
    /*
    //影片30-2 使用指標陣列在函式間傳遞二維陣列(重要)
    int v[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
    int *p[3] = {v[0], v[2], v[1]};
    print(p,3,3); // (int **) = (int *[3])
    //影片30-3 在函式間傳遞任意長寬的二維陣列(重要)
    //影片31 儲存多個字串(重要)
    //影片31-1 可修改內容的多個字串(重要)
    char strA[3][4]={"How", "are", "you"};
    char *strB[3] ={strA[0], strA[1], strA[2]};
    //若想更改字串且超過原本陣列大小，需定義一個新的指標strC
    strB[2][0] ='Y'; (o)
    char strC[5] = "What"; (o)
    strB[0] = strC; (o)
    */
    //print_enter_string();
    //影片32-4 在函式間傳遞函式
    /*
    printf("%d\n",calculate(add));
    printf("%d\n",calculate(multiply));
    */
    //影片34-1 main函式的回傳值
    printf("%d\n", system("input.exe"));
    return 0;
}

int calculate(int (*op)(int, int))
{
    int result=1;
    for (int i=2; i<=5; i++)
    {
        result = op(result,i);
    }
    return result;
}
int add(int a, int b)
{
    return a+b;
}
int multiply(int a,int b)
{
    return a*b;
}
