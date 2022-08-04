#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_info{
	char	**map;
	int		pos_x;
	int		pos_y;
	void	*mlx;
	void	*win;
}   t_info;

#endif
