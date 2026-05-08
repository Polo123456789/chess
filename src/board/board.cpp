#include "board.hpp"

#include <array>
#include <cassert>


piece board::get(position p) const {
    assert(p.col < board_size && p.row < board_size);
    return board[p.row][p.col];
}

piece board::set(position pos, piece p) {
    assert(pos.col < board_size && pos.row < board_size);
    board[pos.row][pos.col] = p;
    return p;
}

void board::clear() noexcept {
    for (auto& row : board) {
        for (auto& col : row) {
            col = piece{piece_type::blank, piece_color::white};
        }
    }
}

void board::initial_position() noexcept {
    this->clear();

    constexpr std::array<piece, board_size> initial_row = {
        piece{piece_type::rook,   piece_color::white},
        piece{piece_type::knight, piece_color::white},
        piece{piece_type::bishop, piece_color::white},
        piece{piece_type::queen,  piece_color::white},
        piece{piece_type::king,   piece_color::white},
        piece{piece_type::bishop, piece_color::white},
        piece{piece_type::knight, piece_color::white},
        piece{piece_type::rook,   piece_color::white}
    };

    board[0] = initial_row;
    for (auto& col : board[0]) {
        col.color = piece_color::black;
    }

    for (auto& col : board[1]) {
        col = piece{piece_type::pawn, piece_color::black};
    }

    board[board_size - 1] = initial_row;
    for (auto& col : board[board_size - 1]) {
        col.color = piece_color::white;
    }

    for (auto& col : board[board_size - 2]) {
        col = piece{piece_type::pawn, piece_color::white};
    }
}
