#include "cub3d.h"

int main(int ag, char **av){
    (void) ag;
    (void) av;
    t_info *info;

    info = malloc(sizeof(t_info));
    
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, 1000, 1000, "cub3D");

    mlx_loop(info->mlx);

    printf("Hello world!");
    return (0);
}