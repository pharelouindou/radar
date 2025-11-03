#include "../dad.h"
#include <criterion/criterion.h>

Test (my_getnbr, is_defined)
{
    my_getnbr("0");
}

Test(my_getnbr, return_1)
{
    int res;

    res = my_getnbr("1");
    cr_assert_eq(1, res);
}

Test(my_getnbr, return_2)
{
    int res;

    res = my_getnbr("2");
    cr_assert_eq(2, res);
}

Test(my_getnbr, return_23)
{
    int res;

    res = my_getnbr("23");
    cr_assert_eq(23, res);
}

Test(my_getnbr, return_43)
{
    int res;

    res = my_getnbr("43");
    cr_assert_eq(43, res);
}

Test(my_getnbr, return_143)
{
    int res;

    res = my_getnbr("143");
    cr_assert_eq(143, res);
}

Test(my_getnbr, return_14673)
{
    int res;

    res = my_getnbr("14673");
    cr_assert_eq(14673, res);
}
