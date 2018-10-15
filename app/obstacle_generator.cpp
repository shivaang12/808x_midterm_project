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
#include <iostream>
#include <cmath>
#include <bfs.hpp>
#include <obstacle_generator.hpp>
#include <sdl_wrapper.hpp>

Obstacle_generator::Obstacle_generator(void)
    : widht_(800), height_(600), obstacle_space_(height_ * widht_, 0),
      start_point_(std::make_pair(0, 0)),
      goal_point_(std::make_pair(799, 599)),
      debug_(false) {}

Obstacle_generator::Obstacle_generator(std::pair<int, int> start_point,
      std::pair<int, int> goal_point, bool debug)
    : widht_(800), height_(600), obstacle_space_(height_ * widht_, 0),
      start_point_(start_point),
      goal_point_(goal_point),
      debug_(debug) {}

auto Obstacle_generator::get_height(void) -> int { return height_; }

auto Obstacle_generator::get_width(void) -> int { return widht_; }

auto Obstacle_generator::generate_obstacles(void) -> void {
  int rectangle_center_x = 600;   // Rectangle center's x coordinate.
  int rectangle_center_y = 400;   // Rectangle center's y coordinate.
  int rectangle_span = 100;       // Span of Rectangle in all direction.

  for (int i = rectangle_center_x - rectangle_span;
       i < rectangle_center_x + rectangle_span; i++) {
    for (int j = rectangle_center_y - rectangle_span;
         j < rectangle_center_y + rectangle_span; j++) {
      obstacle_space_[(j * widht_) + i] = 1;      // updating the matrix
                                            // elements to 1 if in obstacle.
    }
  }

  int circle_center_x = 212;    // Circle's center's x coordinate.
  int circle_center_y = 250;    // Circle's center's y coordinate.
  int circle_rad = 100;         // Circle's radius.

  for (int i = circle_center_x - circle_rad; i < circle_center_x + circle_rad;
       i++) {
    for (int j = circle_center_y - circle_rad; j < circle_center_y + circle_rad;
         j++) {
      if (calculate_euclidean_dist(circle_center_x, circle_center_y, i, j) <=
          circle_rad) {
        obstacle_space_[(j * widht_) + i] = 1;    // updating the matrix
                                            // elements to 1 if in obstacle.
      }
    }
  }
  /**
   * @brief     Storing all the obstacle pairs (coordinates) into vector.
   */
  for (int i = 0; i < widht_; i++) {
    for (int j = 0; j < height_; j++) {
      if (obstacle_space_[(j * widht_) + i] == 1) {
        obstacle_info_.emplace_back(i, j);
      }
    }
  }
}

auto Obstacle_generator::get_startpoint(void) -> std::pair<int, int> {
  return start_point_;
}

auto Obstacle_generator::get_goalpoint(void) -> std::pair<int, int> {
  return goal_point_;
}

auto Obstacle_generator::calculate_euclidean_dist(int x1, int y1, int x2,
                                                  int y2) -> double {
  return std::sqrt(std::pow(x1 - x2, 2) +
    std::pow(y1 - y2, 2));        // Returns norm of points (x1, y1) & (x2, y2).
}

auto Obstacle_generator::run_bfs(void) -> void {
  auto obsInfoPtr =
      std::make_shared<std::vector<int>>
      (std::move(obstacle_space_));     // Creating Shared ptr.
  Bfs bfs(widht_, height_, start_point_,
      goal_point_, obsInfoPtr);         // Creating Bfs object.
  path_container_ = bfs.startBfs();     // Storing path to class variable.
}

auto Obstacle_generator::run_sdl(void) -> void {
  Sdl_wrapper one(widht_, height_);     // Initializing object.
  one.clean();                          // Cleaning window black.
  for (auto &i : obstacle_info_) {
    one.draw_point(i);                  // Drawing all the points
                                        // which are obstacle.
  }
  for (auto &i : path_container_) {
    one.draw_point_path(i);             // Drawing path.
    one.call_delay(0);                  // Calling delay.
  }
    one.update_screen();                // Updating the screen for display.
    one.set_polling_var(debug_);
    do {
    one.event_handler();                // Calling Event Handler.
    one.call_delay(0);                  // Calling delay.
  } while (one.check_polling_var());     // Polling variable.
}

auto Obstacle_generator::get_obstacle_space(void) -> std::vector<int> {
    return obstacle_space_;
  }
