#ifndef PLC_SIEMENS_H
#define PLC_SIEMENS_H

#include "snap7.h"
#include <QThread>
#include <QDebug>
#include <QString>
#include <QMutex>

class PLC_Siemens : public QThread
{
#define DB_LENGTH 200
#define DB_NO 1;
typedef float *pfloat;

public:
    enum dataType {eBit, eByte, eInt, eDInt, eWord, eDowrd, eReal};

    PLC_Siemens(QString ipAddress);
    //
    bool connect();
    void ReadCycle();
    bool WriteVal( dataType typ, int dbNum, int offset,  int val);
//
    QMutex mutex;

 // Helper functions
    uint getUInt16(int Pos);
    uint getUInt16(byte* Buffer, int Pos);

    int getInt16(int Pos);
    int getInt16(byte* Buffer, int Pos);

    int getUInt32( int Pos);
    uint getUInt32(byte* Buffer, int Pos);

    int getInt32(int Pos);
    int getInt32(byte* Buffer, int Pos);

    double getReal(int Pos);
    double getReal(byte* Buffer, int Pos);
//
    QString ipAddress;
    TS7Client *MyS7Client;
    byte DB_Buffer[200];

protected:
    void run();
private:
    int old_value;
};

#endif // PLC_SIEMENS_H
