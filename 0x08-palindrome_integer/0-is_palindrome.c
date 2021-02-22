
/**
 * is_palindrome - Function that checks whether
 * or not a given unsigned integer is a palindrome.
 * @n: Number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long Pivot = n;
	unsigned long Counter = 0;

	while (Pivot)
	{
		Counter = Counter * 10 + Pivot % 10;
		Pivot /= 10;
	}
	return (n == Counter);
}
