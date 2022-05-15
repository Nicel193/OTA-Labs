#include <iostream>
#include "Cross.cpp"

void FindCrossAllSegments(int segmentIndex, Segment *segments);

int main()
{
    srand(time(NULL));

    int N;

    std::cout << "Enter the number of pairs of points: ";
    std::cin >> N;

    if (1 >= N || N > 256)
    {
        std::cout << "Incorrect value: " << N << "\n";
        system("pause");
        return 0;
    }

    Point *points = new Point[N];
    Segment *segments = new Segment[N - 1];

    int segmentCounter = 0;

    for (int i = 0; i < N; i++)
    {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;

        if (i > 0)
        {
            segments[segmentCounter].first = points[i - 1];
            segments[segmentCounter].second = points[i];

            FindCrossAllSegments(segmentCounter, segments);

            segmentCounter++;
        }
    }

    for (int i = 0; i < (N - 1); i++)
    {
        std::cout << "Segment: " << (i + 1) << "\n";
        std::cout << (segments[i].haveCross ? "Have cross!" : "Not cross!") << "\n";
    }

    delete[] points;
    delete[] segments;

    system("pause");
}

void FindCrossAllSegments(int segmentIndex, Segment *segments)
{
    if (segmentIndex < 0)
    {
        return;
    }

    for (int i = 0; i < (segmentIndex - 1); i++)
    {
        segments[segmentIndex].haveCross = Cross(segments[i], segments[segmentIndex]);
    }
}