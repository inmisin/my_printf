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



void ReadValues(const char *const _Format)
{
    write(1, _Format, 1);
    write(1, "\n", 1);
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
    char c;
    int length = 0;
    
    while ((c = _getchar()) != '\n')
    {
        
        write(1, &c, length);
        ReadValues(&c);
    }
    
    
    return 0;
}


