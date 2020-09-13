//
// Created by Mattia Riola on 13/09/2020.
//

#ifndef TIMERCLIONPROJECT_TIMER_H
#define TIMERCLIONPROJECT_TIMER_H



#include <string>

#define DEBUG true
#define SCRIPT_PATH "./SayMessage.sh"
#define DEFAULT_NAME "Deafult name"
#define DEFAULT_MSG "Deafult message"


class Timer {
private:
    static int counter;
    //TODO: modify the script,Timer's constructors, toString(), ring() to control how many times the Timer will repeat the message
    int repetitions;
    bool running;
    int id;
    std::string name;
    std::string msg;
    int minutes;
    int seconds;

public:
    Timer();
    Timer(std::string name, std::string msg);

    /* Useful Methods */
    /**
     * calling this method the timer rings using the bash script
     */
    void ring();

    /**
     * converting the info of the timer in a single string
     * @return the string with the information of the timer
     */
    std::string toString();

    /**
     * Calling this method the timer will start
     */
    void run();


    /* Getter and setter */
    void setName(std::string name){this->name = name;}
    void setMsg(std::string msg){this->msg = msg;}
    std::string getMsg(){return msg;}
    std::string getName(){return name;}
    int getId(){return id;}

};


#endif //TIMERCLIONPROJECT_TIMER_H
