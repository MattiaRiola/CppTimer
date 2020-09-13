#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include "Timer.h"
enum options{ SHOW_TIMER, ADD_TIMER, ADD_DEFAULT_TIMER , REMOVE_TIMER, RUN_TIMER, STOP_TIMER, EXIT };


void testing();

void menu();
void showMenu();
int main() {
    std::cout << "Hello, World!" << std::endl;
//    if(DEBUG)
//        testing();

    std::vector<Timer> timers;

    int exit_flag = 0;
    int cmd;
    std::string name_tmp = "";
    std::string msg_tmp = "";
    while(!exit_flag) {
        do {
            showMenu();
            std::cin >> cmd;
        } while (cmd < 0 || cmd > EXIT);

        switch (cmd) {
            case SHOW_TIMER:
                for(Timer t : timers){
                    std::cout << t.toString() << "\n_______________" << std::endl;
                }
                break;
            case ADD_TIMER:


                std::cout << "Name of the timer: ";
                std::cin >> name_tmp;
                std::cout << "Message: ";
                std::cin >> msg_tmp;
                timers.push_back(Timer(name_tmp,msg_tmp));
                break;
            case ADD_DEFAULT_TIMER:
                timers.push_back(Timer());
                break;
            case REMOVE_TIMER:
                //TODO: Check if it is running (stop it in that case)
                break;
            case RUN_TIMER:
                //TODO: Select the timer
                //TODO: Implement run() method and call it Using threads and chrono
                //TODO: Try to do that without the busy waiting issue
                break;
            case STOP_TIMER:
                //TODO: Is it possible if I use threads?
            case EXIT:
                exit_flag = 1;
            default:
                break;

        }
    }


    return 0;
}

void showMenu(){
    std::cout << "##### MAIN MENU ######" << std::endl;
    std::vector<std::string> vect_str_cmd = {"Show timer", "Add Timer", "Add Default Timer",
                                        "Remove Timer", "Run Timer",
                                        "Stop Timer", "Exit"}; //Exit must be the last one
    for(int i = SHOW_TIMER; i < EXIT ; i++) {
        std::cout << std::to_string(i) << ": " << vect_str_cmd[i];
        if(!i%2) //2 commands in a row separated by \t
            std::cout << "\t"; //for even positions (0,2,4,6,...)
        else
            std::cout << "\n"; //for odd positions (1,3,5,7,...)
    }
    std::cout << std::endl;
}

void testing(){
    Timer* t1 = new Timer("Primo Timer","Messaggio di test");
    std::cout << t1->toString() << std::endl;
    t1->ring();
    delete t1;
}