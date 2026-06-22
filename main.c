#include <stdarg.h>


#ifdef _WIN32
    #include <io.h>
    #define write _write
#else
    #include <unistd.h>
#endif


/*
Bu getchar ile tek tek verileri çekip \n olmadığı takdirde büyutunu arttırmaya devam et
bununla beraber write için uzunluk belirle
bu belirlediğin uzunluk ve veri ile ekrana yazı yazdır
*/

char _getchar(void)
{
    char c = 0;

    read(0, &c, 1);

    return c;
}

void _putchar(char c)
{
    write(1, &c, 1);
}

void _putnbr(int n)
{
    if (n < 0)
    {
        _putchar(*"-");
        n = -n;
    }
    if(n >= 10)
    {
        _putnbr(n/10);
        _putnbr(n%10);
    }
    else
    {
        _putchar(n+'0');
    } 
    
}

void _putstr(char *str)
{
    while(*str != '\0')
    {
        _putchar(*str);
        str++;
    }
}



void my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;
            if(*format == 'd')
            {
                _putnbr(va_arg(args,int));
            }
            else if(*format == 'c')
            {
                _putchar(va_arg(args, int));
            }
            else if(*format == '%')
            {
                _putchar('%');
            }
            else if(*format == 's')
            {
                _putstr(va_arg(args, char *));
            }
        }
        else
        {
            _putchar(*format);
        }
        format++;
    }
    va_end(args);
}

int main()
{
    char a = 'a';
    my_printf("%d %c %s \n", 1, a, "test");

    /*
    write(1, "Bir karakter giriniz\n", 21);
    char ch = _getchar();
    write(1, "\nGirdiginiz karakter: ", 22);
    write(1, &ch, 1);
    write(1, "\n", 1);
    */ 
    
    return 0;
}


