#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>



/*
Bu getchar ile tek tek verileri çekip \n olmadığı takdirde büyutunu arttırmaya devam et
bununla beraber write için uzunluk belirle
bu belirlediğin uzunluk ve veri ile ekrana yazı yazdır
*/




int ft_printf(const char *format, ...)
{
    va_list args;
    int len = 0;
    va_start(args, format);
    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;
            len++;
            if(*format == 'd')
            {
                ft_putnbr(va_arg(args,int));
            }
            else if(*format == 'c')
            {
                ft_putchar(va_arg(args, int));
            }
            else if(*format == '%')
            {
                ft_putchar('%');
            }
            else if(*format == 's')
            {
                ft_putstr(va_arg(args, char *));
            }
        }
        else
        {
            ft_putchar(*format);
        }
        format++;
        len++;
    }
    va_end(args);
    return len;
}

/*
int main()
{
    char a = 'a';
    my_printf("%d %c %s \n", 1, a, "test");

    
    write(1, "Bir karakter giriniz\n", 21);
    char ch = _getchar();
    write(1, "\nGirdiginiz karakter: ", 22);
    write(1, &ch, 1);
    write(1, "\n", 1);
    
    
    return 0;
}

*/


