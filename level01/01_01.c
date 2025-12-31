#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_numbers(int columns[], int max);
void rearrange(char * output, const char * input, int n_columns, const int columns[]);
int main(void)
{
    int n_columns;              // 列数，成对出现
    int columns[MAX_COLS];      // 有效列标号——不包括结尾的负数
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);
    while(gets(input) != NULL)
    {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int n_columns = 0;
    int ch;

    while(n_columns < max && scanf("%d", &columns[n_columns])==1 && columns[n_columns] >= 0)
        n_columns++;
    if(n_columns%2 != 0){
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while((ch = getchar()) != EOF && ch != '\n')
        continue;

    return n_columns;
}

void rearrange(char * output, const char * input, int n_columns, const int columns[])
{
    int col;
    int output_col = 0;         // 下一个待写入的数组下标
    int len = strlen(input);

    for(col = 0; col < n_columns; col += 2)
    {
        int nchars = columns[col+1] - columns[col] + 1;
        
        if(columns[col] >= len || output_col == MAX_INPUT - 1)
            break;
        // ouput数组剩余空间不足以容纳nchars个字符
        if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}