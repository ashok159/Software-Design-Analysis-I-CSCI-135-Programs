/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Time

Create a new program time.cpp. 
(Copy the class Time declaration 
in your program, it should be 
placed before main() function.)
In the same program time.cpp, implement 
your own printing function printTimeSlot(TimeSlot ts).
*/

#include <iostream>
#include <string>
using namespace std;


enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER}; // different genres

class Time {
public:
    int h, m;
};

class Movie { // has a title, genre and duration
public:
    string title;
    Genre genre;
    int duration;
};

class TimeSlot {// has a movie and a startTime
public:
    Movie movie;
    Time startTime;
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTime(Time time);
void printTimeSlot(TimeSlot ts);
void printMovie(Movie mv);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

int main(){
    Movie bttf = {"Back to the Future", COMEDY, 116};
    Movie bp = {"Black Panther", ACTION, 134};

    TimeSlot one = {bttf, {9, 15}};
    TimeSlot two = {bp, {12, 15}};
    TimeSlot three = {bp, {16, 45}};

    printTimeSlot(one);
    printTimeSlot(two);
    printTimeSlot(three);
    
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    cout << " [starts at "; 
    printTime(ts.startTime); 
    cout << ", ends by ";
    printTime(addMinutes(ts.startTime, ts.movie.duration));
    cout << "]\n";
}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time){
    int total = 0;
    total += time.m;
    total += time.h * 60;
    return total;
}

int minutesUntil(Time earlier, Time later){
    int total = 0;
    total += later.m - earlier.m;
    total += (later.h - earlier.h) * 60;
    return total;
}

Time addMinutes(Time time0, int min){
    int hours = time0.h;
    int mins = time0.m;

    hours += min / 60;
    mins += min % 60;

    if (mins > 59){
        mins -= 60;
        hours++;
    }
    return {hours, mins};
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    return {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    if (minutesUntil(ts1.startTime, ts2.startTime) < ts1.movie.duration 
        && minutesUntil(ts2.startTime, ts1.startTime) < ts2.movie.duration){
        return true;
    }
    else
        return false;
}

