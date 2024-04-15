#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here


// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

   // int totalDays = avail.size();
   sched = DailySchedule(avail.size(), std::vector<Worker_T> ());
    std::vector<int> workerShifts(avail[0].size());

    // int currWorker; 
   //std::cout << "After allocating memory for sched" << std::endl;

   return schedHelper(avail,dailyNeed,maxShifts,sched, 0, workerShifts, 0);

//    std::cout << "About to return:  " <<  isScheduled << std::endl;
//    std::cout << "size of avail: " << avail.size() << std::endl;

   
   //return isScheduled;

}


//implement a helper function
        // helper function should 
bool schedHelper(const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sche, size_t whatDay, std::vector<int> workerShifts, int worker)  // deleted       "sche[whatDay].push_back(i);  // set spot back to what "
{
    // number of rows in avail matrix 
    if (whatDay == avail.size()){
        return true; //maybe 
    }

    // std::cout << "Entering sched helper for day  "<< whatDay << std::endl;

    // for(Worker_T i = 0; i < avail[whatDay].size(); i++){
    //     if(avail[whatDay][i])
    //     {
    //         if(isValidPlacement(sche,whatDay, i, dailyNeed, maxShifts)){
    //             //std::cout << "makd it to this step line 75" << std::endl;

    //             sche[whatDay].push_back(i);
    //             //std::cout << "pushed back " << std::endl;
    //             std::cout << "Item pushed backed " << i << std::endl;
    //             if(schedHelper(avail,dailyNeed,maxShifts,sche,(whatDay+1))){
    //                 std::cout << "Next day " << whatDay+1 << " was valid " << std::endl;
    //                 return true;
    //             }
    //             //std::cout << "returning false" << std::endl;
    //             sche[whatDay].pop_back();
    //         }  
    //     }       
    // }
    // std::cout << "returning false for day " << whatDay << std::endl;
    // return false;

    //check if worker can't work // recursive call
    //if they can 
            // add then and check condtions (if they are able to be schedule  = maxshifts)

    //

    // std::cout << whatDay << " " << worker << std::endl;

    if(avail[0].size() <= worker){
        return false;
    }

    if(!avail[whatDay][worker] || (workerShifts[worker] >= maxShifts)){
        return schedHelper(avail, dailyNeed, maxShifts, sche, whatDay, workerShifts, worker+1);
    }

    sche[whatDay].push_back(worker);
    workerShifts[worker]++;

    // std::cout << sche[whatDay].size() << std::endl;
    // std::cout << dailyNeed << std::endl;

    int nextDay;
    int nextWorker;
    if(dailyNeed == sche[whatDay].size()){
        nextDay = whatDay+1;
        nextWorker = 0;
    }
    else{
        nextWorker = worker+1;
        nextDay = whatDay;
    }

    // std::cout << "HERE" << std::endl;
    // std::cout << nextDay << " " << nextWorker << std::endl;

    bool success = schedHelper(avail, dailyNeed, maxShifts, sche, nextDay, workerShifts, nextWorker);
    if(success){
        return true;
    }
    sche[whatDay].pop_back();
    workerShifts[worker]--;

    return schedHelper(avail, dailyNeed, maxShifts, sche, whatDay, workerShifts, worker+1);




    



}


// bool isValidPlacement(DailySchedule& sche,size_t whatDay, Worker_T person,const size_t dailyNeed, const size_t maxShifts)
// {
//     //they don't have too many shifts already assigned 
//             // check throguh whole array and count how many number (the person's number) there are in sche

//     // size_t totalRows = sche.size()
//     // size_t subRow = row - row % (maxrow/2);
//     // size_t subCol = col - col % (maxcol/2);

//     size_t count = 0;  // shifts count 

//     for(size_t i = 0; i < whatDay; ++i){
//         for(size_t j = 0; j < sche[i].size(); ++j){
//             //std::cout << "In isValidPlacement about to check if person == sched[i][j]" << std::endl;
//             if(person == sche[i][j]){
//                 count++;
//             }
//         }
//     }

//     if(count < maxShifts && count < dailyNeed*sche.size()){
//         //std::cout << "Return true in isValid" << endl;
//         return true;
//     }
//     // if(count < maxShifts && count < dailyNeed*(whatDay+1)){
//     //     return true;
//     // }

//     return false; 
// }