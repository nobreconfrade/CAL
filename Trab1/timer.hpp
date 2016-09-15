#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

using std::chrono::time_point;
using std::chrono::high_resolution_clock;

class Timer {
private:
	const char* mName;
	time_point<high_resolution_clock> startTime;

public:
	Timer (const char* name);
	virtual ~Timer ();
};

#endif
