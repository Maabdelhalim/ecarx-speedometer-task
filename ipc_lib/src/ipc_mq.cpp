#include "ipc_mq.hpp"


IPCMqManager::IPCMqManager(const std::string& queueName) : queueName_(queueName)
{
    // Open the message queue for reading and writing
    mqAttr_.mq_flags = 0;
    mqAttr_.mq_maxmsg = MAX_MESSAGES;
    mqAttr_.mq_msgsize = MAX_MSG_SIZE;
    mqAttr_.mq_curmsgs = 0;

    mq_ = mq_open(queueName_.c_str(), O_RDWR | O_CREAT | O_NONBLOCK, S_IRUSR | S_IWUSR, &mqAttr_);
    if (mq_ == (mqd_t)-1)
    {
        std::cerr << "Failed to open the message queue: " << strerror(errno) << std::endl;
    }
}

IPCMqManager::~IPCMqManager()
{
    if (mq_ != (mqd_t)-1)
    {
        mq_close(mq_);
        mq_unlink(queueName_.c_str());
    }
}


bool IPCMqManager::MqSend(const std::string& message)
{
    if (mq_ == (mqd_t)-1)
    {
        std::cerr << "Message queue is not open." << std::endl;
         return false;
    }

    std::string msg = toString(message);
    if (mq_send(mq_, msg.c_str(), msg.length(), 0) == -1)
    {
        return false;
    }

    return true;
}

bool IPCMqManager::MqReceive(std::string& message)
{
    char buffer[MAX_MSG_SIZE];
    unsigned int prio;
    int bytes_read = mq_receive(mq_, buffer, MAX_MSG_SIZE, &prio);

    if (mq_ == (mqd_t)-1)
    {
        std::cerr << "Message queue is not open." << std::endl;
        return false;
    }

    if (bytes_read == -1)
    {
        return false;
    }

    buffer[bytes_read] = '\0';
    message = buffer;
    return true;
}
