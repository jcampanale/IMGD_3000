#include "LogManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
using namespace df;

FILE *logfile;

/// Default Dragonfly cofiguration file.
/// Override with DRAGONFLY_LOG environment variable.
const char* LOGFILE_DEFAULT = "dragonfly.log";

LogManager::LogManager(){
    setType("LogManager");
}

int LogManager::writeLog(const char *fmt, ...) const{
  fprintf ( logfile , " Message : ");
  va_list args ;
  va_start ( args , fmt );
  vfprintf ( logfile , fmt , args );
  va_end ( args ) ;
  return 0;
}

int LogManager::writeLog(int log_level, const char *fmt, ...) const{
    if(log_level > this->m_log_level){
        va_list args ;
        va_start ( args , fmt );
        vfprintf ( logfile , fmt , args );
        va_end ( args ) ;
        return 0;
    }
    else return -1;
}

LogManager &LogManager::getInstance() {
    static LogManager single;
    return single;
}

int LogManager::startUp(){
    Manager::StartUp();
    if(logfile = fopen(LOGFILE_DEFAULT, "w"))
        return 0;
    else return -1;
}

void LogManager::shutDown(){
    LM.writeLog("LM shutting down\n");
    Manager::ShutDown();
    df::LogManager::~LogManager();
}

LogManager::~LogManager(){
    fclose(logfile);
}
