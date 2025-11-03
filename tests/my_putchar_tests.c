#include "../dad.h"
#include <criterion/criterion.h>

Test(my_putchar, is_define)
{
    char c = 'o';
    my_putchar(c);
}
