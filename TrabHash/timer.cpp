#include "timer.hpp"
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <fstream>

using namespace std;

using std::chrono::duration;

Timer::Timer(const char* name) {
	this->mName = name;
	startTime = high_resolution_clock::now();
}

Timer::~Timer() {
	auto endTime = high_resolution_clock::now();
	duration<float> elapsedTime = endTime - startTime;

	//cout << mName << ": " << elapsedTime.count() << endl;
	ofstream outfile;
	//outfile.open("Tempo-1.txt", std::ios::out | std::ios::app);
  	outfile.open("tempo5.txt", std::ios_base::app);
  	outfile << mName << ": " << elapsedTime.count() << endl;
}
