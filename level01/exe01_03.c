#include <stdio.h>
int main(void)
{
    /*
        只要不等于EOF，读取字符并进入循环
            累加到signed char类型的变量上
            如果该字符是\n
                退出循环
    */
   int ch;
   signed char checksum = -1;

   while((ch = getchar()) != EOF)
   {
        checksum += ch;
        if(ch == '\n')
            break;
   }
   printf("%d\n", checksum);

    return 0;
}