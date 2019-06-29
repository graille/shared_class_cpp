#include <iostream>
#include <unistd.h>

#include <chrono>
#include <thread>

#include "User.h"
#include "tasks.h"

int main(int argc, char **argv)
{
    // Create Object instance before fork
    // "new" is the important keywork here.
    // With new we will store our object in the HEAP space
    User* my_user = new User();

    thread thread_0(task_0, my_user);
    thread thread_1(task_1, my_user);
    thread thread_2(task_2, my_user);
    thread thread_3(task_3, my_user);

    thread_0.join();
    thread_1.join();
    thread_2.join();
    thread_3.join();

    printf("--end of program--\n");
    return 0;
}