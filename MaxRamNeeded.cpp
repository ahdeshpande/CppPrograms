//
// Created by Abhiraj Deshpande on 10/5/16.
//

#include <list>
#include "iostream"

using namespace std;

class Process {
public:
    // Constructor
    Process(const int iStartTime = 0, const int iEndTime = 0, const int iRamNeeded = 0) {
        this->iStartTime = iStartTime;
        this->iEndTime = iEndTime;
        this->iRamNeeded = iRamNeeded;
    }

    // Sort the list according to start time (Ascending order)
    bool operator<(const Process &rhs) const {
        return iStartTime < rhs.iStartTime;
    }

    // Functions to get the times and RAM
    int getStartTime() {
        return iStartTime;
    }

    int getEndTime() {
        return iEndTime;
    }

    int getRamNeeded() {
        return iRamNeeded;
    }

private:
    int iStartTime;
    int iEndTime;
    int iRamNeeded;
};

class Calculator {

public:
    // Function to calculate the max RAM needed for the list of processes
    int calcRamNeeded(list<Process> listProcesses) {
        int iMaxRam = 0;
        int iRam = 0;

        // Sort according to start time (Ascending order)
        list<Process>::iterator itSort;
        for (itSort = listProcesses.begin(); itSort != listProcesses.end(); itSort++) {
            listProcesses.sort(less<Process>());
        }

        // Iterate all processes to check if another process starts before the initial process ends
        list<Process>::iterator itInitial;
        list<Process>::iterator itNext;
        list<Process>::iterator itTemp;
        itInitial = listProcesses.begin();
        while (itInitial != listProcesses.end()) {
            iRam = (*itInitial).getRamNeeded();
            itTemp = itInitial;
            for (itNext = ++itTemp; itNext != listProcesses.end(); itNext++) {
                if ((*itInitial).getEndTime() > (*itNext).getStartTime()) {
                    iRam = iRam + (*itNext).getRamNeeded();
                }
            }
            // Check if the current set of processes require greater RAM than the previous: update accordingly
            if (iMaxRam < iRam)
                iMaxRam = iRam;
            ++itInitial;
        }
        return iMaxRam;
    }

};

int main() {

    list<Process> processes;
    Process p1(0, 5, 5);
    Process p2(3, 5, 7);
    Process p3(5, 8, 4);

    processes.push_back(p1);
    processes.push_back(p2);
    processes.push_back(p3);

    Calculator objCalc;

    cout << "Max RAM Needed = " << objCalc.calcRamNeeded(processes);
    return 0;
}