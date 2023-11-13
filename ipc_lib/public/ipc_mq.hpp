/*
 *
 * ipc_mq.hpp
 *
 *  Created on: Nov 5, 2023
 *      Author: Mahmoud Abdelhalim
 */
#ifndef _IPC_LIB_PUBLIC_IPC_MQ_HPP_
#define _IPC_LIB_PUBLIC_IPC_MQ_HPP_

#include <mqueue.h>
#include <cerrno>
#include <iostream>
#include <cstring>
#include "utils.hpp"

class IPCMqManager
{
    public:

        IPCMqManager(const std::string& queueName);
        ~IPCMqManager();
        bool MqSend(const std::string& message);
        bool MqReceive(std::string& message);

    private:
        mqd_t mq_;
        struct mq_attr mqAttr_;
        const std::string queueName_;
        static const int MAX_MESSAGES = 1;
        static const int MAX_MSG_SIZE = 256;
};

#endif /* _IPC_LIB_PUBLIC_IPC_MQ_HPP_ */
