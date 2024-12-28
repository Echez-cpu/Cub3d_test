/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:53:04 by pokpalae          #+#    #+#             */
/*   Updated: 2024/12/24 23:07:25 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB_H
# define CUB_H

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/includes/libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>



# define WIN_HEIGHT 200
# define WIN_WIDTH 320

# define TEXTURE_SIZE 64
# define MOVESPEED 0.0525
# define TURN_RATE 0.515

#define KEY_ESC		65307
#define	KEY_PRESS	2
#define	KEY_W		119
#define	KEY_S		115
#define	KEY_A		97
#define	KEY_D		100
#define	KEY_LEFT	65361
#define KEY_RIGHT	65363
#define	X_CLICK		17


enum e_output
{
	SUCCESS = 0,
	FAIL = 1,
	ERROR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};


// structures


typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			end_of_map_index;
}	t_mapinfo;

typedef struct s_img
{
	void	*img;
	int		*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_cast_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_cast_ray;

typedef struct s_field_of_view
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_field_of_view;

typedef struct s_game_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	t_field_of_view	first_person;
	t_cast_ray		casted_ray;
	t_mapinfo	mapinfo;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_game_data;




// Parsing functions
int	validity_check(t_game_data *data, char **argv);
int	end_game(t_game_data *data);
int	extract_map_data(t_game_data *data, char **map);
int	set_floor_ceiling_colors(t_game_data *data, t_texinfo *textures, char *line, int j);
int	*convert_string_to_rgb(char *line);
int	*convert_string_to_rgb(char *line);
int	map_constructor(t_game_data *data, char **file, int i);
int	inspect_map_characters(t_game_data *data, char **map_grid);
int	confirm_map_enclosure(t_mapinfo *map, char **map_grid);
int	locate_cam_and_validate(t_game_data *data, char **map_grid);



// ray casting functions
int	update_graphics(t_game_data *data);
void	initialize_mlx(t_game_data *data);

int	move_if_valid(t_game_data *data, double i, double j);
int	apply_turn(t_game_data *data, double turn_rate);
bool	is_position_inside_map(t_game_data *data, double x, double y);
int	rotate_camera(t_game_data *data, double rotdir);
bool	is_position_free_of_walls(t_game_data *data, double x, double y);

int generate_rays(t_field_of_view *camera, t_game_data *data);

void	map_texture_to_ray_hit(t_game_data *data, t_texinfo *txture, t_cast_ray *ray, int x);

void	set_texture_direction(t_game_data *data, t_cast_ray *ray);
int	update_graphics(t_game_data *data);
void	free_things(void **tab);
void	setup_game_state(t_game_data *data);
void	paint_frame(t_game_data *data);
void	draw_graphics(t_game_data *data);
void	allocate_pixel_memory(t_game_data *data);

void	setup_input_hooks(t_game_data *data);
int	camera_spin(t_game_data *data);

int	reset_keyPress_flags(int key, t_game_data *press);
int	key_press(int key, t_game_data *press);
void	setup_image(t_game_data *data, t_img *image, int width, int height);
void	reset_img_struct(t_img *img);
void	set_pixel_color(t_game_data *data, t_img *image, int x, int y);
void	write_color_2_pixel(t_img *image, int x, int y, int color);
void	configure_textures(t_game_data *data);
int	*get_texture_from_xpm(t_game_data *data, char *path);
void	fill_raycastg_para(int x, t_cast_ray *ray, t_field_of_view *player);
void	initialize_ray_traversal (t_cast_ray *ray,  t_field_of_view *camera);
void	zero_out_ray(t_cast_ray *ray);
void step_through_grid(t_game_data *data, t_cast_ray *ray);
void	compute_wall_visualization(t_cast_ray *ray, t_game_data *data, t_field_of_view *camera);
int	confirm_map_enclosure(t_mapinfo *map, char **map_grid);
int	is_white_space(char c);
int	is_spawn_position_valid(t_game_data *data, char **map_grid);
#endif