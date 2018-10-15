/**
 * @file      bfs.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * This file implements Bfs class.
 *
 */

#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
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

auto Bfs::get_width(void) -> int { return width_; }

auto Bfs::set_height(int height) -> void { height_ = height; }

auto Bfs::get_height(void) -> int { return height_; }

auto Bfs::set_startpoint(std::pair<int, int> start_point) -> void {
  start_point_ = start_point;
}

auto Bfs::get_startpoint(void) -> std::pair<int, int> { return start_point_; }

auto Bfs::set_goalpoint(std::pair<int, int> goal_point) -> void {
  goal_point_ = goal_point;
}

auto Bfs::get_goalpoint(void) -> std::pair<int, int> { return goal_point_; }

auto Bfs::get_next_point(std::pair<int, int> point)
    -> std::vector<std::pair<int, int>> {
  std::vector<std::pair<int, int>> tempContainer;   ///> For Exploration
  tempContainer.reserve(8);

  std::vector<std::pair<int, int>>
      returnContainer;    ///> Removed obstacle co-ordinates from tempContainer
  returnContainer.reserve(8);

  int &x = point.first;     ///> Alis x for x co-ordinate of point
  int &y = point.second;    ///> Alis y for y co-ordinate of point

  /**
   * @brief               Finding possible neighbors of the var point
   * without any knowledge of obstacle.
   */
  if (((y - 1) >= 0)) {
    tempContainer.push_back(std::make_pair(x, (y - 1)));
  }
  if (((y - 1) >= 0) && ((x - 1) >= 0)) {
    tempContainer.push_back(std::make_pair(x - 1, (y - 1)));
  }
  if (((y - 1) >= 0) && ((x + 1) < width_)) {
    tempContainer.push_back(std::make_pair(x + 1, (y - 1)));
  }
  if (((y + 1) < height_) && ((x - 1) >= 0)) {
    tempContainer.push_back(std::make_pair(x - 1, (y + 1)));
  }
  if (((y + 1) < height_) && ((x + 1) < width_)) {
    tempContainer.push_back(std::make_pair(x + 1, (y + 1)));
  }
  if ((y + 1) < height_) {
    tempContainer.push_back(std::make_pair(x, (y + 1)));
  }
  if ((x + 1) < width_) {
    tempContainer.push_back(std::make_pair((x + 1), (y)));
  }
  if ((x - 1) >= 0) {
    tempContainer.push_back(std::make_pair(x - 1, (y)));
  }

  /**
   * @brief               Now the obtained neighbors are being checked for
   * obstacles.
   */
  int size = (*occupancy_matrix_).size();
  if (size >= (width_ * height_)) {
    for (auto &i : tempContainer) {
      if ((*occupancy_matrix_)[(i.second * width_) + i.first] < 1) {
        returnContainer.emplace_back(i);
      }
    }
  } else {
    returnContainer = tempContainer;
  }

  return returnContainer;
}

auto Bfs::startBfs() -> std::vector<std::pair<int, int>> {
  /**
   * @brief           Custom sorter for priority queue. 
   */
  struct cmp {
    bool operator()(const std::pair<std::pair<int, int>, double> &a,
                    const std::pair<std::pair<int, int>, double> &b) {
      return b.second < a.second;
    }
  };

  std::vector<std::pair<int, int>> vecContainer;

  auto& start = start_point_;         ///> Alias for start point
  auto& EndNode = goal_point_;        ///> Alias for Goal point

  std::priority_queue<std::pair<std::pair<int, int>, double>,
                      std::vector<std::pair<std::pair<int, int>, double>>, cmp>
      front;                          ///> for storing coordinates with
                                      ///  corresponding cost.

  front.push({start, 0});

  std::map<std::pair<int, int>,
    std::pair<int, int>> came_from;   ///> Parent-child relations.
  std::map<std::pair<int, int>,
    double> cost_so_far;              ///> Tracking cost.
  came_from[start] = start;
  /**
   * @brief          Below while loop explores node (co-ordinates) from start
   * point to end point.
   */
  while (!front.empty()) {
    auto current = front.top().first;   ///> Exploring the first element.
    front.pop();                        ///> removing that from queue.
    if (current == EndNode) {
      break;
    }
    /**
     * @brief        Below code expands the childs of parent "current" and
     * assigning cost them.
     */
    for (auto &next : get_next_point(current)) {
      auto new_cost = cost_so_far[current] + 1;
      if ((cost_so_far.find(next) == cost_so_far.end()) ||
          (new_cost < cost_so_far[next])) {
        cost_so_far[next] = new_cost;
        double prior =
            new_cost + (std::abs((next.first) - (next.second)) +
                        std::abs((EndNode.first) - (EndNode.second)));
        front.push({next, prior});
        came_from[next] = current;        ///> Assigning parent/child
      }
    }
  }
  auto count = EndNode;
  std::vector<std::pair<int, int>> returnVector;
  returnVector.push_back(count);
  /**
   * @brief         Tracing parent-child to generate path.
   */
  while (count != start) {
    count = came_from[count];
    returnVector.push_back(count);
  }
  std::reverse(returnVector.begin(),
    returnVector.end());                    ///> Reversing the path in order.
  return returnVector;
}
