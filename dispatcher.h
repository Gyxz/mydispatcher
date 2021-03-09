/*
	dispatcher.h - header file for the Dispatcher class.
	
	Revision 0
	
	Notes:
			- 
			
	2016/11/19, Maya Posch
	(c) Nyanko.ws.
*/


#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "abstract_request.h"
#include "worker.h"

#include <queue>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;


class Dispatcher {
	static queue<unique_ptr<AbstractRequest>> requests;
	static queue<shared_ptr<Worker>> workers;
	static mutex requestsMutex;
	static mutex workersMutex;
	static vector<shared_ptr<Worker>> allWorkers;
	static vector<unique_ptr<thread>> threads;
	
public:
	static bool init(int workers);
	static bool stop();
	static void addRequest(unique_ptr<AbstractRequest> request);
	static bool addWorker(shared_ptr<Worker> worker);
};

#endif
