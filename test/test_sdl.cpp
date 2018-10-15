/**
 * @file      test_sdl.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * Testing file for the Sdl_wrapper class.
 */
#include <gtest/gtest.h>
#include <sdl_wrapper.hpp>

/**
 * @brief     1st Constructor test, cheaking the assignments
 */
TEST(testSdl, constructorTest1) {
  int height = 10;
  int width = 10;
  Sdl_wrapper sdl(width, height);
  EXPECT_EQ(sdl.get_width(), 10);
  EXPECT_EQ(sdl.get_height(), 10);
}
/**
 * @brief     Individual assignment checking of width
 * height and obstacle ptr.
 */
TEST(testSdl, IndividualAssignment) {
  int height = 10;
  int width = 10;
  std::vector<int> occ_mat;
  auto occShared_ptr =
      std::make_shared<std::vector<int>>(std::move(occ_mat));
  occ_mat.push_back(0);
  Sdl_wrapper sdl(width, height);
  sdl.set_height(100);
  sdl.set_width(100);
  EXPECT_EQ(sdl.get_width(), 100);
  EXPECT_EQ(sdl.get_height(), 100);
}
/**
 * @brief     Testing SDL utilities functionality.
 * 0 indicates failure of the assigned task and 1
 * means success. 
 */
TEST(testSdl, sdlUtilitiesTest) {
  int height = 10;
  int width = 10;
  int delay = 10;
  std::pair<int, int> point = {0, 0};
  Sdl_wrapper sdl(width, height);
  EXPECT_EQ(sdl.event_handler(), 0);
  EXPECT_EQ(sdl.update_screen(), 0);
  EXPECT_EQ(sdl.clean(), 0);
  EXPECT_EQ(sdl.call_delay(delay), 0);
  EXPECT_EQ(sdl.draw_point(point), 0);
  EXPECT_EQ(sdl.draw_point_path(point), 0);
  EXPECT_TRUE(sdl.check_polling_var());
}
/**
 * @brief     Testing event handler with polling variable.
 */
TEST(testSdl, pollingVarTest) {
  Sdl_wrapper sdl(10, 10);
  sdl.set_polling_var(false);
  sdl.event_handler();
  EXPECT_FALSE(sdl.check_polling_var());
}
