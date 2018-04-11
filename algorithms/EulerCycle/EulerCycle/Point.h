#pragma once
struct Point
{
	int v1;
	int v2;
	bool operator ==(const Point & rhs)
	{
		return((v1 == rhs.v1) && (v2 == rhs.v2));
	}
	bool operator !=(const Point & rhs)
	{
		return !(*this == rhs);
	}
};
inline bool operator< (const Point& p1, const Point& p2)
{
	if (p1.v1 < p2.v1) return true;
	if((p1.v1 == p2.v1)&&(p1.v2 < p2.v2)) return true;
	return false;
}
