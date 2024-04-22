#ifndef TRAININGSESSION_H
#define TRAININGSESSION_H
#include <iostream>
#include "Date.h"
class TrainingSession
{
private:
    /* data */

    int _duration;
    unsigned int _studentCount;
    std::string _studentName;
    std::string _sessionTopic;
    Date _date; 
    
public:
    TrainingSession() =default;
    TrainingSession (const TrainingSession &)=delete;
    TrainingSession (const TrainingSession &&)=delete;
    TrainingSession& operator =(const TrainingSession &)=delete;
    TrainingSession&& operator =(const TrainingSession &&)=delete;
    ~TrainingSession()=default;

    int duration() const { return _duration; }
    void setDuration(int duration) { _duration = duration; }

    unsigned int studentCount() const { return _studentCount; }
    void setStudentCount(unsigned int studentCount) { _studentCount = studentCount; }

    std::string studentName() const { return _studentName; }
    void setStudentName(const std::string &studentName) { _studentName = studentName; }

    std::string sessionTopic() const { return _sessionTopic; }
    void setSessionTopic(const std::string &sessionTopic) { _sessionTopic = sessionTopic; }

    Date date() const { return _date; }
    void setDate(const Date &date) { _date = date; }


    friend std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs);
};

#endif // TRAININGSESSION_H
