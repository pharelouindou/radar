#include "../dad.h"
#include <criterion/criterion.h>

Test(my_strlen, is_define)
{
    my_strlen("");
}

Test(my_strlen, empty_string_return_0)
{
    int res;
    
    res = my_strlen("");
    cr_assert_eq(0, res);
}

Test(my_strlen, string_A_return_1)
{
    int res;
    
    res = my_strlen("A");
    cr_assert_eq(1, res);
}

Test(my_strlen, string_AB_return_2)
{
    int res;
    
    res = my_strlen("AB");
    cr_assert_eq(2, res);
}

Test(my_strlen, maxi_string)
{
    int res;
    
    res = my_strlen("qwertyuioplkjhgfdsazxcvbnm");
    cr_assert_eq(26, res);
}
