#include <stdio.h>
int main(void)
{
    /*
        只要不等于EOF，就接受该字符并进入循环
            如果at_beginning为真，就输出行号，并将
            at_beginning设置为假

            如果字符为换行，at_begning设置为真
            输出该字符
     */
    int ch;
    int line = 0;
    int at_beginning = 1;   // 1在行首，0不在行首

    while((ch = getchar()) != EOF)
    {
        if(at_beginning == 1)
        {
            ++line;
            printf("%d: ", line);
            at_beginning = 0;
        }
        putchar(ch);
        if(ch == '\n')
            at_beginning = 1;
    }

    return 0;
}