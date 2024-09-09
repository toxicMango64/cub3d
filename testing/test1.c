#include "test.h"

void	init_map(t_map *map)
{
	map->rows = 0;
	map->full = NULL;
	map->grid = NULL;
}

void	init_player(t_player *player)
{
	player->direction = '\0';
	player->x = '\0';
	player->y = '\0';
}

void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->south = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
}

int	initgame(t_soul_catcher *game)
{

}

int	main(const int ac, const char * const *av)
{
	t_soul_catcher	*game;

	if (initgame(game))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
