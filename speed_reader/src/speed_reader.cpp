#include <iostream>

#include "../../ipc_lib/public/ipc_mq.hpp"

int main()
{
	std::string speedmsg;
    int speed = 0;
	IPCMqManager ipc_mq("speed");

	std::cout << "Welcome to SpeedReader App!" << std::endl;
	while(true)
	{
		if (ipc_mq.MqReceive(speedmsg) == true)
		{
			speed = std::stoi(speedmsg);
			std::cout<<"Generated speed : "<<speed<<std::endl;
		}
		else
		{
			std::cout << "No Speed Available!" << std::endl;
		}

		sleep(1);
	}
	return 0;
}
