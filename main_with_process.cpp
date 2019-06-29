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

    // Creating first child 
    int n1 = fork(); 
  
    // Creating second child. First child 
    // also executes this line and creates 
    // grandchild. 
    int n2 = fork(); 
  
    if (n1 > 0 && n2 > 0)
        task_0(my_user);
    else if (n1 == 0 && n2 > 0)
        task_1(my_user);
    else if (n1 > 0 && n2 == 0)
        task_2(my_user);
    else
        task_3(my_user);

    printf("--end of program--\n");
    return 0;
}