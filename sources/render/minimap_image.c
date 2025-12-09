#include "cub3d.h"

int handle_key(int key_code, t_data *data)
{
    if (key_code == 65307)
    {
        free_data(data);
        exit(0);
    }
    return 0;
}