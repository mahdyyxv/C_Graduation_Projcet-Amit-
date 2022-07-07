#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions.h"

queue DataBase;   // initializing of database as globale variable


int Fun(void){

    Create_Queue();

    return 0;
}

void Create_Queue()
{
    queue *ptr = &DataBase;
    ptr->head=0;
    ptr->tail=0;
}

bool SDB_IsFull(void)
{
    queue *ptr = &DataBase;

    bool status;

    if ( ptr -> tail == Max ) status = 1;
    else status = 0;

    return status;
}

uint8 SDB_GetUsedSize(void)
{
    queue *ptr = &DataBase;

    uint8 Size = ( ptr -> tail );

    return Size;
}

bool SDB_IsIdExist(uint8 id)
{
    int i = 0;
    bool status = 0;
    queue *ptr = &DataBase;
    if(id == 0) status = 1;
    else{
        for(i = 0; i < SDB_GetUsedSize(); i++)
        {
            if( ptr -> Students[i].Student_Id == id )
            {
                status = 1;
                break;
            }
        }

    }
    return status;
}


bool SDB_AddEntry(uint8 id, uint8 year, uint8 *subject, uint8 *grades)
{
    queue *ptr = &DataBase;
    bool status = false;

    if( SDB_IsFull() || SDB_IsIdExist(id) || grades[0] > 100 || grades[1] > 100 || grades[2] > 100 )
    {
        return status;
    }

    else
    {
        ptr -> Students[ptr -> tail].Student_Id = id;
        ptr -> Students[ptr -> tail].Student_Year = year;

        ptr -> Students[ptr -> tail].Course_1_Id = subject[0];
        ptr -> Students[ptr -> tail].Course_1_Grade = grades[0];

        ptr -> Students[ptr -> tail].Course_2_Id = subject[1];
        ptr -> Students[ptr -> tail].Course_2_Grade = grades[1];

        ptr -> Students[ptr -> tail].Course_3_Id = subject[2];
        ptr -> Students[ptr -> tail].Course_3_Grade = grades[2];

        ptr -> tail ++;

        status = true;

        return status;
    }

}

void SDB_DeleteEntry(uint8 id)
{
    queue *ptr = &DataBase;
    int i = 0, j = 0;
    if( ptr -> tail == ptr -> head || !SDB_IsIdExist(id) || id == 0)
    {
        printf("Error For deleting\n");
        return;
    }

    for(i = 0; i < Max; i++)
    {
        if( ptr -> Students[i].Student_Id == id )
        {
            break;
        }
    }

    ptr -> Students[i].Student_Id = 0;
    ptr -> Students[i].Student_Year =0;

    ptr -> Students[i].Course_1_Id = 0;
    ptr -> Students[i].Course_1_Grade = 0;

    ptr -> Students[i].Course_2_Id = 0;
    ptr -> Students[i].Course_2_Grade = 0;

    ptr -> Students[i].Course_3_Id = 0;
    ptr -> Students[i].Course_3_Grade = 0;

    for(j = i; i < ptr -> tail ; i++)
    {
        ptr -> Students[i].Student_Id = ptr -> Students[i+1].Student_Id;
        ptr -> Students[i].Student_Year = ptr -> Students[i+1].Student_Year;

        ptr -> Students[i].Course_1_Id = ptr -> Students[i+1].Course_1_Id;
        ptr -> Students[i].Course_1_Grade = ptr -> Students[i+1].Course_1_Grade;

        ptr -> Students[i].Course_2_Id = ptr -> Students[i+1].Course_2_Id;
        ptr -> Students[i].Course_2_Grade = ptr -> Students[i+1].Course_2_Grade;

        ptr -> Students[i].Course_3_Id = ptr -> Students[i+1].Course_3_Id;
        ptr -> Students[i].Course_3_Grade = ptr -> Students[i+1].Course_3_Grade;
    }
    ptr -> tail--;
    printf("User With Id = %d, Deleted\n", id);

}

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subject, uint8 *grades)
{
    queue *ptr = &DataBase;
    int i = 0;

    if( !SDB_IsIdExist(id) ){
        return 0;
    }

    else if (id == 0)
    {
        return 0;
    }

    else{

        for(i = 0; i < SDB_GetUsedSize(); i++)
        {
            if( ptr -> Students[i].Student_Id == id )
            {
                break;
            }
        }

        *year = ptr -> Students[i].Student_Year;

        subject[0] = ptr -> Students[i].Course_1_Id;
        grades[0] = ptr -> Students[i].Course_1_Grade;

        subject[1] = ptr -> Students[i].Course_2_Id;
        grades[1] = ptr -> Students[i].Course_2_Grade;

        subject[2] = ptr -> Students[i].Course_3_Id;
        grades[2] = ptr -> Students[i].Course_3_Grade;
        return 1;
    }
}

void SDB_GetIdList(uint8 *count, uint8 *list)
{
    queue *ptr = &DataBase;
    int i = 0;

    *count = ptr -> tail;

    for( i = 0; i < ptr -> tail; i++ )
    {
        list[i] = ptr->Students[i].Student_Id;
    }
}
