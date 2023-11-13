# ECARX Speedometer Task

## Version 1.0.0

### Description
The project contains two applications and  QNX ipc services library message queue and message passing wrapper , where one application generates speed and the second application speed reader reads speed using mqueue for inter-process communication.

### Modules 

| Module          |                     |  Description  |
| ----------------|---------------------|---------------|   
| Application 1   | Speed Generator App | Generates speed and writes it into message queue periodically
| Application 2   | Speed Reader App    | reads speed from the message queue
| QNX IPC Wrapper |  Message-queues     | wrapper for qnx ipc message queue library 


## Apps Execution  

#### Method 1 : 
>1- Connect to target with two terminals either one terminal by serial using minicom and the other terminal by using ssh or the two terminals using ssh 
>2- Copy apps executables and the libipc_mq.so file to the target
>3- Use one terminal to run speed generator app first , then use another terminal to run the speed reader app
>4- To end apps , exit two apps , then delete the queue manually taking to into consideration that an exit mechanism is going to be added in the next release to for the app to call the destructor to close and unlink the created  message queue.

#### Method 2 :
>1- Connect to target by one terminals either serial or ssh
>2- Apply step 2 in method 1
>3- Use one terminal to run speed generator app first as background process , then run the speed reader app in the main terminal.
>4- To end apps , exit speed reader app and then process for speed generator app , then delete the queue manually taking to into consideration same noted stated at the end of step 5 in the above method

### Information on QNX IPC Message Queue Wrapper
Message queues are used for the asynchronous communication between two apps where they are not dependant on reading and writing from the queue or known as non-blocking message-passing.

### Next Enhancments Steps:
1-Add control for exiting speedometer apps to ensure deleting the queue before exit
1-Add shared memory QNX library wrapper
2-Add QNX IPC library Wrapper interface for better abstraction and usability with namespace.
3-Add GUI to speed reader app



