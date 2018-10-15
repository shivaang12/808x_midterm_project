/**
 * @file      obstacle_generator.hpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * This class will artificially generate obstacle, throught methods,
 * for BFS algorithm. This class will act as Acme's high level planner's
 * input to Bfs module.
 *
 */
#pragma once

#include <memory>
#include <utility>
#include <vector>

/**
 * @brief      This class will mimic the Acme's high level planner's
 * input to Bfs module. This class will provide the hight and width of
 * the area, obstacle space and start - goal points.
 */
class Obstacle_generator {
 public:
  /**
   * @brief       A constructor sets width_ and height_ vars of the class.
   *
   * @return      Return nothing.
   */
  Obstacle_generator(void);
  /**
   * @brief       A constructor sets start point, goal point and debug flag
   * vars of the class.
   * 
   * @param[in]   start_point, goal_point: Start and goal point for BFS.
   * 
   * @param[in]   debug: true for debug, false for not debug.
   *
   * @return      Return nothing.
   */
  Obstacle_generator(std::pair<int, int> start_point,
      std::pair<int, int> goal_point, bool debug);
  /**
   * @brief       This method will generate obstacle artificially.
   *
   * @return      void: vector of 1's and 0's, 1 being obstacle and
   * 0 will be traversable space.
   */
  auto generate_obstacles(void) -> void;
  /**
   * @brief       Getter method to get the
   * height_ var of the class.
   *
   * @return      int: value of height_ var.
   */
  auto get_height(void) -> int;
  /**
   * @brief       Getter method to get the
   * width_ var of the class.
   *
   * @return      int: value of width_ var.
   */
  auto get_width() -> int;
  /**
   * @brief       Getter method to retrive the start_point_ var of the class.
   *
   * @return      pair<int, int>: value of start_point_ var.
   */
  auto get_startpoint(void) -> std::pair<int, int>;
  /**
   * @brief       Getter method to retrive the goal_point_ var of the class.
   *
   * @return      pair<int, int>: value of goal_point_ var.
   */
  auto get_goalpoint(void) -> std::pair<int, int>;
  /**
   * @brief       This function will handle Bfs object.
   * 
   * @return      void: none.
   */
  auto run_bfs(void) -> void;
  /**
   * @brief       This function will handle Sdl_wrapper object.
   * 
   * @return      void: none.
   */
  auto run_sdl(void) -> void;
  /**
   * @brief       This function will provide euclidean distace.
   * 
   * @param[in]   x1, x2, y1, y2: point (x1, y1) and (x2, y2)
   * 
   * @return      double: eucliean distance  
   */
  auto calculate_euclidean_dist(int x1, int y1, int x2,
                                                  int y2) -> double;
  /**
   * @brief       This function will return class var obstacle_space_.
   * 
   * @return      vector<int>: Occupancy Matrix.  
   */
  auto get_obstacle_space(void) -> std::vector<int>;

 private:
  int widht_;                         ///> Width of the operated area.
  int height_;                        ///> Height of the operated area
  std::vector<int> obstacle_space_;   ///> Obstacle space (occupancy matrix)
                                      ///  of the operated area.
  std::vector<std::pair<int,
    int>> obstacle_info_;
  std::pair<int, int> start_point_;   ///> Start point for the algorithm.
  std::pair<int, int> goal_point_;    ///> goal point for the algorithm.
  std::vector<std::pair<int,
    int>> path_container_;            ///> This variable will contain path
                                      ///   returned from run_bfs method.
  bool debug_;                        ///> Debug flag for explicit debugging.
};
