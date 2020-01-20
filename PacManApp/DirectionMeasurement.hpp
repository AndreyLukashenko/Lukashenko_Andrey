#ifndef DIRECTION_MEASUREMENT_H
#define DIRECTION_MEASUREMENT_H

#include <vector>
#include <algorithm>

#include "Constants.hpp"
#include "Ghost.hpp"

class DirectionMeasurement
{
public:
    DirectionMeasurement() = default;
    DirectionMeasurement(const DirectionMeasurement&) = delete;
    DirectionMeasurement& operator=(const DirectionMeasurement&) = delete;
    ~DirectionMeasurement() = default;

    std::vector<Direction> computePossibleDirections(const Ghost& ghost) const;
    double computeDistance(const CoordinatesXY& startPoint, const CoordinatesXY& endPoint) const;
    Direction computePreferenceDirection(const CoordinatesXY& ghost, const CoordinatesXY& target, const std::vector<Direction>& possibleDirections) const;
    CoordinatesXY computeTargetPoint(const Direction direction, const CoordinatesXY& ghost, int offset) const;
};

#endif // !DIRECTION_MEASUREMENT_H



