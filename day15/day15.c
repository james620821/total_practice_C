#include <stdio.h>

void swap(int *, int *);
void sort(int *, int *);
int main()
{
    //影片21-2 指標宣告語法 資料型別 *變數名稱;
    // 取址運算子(&) int *countAddr = &count 將count的位址存入countAddr指向的位址
    //影片21-4 *&可以互消
    /*
    int a=3, b=5;
    printf("a= ");
    scanf("%d",&a);
    printf("b= ");
    scanf("%d",&b);
    //swap(&a, &b);
    sort(&a,&b);
    printf("a: %d\n",a);
    printf("b: %d\n",b);
    */
    //影片23-1 指標對整數的加減運算(重要)
    /*
    int v[5];
    &v[0] +1 == &v[1] //從v[0]位址往前移動一個陣列元素後的位址
    &v[0] + &v[1] //編譯失敗
    &v[2] - &v[1] == 1 //從v[2]位址到v[1]位址距離1個元素
    &v[3] - &v[0] == 3//從v[3]位址到v[0]位址距離3個元素
    */
    //影片23-2 指標與陣列(重要)
    /*
    int v[5];
    int *n;
    n=&v[0];
    n=v; //編譯器會將之隱性轉型成 n = &v[0]
    n == &v[0];   *n     == v[0]; // *n = 0 等價於v[0]=0
    n+1 == &v[1]; *(n+1) == v[1]; // *(n+1) = 0 等價於v[1]=0
    n+2 == &v[2]; *(n+2) == v[2]; // *(n+2) = 0 等價於v[2]=0
    */
    //影片23-3 循序存取陣列元素(重要)
    /*
    int v[5] = {1, 2, 3, 4, 5};
    int *n;
    for (n=v; n != v+5; n++) //雖然沒有定義v[5]，但C語言設定v[5]的起始位址ㄑ是存在的
    {
        printf("%d\n", *n);
    }
    */
    //影片23-4 指標與下標運算子(重要)
    /*
    int v[5];
    int *n =v;
    n[0]=0; v[0]=0; // a[b] == *(a+b)
    n[0] == *n;
    n[1] == *(n+1);
    n[2] == *(n+2);
    */
    //影片23-7 指標與遞增遞減運算子(重要)
    /*
    int v[5];
    int *p=v;
    while(p != v+5)
    {
        *p++ = 0; //*(p++) = 0 ->先p[0]==v[0]=0後p++(特殊)
    }
    */
    //影片24-2 const 修飾字
    //const int b = 5; //表示b是唯讀
    //影片24-3 字串字面常數與const char*
    //若查詢cplusplus出現(const char * format)表示可輸入"字串"
    //影片24-5 使用函式複製字串
    /*
    char source[5]="test";
    char *destination;
    destination = source; // 淺複製(shallow copy)<-改變其中一個，另一個也會改變
    //深複製 (deep copy)
    char destination[5];
    for (int i=0; i<5; i++)
    {
        destination[i]=source[i];
    }
    printf("%s\n", destination);
    //strcpy用法
    //char * strcpy ( char * destination, const char * source );
    char source[5]="test";
    char *destination; (x)
    char destination[5]; (o)
    strcpy(destination,source);
    */
    //影片25-1 指標陣列(重要*2)
    //可更彈性的處理陣列，或是將非陣列資料存成陣列
    /*
    int v[3]= {1,2,3}
    int *p[3]={&v[0],&v[1],&v[2]};
    //循序存取
    for(int i=0; i<3; i++)
    {
        *p[i]=0;
    }
    //隨機存取
    *p[2]=5;
    //指標陣列初始化
    int a[4]={1,2,7,9};
    int b[2]={3,4};
    int c[2]={5,6};
    int *p[3]={a,b,c};
    //循序存取
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<2; j++)
        {
            p[i][j]=0;
        }
    }
    //隨機存取
    p[0][2]=9;
    p[1][2]=10;//(X)未定義行為
    */
    //25-2 陣列的指標
    /*
    int v[3]={1,2,3};
    int (*q)[3]=&v;
    //循序存取
    for(int i=0; i<3; i++)
    {
        (*q)[i]=1;
    }
    //隨機存取
    (*q)[2]=5;
    */
    //影片26-2 合法的隱性傳型 (重要)
    int intVar = 3;
    char charVar = '3';
    float floatVar = 3.5f;
    double doubleVar = 3.5;
    //同類型別內互傳
    floatVar = doubleVar;(o)
    intVar = charVar;(o)
    //整數與浮點樹間互傳
    intVar = doubleVar;(o)
    doubleVar = intVar;(o)
    int v[3];
    int *n;
    const int *p;
    //陣列可以隱性轉型成指向第一個元素的指標
    n = v; //(int *)=(int [3]) (O)
    v = n; //(int [3]) = (int *)(x)
    //Type * 可以隱性轉型成 const Type *
    p = n; //(const int *) = (int *) (O)
    n = p; // (int *) = (const int *) (?)
    // void * 與其他型別的指標"可能"可以互傳，但大部分都是未定義行為
    int intVar = 3;
    void *voidPtr = &intVar;
    int *intPtr = voidPtr;
    printf("%d\n", *intPtr);
    printf("%d\n", *voidPtr); (X)
    return 0;
}
void sort(int *a, int *b)
{
    if (*a > *b)
    {
        swap(&*a,&*b);
    }
}

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
