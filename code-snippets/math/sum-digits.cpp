unsigned int sum_digits(int num)
{
    num = abs(num);
    unsigned int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

template <typename IntT, typename enable = typename enable_if<is_integral<IntT>::value>::type>
unsigned int sum_digits(IntT num)
{
    num = abs(num);
    unsigned int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
