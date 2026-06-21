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

int _putnbr()
{

}



void WriteValues(int n, ...)
{
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
    {
        int a = va_arg(args, int);
        char c = a+'0';
        _putchar(c);
        _putchar(*"\n");
    }
    
    va_end(args);
}

int main()
{
    /*
    write(1, "Bir karakter giriniz\n", 21);
    char ch = _getchar();
    write(1, "\nGirdiginiz karakter: ", 22);
    write(1, &ch, 1);
    write(1, "\n", 1);
    */
    
    WriteValues(2, 1,2);
    
    
    return 0;
}


