


int	main(int argc, char **argv)
{
	t_data	data;

	1//if (ac != 2)
	//	return (error_message));
	2// A function that initializes all the fields of the t_data structure to default values.

  3//A function that processes the map file passed as argv[1].
 //function that processes the map file passed as argv[1].
//It opens and reads the map file.
//Verifies that the map adheres to rules (e.g., surrounded by walls, valid characters).
//Updates data with map data (grid layout, dimensions, etc.)
  4 initialize_mlx (&data);	
  
5  initialize_textures(&data);
//Performs the initial render of the game view.
//Casts rays for every column of pixels on the screen.
//Draws walls, ceilings, and floors based on the player’s current position and direction.
//The rendered image may be stored in an off-screen buffer.	
  
  //Sets up hooks or listeners for player input (e.g., keyboard or mouse events).
    
  mlx_loop_hook(data.mlx, render_&_cast, &data);
	mlx_loop(data.mlx);
	return (0);
}