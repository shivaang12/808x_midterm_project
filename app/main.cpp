/**
 * @file      main.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * This files is the main file which creates
 * object of Obstacle_generator class.
 *
 */
#include <iostream>
#include <obstacle_generator.hpp>

int main() {
  Obstacle_generator obs(std::make_pair(0, 599),
      std::make_pair(799, 0), true);            // Making object.
  obs.generate_obstacles();                     // Creating obstacle.
  obs.run_bfs();                                // BFS
  obs.run_sdl();                                // Showing the outpur.
}
