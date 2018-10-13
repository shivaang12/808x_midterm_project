/**
 * @file      bfs.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * This file implements Bfs class.
 *
 */

#include <bfs.hpp>

Bfs::Bfs(int width, int height, std::pair<int, int> start_point,
         std::pair<int, int> goal_point)
    : width_(width), height_(height), start_point_(start_point),
      goal_point_(goal_point) {}

Bfs::Bfs(int width, int height, std::pair<int, int> start_point,
         std::pair<int, int> goal_point,
         std::shared_ptr<std::vector<int>> occupancy_matrix)
    : width_(width), height_(height), start_point_(start_point),
      goal_point_(goal_point), occupancy_matrix_(occupancy_matrix) {}

auto Bfs::set_occmat(std::shared_ptr<std::vector<int>> occupancy_matrix)
    -> int {
  occupancy_matrix_ = occupancy_matrix;

  return 0;
}

auto Bfs::set_width(int width) -> void { width_ = width; }

auto Bfs::get_width(void) -> int { return width_ ;}

auto Bfs::set_height(int height) -> void { height_ = height; }

auto Bfs::get_height(void) -> int { return height_ ;}

auto Bfs::set_startpoint(std::pair<int, int> start_point) -> void {
  start_point_ = start_point;
}

auto Bfs::get_startpoint(void) -> std::pair<int, int> {
  return start_point_;
}

auto Bfs::set_goalpoint(std::pair<int, int> goal_point) -> void {
  goal_point_ = goal_point;
}

auto Bfs::get_goalpoint(void) -> std::pair<int, int> {
  return goal_point_;
}

auto Bfs::get_next_point(std::pair<int, int> point)
    -> std::vector<std::pair<int, int>> {
  std::vector<std::pair<int, int>> return_variable;
  return_variable.emplace_back(point);
  return return_variable;
}

auto Bfs::startBfs() -> std::vector<std::pair<int, int>> {
  std::vector<std::pair<int, int>> return_variable;
  return_variable.emplace_back(0, 0);
  return return_variable;
}