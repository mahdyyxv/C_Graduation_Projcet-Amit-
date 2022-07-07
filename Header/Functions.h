#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdbool.h>

#define Max 10

typedef unsigned char uint8;
typedef struct SimpleDb Db;
typedef struct queue queue;

struct SimpleDb{

    uint8 Student_Id;
    uint8 Student_Year;

    uint8 Course_1_Id;
    uint8 Course_1_Grade;

    uint8 Course_2_Id;
    uint8 Course_2_Grade;

    uint8 Course_3_Id;
    uint8 Course_3_Grade;

};


struct queue{
    Db Students[Max];
    uint8 head;
    uint8 tail;
};

bool SDB_IsFull(void);

uint8 SDB_GetUsedSize(void);

bool SDB_AddEntry(uint8 id, uint8 year, uint8 *subject, uint8 *grades);

void SDB_DeleteEntry(uint8 id);

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subject, uint8 *grades);

void SDB_GetIdList(uint8 *count, uint8 *list);

bool SDB_IsIdExist(uint8 id);

void Create_Queue();


#endif // FUNCTIONS_H_INCLUDED
