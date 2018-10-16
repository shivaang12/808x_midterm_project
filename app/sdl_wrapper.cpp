/**
 * @file      sdl_wrapper.cpp
 * @author    Shivang Patel
 * @copyright MIT license
 *
 * @brief DESCRIPTION
 * This files implements the class Sdl_wrapper.
 *
 */

#include <sdl_wrapper.hpp>

Sdl_wrapper::Sdl_wrapper(int width, int height)
    : width_(width), height_(height), isPolling_(true) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(width_, height_, 0, &window_, &renderer_);
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
  SDL_RenderClear(renderer_);
  SDL_RenderPresent(renderer_);
}

auto Sdl_wrapper::set_width(int width) -> void { width_ = width; }

auto Sdl_wrapper::get_width(void) -> int { return width_; }

auto Sdl_wrapper::set_height(int height) -> void { height_ = height; }

auto Sdl_wrapper::get_height(void) -> int { return height_; }

auto Sdl_wrapper::event_handler(void) -> int {
  SDL_Event event;         // Creating event variable.
  SDL_PollEvent(&event);   // Poll event, if any.
  if (event.type == SDL_QUIT) {
    isPolling_ = false;    // Make the isPolling_ flase.
  }
  return 0;                // Conformation of execution.
}

auto Sdl_wrapper::update_screen(void) -> int {
  SDL_RenderPresent(
      renderer_);           // Updating the screen.
  return 0;
}

auto Sdl_wrapper::clean(void) -> int {
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
  SDL_RenderClear(
      renderer_);           // Clear the screen.
  return 0;
}

auto Sdl_wrapper::call_delay(int delay) -> int {
  SDL_Delay(delay);         // Delay.
  return 0;
}

auto Sdl_wrapper::draw_point(std::pair<int, int> point) -> int {
  SDL_SetRenderDrawColor(renderer_,
      255, 0, 0, 255);      // Set color Red.
  SDL_RenderDrawPoint(
    renderer_,
    point.first,
    point.second);          // Draw point at passed coordinate.
  return 0;
}

auto Sdl_wrapper::draw_point_path(std::pair<int, int> point) -> int {
  SDL_SetRenderDrawColor(
      renderer_,
      0, 255,
      0, 255);               // Set color Green.
  SDL_RenderDrawPoint(
      renderer_,
      point.first,
      point.second);          // Draw point.
  return 0;
}

auto Sdl_wrapper::check_polling_var(void) -> bool { return isPolling_; }

auto Sdl_wrapper::set_polling_var(bool state) -> void { isPolling_ = state; }
