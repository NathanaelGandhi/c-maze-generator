/**
 * @file app.c
 *
 * @brief Main application entry point
 *
 * @author Nathanael Gandhi
 * @link https://github.com/NathanaelGandhi
 */

/*##############################################################################
// # C Style Naming Convention                                                 |
// ## Key: [ ] used for optional parameters. < > used for placeholders.        |
// | Element     | Naming Convention            | Example(s)                   |
// | :---------: | :--------------------------: | :--------------------------: |
// | filenames   | snake_case                   | header_file.h, source.c      |
// | classes     | TitleCase                    | MyClass                      |
// | structs     | [TitleCasePrefix_]TitleCase  | MyStruct, MyClass_MyStruct   |
// | enums       | [TitleCasePrefix_]TitleCase  | AnEnum, MyClass_AnotherEnum  |
// | functions   | [TitleCasePrefix_]lower_case | my_func, CoolClass_my_func   |
// | constants   | [TitleCasePrefix_]UPPER_CASE | SOME_LIMIT, MyClass_LOW_VAL  |
// | macros      | TitleCasePrefix_UPPER_CASE   | MyMacro_ADD_1(x)             |
// | local vars  | snake_case                   | hold_my_data                 |
// | global vars | g_snake_case                 | g_is_global                  |
// | booleans    | is_< element >_< condition > | is_led_on, MyClass_is_led_on |
// | units       | < element >_< SI_units >     | rotation_rad, current_mA     |
//############################################################################*/

#include <stdio.h>

#include "maze_generator.h"

/* Function Prototypes */

/**
 * @brief Application entry function
 *
 * @return int
 */
int main() {
    int32_t rows = 5;
    int32_t columns = rows;
    // create maze object
    MazeGen_Maze maze = {0};

    printf("Using %d rows and %d columns\n", rows, columns);

    MazeGen_init(rows, columns, &maze);
    MazeGen_print_maze(&maze);

    MazeGen_deinit();

    return 0;
}
