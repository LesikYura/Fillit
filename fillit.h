/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:22:53 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/26 17:51:39 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"
# include <unistd.h>

char	*ft_expand(int count, int retry, int raws);
int		ft_read(char *sfin, char *str, int *flag, int c);
void	ft_trackslow(char *sfin, char **str, int j, int *flag);
void	ft_trackfast(char *sfin, char **str, int j, int *flag);
char	*ft_algor(char **str, int count);

int		ft_count(int *flag);
int		ft_raws(char *sfin);
int		ft_addr(int i, char *flag, int counter, int raws);
void	ft_clear(char *str, int c);
char	*ft_blocks(char *str);

void	ft_clearbreak(char *sfin, int c, int *counter);
int		ft_add(char *sfin, char *str, int c, int start);
int		ft_ok(int *str);
int		ft_end(int *str);
int		*ft_strflag(int count);

char	*buff_copy(char *buff, size_t ret);
char	*read_input(char *f_name);
int		count_block(char *str);

int		field_valid(char *str);
int		valid_figure_result(int connect, char c1, char c2);
int		valid_figure_hash(char *str, int connect, int i, int figure_count);
int		valid_figure_chek_connect(int *connect, int *dies, int *y);
int		valid_figure(char *str, int i, int dies, int connect);

#endif
