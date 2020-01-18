#ifndef COORDINATES_XY_H
#define COORDINATES_XY_H

struct CoordinatesXY
{
	int x;
	int y;

	bool operator== (const CoordinatesXY& xy2) const
	{
		return (this->x == xy2.x && this->y == xy2.y);
	};

	bool operator!= (const CoordinatesXY& xy2) const
	{
		return !(*this == xy2);
	}
};

#endif // !COORDINATES_XY_H


