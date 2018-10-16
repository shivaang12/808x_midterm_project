# Breadth First Search (BFS)
[![Build Status](https://travis-ci.org/shivaang12/808x_midterm_project.svg?branch=master)](https://travis-ci.org/shivaang12/808x_midterm_project)
[![Coverage Status](https://coveralls.io/repos/github/shivaang12/808x_midterm_project/badge.svg?branch=master)](https://coveralls.io/github/shivaang12/808x_midterm_project?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Overview
A basic planner module for any traversable vehicle by Acme Robotics. Acme's high level planner sometimes need local planner for estimating feasible paths for the robot. This planner, given the information of the environment, starting point and goal point, will provide feasible path from start point to goal point. It will executes Breath First Search algorithm to find feasible path between start point and goal point. More details can be found below.

## Dependencies 
To build and run this module successfully, following dependencies should be met:
* CMake version at least 3.2.1
* SDL 2.0.8 or higher: To download and build the library, please follow the instructions 
```
curl -L https://www.libsdl.org/release/SDL2-2.0.8.tar.gz | tar xz cd SDL2-2.0.8
./configure
make
sudo make install
```
* For unit testing, this project depends on *gtest* framework by Google.

## Instructions to build the module
```
git clone --recursive https://github.com/shivaang12/808x_midterm_project
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Algorithm
Breath First Search algorithm is essentially a search algorithm. It is mostly used for traversing in robotics. Algorithm intitally start from a start point by adding to a priority queue. Then it explores each node from a priority queue to its child and adds to to a priority queue till it encounters goal point. In between, algorithm links each node to its respective childs. If it encounters goal point during exploration, then this links will be used to link back to start point. This will be the feasible path from start point to goal point generated using BFS algorithm.

## Output
Given the start point -> (0, 599) and goal point -> (799, 0), below is the output figure.
| Output Image |
| ------------- |
| <img src="https://github.com/nr-parikh/acme_robotics_perception_module/data/output.png" width="500"> |

## Singular Iterative Process (SIP)

SIP process charts for this project can be found [here](https://docs.google.com/spreadsheets/d/1IbgtYZAE8amdw-byhspCRRnXf8tBoE707xSWsrF4pjw/edit?usp=sharing).