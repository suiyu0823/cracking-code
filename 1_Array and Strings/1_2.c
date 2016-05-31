#include <stdio.h>
void reverse(char* str)
{
    char* end = str;
    char temp;
    if(str)
    {
        while(*end)
        {
            ++end;
        }
        --end;
        while(str < end)
        {
            temp = *str;
            //*str++ = *end;
            //*end-- = temp;
            *(str++) = *end;
            *(end--) = temp;
        }
    }
}
int main()
{

	char str[25] = "I    love xiuxiubaobao";
    reverse(str);
    char* ptr = str;
    while(*ptr)
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}