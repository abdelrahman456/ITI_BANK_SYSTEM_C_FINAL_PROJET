#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_Types.h"
#include "Bank_sys.h"
#include "Bank_sys.c"
#include <windows.h>
#include <conio.h>

void main(void)
{
	u8 input, n=1;
    //char	password[20];
	char	n_password[4];
	//char	default_pass[20]="1234";
	u8  ExitFlag = 0;
	u8 i=0,j=0, choice_1, choice_2;
   char 	ch;
   int password ;
	
	
while (ExitFlag == 0)
{
  printf("*********************************\n");
  printf("* TO CHOOSE ADMIN MODE ENTER:0  *\n");
  printf("* TO CHOOSE USER MODE ENTER::1  *\n");
  printf("********* YOUR CHOICE ***********\n::"); fflush(stdout);
  scanf("%d", &input);
	
 switch (input)
  {
	case 0 :
	 system("cls");
	 printf("***************************************************\n");
	 printf("*please enter default password:: "); fflush(stdout);
	 for (i = 0; i < 20; i++) {
		ch = getch();
		if (ch != 13) {
			n_password[i] = ch;
			ch = '#';
			printf("%c", ch);
		}
		else
			break;
	}
	 //scanf("%d", &password);
	 
	 j=1;
	 
	password = atoi(n_password);
	
	 if(password==1234)
	   {
		      //printf("*correct password enter your choice :"); fflush(stdout);
		printf("\n***************************************************\n");
	    printf("------------ YOU ARE IN ADMIN MODE ----------------\n");
	    printf("***************************************************\n");
		printf("\n************************************************\n");
	    printf("*  1- TO Create New Account                     *\n"); fflush(stdout);
		printf("*  2- TO Open Existing Account                  *\n"); fflush(stdout);
		printf("*  0- TO EXIT SYSTEM                            *\n"); fflush(stdout);
			  //printf("4- TO CANCEL RESERVATION \n"); fflush(stdout);
		printf("*************************************************\n:: ");
		scanf("%d", &choice_1);
		printf("\n***********************************************\n");
		switch(choice_1)
		 {  
		    case 0 : 
			    system("cls");
				printf("*************************************************\n");
				printf("*       EXIT SYSTEM                             *\n");
				printf("*       Thank You  Good Bye                     *\n"); 
				printf("*************************************************\n");
				ExitFlag=1;
				break;
			case 1 :
				
			   //Create_New_Account(u8 N_ID[], u8 Acc_ID[],u8 address[], u8 age, u8 gender, u32 balance, u8 name[] )

			    Create_New_Account( );
				break;
			case 2 :
					
				   Open_Existing_Account();
				
				break;
				
			default : 
			    system("cls");
				printf("*************************************************\n");
				printf("* Invalid Choice please try again               *\n");
				printf("* Thank You\nGood Bye                           *\n"); 
				printf("*************************************************\n");
				ExitFlag = 1;
				break;
				
			}
			
		   
		}
	else
		{  
		 
		  while(password!= 1234)
		    { 
		      
		      j++;
			  printf("\n**********INCORRECT PASSWORD**************\n"); fflush(stdout);
			  printf("*try again :"); fflush(stdout);
		     for (i = 0; i < 20; i++) {
		     ch = getch();
		     if (ch != 13) {
			      n_password[i] = ch;
			      ch = '#';
			       printf("%c", ch);
		         }
		        else
			          break;
	        } 
	
	          password = atoi(n_password);
			  
			  if(password==1234){
				  printf("\n\n %d", password);
				  break;
			  }
			  printf("\n*************************************************\n");
			  
			if(j==3)
			  {
				 printf("*INCORRECT PASSWORD FOR 3 TIMES : NO MORE TRIES *\n");
				 printf("*************************************************\n");
				
				 ExitFlag = 1;
				 break;
			  }
			 
		    }
			break;
			 
	    }
		  break;
		case 1 :
		   printf("------------ YOU ARE IN USER MODE ----------------\n");
		   printf("**************************************************\n");
		   printf("**************************************************\n");
		 /*printf("Please Enter Account_ID::"); fflush(stdout);
		 scanf("%s",&Acc_ID);*/
		   User_mode();
			
         
		 break;
		default :
		  system("cls");
          printf("*************************************************\n");
		  printf("* Invalid Choice please try again               *\n");
	      printf("* Thank You  Good Bye                           *\n"); 
		  printf("*************************************************\n");
		  ExitFlag = 1;

		break;
	 }
	
 }
	
	
	
	
	
	
	
	
}