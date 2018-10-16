/**
 * @file      bfs.hpp
 * @author    Shivang Patel
 * @copyright MIT license
 * @brief DESCRIPTION
 * Header file for the class Bfs. Bfs class implements a planning algorithm
 * BFS. Breadth First Search algorithm is used for traversing as well as
 * searching. It starts at root and explores all the neighbor nodes at
 * current depth before moving to next depth untill it finds the required
 * thing, or traverse to the goal point respectively.
 *
 */

#pragma once

#include <memory>
#include <utility>
#include <vector>

/**
 * @brief      Bfs class which is used to find stortest path possible
 * by using BFS algorithm.
 */
class Bfs {
 public:
  /**
   * @brief       A constructor sets width_, height_, start_point_ and
   *  goal_point_ vars of the class.
   *
   * @param[in]   width, height: width and height of the planned area.
   * 
   * @param[in]   start_point, goal_point: start_point and goal_point
   * of the algorithm
   *
   * @return      none: Return nothing.
   */
  Bfs(int width, int height, std::pair<int, int> start_point,
      std::pair<int, int> goal_point);
  /**
   * @brief       A constructor sets width_, height_, start_point_,
   *  goal_point_ vars and occupancy_matrix of the class.
   *
   * @param[in]   width, height: width and height of the planned area.
   * 
   * @param[in]   start_point, goal_point: start_point and goal_point
   * of the algorithm
   * 
   * @param[in]   occupancy_matrix: This var holds the information
   * of the area. Such as obstacle space or traversable space.
   *
   * @return      none: Return nothing.
   */
  Bfs(int width, int height, std::pair<int, int> start_point,
      std::pair<int, int> goal_point,
      std::shared_ptr<std::vector<int>> occupancy_matrix);
  /**
   * @brief       Sets the occupancy_matrix_ of the class.
   *
   * @param[in]   occupancy_matrix: This thing holds the information
   * of the area. Such as obstacle space or traversable space.
   *
   * @return      int: 0 for sucessful execution.
   */
  auto set_occmat(std::shared_ptr<std::vector<int>> occupancy_matrix) -> int;
  /**
   * @brief       Sets the width_ var of the class.
   *
   * @param[in]   width: width of the planned area.
   *
   * @return      void: Return nothing.
   */
  auto set_width(int width) -> void;
  /**
   * @brief       Getter method to retrive the width_ var of the class.
   *
   * @return      int: value of width_ var.
   */
  auto get_width(void) -> int;
  /**
   * @brief       Sets the height_ var of the class.
   *
   * @param[in]   height: height of the planned area.
   *
   * @return      void: Return nothing.
   */
  auto set_height(int height) -> void;
  /**
   * @brief       Getter method to retrive the height_ var of the class.
   *
   * @return      int: value of height_ var.
   */
  auto get_height(void) -> int;
  /**
   * @brief       Sets the start_point_ var of the class.
   *
   * @param[in]   start_point: start point for the BFS algorithm.
   *
   * @return      void: Return nothing.
   */
  auto set_startpoint(std::pair<int, int> start_point) -> void;
  /**
   * @brief       Getter method to retrive the start_point_ var of the class.
   *
   * @return      pair<int, int>: value of start_point_ var.
   */
  auto get_startpoint(void) -> std::pair<int, int>;
  /**
   * @brief       Sets the goal_point_ var of the class.
   *
   * @param[in]   goal_point: goal point for the BFS algorithm.
   *
   * @return      void: Return nothing.
   */
  auto set_goalpoint(std::pair<int, int> goal_point) -> void;
  /**
   * @brief       Getter method to retrive the goal_point_ var of the class.
   *
   * @return      pair<int, int>: value of goal_point_ var.
   */
  auto get_goalpoint(void) -> std::pair<int, int>;
  /**
   * @brief       This function provides the possible neighbors of param point.
   *
   * @param[in]   point: co-ordinate on the map.
   *
   * @return      vector<pair<int, int>: vector of pairs - co-ordinates.
   */
  auto get_next_point(std::pair<int, int> point)
      -> std::vector<std::pair<int, int>>;
  /**
   * @brief       This function will compute the shortest path acoording
   * to BFS algorithm.
   *
   * @return      vector<pair<int, int>: vector of pairs contains path in
   * order of co-ordinates.
   */
  auto startBfs(void) -> std::vector<std::pair<int, int>>;

 private:
  int width_;                         ///< width of the area
  int height_;                        ///< width of the area
  std::pair<int, int> start_point_;   ///< start point for the BFS algorithm
  std::pair<int, int> goal_point_;    ///< goal point for the BFS algorithm
  std::shared_ptr<std::vector<int>>
  occupancy_matrix_;                  ///< occupancy matrix constains info
                                      ///  about the obstacles in the space.
};
