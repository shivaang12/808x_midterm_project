/**
 * @file      obstacle_generator.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 *
 * This files implements the class Obstacle_generator.
 *
 */
#include <obstacle_generator.hpp>

Obstacle_generator::Obstacle_generator(void) : widht_(800), height_(600) {}

auto Obstacle_generator::get_height(void) -> int {
  return height_;
}

auto Obstacle_generator::get_width(void) -> int {
  return widht_;
}

auto Obstacle_generator::generate_obstacles(void) -> std::vector<int> {
  std::vector<int> obs_vec;
  obs_vec.push_back(0);
  return obs_vec;
}

auto Obstacle_generator::get_startpoint(void) -> std::pair<int, int> {
  return start_point_;
}

auto Obstacle_generator::get_goalpoint(void) -> std::pair<int, int> {
  return goal_point_;
}
