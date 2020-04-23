#ifndef _TASK_H_
#define _TASK_H_

class Task
{
    public:
        Task();
        virtual ~Task();

        int _chapter;  //章节
        virtual void _doTask(int _chapter);  //做题

    protected:

    private:
};

#endif // _TASK_H_
