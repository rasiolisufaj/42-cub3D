
#include "cub3d.h"

/* Handle keyboard input by setting movement flags
(press = set, release = reset).
Key Idea: You don't move your player inside the key handler.
Instead, you set movement flags, and the render loop function to the
render part uses them.
*/

static int	key_press_handler(int key, t_data *data)
{
    if (key == XK_Escape)
        quit_cub3d(data);
    if (key == XK_Left)
        data->player.rotate = -1;
    if (key == XK_Right)
        data->player.rotate = 1;
    if (key == XK_w || key == XK_W)
        data->player.move_y = -1;  // Set flag
    if (key == XK_s || key == XK_S)
        data->player.move_y = 1;   // Set flag
    if (key == XK_a || key == XK_A)
        data->player.move_x = -1;  // Set flag
    if (key == XK_d || key == XK_D)
        data->player.move_x = 1;   // Set flag
    return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_W || key == XK_w || key == XK_S || key == XK_s)
		data->player.move_y = 0;
	if (key == XK_A || key == XK_a || key == XK_D || key == XK_d)
		data->player.move_x = 0;
	if (key == XK_Left || key == XK_Right)
		data->player.rotate = 0;
	return (0);
}

// Handle Mouse Function

static int render_loop(t_data *data)
{
    float speed;
    float new_y;
    float new_x;

    speed = 0.010;
    mlx_destroy_image(data->mlx, data->minimap.img);
    if (data->player.move_y != 0)
    {
        new_y = data->player.pos_y + (data->player.move_y * speed);
        if (validate_move(data, data->player.pos_x, new_y) == 1)
        {
            if (detect_wall(new_y, data->player.pos_x, data) == 1)
                data->player.pos_y = new_y;
        }
    }
    if (data->player.move_x != 0)
    {
        new_x = data->player.pos_x + (data->player.move_x * speed);
        if (validate_move(data, new_x, data->player.pos_y) == 1)
        {
            if (detect_wall(data->player.pos_y, new_x, data) == 1)
                data->player.pos_x = new_x;
        }
    }
    draw_map(data, 40);
    draw_player(data, 10);
    return 0;
}

void	listen_for_event_input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit_cub3d, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
    mlx_loop_hook(data->mlx, render_loop, data);
	// if (BONUS)
		// mlx_hook -> handle mouse motion
}