//
// Created by Mattia Riola on 13/09/2020.
//

#include <iostream>
#include "Timer.h"
#include <unistd.h>

int giveMeTheMinutes();
int giveMeTheSeconds();

int Timer::counter = 0;
Timer::Timer() {
    this->id = counter;
    counter++;
    this->running = false;
    this->name = DEFAULT_NAME;
    this->msg = DEFAULT_MSG;
    this->minutes = giveMeTheMinutes();
    this->seconds = giveMeTheSeconds();
    if(DEBUG)
        std::cout << "creating a default Timer" << std::endl;

}
Timer::Timer(std::string name, std::string msg) : name(name), msg(msg) {
    this->id = counter;
    counter++;
    this->running=false;
    this->minutes = giveMeTheMinutes();
    this->seconds = giveMeTheSeconds();

    if(DEBUG)
        std::cout << "creating Timer " << this->name << " with this msg: "<< this->msg << std::endl;
}

std::string Timer::toString(){
    std::string str;
    std::string min_dur;
    std::string sec_dur;
    std::string duration;
    if(this->minutes < 10)
        min_dur = "0" + std::to_string(this->minutes);
    else
        min_dur = std::to_string(this->minutes);
    if(this->seconds < 10)
        sec_dur = "0" + std::to_string(this->seconds);
    else
        sec_dur = std::to_string(this->seconds);

    duration =  min_dur + ":" + sec_dur;
    str = "Timer #" + std::to_string(this->id) + " | " + this->name + " | message: " + this->msg + "\n" +"duration: " + duration + " | state: " + std::to_string(this->running) +"\n";
    return str;
}

void Timer::ring(){
   if(DEBUG)
       std::cout << this->toString() << " is going to ring" << std::endl;

    pid_t processId = fork();

    if(processId == 0) {
        //I'm the child
        if(DEBUG)
            std::cout<< "I'm the child" << std::endl;
        //Starting the script to say something
        char * const cmsg = this->msg.data();
        if (execl(SCRIPT_PATH, SCRIPT_PATH,cmsg,0) == -1)
            std::cout << ("Child: execl failed\n");

    }
    else
        //I'm the father
        if(DEBUG)
            std::cout << "I'm the father" << std::endl;
    return;

}

void Timer::run() {
    //TODO: I've to lock the variable running if I use threads
    this->running = true;
    //TODO: it has to wait for the duration and call the ring() method
    this-> running = false;
}

/**
 * Useful function that asks Minutes from cin (with checks <0)
 * @return
 */
int giveMeTheMinutes(){
    int minutes;
    std::cout << "Insert the minutes: " << std::endl;
    do {
        std::cin >> minutes;
        if(minutes < 0)
            std::cerr << "Insert a valid number ( integer and > 0 )" << std::endl;
    }while(minutes < 0);
    return minutes;
}

/**
 * Useful function that asks Minutes from cin (with checks <0 and >60)
 * @return
 */
int giveMeTheSeconds(){
    int seconds;
    std::cout << "Insert the seconds: " << std::endl;
    do {
        std::cin >> seconds;
        if(seconds <0 || seconds >=60)
            std::cerr << "Insert a valid number ( integer, > 0 and < 60 )" << std::endl;
    }while(seconds < 0 || seconds >= 60);
}