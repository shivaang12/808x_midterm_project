/**
 * @file      test_obstacle.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * Testing file for the Obstacle_generator class.
 */
#include <gtest/gtest.h>
#include <obstacle_generator.hpp>
/**
 * @brief     A general test, for testing all the methods of the class.
 */
TEST(testObstacleClass, allVarTest) {
  Obstacle_generator obs(std::make_pair(0, 0), std::make_pair(799, 0), true);
  EXPECT_GE(obs.get_height(), 0);
  EXPECT_GE(obs.get_width(), 0);
  EXPECT_GE(obs.get_goalpoint().first, 0);
  EXPECT_GE(obs.get_startpoint().second, 0);
}
/**
 * @brief     A general test, for testing all the methods of the class.
 */
TEST(testObstacleClass, loopTest) {
  Obstacle_generator obs;
  obs.generate_obstacles();
  obs.run_bfs();
  obs.run_sdl();
  EXPECT_EQ(obs.get_height(), 600);
}
