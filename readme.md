# Breadth First Search (BFS)
[![Build Status](https://travis-ci.org/shivaang12/808x_midterm_project.svg?branch=master)](https://travis-ci.org/shivaang12/808x_midterm_project)
[![Coverage Status](https://coveralls.io/repos/github/shivaang12/808x_midterm_project/badge.svg?branch=master)](https://coveralls.io/github/shivaang12/808x_midterm_project?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Algorithm
BFS, Breadth First Search, is one of the search algorithm used in planning.

## Standard install via command-line
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

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Singular Iterative Process (SIP)

SIP process charts for this project can be found [here](https://docs.google.com/spreadsheets/d/1IbgtYZAE8amdw-byhspCRRnXf8tBoE707xSWsrF4pjw/edit?usp=sharing).