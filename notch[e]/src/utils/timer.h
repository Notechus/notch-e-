#pragma once
#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <Windows.h>

namespace notche
{
	class Timer
	{
	private:
		LARGE_INTEGER start;
		double frequency;
	public:
		Timer()
		{
			LARGE_INTEGER frequency_;
			QueryPerformanceFrequency(&frequency_);
			frequency = 1.0 / frequency_.QuadPart;
			QueryPerformanceCounter(&start);
		}

		void reset()
		{
			QueryPerformanceCounter(&start);
		}

		float elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - start.QuadPart;
			//start = current;

			return (float) (cycles * frequency);
		}

		float time()
		{
			/*
			if (start == 0)
			{
			QueryPerformanceCounter((LARGE_INTEGER*) &start);
			QueryPerformanceFrequency((LARGE_INTEGER*) &frequency);
			return 0.0f;
			}

			__int64 counter = 0;
			QueryPerformanceCounter((LARGE_INTEGER*) &counter);
			return (float) ((counter - start) / double(frequency));
			*/
		}
	};
}

#endif