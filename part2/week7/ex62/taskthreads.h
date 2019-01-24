#ifndef TASKTHREADS_H
#define TASKTHREADS_H

#include <thread>
#include <cctype>

#include "task.h"
#include "isvowel.h"

class TaskThreads
{
    static char *d_filename;
    size_t args;

    Task tasks[4] =
    {
        Task{isvowel, "vowels"},
        Task{isdigit, "digits"},
        Task{isxdigit, "hexadecimal digits"},
        Task{ispunct, "punctuation characters"}
    };
    std::thread threads[4];

    friend void Task::operator()();

    public:
        TaskThreads(int argc, char* argv[]);
        void run();
};

#endif