#include "../../inc/cub3d.h"

/** Initialize game state */
// void	init_cub3d(t_soul_catcher *game)
// {
// 	game->win_w = 800;
// 	game->win_h = 600;
// 	game->mx = 0;
// 	game->my = 0;
// 	game->forward = 0;
// 	game->backward = 0;
// 	game->left = 0;
// 	game->right = 0;
// }

char	**intit_texture(void)
{
	static char *t_id[7] = {"NO", "EA", "WE", "SO", "F", "C", NULL};
	return (t_id);
}
