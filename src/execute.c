# include "cub3D.h"

void set_map(t_game *game);

int	close_esc(int keycode, t_game *game)
{
	(void) game;
	if (keycode == 53)
	{
		mlx_destroy_window(game->vars->mlx, game->vars->win);
		free(game->vars);
		cleaner(game);
		exit(0);
	}
	return (0);
}

void	pixels_init(t_game *game, t_vars *vars){
	void    *floor;
    void    *wall;
    void    *start;
	char	**map;
	int		i;
	int		j;
	int	width;
	int hight;

	width = 32;
	hight = 32;
	i = 0;
	j = 0;
	map = game->map;
	floor = mlx_xpm_file_to_image(vars->mlx, "/Users/mmeredit/Desktop/cubas/Textures/floor.xpm", &width, &hight);
	wall = mlx_xpm_file_to_image(vars->mlx, "/Users/mmeredit/Desktop/cubas/Textures/wall.xpm", &width, &hight);
	start = mlx_xpm_file_to_image(vars->mlx, "/Users/mmeredit/Desktop/cubas/Textures/dot.xpm", &width, &hight); 

	while (map[i])
	{
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, wall, j * 64, i * 64);
			}
			else if (map[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, floor, j * 64, i * 64);
			}
			else if (map[i][j] == 'N')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, floor, j * 64, i * 64);
				// mlx_put_image_to_window(vars->mlx, vars->win, start, j * 64, i * 64);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	move_all(t_game *game, double x, double y)
{
	// double	i;
	// double	j;

	// i = x;
	// j = y;
	// printf("HERE\n");
	// game->info->player_pos_x += x;
	// game->info->player_pos_y += y;
	// set_map(game);
	// if ((game->map)[i + y][j + x] != '1' && (game->map)[i + y][j + x] != ' ')
	// {
	// 	(game->map)[i][j] = '0';
		// (game->map)[i + y][j + x] = 'N'; 			/* добавить e, w, s */
		game->info->player_pos_x += x;
		game->info->player_pos_y += y;
		pixels_init(game, game->vars);
		set_map(game);
		// game->steps++;
		// pixels_init(game, game->vars);
				// printf("I am here");
		// ft_itoa(game->steps, game);
	// }
	return (1);
}

int move(int keycode, t_game *game){
	// printf("I AM MOVE! keycode = %d\n", keycode);
	close_esc(keycode, game);
	if (keycode == 13)
		move_all(game, 0, -0.5);
	else if (keycode == 0)
		move_all(game, -0.5, 0);
	else if (keycode == 1)
		move_all(game, 0, 0.5);
	else if (keycode == 2)
		move_all(game, 0.5, 0);
	// if (!game->game_over)
	// {
	// 	mlx_clear_window(game->libx->mlx, game->libx->win);
	// 	last_img(game, 0, 0);
	// }
	return (0);
}

// int move2(int keycode, t_game *game){
// 	// printf("I AM MOVE! keycode = %d\n", keycode);
// 	close_esc(keycode, game);
// 	if (keycode == 13)
// 		move_all(game, 0, -0.5);
// 	else if (keycode == 0)
// 		move_all(game, -0.5, 0);
// 	else if (keycode == 1)
// 		move_all(game, 0, 0.5);
// 	else if (keycode == 2)
// 		move_all(game, 0.5, 0);
// 	// if (!game->game_over)
// 	// {
// 	// 	mlx_clear_window(game->libx->mlx, game->libx->win);
// 	// 	last_img(game, 0, 0);
// 	// }
// 	return (0);
// }


void find_pos_hero(char **map, t_info *info){
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				info->player_pos_x = j;
				info->player_pos_y = i;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int argb_to_int(int a, int r, int g, int b){
	return (a << 24 | r << 16 | g << 8 | b);
}

// void set_map(t_game *game){
// 	int i = 0;
// 	int j = 0;
// 	char	**map = game->map;
// 	while (map[i])
// 	{
// 		while (map[i][j])
// 		{
// 			mlx_pixel_put(game->vars->mlx, game->vars->win, j * 64, i * 64, 0x808080);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }

void set_map(t_game *game){
	// t_img	img;
	// printf ("lenght = %d\n", game->y * 64);
	// printf ("height = %d\n", game->x * 64);
	// img.ptr = mlx_new_image(game->vars->mlx, game->y * 64, game->x * 64);
	// img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	// printf ("bits = %d  size_line = %d  endian = %d\n", img.bits_per_pixel, img.size_line, img.endian);
	// // printf ("height = %d\n", game->x * 64);

	// int color = argb_to_int(0, 192, 192, 192);

	// int width;
	// int height = 0;
	// char	*tmp = img.addr;

	// while (height < game->x * 64)
	// {
	// 	width = 0;
	// 	while (width < game->y * 64)
	// 	{
	// 		int pixel = (height * img.size_line) + (width * 4);
	// 		tmp[pixel + 0] = (color) & 0xFF;
	// 		tmp[pixel + 1] = (color >> 8) & 0xFF;
	// 		tmp[pixel + 2] = (color >> 16) & 0xFF;
	// 		tmp[pixel + 3] = (color >> 24);
	// 		width++;
	// 	}
	// 	height++;
	// }

	// color = argb_to_int(0, game->c[0], game->c[1], game->c[2]);
	
	// while (height < game->x * 64)
	// {
	// 	width = 0;
	// 	while (width < game->y * 64)
	// 	{
	// 		int pixel = (height * img.size_line) + (width * 4);
	// 		tmp[pixel + 0] = (color) & 0xFF;
	// 		tmp[pixel + 1] = (color >> 8) & 0xFF;
	// 		tmp[pixel + 2] = (color >> 16) & 0xFF;
	// 		tmp[pixel + 3] = (color >> 24);
	// 		width++;
	// 	}
	// 	height++;
	// }

	// mlx_put_image_to_window(game->vars->mlx, game->vars->win, img.ptr, 0, 0);

	t_img	img2;

	int		color;
	int width;
	int height = 0;
	img2.ptr = mlx_new_image(game->vars->mlx, 15, 15);
	img2.addr = mlx_get_data_addr(img2.ptr, &img2.bits_per_pixel, &img2.size_line, &img2.endian);

		printf ("bits = %d  size_line = %d  endian = %d\n", img2.bits_per_pixel, img2.size_line, img2.endian);

	color = argb_to_int(0, 0, 0, 255);

	width = 0;
	height = 0;
	while (height < 15)
	{
		while (width < 15)
		{
			int pixel = (height * img2.size_line) + (width * 4);
			img2.addr[pixel + 0] = (color) & 0xFF;
			img2.addr[pixel + 1] = (color >> 8) & 0xFF;
			img2.addr[pixel + 2] = (color >> 16) & 0xFF;
			img2.addr[pixel + 3] = (color >> 24);
			width++;
		}
		width = 0;
		height++;
	}
	img2.pos_x = game->info->player_pos_x * 64;
	img2.pos_y = game->info->player_pos_y * 64;
	game->img = img2;
	printf ("pos_x = %f   pos_y = %f\n", game->info->player_pos_x * 64, game->info->player_pos_y * 64);
	mlx_put_image_to_window(game->vars->mlx, game->vars->win, img2.ptr, game->info->player_pos_x * 64, game->info->player_pos_y * 64);
}

void execute(t_game *game){
    game->vars = malloc(sizeof(t_vars));
	game->info = malloc(sizeof(t_info));
	find_pos_hero(game->map, game->info);

	game->vars->mlx = mlx_init();
	game->vars->win = mlx_new_window(game->vars->mlx, game->y * 64, game->x * 64, "cub3D");
	
	pixels_init(game, game->vars);
	set_map(game);
	mlx_hook(game->vars->win, 2, 0, &move, game);
    mlx_loop(game->vars->mlx);

	// int 	i = 0;
	// char	**map = game->map;
    // printf("MYMAP\n");
    // while (map[i]){
    //     printf ("%s", map[i]);
    //     i++;
    // }
    // i = 0;

}


// t_img	img;
// 	printf ("lenght = %d\n", game->y * 64);
// 	printf ("height = %d\n", game->x * 64);
//     game->vars->win = mlx_new_window(game->vars->mlx, game->y * 64, game->x * 64, "cub3D");
// 	img.ptr = mlx_new_image(game->vars->mlx, game->y * 64, game->x * 64);
// 	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

// 	printf ("bits = %d  size_line = %d  endian = %d\n", img.bits_per_pixel, img.size_line, img.endian);
// 	// printf ("height = %d\n", game->x * 64);

// 	int color = argb_to_int(0, game->f[0], game->f[1], game->f[2]);

// 	int width;
// 	int height = 0;
// 	char	*tmp = img.addr;

// 	while (height < game->x * 64 / 2)
// 	{
// 		width = 0;
// 		while (width < game->y * 64)
// 		{
// 			int pixel = (height * img.size_line) + (width * 4);
// 			tmp[pixel + 0] = (color) & 0xFF;
// 			tmp[pixel + 1] = (color >> 8) & 0xFF;
// 			tmp[pixel + 2] = (color >> 16) & 0xFF;
// 			tmp[pixel + 3] = (color >> 24);
// 			width++;
// 		}
// 		height++;
// 	}

// 	color = argb_to_int(0, game->c[0], game->c[1], game->c[2]);
	
// 	while (height < game->x * 64)
// 	{
// 		width = 0;
// 		while (width < game->y * 64)
// 		{
// 			int pixel = (height * img.size_line) + (width * 4);
// 			tmp[pixel + 0] = (color) & 0xFF;
// 			tmp[pixel + 1] = (color >> 8) & 0xFF;
// 			tmp[pixel + 2] = (color >> 16) & 0xFF;
// 			tmp[pixel + 3] = (color >> 24);
// 			width++;
// 		}
// 		height++;
// 	}

// 	mlx_put_image_to_window(game->vars->mlx, game->vars->win, img.ptr, 0, 0);

// 	t_img	img2;

// 	img2.ptr = mlx_new_image(game->vars->mlx, 50, 50);
// 	img2.addr = mlx_get_data_addr(img2.ptr, &img2.bits_per_pixel, &img2.size_line, &img2.endian);

// 		printf ("bits = %d  size_line = %d  endian = %d\n", img2.bits_per_pixel, img2.size_line, img2.endian);

// 	color = argb_to_int(0, 0, 0, 255);

// 	width = 0;
// 	height = 0;
// 	while (height < 50)
// 	{
// 		while (width < 50)
// 		{
// 			int pixel = (height * img2.size_line) + (width * 4);
// 			img2.addr[pixel + 0] = (color) & 0xFF;
// 			img2.addr[pixel + 1] = (color >> 8) & 0xFF;
// 			img2.addr[pixel + 2] = (color >> 16) & 0xFF;
// 			img2.addr[pixel + 3] = (color >> 24);
// 			width++;
// 		}
// 		width = 0;
// 		height++;
// 	}
	
// 	mlx_put_image_to_window(game->vars->mlx, game->vars->win, img2.ptr, 400, 440);