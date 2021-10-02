// Given an integer A, count and return the number of trailing zeroes.

int solve(int A)
{
    int c = 0;
    for (int i = 31; i >= 0; i--)
    {
        int k = A >> i;
        if (k & 1)
            c = 0;
        else
            c++;
    }
    return c;
}