// http://www.careercup.com/question?id=5692127791022080
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Timer {
public:
	Timer(): begin(0), end(0) {};
	
	clock_t ticks() {
		if (begin == 0) {
			return end;
		} else {
			end = clock();
			return end - begin;
		}
	};
	
	double seconds() {
		return 1.0 * ticks() / CLOCKS_PER_SEC;
	};
	
	void start() {
		begin = clock();
	};
	
	void stop() {
		if (begin > 0) {
			end =  clock();
			end -= begin;
			begin = 0;
		}
	};
	
	void reset() {
		begin = end = 0;
	};
private:
	clock_t begin, end;
};

int main()
{
	Timer timer;
	string cmd;
	
	while (cin >> cmd) {
		if (cmd == "start") {
			timer.start();
		} else if (cmd == "stop") {
			timer.stop();
		} else if (cmd == "time") {
			printf("%.2f seconds.\n", timer.seconds());
		} else if (cmd == "reset") {
			timer.reset();
		}
	}
	
	return 0;
}