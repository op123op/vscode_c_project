#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 编写一个程序，接收用户的输入信息，当用户输入完成后（'#'代表输入完成），自动统计用户输入的空格数、大小写字母数和其他字符数。
    // 提示：scanf函数如何输入空格字符
    char buf[128] = {0};
    printf("请输入：");
    scanf("%[^#]", buf);    // 除非遇到#号，否则不退出输入界面
    int lenght = strlen(buf);
    int blank_key = 0,capital_letter = 0,lowercase = 0,rests = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (buf[i] == 32)
        {
            blank_key++;
        }else if ( (65 <= buf[i]) && (buf[i] <= 90) )
        {
            capital_letter++;
        }else if ( (97 <= buf[i]) && (buf[i] <= 122) )
        {
            lowercase++;
        }else{
            rests++;
        }   
    }
    printf("空格数：%d,大写字母数：%d,小写字母数：%d,其他数：%d\n",blank_key,capital_letter,lowercase,rests);

    return 0;
}
