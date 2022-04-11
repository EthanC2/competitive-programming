unsigned int num_digits(int num)
{
    return (num == 0) ? 1 : log10(abs(num))+1;
}

template <typename IntT, typename enable = typename enable_if<is_integral<IntT>::value>::type>
unsigned int num_digits(IntT num)
{
    return (num == 0) ? 1 : log10(abs(num))+1;
}
