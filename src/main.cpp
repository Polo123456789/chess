#include <board.hpp>
#include <ui.hpp>

int main() {
    board board;
    board.initial_position();

    naive_board_draw(board);

    return 0;
}
