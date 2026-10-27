#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <iostream>
#include <sstream>
#include <fstream>

#include <string>
#include <unordered_map>
#include <array>
#include <vector>

#include <memory>

#include <raylib.h>
#include <raymath.h>

using std::shared_ptr;
using std::make_shared;

enum SceneName {TITLE, FIELD, BATTLE};
enum State {NORMAL, INVENTORY, MAP};

#endif
