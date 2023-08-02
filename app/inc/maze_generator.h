#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

//##############################################################################

#include <stdint.h>

#define MazeGen_MAX_NUM_MAZE_CELLS 10000  // 100x100 Grid

typedef enum MazeGen_CellType_e {
    MazeGen_WALL = 0,
    MazeGen_PATH = 1,
    MazeGen_START = 2,
    MazeGen_END = 3
} MazeGen_CellType;

typedef struct MazeGen_Cell_s {
    int32_t row;
    int32_t column;
    MazeGen_CellType type;
} MazeGen_Cell;

typedef struct MazeGen_Maze_s {
    MazeGen_Cell grid[MazeGen_MAX_NUM_MAZE_CELLS];
    int32_t rows;
    int32_t columns;
    MazeGen_Cell active_cell;
} MazeGen_Maze;

// public
void MazeGen_init(const int32_t rows, const int32_t columns,
                  MazeGen_Maze* maze);
void MazeGen_deinit(void);
void MazeGen_print_maze(const MazeGen_Maze* maze);

// private
int32_t _MazeGen_index_from_position(const int32_t row, const int32_t column,
                                     const int32_t num_columns);
void _MazeGen_generate_grid(MazeGen_Maze* maze);
void _MazeGen_set_cell_type(const int32_t row, const int32_t column,
                            const MazeGen_CellType type, MazeGen_Maze* maze);

//##############################################################################

#ifdef __cplusplus
}
#endif

#endif  // MAZE_GENERATOR_H