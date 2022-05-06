#include <iostream>

struct Point
{
    int x, y;
};

struct Segment
{
    Point first, second;

    bool haveCross = false;
};

bool Cross(Segment s1, Segment s2)
{
    double Ua, Ub, numerator_a, numerator_b, denominator;

    denominator = (s2.second.y - s2.first.y) * (s1.first.x - s1.second.x) - (s2.second.x - s2.first.x) * (s1.first.y - s1.second.y);

    if (denominator == 0)
    {
        if ((s1.first.x * s1.second.y - s1.second.x * s1.first.y) * (s2.second.x - s2.first.x) - (s2.first.x * s2.second.y - s2.first.y * s2.first.y) * (s1.second.x - s1.first.x) == 0 && (s1.first.x * s1.second.y - s1.second.x * s1.first.y) * (s2.second.y - s2.first.y) - (s2.first.x * s2.second.y - s2.first.y * s2.first.y) * (s1.second.y - s1.first.y) == 0)
            return true;
        else
           return false;
    }
    else
    {
        numerator_a = (s2.second.x - s1.second.x) * (s2.second.y - s2.first.y) - (s2.second.x - s2.first.x) * (s2.second.y - s2.first.y);
        numerator_b = (s1.first.x - s1.second.x) * (s2.second.y - s2.first.y) - (s2.second.x - s1.second.x) * (s1.first.y - s1.second.y);
        Ua = numerator_a / denominator;
        Ub = numerator_b / denominator;

        return (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? true : false);
    }
}