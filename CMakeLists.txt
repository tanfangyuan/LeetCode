cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)
add_executable(146-lru-cache leetcode/editor/cn/146-lru-cache.cpp)
add_executable(96-unique-binary-search-trees leetcode/editor/cn/96-unique-binary-search-trees.cpp)
add_executable(543-diameter-of-binary-tree leetcode/editor/cn/543-diameter-of-binary-tree.cpp)
add_executable(207-course-schedule leetcode/editor/cn/207-course-schedule.cpp)
add_executable(5-longest-palindromic-substring leetcode/editor/cn/5-longest-palindromic-substring.cpp)
add_executable(121-best-time-to-buy-and-sell-stock leetcode/editor/cn/121-best-time-to-buy-and-sell-stock.cpp)
add_executable(22-generate-parentheses leetcode/editor/cn/22-generate-parentheses.cpp)
add_executable(11-container-with-most-water leetcode/editor/cn/11-container-with-most-water.cpp)
add_executable(215-kth-largest-element-in-an-array leetcode/editor/cn/215-kth-largest-element-in-an-array.cpp)
add_executable(200-number-of-islands leetcode/editor/cn/200-number-of-islands.cpp)
add_executable(53-maximum-subarray leetcode/editor/cn/53-maximum-subarray.cpp)