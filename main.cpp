#include"Data.h"
using namespace std;

extern int Window_Width;
extern int Window_Height;

int main() {
	initgraph(Window_Width, Window_Height, NULL);
	cleardevice();
	//Game_Show();
	Home_Show();
}
