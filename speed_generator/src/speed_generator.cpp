#include <iostream>
#include <stdio.h>
#include <stdbool.h>

#include "../../ipc_lib/public/ipc_mq.hpp"

int main() {

	ipc::mqueue::IPCMqManager ipc_mq("speed");
	int random = 0;
	std::string str;

	std::cout << "Welcome to SpeedGenerator App!" << std::endl;
	while(true)
	{
		// Speed generator reads the speed from the queue before writing it to make the queue empty to ensure that it
		// can write the speed into the queue , this is because the two apps are asynchronous and if speed reader app
		// has not yet read the speed , speed writer will block due to queue size is 1 to make speed readings realtime
		// and the most update.
		ipc_mq.MqReceive(str);

		// Maximum speed is set to 200.
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
