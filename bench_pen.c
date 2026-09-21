/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_pen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:28:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/21 16:28:38 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

static void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	write_bench_file(int fd, t_bench *bench, char *strategy_name)
{
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(bench->disorder_pct, fd);
	ft_putstr_fd(".", fd);
	if (bench->disorder_dec < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(bench->disorder_dec, fd);
	ft_putstr_fd("%\n[bench] strategy: ", fd);
	ft_putstr_fd(strategy_name, fd);
	ft_putstr_fd("\n[bench] total_ops: ", fd);
	ft_putnbr_fd(bench->total_ops, fd);
}

void	write_bench_file2(int fd, t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa: ", fd);
	ft_putnbr_fd(bench->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(bench->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(bench->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(bench->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(bench->pb, fd);
	ft_putstr_fd("\n[bench] ra: ", fd);
	ft_putnbr_fd(bench->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(bench->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(bench->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(bench->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(bench->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(bench->rrr, fd);
	ft_putstr_fd("\n", fd);
}
