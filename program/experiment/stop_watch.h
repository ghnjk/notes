//
// File: stop_watch.h
// Created by jkguo on 2020/1/16.
//

#pragma once

#include <sys/time.h>

namespace cpp_util{

class StopWatch{
public:
    StopWatch();
    void start();
    void stop();
    void resume();
    void reset();
    long long getTimeMs()const;
protected:
    volatile long long m_tiStart;
    volatile long long m_costedMs;
};


StopWatch::StopWatch(){
    m_tiStart = 0;
    m_costedMs = 0;
}
void StopWatch::reset(){
    m_tiStart = 0;
    m_costedMs = 0;
}
void StopWatch::start(){
    struct timeval tv;
    gettimeofday (&tv, nullptr);
    m_tiStart = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    m_costedMs = 0;
}
void StopWatch::stop(){
    if(m_tiStart > 0) {
        struct timeval tv;
        gettimeofday(&tv, nullptr);
        long long end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
        m_costedMs += end - m_tiStart;
        m_tiStart = 0;
    }
}
void StopWatch::resume(){
    if(m_tiStart <= 0) {
        struct timeval tv;
        gettimeofday(&tv, nullptr);
        m_tiStart = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    }
}
long long StopWatch::getTimeMs()const{
    if(m_tiStart <= 0){
        // already stop
        return m_costedMs;
    }else{
        struct timeval tv;
        gettimeofday (&tv, nullptr);
        long long end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
        return m_costedMs + end - m_tiStart;
    }
}

}//namespace cpp_util