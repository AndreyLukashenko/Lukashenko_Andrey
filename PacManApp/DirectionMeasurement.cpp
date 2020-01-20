#include "DirectionMeasurement.hpp"


std::vector<Direction> DirectionMeasurement::computePossibleDirections(const Ghost& ghost) const
{
	std::vector<Direction> routes;

	if (Direction::UP != ghost.getDirectionOpposite())
		if (ghost.isCollisionUp())
			routes.push_back(Direction::UP);

	if (Direction::RIGHT != ghost.getDirectionOpposite())
		if (ghost.isCollisionRight())
			routes.push_back(Direction::RIGHT);

	if (Direction::DOWN != ghost.getDirectionOpposite())
		if (ghost.isCollisionDown())
			routes.push_back(Direction::DOWN);

	if (Direction::LEFT != ghost.getDirectionOpposite())
		if (ghost.isCollisionLeft())
			routes.push_back(Direction::LEFT);

	return routes;
}


double DirectionMeasurement::computeDistance(const CoordinatesXY& ghost, const CoordinatesXY& target) const
{
	CoordinatesXY difference = { ghost.x - target.x, ghost.y - target.y };

	return sqrt((difference.x * difference.x) + (difference.y * difference.y));
}


Direction DirectionMeasurement::computePreferenceDirection(const CoordinatesXY& ghost, const CoordinatesXY& target, const std::vector<Direction>& possibleDirections) const
{
	std::vector<double> distances;
	double distance = 0;

	for (Direction direction : possibleDirections)
	{
		switch (direction)
		{
		case Direction::UP:
			distance = computeDistance({ ghost.x, ghost.y - 1 }, target);
			distances.push_back(distance);
			break;
		case Direction::RIGHT:
			distance = computeDistance({ ghost.x + 1, ghost.y }, target);
			distances.push_back(distance);
			break;
		case Direction::DOWN:
			distance = computeDistance({ ghost.x, ghost.y + 1 }, target);
			distances.push_back(distance);
			break;
		case Direction::LEFT:
			distance = computeDistance({ ghost.x - 1, ghost.y }, target);
			distances.push_back(distance);
			break;
		}
	}

	int minDistanceIndex = std::min_element(distances.begin(), distances.end()) - distances.begin();
	
	return possibleDirections[minDistanceIndex];
}


CoordinatesXY DirectionMeasurement::computeTargetPoint(const Direction direction, const CoordinatesXY& ghost, int offset) const
{
	CoordinatesXY point;

	switch (direction)
	{
	case Direction::UP:
		point = { ghost.x, ghost.y - offset };
		break;
	case Direction::LEFT:
		point = { ghost.x - offset, ghost.y };
		break;
	case Direction::DOWN:
		point = { ghost.x, ghost.y + offset };
		break;
	case Direction::RIGHT:
		point = { ghost.x + offset, ghost.y };
		break;
	default:
		break;
	}

	return point;
}