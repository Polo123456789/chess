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
            col = piece{piece_type_t::blank, color_t::white};
        }
    }
}

void board::initial_position() noexcept {
    this->clear();

    constexpr std::array<piece, board_size> initial_row = {
        piece{piece_type_t::rook,   color_t::white},
        piece{piece_type_t::knight, color_t::white},
        piece{piece_type_t::bishop, color_t::white},
        piece{piece_type_t::queen,  color_t::white},
        piece{piece_type_t::king,   color_t::white},
        piece{piece_type_t::bishop, color_t::white},
        piece{piece_type_t::knight, color_t::white},
        piece{piece_type_t::rook,   color_t::white}
    };

    board[0] = initial_row;
    for (auto& col : board[0]) {
        col.color = color_t::black;
    }

    for (auto& col : board[1]) {
        col = piece{piece_type_t::pawn, color_t::black};
    }

    board[board_size - 1] = initial_row;
    for (auto& col : board[board_size - 1]) {
        col.color = color_t::white;
    }

    for (auto& col : board[board_size - 2]) {
        col = piece{piece_type_t::pawn, color_t::white};
    }
}
