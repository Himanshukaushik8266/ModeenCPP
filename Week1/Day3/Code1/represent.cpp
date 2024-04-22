/*
    Represent "state" of "something"!

*/

class TrainingSession{
    /*
        _duration (in hours) :int 
        _studentCount : unsigned int
        _trainerName : string
        _sessionTopic: string
        _date : Date
    */

};//Each object of this class must represent one training session


class ID{
    /*
        _country : COUNTRY
        _year : 24
        _month : 01
        _location : optional
        _track_level : (LEVEL enum)
        _batch_number :01
        _traack name : Track 
    */
};

class TrainingBatch{
    /*
        _id : ID 
        _strength : integer
        _trainer :  Trainer ----------------------Employee
        _pmt_coordinator : Coordinator -----------Employee
        _schedule : Schedule
        _talent : Container <Talent>
    */
};



/*

    Pointer ka state representation 
        ----> Smart Pointers
    Reference ka state representation
        ----> reference_wrapper
    Thread (set of instructions)
        -std::async
    Semaphore ka state
        ----> lock_guard
        ----> unique_lock
    union ka state represent
        ----> std::variant

*/