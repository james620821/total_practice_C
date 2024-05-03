#include <stdio.h>
void print_number(void);
void print_number_1(void);
int main()
{
    //print_number(); //缺點:只能固定陣列大小
    //影片28-6 動態配置記憶體(重要)
    //<stdlib.h>提供malloc函式讓我們動態配置記憶體
    // void* malloc(size_t size); size為非負整數型態(size_t)-->表示要配置的記憶體空間大小，可使用sizeof
    print_number_1(); //缺點:舊陣列不會消失，故記憶體會飽和
    //影片28-7 釋放動態配置記憶體
    //<stdlib.h>提供free函式來釋放動態配置的記憶體
    //void free(void* ptr); ptr-->要釋放的動態記憶體位址
    //影片28-8 重新配置記憶體
    //<stdlib.h>提供realloc函式來複製記憶體內容
    //void* realloc(void* ptr, size_t size);
    //ptr-->重新配置的記憶體空間開頭位址
    //size-->重新配置後的記憶體空間大小
    return 0;
}
void print_number_1(void)
{
    int *numbers;
    //int *numbers = 0; // 0-->表示空指標(null)
    int length = 0;
    while(1)
    {
        int input;
        scanf("%d",&input);
        if(input == 0) break;

        numbers = realloc(numbers, sizeof(int)*(length+1));
        /*
        int *larger = malloc(sizeof(int)*(length+1));//產生一個大一格的新陣列
        for (int i =0; i<length; i++)
        {
            larger[i] = numbers[i]; //複製舊陣列到新陣列裡
        }
        //free(numbers); //free參數若為空指標，則不執行
        numbers = larger; //將numbers指向新陣列
        */
        numbers[length] = input; //將輸入的數字加在新陣列的最後
        length++;
    }
    printf("Numbers: ");
    for (int i=0; i<length; i++)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");


}
void print_number(void)
{
    int i=0, num[10];
    while(1)
    {
        scanf("%d",&num[i]);
        if(num[i] == 0)
        {
            break;
        }
        i++;
    }
    printf("Number: ");
    for(int j=0; j<=i ; j++)
    {
        printf("%d ",num[j]);
    }

}
