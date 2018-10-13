/**
 * @file      sdl_wrapper.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 *
 * This files implements the class Sdl_wrapper.
 *
 */

#include <sdl_wrapper.hpp>

Sdl_wrapper::Sdl_wrapper(int width, int height)
    : width_(width), height_(height) {}

Sdl_wrapper::Sdl_wrapper(
    int width, int height,
    std::shared_ptr<std::vector<int>> obstacle_ptr)
    : width_(width), height_(height), obstacle_ptr_(obstacle_ptr) {}

auto Sdl_wrapper::set_width(int width) -> void { width_ = width; }

auto Sdl_wrapper::get_width(void) -> int { return width_; }

auto Sdl_wrapper::set_height(int height) -> void { height_ = height; }

auto Sdl_wrapper::get_height(void) -> int { return height_; }

auto Sdl_wrapper::event_handler(void) -> int { return 0; }

auto Sdl_wrapper::update_screen(void) -> int { return 0; }

auto Sdl_wrapper::clean(void) -> int { return 0; }

auto Sdl_wrapper::call_delay(int delay) -> int { return 0; }

auto Sdl_wrapper::draw_point(std::pair<int, int> point) -> int { return 0; }

auto Sdl_wrapper::set_obstacle_ptr(
    std::shared_ptr<std::vector<int>> obstacle_ptr) -> int {
  return 0;
}
