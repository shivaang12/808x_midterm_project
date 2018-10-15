/**
 * @file      test_sdl.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * Testing file for the Camera class.
 */

#include <gtest/gtest.h>
#include <bfs.hpp>
#include <obstacle_generator.hpp>

/**
 * @brief     1st Constructor test, cheaking the assignments
 */
TEST(testBfs, constructorTest1) {
  Bfs bfs(10, 10, std::make_pair(0, 10), std::make_pair(10, 0));
  EXPECT_EQ(bfs.get_width(), 10);
  EXPECT_EQ(bfs.get_height(), 10);
  EXPECT_EQ(bfs.get_startpoint().first, 0);
  EXPECT_EQ(bfs.get_startpoint().second, 10);
  EXPECT_EQ(bfs.get_goalpoint().first, 10);
  EXPECT_EQ(bfs.get_goalpoint().second, 0);
}

/**
 * @brief     2nd Constructor test, cheaking the assignments
 */
TEST(testBfs, constructorTest2) {
  std::vector<int> occ_mat;
  auto occShared_ptr =
      std::make_shared<std::vector<int>>(std::move(occ_mat));
  occShared_ptr->push_back(0);
  Bfs bfs(10, 10, std::make_pair(0, 10), std::make_pair(10, 0), occShared_ptr);
  EXPECT_EQ(bfs.get_width(), 10);
  EXPECT_EQ(bfs.get_height(), 10);
  EXPECT_EQ(bfs.get_startpoint().first, 0);
  EXPECT_EQ(bfs.get_startpoint().second, 10);
  EXPECT_EQ(bfs.get_goalpoint().first, 10);
  EXPECT_EQ(bfs.get_goalpoint().second, 0);
}
/**
 * @brief     Testing Getter and Setter methods.
 */
TEST(testBfs, getterSetterTest) {
  Bfs bfs(10, 10, std::make_pair(0, 10), std::make_pair(10, 0));
  bfs.set_width(10);
  bfs.set_height(10);
  bfs.set_startpoint(std::make_pair(0, 10));
  bfs.set_goalpoint(std::make_pair(10, 0));
  EXPECT_EQ(bfs.get_width(), 10);
  EXPECT_EQ(bfs.get_height(), 10);
  EXPECT_EQ(bfs.get_startpoint().first, 0);
  EXPECT_EQ(bfs.get_startpoint().second, 10);
  EXPECT_EQ(bfs.get_goalpoint().first, 10);
  EXPECT_EQ(bfs.get_goalpoint().second, 0);
}
/**
 * @brief     Testing get_next_point, which returns neighbors
 * regardless of obstacles.
 */
TEST(testBfs, nextPointTest) {
  std::vector<int> occ_mat;
  occ_mat.push_back(0);
  auto occShared_ptr =
      std::make_shared<std::vector<int>>(std::move(occ_mat));
  Bfs bfs(11, 11, std::make_pair(0, 10), std::make_pair(10, 0), occShared_ptr);
  auto container = bfs.get_next_point(std::make_pair(1, 1));
  std::vector<std::pair<int, int>>::iterator it;
  it = find(container.begin(), container.end(), std::make_pair(0, 0));
  int flag = 0;
  if (it != container.end()) {
    flag = 1;
  }
  EXPECT_EQ(flag, 1);
}
/**
 * @brief     Testing main startBfs method which implements original
 * algorithm. The returning vector must contains start and end points.
 */
TEST(testBfs, startBfsTest) {
  std::vector<int> occ_mat;
  occ_mat.push_back(0);
  auto occShared_ptr =
      std::make_shared<std::vector<int>>(std::move(occ_mat));
  Bfs bfs(11, 11, std::make_pair(0, 10), std::make_pair(10, 0), occShared_ptr);
  auto container = bfs.startBfs();
  std::vector<std::pair<int, int>>::iterator it;
  int flag1 = 0;
  int flag2 = 0;
  it = find(container.begin(), container.end(), std::make_pair(0, 10));
  if (it != container.end()) {
    flag1 = 1;
  }
  it = find(container.begin(), container.end(), std::make_pair(10, 0));
  if (it != container.end()) {
    flag2 = 1;
  }
  EXPECT_EQ(flag1, 1);
  EXPECT_EQ(flag2, 1);
}
/**
 * @brief     Final test. Testing with real obstacle matrix.
 */
TEST(testBfs, realTesting) {
  Obstacle_generator obs;
  auto occShared_ptr =
      std::make_shared<std::vector<int>>(std::move(obs.get_obstacle_space()));
  Bfs bfs(obs.get_width(), obs.get_height(), obs.get_startpoint(),
      obs.get_goalpoint());
  bfs.set_occmat(occShared_ptr);
  auto container = bfs.startBfs();
  std::vector<std::pair<int, int>>::iterator it;
  int flag1 = 0;
  int flag2 = 0;
  it = find(container.begin(), container.end(), obs.get_startpoint());
  if (it != container.end()) {
    flag1 = 1;
  }
  it = find(container.begin(), container.end(), obs.get_goalpoint());
  if (it != container.end()) {
    flag2 = 1;
  }
  EXPECT_EQ(flag1, 1);
  EXPECT_EQ(flag2, 1);
}
