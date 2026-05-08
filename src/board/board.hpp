#ifndef BOARD_BOARD_HPP
#define BOARD_BOARD_HPP

#pragma once

#include <array>
#include <cstdint>
#include <cstddef>

constexpr size_t board_size = 8;

enum class piece_type : uint8_t {
    blank,
    king,
    queen,
    rook,
    bishop,
    knight,
    pawn
};

enum class piece_color : uint8_t {
    white,
    black
};

struct position {
    size_t col;
    size_t row;
};

struct piece {
    piece_type type;
    piece_color color;
};

using internal_board_t = std::array<std::array<piece, board_size>, board_size>;

struct board {
    static constexpr size_t size = board_size;

    [[nodiscard]] piece get(position p) const;
    piece set(position pos, piece p);

    void clear() noexcept;
    void initial_position() noexcept;

    internal_board_t board;
    piece_color turn = piece_color::white;
    uint64_t moves_without_capture_or_pawn_move = 0;
};

#endif // BOARD_BOARD_HPP
