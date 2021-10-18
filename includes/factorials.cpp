int Factorial_Recursive(int number)
{
    if (number == 2)
    {
        return number;
    }

    return number * Factorial_Recursive(number - 1);
}

int Factorial_Biasa(int number)
{
    int i, factorial = 1;

    for (i = 1; i <= number; ++i)
    {
        factorial *= i;
    }
    return factorial;
}
