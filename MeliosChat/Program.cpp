#include "ChatWindow.h"
#include <string>

int main(int argc, char* argv[])
{
	const int width = std::stoi(argv[1]);
	const int height = std::stoi(argv[2]);

	MeliosChat::ChatWindow chatWindow(width, height);
	chatWindow.Run();
}
