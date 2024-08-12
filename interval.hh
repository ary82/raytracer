#ifndef INTERVAL_H
#define INTERVAL_H

#include <cmath>

class interval {
public:
  double min, max;

  interval() : min(+INFINITY), max(-INFINITY) {} // Default interval is empty

  interval(double min, double max) : min(min), max(max) {}

  double size() const { return max - min; }

  bool contains(double x) const { return min <= x && x <= max; }

  bool surrounds(double x) const { return min < x && x < max; }

  static const interval empty, universe;
};

inline const interval interval::empty = interval(+INFINITY, -INFINITY);
inline const interval interval::universe = interval(-INFINITY, +INFINITY);

#endif // !INTERVAL_H
