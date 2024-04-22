std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs) {
    os << "_duration: " << rhs._duration
       << " _studentCount: " << rhs._studentCount
       << " _studentName: " << rhs._studentName
       << " _sessionTopic: " << rhs._sessionTopic
       << " _date: " << rhs._date;
    return os;
}
