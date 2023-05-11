/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 09:35:31 by jbouma        #+#    #+#                 */
/*   Updated: 2023/05/11 16:46:49 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	get_int_length(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	bit_value(long n, int x)
{
	// printf("n: %lu, n: %ld\n", n, n);
	if ((n >> x) & 1)
		return (1);
	return (0);
}
