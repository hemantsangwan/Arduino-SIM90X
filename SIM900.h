#ifndef SIMCOM900_H
#define SIMCOM900_H
#include "GSM.h"
class SIMCOM900: public virtual GSM {

private:
    int configandwait(char* pin);
    int setPIN(char *pin);
    int changeNSIPmode(char);
    public:
    SIMCOM900();
    ~SIMCOM900();
    int getCCI(char* cci);
    int getIMEI(char* imei);
    int sendSMS(const char* to, const char* msg);
    boolean readSMS(char* msg, int msglength, char* number, int nlength);
    boolean readCall(char* number, int nlength);
    boolean call(char* number, unsigned int milliseconds);
    char forceON();
    virtual int read(char* result, int resultlength);
    virtual uint8_t read();
    virtual int available();
    int readCellData(int &mcc, int &mnc, long &lac, long &cellid);
    void SimpleRead();
    void WhileSimpleRead();
    void SimpleWrite(char *comm);
    void SimpleWrite(char const *comm);
    void SimpleWrite(int comm);
    void SimpleWrite(const __FlashStringHelper *pgmstr);
    void SimpleWriteln(char *comm);
    void SimpleWriteln(char const *comm);
    void SimpleWriteln(const __FlashStringHelper *pgmstr);
    void SimpleWriteln(int comm);

    int getString(char *pre_string, char *post_string, char *buffer, int length) {
        if (_cell->find(pre_string)) {
            int index = 0;
            *buffer = 0;
            while (index < length - 1) {
                char c = _cell->read();
                if (c == 0) {
                    return 0;   // timeout returns 0 !
                } else if (c == *post_string) {

                    while (index < length) {
                        buffer[index] = '\0'; // terminate the string !!!!!!!!!!!IT DOESN'T WORK!!!!!!!!!!!!!!!!!
                        index++;
                    }

                    //buffer[index]=0;
                    return index;               // data got successfully
                } else {
                    buffer[index++] = c;
                }
            }
            buffer[index] = 0;
            return index; // Note: buffer full before the closing post_string encountered
        }
        return 0;    //failed to find the prestring
    }
};

extern SIMCOM900 gsm;

#endif

