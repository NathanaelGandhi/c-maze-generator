#include "maze_generator.h"

#include <stdio.h>

void MazeGen_init(const int32_t rows, const int32_t columns,
                  MazeGen_Maze *maze) {
    // guard bad inputs (<= 0)
    if (rows < 1 || columns < 1) {
        return;
    }

    maze->rows = rows;
    maze->columns = columns;

    // generate a grid
    _MazeGen_generate_grid(maze);

    // set the starting location
    _MazeGen_set_cell_type(0, 0, MazeGen_START, maze);

    // set the ending location
    _MazeGen_set_cell_type(maze->rows - 1, maze->columns - 1, MazeGen_END,
                           maze);

    return;
}

void MazeGen_deinit(void) { return; }

void MazeGen_print_maze(const MazeGen_Maze *maze) {
    for (int32_t row = 0; row < maze->rows; row++) {
        for (int32_t column = 0; column < maze->columns; column++) {
            int32_t current_index =
                _MazeGen_position_to_index(row, column, maze->columns);
            char printable_char;
            switch (maze->grid[current_index].type) {
                case MazeGen_WALL:
                    printable_char = '*';
                    break;
                case MazeGen_PATH:
                    printable_char = ' ';
                    break;
                case MazeGen_START:
                    printable_char = 'S';
                    break;
                case MazeGen_END:
                    printable_char = 'E';
                    break;
                default:
                    break;
            }
            printf("%c ", printable_char);
        }
        printf("\n");
    }

    return;
}

int32_t _MazeGen_position_to_index(const int32_t row, const int32_t column,
                                   const int32_t num_columns) {
    return row * num_columns + column;
}

void _MazeGen_generate_grid(MazeGen_Maze *maze) {
    // assign blank maze
    for (int32_t row = 0; row < maze->rows; row++) {
        for (int32_t column = 0; column < maze->columns; column++) {
            // calculate the position in the linear array
            int32_t current_cell =
                _MazeGen_position_to_index(row, column, maze->columns);
            // assign to the maze
            maze->grid[current_cell].row = row;
            maze->grid[current_cell].column = column;
            maze->grid[current_cell].type = MazeGen_WALL;
        }
    }

    return;
}

void _MazeGen_set_cell_type(const int32_t row, const int32_t column,
                            const MazeGen_CellType type, MazeGen_Maze *maze) {
    maze->grid[_MazeGen_position_to_index(row, column, maze->columns)].type =
        type;

    return;
}