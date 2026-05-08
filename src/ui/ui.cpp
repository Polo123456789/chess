#include <ui.hpp>
#include <iostream>

static char letter_for_piece(piece p) {
    switch (p.piece_type) {
    case piece_type_t::blank:
        return '.';
    case piece_type_t::king:
        return 'k';
    case piece_type_t::queen:
        return 'q';
    case piece_type_t::rook:
        return 'r';
    case piece_type_t::bishop:
        return 'b';
    case piece_type_t::knight:
        return 'n';
    case piece_type_t::pawn:
        return 'p';
    }
    return '?';
}

void naive_board_draw(const board &b) {
    for (const auto &row : b.board) {
        for (const auto col : row) {
            if (col.color == color_t::white) {
                std::cout << "\033[32m" << letter_for_piece(col) << "\033[0m";
            } else {
                std::cout << "\033[31m" << letter_for_piece(col) << "\033[0m";
            }
        }
        std::cout << '\n';
    }
}
