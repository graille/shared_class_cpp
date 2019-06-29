#include <mutex>
std::mutex m;

void task_0(User* my_user) {
    // This task print the age every second

    printf("\033[1;31mTask 0 : start \033[0m  \r\n"); 
    printf("\033[1;31mTask 0 : User adress %p \033[0m  \r\n", my_user); 

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        // Mutex to lock the shared space between operations
        m.lock();
        
        printf("\033[1;31mTask 0 : This is the age of my user : %d \033[0m \r\n", my_user->age);

        // Release Mutex
        m.unlock();
    }
}

void task_1(User* my_user) {
    // This task add 1 to the age every half second

    printf("\033[0;32mTask 1 : start \033[0m \r\n"); 
    printf("\033[0;32mTask 1 : User adress %p \033[0m \r\n", my_user); 

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        // Mutex to lock the shared space between operations
        m.lock();
        
        my_user->age++;
        printf("\033[0;32mTask 1 : I added one to the age of my user \033[0m\r\n");

        // Release Mutex
        m.unlock();
    }
}


void task_2(User* my_user) {
    // This task reset the age to 1 every 10 seconds

    printf("\033[0;34mTask 2 : start \033[0m \r\n"); 
    printf("\033[0;34mTask 2 : User adress %p \033[0m \r\n", my_user); 

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        
        // Mutex to lock the shared space between operations
        m.lock();
        
        my_user->age = 1;
        printf("\033[0;34mTask 2 : I resetted the age of my user \033[0m\r\n");

        // Release Mutex
        m.unlock();
    }
}

void task_3(User* my_user) {
    // This task reset the age to a random int between 0 and 100 every 9.4 seconds

    printf("\033[0;36mTask 3 : start \033[0m \r\n"); 
    printf("\033[0;36mTask 3 : User adress %p \033[0m \r\n", my_user); 

    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(9400));
        
        // Mutex to lock the shared space between operations
        m.lock();
        
        my_user->age = rand() % 100;
        printf("\033[0;36mTask 3 : I resetted the age of my user \033[0m\r\n");

        // Release Mutex
        m.unlock();
    }
}