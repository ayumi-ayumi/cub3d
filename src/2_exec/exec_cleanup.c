
void	cleanup_exec(t_game *game, t_exec *exec)
{
	if (game->mlx)
		free_mlx(game, exec);
}
