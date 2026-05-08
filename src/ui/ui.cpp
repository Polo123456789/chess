#include <ui.hpp>
#include <iostream>

static char letter_for_piece(piece p) {
    switch (p.type) {
    case piece_type::blank:
        return '.';
    case piece_type::king:
        return 'k';
    case piece_type::queen:
        return 'q';
    case piece_type::rook:
        return 'r';
    case piece_type::bishop:
        return 'b';
    case piece_type::knight:
        return 'n';
    case piece_type::pawn:
        return 'p';
    }
    return '?';
}

void naive_board_draw(const board &b) {
    for (const auto &row : b.board) {
        for (const auto col : row) {
            if (col.color == piece_color::white) {
                std::cout << "\033[32m" << letter_for_piece(col) << "\033[0m";
            } else {
                std::cout << "\033[31m" << letter_for_piece(col) << "\033[0m";
            }
        }
        std::cout << '\n';
    }
}
