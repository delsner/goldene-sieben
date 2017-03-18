cmake_minimum_required(VERSION 3.6)
project(goldene_sieben)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES card.cpp card.h color.cpp color.h player.cpp player.h game.cpp game.h ruleset.cpp ruleset.h draw.cpp draw.h card_collection.cpp card_collection.h test_card.cpp card_value.cpp card_value.h)
add_executable(goldene_sieben ${SOURCE_FILES})