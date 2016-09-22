#include "timer.hpp"
#include <iostream>
#include <chrono>

using namespace std;

using std::chrono::duration;

Timer::Timer(const char* name) {
	this->mName = name;
	startTime = high_resolution_clock::now();
}

Timer::~Timer() {
	auto endTime = high_resolution_clock::now();
	duration<float> elapsedTime = endTime - startTime;

	cout << mName << ": " << elapsedTime.count() << "s" << endl;
}
