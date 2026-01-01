#include <stdio.h>
int main(void)
{
    int ch;
    int braces = 0;
    int flag = 0;       // 0表示配套顺序正确，1表示配套顺序错误

    /*
        没遇到EOF前，循环读取字符
            如果遇到'{'，braces自增
            如果遇到'}'
                如果braces个数此时等于0，flag = 1
                braces自减
        如果braces等于0
            如果flag等于0，提示正确配对
            否则提示个数配套，但顺序不配套
        否则
            提示不配套
     */
    while((ch = getchar()) != EOF)
    {
        if(ch == '{')
            braces++;
        if(ch == '}')
        {
            if(braces == 0)
                flag = 1;
            braces--;
        }
    }
    if(braces == 0)
    {
        if(flag == 0)
            printf("个数及顺序均配套\n");
        else
            printf("个数配套，但顺序不配套\n");
    }else
        printf("不配套\n");

    return 0;
}