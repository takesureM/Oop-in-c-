#include "Route.h"
#define COUNT_ROUTES 3

void DemoRoute()
{
	Route routes[COUNT_ROUTES];
	for (int i = 0; i < COUNT_ROUTES; i++)
	{
		ReadRouteFromConsole(routes[i]);
	}

	for (int i = 0; i < COUNT_ROUTES; i++)
	{
		WriteRouteToConsole(routes[i]);
	}

	string stop;
	cout << "Enter stop: ";
	getline(cin, stop);

	int result = FindRouteTo(routes, COUNT_ROUTES, stop);

	if (result == -1)
	{
		cout << "There are no result found.";
	}
	else
	{
		WriteRouteToConsole(routes[result]);
	}
}

void ReadRouteFromConsole(Route& route)
{
	cout << "Enter number of the flight: ";
	cin >> route.Number;

	while (true)
	{
		cout << "Enter the duration of the flight: ";
		cin >> route.Duration;
		if (route.Duration > 0)
		{
			break;
		}
		cout << "The duration must be less than zero!. ";
		cout << "\n Please Enter again!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
	}

	while (true)
	{
		cout << "Enter the frequency: ";
		cin >> route.Frequency;
		if (route.Frequency > 0)
		{
			break;
		}
		cout << "Frequency must not be greater than zero! " << endl;
		cout << "\nPlease enter again!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
	}

	while (true)
	{
		cout << "Enter number of stops: " << endl;
		cin >> route.countStops;
		if (route.countStops > 0 && route.countStops <= 10)
		{
			break;
		}
		cout << "The number of stops must be between 1 to 10!" << endl;
		cout << "\nEnter again!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
	}
	cin.clear();
	cin.ignore(32767, '\0');
	for (int i = 0; i < route.countStops; i++)
	{
		cout << "Stop number :" << i << ": ";
		getline(cin, route.Stops[i]);
	}
}

void WriteRouteToConsole(Route& route)
{
	cout << "Flight n: " << route.Number << "Duration: "
		<< route.Duration << ", Frequency :" << route.Frequency << ", ";
	cout << "Number of stops: ";
	if (route.countStops > 1)
	{
		for (int i = 0; i < route.countStops-1; i++)
		{
			cout << route.Stops[i] << ", ";
		}
	}
	cout << route.Stops[route.countStops - 1] << ". ";
}

int FindRouteTo(Route* route, int routeCount, string stop)
{
	int index = -1;
	for (int i = 0; i < routeCount; i++)
	{
		for (int j = 0; j < route[i].countStops; j++)
		{
			if (stop == route[i].Stops[j])
			{
				index = i;
				break;
			}
		}
	}
	return index;
}