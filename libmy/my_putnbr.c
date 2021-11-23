
int calc_power(int n)
{
    int diviser = 1;

    while ((n / diviser) >= 10)
    {
        diviser *= 10;
    }
    return diviser;
}

void my_putnbr(int n)
{
    int power;
    char ch;

    if (n == -2147483648)
    {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return;
    }

    if (n < 0)
    {
        n *= -1;
        my_putchar('-');
    }

    power = calc_power(n);

    while (power > 0)
    {
        ch = n / power + 48;
        n = n % power;
        power = power / 10;
        my_putchar(ch);
    }
}
