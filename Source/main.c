#include <stdio.h>
#include <stdlib.h>

#include "Functions.h"

int i = 0, j=0;
uint8 user_input;
uint8 grades[3] = {0};
uint8 count = 0, list[Max]={0};
uint8 Id = 0;
uint8 subject[3] = {0,0,0} ;
//////////////
uint8 Subj[3]={0};
uint8 grade[3]={0};
//////////////
int main()
{
    /************** Note **************/

    /// Id = 0 Not acceptable;

    /**********************************/

    uint8 Year = 0;

    while(true)
    {
        printf("********************************\n");
        printf("Please Choose What You Want\n");
        printf("1 - Enter New Student DataBase\n");
        printf("2 - Delete Student DataBase\n");
        printf("3 - Check if DataBase is full\n");
        printf("4 - Get used Size of DataBase\n");
        printf("5 - Check if Id id exist in DataBase\n");
        printf("6 - Get Id List Of all Students\n");
        printf("7 - Read Student DataBase\n");
        printf("********************************\n");

        printf("\n ********************* \nEnter Your Choice:\t");
        scanf("%u", &user_input);
        printf("\n ********************* \n");


        if(user_input == 1)
        {

            printf("Please Enter Student Id: \n");
            scanf("%u", &Id);

            printf("Please Enter Student year: \n");
            scanf("%u", &Year);

            printf("Please Enter Subject Id & Grade\n");
            for(i = 0; i < 3; i++)
            {
                printf("Enter (%u)'s Subject Id: \n", i+1);
                scanf("%u", &subject[i]);

                printf("Enter (%u)'s grade Id: \n", i+1);
                scanf("%u", &grades[i]);

            }

            if ( SDB_AddEntry(Id, Year, subject, grades) ) printf("Added Successfully <3 \n");
            else printf("*****\nCan't Add Database Entry !!\nPlease check input parameter\n*****\n");
        }

        else if (user_input == 2)
        {
	        printf("Please Enter Student Id: \n");
            scanf("%u", &Id);
            SDB_DeleteEntry(Id);
        }


        else if ( user_input == 3)
        {
            if( SDB_IsFull() ) printf("Database is full...!!\n");
            else printf("Not full...!\n");
        }

        else if ( user_input == 4)
        {
            printf("Used Size = (%d)\n", SDB_GetUsedSize());
        }


        else if ( user_input == 5)
        {
            printf("Please Enter Student Id: \n");
            scanf("%u", &Id);

            if( SDB_IsIdExist(Id) ) printf("\nExist..!\n");
            else printf("\nNot Exist!!\n");
        }

        else if ( user_input == 6)
        {
            SDB_GetIdList(&count, list);

            printf("Number of student = %u\n",count);

            for (i = 0; i < SDB_GetUsedSize(); i++)
            {
                printf("(%u)'s Student Id  = (%u)",i+1, list[i]);
            }

        }

        else if ( user_input == 7)
        {
            printf("Please Enter Student Id: \n");
            scanf("%u", &Id);

            if(SDB_ReadEntry(Id, &Year, Subj, grade))
            {
                printf("Student Id = %u\n", Id);
                printf("Student Year = 20%u\n", Year);

                for(j = 0; j < 3; j++)
                {
                    printf("(%u)'s Subject Id: (%u) \n",j+1 , Subj[j]);
                }

                for(i = 0; i < 3; i++)
                {
                    printf("(%u)'s grade: (%u) \n",i+1, grade[i]);
                }
            }
            else
            {
                printf("Error..!!\n");
            }
        }

        else printf("Please choose correct number...!!\n\n");
        printf("\n\n");
        for(i = 0; i < 3; i++)
        {
            grades[i] = 0;
            subject[i] = 0;
        }
        Year = 0;
    }



    return 0;
}
