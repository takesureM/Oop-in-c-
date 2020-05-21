#include <iostream>
#include <string>
using namespace std;

struct Route{
	int Number;
	double Duration;
	int Frequency;
	string Stops[10];
	int countStops;
};

void DemoRoute();
void ReadRouteFromConsole(Route& route);
void WriteRouteToConsole(Route& route);
int FindRouteTo(Route* routes, int routeCount, string stop);