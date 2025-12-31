#include <stdio.h>
#include <string.h>
#define MAX_SIZE    1000
int main(void)
{
    /*
        循环读取每一行，直到没有更多行
            计算该行长度
            如果比最长长度还长
                更新最长长度
                把改行拷贝到目标数组中
        输出最长长度及目标数组
    */
   char input[MAX_SIZE + 1];
   char tmp[MAX_SIZE + 1];
   int max_len = 0;

   while (gets(tmp) != NULL)
   {
        int tmp_len = strlen(tmp);
        if(tmp_len > max_len)
        {
            max_len = tmp_len;
            strcpy(input, tmp);
        }
   }
   printf("%s\n", input);

    return 0;
}