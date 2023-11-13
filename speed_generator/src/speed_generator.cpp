#include <iostream>
#include <stdio.h>
#include <stdbool.h>

#include "../../ipc_lib/public/ipc_mq.hpp"

int main() {

	IPCMqManager ipc_mq("speed");
	int random = 0;
	std::string str;

	std::cout << "Welcome to SpeedGenerator App!" << std::endl;
	while(true)
	{
		ipc_mq.MqReceive(str);
		random = 0 + (rand() % 201);
		std::cout<<"Generated speed : "<<random<<std::endl;

		str =  std::to_string(random);
		if (ipc_mq.MqSend(str) == true)
		{
			std::cout << "sending message success !" << std::endl;
		}
		else
		{
			std::cout << "sending message failed !" << std::endl;
		}
		sleep(1);
	}
	return 0;
}
