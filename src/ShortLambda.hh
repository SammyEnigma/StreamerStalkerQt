#pragma once

#define SL1(expr) [&](auto&& a){ return expr; }
#define SL2(expr) [&](auto&& a, auto&& b){ return expr; }
#define SL3(expr) [&](auto&& a, auto&& b, auto&& c){ return expr; }
#define SL4(expr) [&](auto&& a, auto&& b, auto&& c, auto&& d){ return expr; }
