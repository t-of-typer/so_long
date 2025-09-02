🎮 FLUJO COMPLETO DEL PROGRAMA SO_LONG
1. MAIN.C - Punto de entrada
Mi programa empieza en el main (como todos), que se encuentra en main.c, en la función recibimos el número de argumentos y los argumentos en sí. Declaramos la variable map que es un char ** (una matriz) en la que vamos a guardar el mapa y una estructura t_game llamada game, que contiene:

```
typedef struct s_game
{
    void    *mlx;              // Conexión con MLX
    void    *window;           // Ventana del juego
    char    **map;             // El mapa como matriz de caracteres
    int     width;             // Ancho del mapa en tiles
    int     height;            // Alto del mapa en tiles
    int     player_x;          // Posición X del jugador
    int     player_y;          // Posición Y del jugador
    int     moves;             // Contador de movimientos
    int     collectibles;      // Coleccionables recogidos
    int     total_collectibles; // Total de coleccionables en el mapa
    void    *img_wall;         // Imagen del muro (XPM)
    void    *img_floor;        // Imagen del suelo (XPM)
    void    *img_player;       // Imagen del jugador (XPM)
    void    *img_collectible;  // Imagen del coleccionable (XPM)
    void    *img_exit;         // Imagen de la salida (XPM)
} t_game;
```

Lo primero que comprobamos es si hay dos argumentos, que serían el programa so_long y la ruta del mapa. Si hay un error llamamos a exit_error que está en el propio main.c y lo que hace es imprimir "Error\n" seguido del mensaje específico y terminar el programa con exit(EXIT_FAILURE).

Comprobamos la extensión del mapa pasando el segundo argumento a check_file_extension, que también está en el main y lo que hace es comprobar si el string acaba en .ber usando ft_strncmp.

Después metemos en map el char ** que devuelve la función load_map, que está en map_init.c y recibe la ruta de nuestro mapa.

2. MAP_INIT.C - Carga del mapa
La función load_map hace dos cosas:

Llama a read_map_lines que abre el archivo, lee línea por línea con get_next_line (que está en nuestra Libft) y crea una lista enlazada con cada línea del mapa.
Llama a list_to_map que convierte la lista enlazada en una matriz char **, verificando que todas las líneas tengan la misma longitud (mapa rectangular).
3. MAP_CHECKS.C y MAP_UTILS.C - Validación
Después llamamos a map_is_valid que está en map_checks.c y hace estas validaciones:

count_map_elements: Cuenta que haya exactamente 1 jugador ('P'), al menos 1 salida ('E'), al menos 1 coleccionable ('C') y solo caracteres válidos ('0', '1', 'C', 'E', 'P').

check_walls: Verifica que el mapa esté completamente rodeado de muros ('1').

flood_fill_check: Hace una copia del mapa y usa flood fill (algoritmo que "inunda" desde la posición del jugador) para verificar que todos los coleccionables y la salida sean alcanzables.

4. GAME.C - Inicialización del juego
Si el mapa es válido, llamamos a init_game que está en game.c y hace:

mlx_init(): Inicializa la conexión con MLX (sistema gráfico).
mlx_new_window(): Crea una ventana del tamaño del mapa (width × TILE_SIZE, height × TILE_SIZE).
find_player_position: Busca la 'P' en el mapa, guarda su posición en game->player_x y game->player_y, y convierte esa casilla en '0'.
count_collectibles: Cuenta cuántos 'C' hay en total.
load_images: Carga todos los sprites XPM usando mlx_xpm_file_to_image.
mlx_key_hook: Conecta las teclas con la función handle_keypress.
mlx_hook: Conecta el cierre de ventana (X) con handle_close.
render_map: Dibuja el mapa inicial en pantalla.
5. SISTEMA DE RENDERIZADO
render_map recorre toda la matriz del mapa y:

Primero pone el suelo en todas las casillas.
Si la posición coincide con la del jugador, dibuja al jugador.
Si no, si hay un elemento que no sea '0', dibuja ese elemento (muro, coleccionable, salida).
render_tile decide qué imagen poner según el carácter del mapa usando mlx_put_image_to_window.

6. SISTEMA DE EVENTOS
handle_keypress recibe las teclas pulsadas:

ESC: Cierra el juego limpiamente.
WASD o flechas: Llaman a move_player con la nueva posición.
move_player hace:

can_move_to: Verifica que la nueva posición no sea un muro ('1') ni esté fuera del mapa.
Incrementa el contador de movimientos.
collect_item: Si hay un 'C' en la nueva posición, lo convierte en '0' y aumenta el contador de coleccionables.
Actualiza la posición del jugador.
render_map: Redibuja todo el mapa.
check_win_condition: Si el jugador está en 'E' y ha recogido todos los coleccionables, ¡gana!

7. LOOP PRINCIPAL
mlx_loop en el main entra en un bucle infinito que:

Espera eventos (teclas, ratón, cierre de ventana).
Llama a las funciones correspondientes cuando ocurren.
Mantiene la ventana actualizada.

8. LIMPIEZA DE MEMORIA
cleanup_game libera todos los recursos:

Destruye todas las imágenes MLX.
Destruye la ventana.
Destruye la conexión MLX.
Libera la memoria del mapa.

🔄 RESUMEN DEL FLUJO:
```
MAIN → Validar argumentos → Cargar mapa → Validar mapa → 
Inicializar juego → Cargar sprites → Renderizar → 
LOOP (Esperar eventos → Mover jugador → Renderizar → Verificar victoria) → 
Limpiar y salir
```

Maneja entrada, lógica, renderizado y memoria de forma ordenada y segura 🎮✨
