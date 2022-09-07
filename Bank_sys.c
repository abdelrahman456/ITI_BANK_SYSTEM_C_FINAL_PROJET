/* STD libs */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
/* User-Defined Libs */
#include "STD_Types.h"
#include "Bank_sys.h"
user head; 
u32 ListLength = 0;

/*u8 searchpatient(u32  id)
{
	if (ListLength == 0)
	{
		printf("no PATIENT ADD\n");
		return 0;
	}else
	{
		user *searched =&head;
		while((searched ->ID !=id) && (searched -> Next !=NULL))
		{
			searched = (searched -> Next);
			
		}
		if(searched -> Next == NULL)
		{
			printf("WRONG ID PLEASE TRY AGAIN \n");
		    return 0;
			
		}else  return 1;
		
	}
	
	
	
	
	
	
}
*/
void Create_New_Account( )
{
	u8 i=0;
	u8 age;
	char ch;
	FILE *fp, *fu;
	u32 date, month, year;
    u32	balance;
	u8 gender[5];
	u8 name[50];
	char N_ID[14];
	u8 Acc_ID[14];
	u8 address[50];
	u8 typeaccount[20];
	u8 password[50];
	/* First Node to Create */
	fp = fopen("username.txt", "ab");
	system("cls");
	printf("------------------------------------------------\n");
	printf("\n\n ACCOUNT_ID 10 CHARACTERS MAX!!");
	printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
	printf("\n------------------------------------------------\n");
	printf("*************************************************\n");
	printf("*Please Enter Account_ID::"); fflush(stdout);
	scanf("%s",&Acc_ID);
	printf("*Please Enter PASSWORD::"); fflush(stdout);
	// Taking password in the form of
	// stars
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '#';
			printf("%c", ch);
		}
		else
			break;
	}
	//scanf("%s",&password);
	fflush(stdout);
	printf("\n*please enter CLient NAME:: "); fflush(stdout);
	scanf("%s",&name);
	printf("*\n*please enter National_ID::"); fflush(stdout);
	scanf("%s",&N_ID);
	
	/*printf("*please enter ACCOUNT type \n1-ACTIVE \n2-RESTRICTED \n3-CLOSED \n:: "); fflush(stdout);
	scanf("%s",&typeaccount);*/
	printf("*\n*please enter ADDRESS::"); fflush(stdout);
	scanf("%s",&address);
	printf("\n*please Enter Client age:"); fflush(stdout);
	scanf("%d", &age);
	printf("* please enter Client gender:\n"); fflush(stdout);
	printf("*1-MALE \n*2-FEMALE:\n"); fflush(stdout);
	scanf("%s", &gender);
	printf("\n*please Enter CLient Balance ::"); fflush(stdout);
	scanf("%d", &balance) ;
	
	printf("\n----------------------------------------------\n");
	if (ListLength == 0){
		
		stpcpy((head.National_ID), N_ID);
		/*for(i=0;i<14;i++){
			head.National_ID[i]=N_ID[i];
		}*/
		stpcpy((head.Account_ID), Acc_ID);
		/*for(i=0;i<10;i++){
			head.Account_ID[i]=Acc_ID[i];
		}*/
		strcpy(head.Address, address);
		/*for(i=0;i<14;i++){
			head.Address[i]=address[i];
		}*/
		ListLength++;
		head.Age=age;
		strcpy(head.Gender, gender);
		strcpy(head.typeaccount, "active");
		head.Balance=balance;
		strcpy(head.Name, name);
		/*
		for(i=0;i<20;i++){
			head.Name[i]=name[i];
		}*/
		//head.Name[10]=name[10];
		// Writing to the file
       fwrite(&head, sizeof(head),
		 1, fp);

	   // Closing file
	   fclose(fp);
		head.Next  = NULL; 
		accountcreated();
	}else{
		user *searche = &head;
		//printf("******** ACCOUNT_ID::::%s*******", Acc_ID);
		while((strcmp(searche ->Account_ID , Acc_ID)) && (searche-> Next !=NULL))
		{
			searche = (searche -> Next);
			
			
		}if(!strcmp(searche ->Account_ID , Acc_ID))
		{
		  printf("WRONG ID PLEASE TRY AGAIN \n");
		}else{
		user *new = (user*) malloc(sizeof(user));
		
		stpcpy((new -> National_ID), N_ID);
		/*for(i=0;i<14;i++){
			new -> National_ID[i]=N_ID[i];
		}*/
		strcpy(new ->Account_ID, Acc_ID);
		strcpy(new ->password, password);
		printf("Account_ID :::: %s*************", new ->Account_ID);
		printf("********%s*************", Acc_ID);
		/*for(i=0;i<10;i++){
			new -> Account_ID[i]=Acc_ID[i];
		}*/
		strcpy(new -> Address, address);
		/*for(i=0;i<14;i++){
			new -> Address[i]=address[i];
		}*/
	
		new -> Age = age;
		stpcpy(new -> Gender , gender);
		new -> Balance = balance;
		
		stpcpy(new -> Name, name);
		/*for(i=0;i<20;i++)
		{
		 new -> Name[i] = name[i];
		}*/
		fwrite(new, sizeof(head),
		 1, fp);

	    // Closing file
	    fclose(fp);
		new -> Next  = NULL;
		user *last = &head;
		accountcreated();
		while( (last -> Next) != NULL ){
			last = (last -> Next); 
		} 
		last -> Next = new;
		/* 4- Search for the last node */
		
		
	}
	
	}
	
	ListLength++;	
}

void Open_Existing_Account()
{
	char ch;
	u8 i=0, n=1;
	FILE *fp, *fu;
	u8  ExitFlag = 0;
	u8 Sec_Acc_ID[14];
	u8  choice_1, choice_2;
	u8 age;
    u32	balance, amount_of_money;
	u8 gender;
	u8 name[20];
	char N_ID[14];
	u8 Acc_ID[14];
	u8 address[20];
	u8 typeaccount[20];
	u8 closed_[20]= "closed";
	u8 restricted[20]= "restricted";
	u8 password[50];
	/* First Node to Create */
	// Opening file of
	// user data
	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	system("cls");
	printf("------------------------------------------------\n");
	printf("\n\n ACCOUNT_ID 10 CHARACTERS MAX!!");
	printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
	printf("\n------------------------------------------------\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("*Please Enter Account_ID::"); fflush(stdout);
	scanf("%s",&Acc_ID);
	printf("*Please Enter PASSWORD::"); fflush(stdout);
	// Taking password in the form of
	// stars
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '#';
			printf("%c", ch);
		}
		else
			break;
	}
	
	/*if (ListLength > 0) 
	{*/
	    user *searched =&head;
	while(fread(&head, sizeof(head),
				1, fp))
	{
		
		while((strcmp(searched ->Account_ID , Acc_ID)==1)&&(searched -> Next != NULL))
		{
			searched = (searched -> Next);
			
		}
		
		if(strcmp(searched ->Account_ID , Acc_ID)==0)
		{
			printf("\n*************************************************\n");
			printf("*  1- CLIENT ID : %s                            *\n", Acc_ID ); fflush(stdout);
			printf("*  2-ACCOUNT BALANCE: %d                        *\n", searched -> Balance);fflush(stdout);
			printf("*  3-CLIENT NAME is: %s                         *\n\n", searched ->Name); fflush(stdout);
			printf("*************************************************\n\n");
			printf("*  1- TO MAKE TRANSACTION                       *\n"); fflush(stdout);
			printf("*  2- TO CHANGE Account STATUS                  *\n"); fflush(stdout);
			printf("*  3- TO GET CASH                               *\n"); fflush(stdout);
			printf("*  4- TO DEPOSIT IN ACCOUNT                     *\n"); fflush(stdout);
		    printf("*  0- TO RETURN TO MAIN MENU                    *\n"); fflush(stdout);
			printf("*************************************************\n\n");
			printf("*************************************************\n::"); fflush(stdout);
		    scanf("%d", &choice_2);
			printf("\n*************************************************\n"); 
			switch(choice_2) {
					 case 0:
					   system("cls");
                       printf("*************************************************\n");
				       printf("*       RETURN TO MAIN MENU                     *\n");
				       printf("*       Thank You  Good Bye                     *\n"); 
				       printf("*************************************************\n");
				       break;
                     case 1:	
					 if((strcmp((searched -> typeaccount), closed_ )==0)||(strcmp((searched -> typeaccount), restricted )==0)){
						 system("cls");
					   printf("*************************************************\n");
					   printf("*  1- YOU can't  MAKE A TRANSACTION              *\n"); fflush(stdout);
						 break;
						 
					 }else{
                       printf("*************************************************\n");
					   printf("*  1- YOU WILL MAKE TRANSACTION              *\n"); fflush(stdout);
				       
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   printf("*Please Enter 2ND Account_ID::"); fflush(stdout);
				       n=1;
					   scanf("%s",&Sec_Acc_ID);
					   
						  Make_Transaction(Acc_ID, Sec_Acc_ID, amount_of_money);
					 break;
					 }	
					case 2:	
                       printf("*************************************************\n");
					   printf("*  2- YOU WILL CHANGE Account STATUS         *\n"); fflush(stdout);
				       /*printf("*Please Enter  Account_ID::"); fflush(stdout);
				       n=1;
					   scanf("%s",&Acc_ID);*/
					   printf("*YOUR ACCOUNT STATUS %s::", searched -> typeaccount); fflush(stdout);
					   printf("\n*please enter ACCOUNT STATUS \n1-ACTIVE \n2-RESTRICTED \n3-CLOSED \n:: "); fflush(stdout);
				       
			            scanf("%s",&typeaccount);
						
						stpcpy(searched-> typeaccount, typeaccount);
                        break;	
					case 3:	
					if((strcmp((searched -> typeaccount), "closed" )==0)||(strcmp((searched -> typeaccount), "restricted" )==0))
					{
					   system("cls");
					   printf("*************************************************\n");
					   printf("*  1- YOU can't  GET A CASH                  *\n"); fflush(stdout);
						 break;
						 
					 }else{
                       printf("*************************************************\n");
					   printf("*  3- YOU WANT TO GET A CASH                    *\n"); fflush(stdout);
				       //printf("*Please Enter  Account_ID::"); fflush(stdout);
				       n=1;
				       /*do
                       {
                        scanf("%c",&Acc_ID[n]);
                         n++;
                        }while(Acc_ID[n] != ' ' && n<14);
			              n=1;*/	
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   Get_Cash(Acc_ID, amount_of_money);
					 break;	}
						case 4:	
						if((strcmp((searched -> typeaccount), closed_ )==0)||(strcmp((searched -> typeaccount), restricted )==0)){
						 system("cls");
					   printf("*************************************************\n");
					   printf("*  1- YOU can't  DEPOSIT IN ACCOUNT           *\n"); fflush(stdout);
						 break;
						 
					 }else{
                       printf("*************************************************\n");
					   printf("*  4- YOU WANT TO DEPOSIT IN ACCOUNT                   *\n"); fflush(stdout);
				       //printf("*Please Enter  Account_ID::"); fflush(stdout);
				       n=1;
				       /*do
                       {
                        scanf("%c",&Acc_ID[n]);
                         n++;
                        }while(Acc_ID[n] != ' ' && n<14);
			              n=1;	*/
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   Deposit_InAccount( Acc_ID,  amount_of_money);
					 break;
					 }
                    default :
					   system("cls");
					   printf("*************************************************\n");
				       printf("* Invalid Choice please try again               *\n");
				       printf("* Thank You\nGood Bye                           *\n"); 
				       printf("*************************************************\n");
                        ExitFlag = 1;
		               break;						
					  
					  
					  
				  }   
		}//else if(strcmp(searched ->Account_ID , Acc_ID)) printf("*-----------------WRONG ID PLEASE TRY AGAIN----------------- \n");
		
	}/*else
	 {
		printf("--------------------------List is Empty--------------------------\n");
	 }*/
	fclose(fp);
	printf("---------------------------------------------------------------------------\n\n\n");
}

void Get_Cash(u8 Acc_ID[], u32 Money)
{
	u8 i=0;
	FILE *fp, *fu;
	fp = fopen("username.txt",
			"rb");
			fu = fopen("username.txt",
			"ab");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	/*if (ListLength > 0) */
	user *searched =&head;
	while(fread(&head, sizeof(head),
				1, fp))
	{
			searched =&head;
	
	    
		while((strcmp(searched ->Account_ID , Acc_ID)==1)&&(searched -> Next != NULL))
		{
			searched = (searched -> Next);
			
		}
		if(strcmp(searched ->Account_ID , Acc_ID)==0)
		{
			printf("*************************************************\n");
			printf("*  1- CLIENT ID : %s                            *\n", searched ->Account_ID ); fflush(stdout);
			printf("*  2-ACCOUNT BALANCE: %d                        *\n", searched -> Balance);fflush(stdout);
			printf("*  3-CLIENT NAME is: %s                         *\n",searched ->Name); fflush(stdout);
			if(((searched -> Balance)>=Money)&&(Money>0)) 
			{
				searched -> Balance=(searched -> Balance)-Money;
				fwrite(&(searched->Balance), sizeof(searched->Balance),
		           1, fu);
					fwrite(searched, sizeof(head),
		           1, fu);
			    printf("\n*  ACCOUNT BALANCE AFTER GET CASH : %d          *\n", searched -> Balance);fflush(stdout);
		    }
	         else {
				 printf("\n*-----------------WRONG AMOUNT OF MONEY PLEASE TRY AGAIN----------------- \n");
				 }
			
		}//else printf("\n-----------------WRONG ID PLEASE TRY AGAIN----------------- \n");
		
	}
	
	fclose(fp);
	fclose(fu);
	printf("---------------------------------------------------------------------------\n\n\n");
}




void Deposit_InAccount(u8 Acc_ID[], u32 Money)
{
	u8 i=0;
	FILE *fp, *fu;
	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	/*if (ListLength > 0) 
	{*/
  user *searched =&head;
  while(fread(&head, sizeof(head),
				1, fp))
	{
			searched =&head;
	    
		while((strcmp(searched ->Account_ID , Acc_ID))&&(searched -> Next != NULL))
		{
			searched = (searched -> Next);
			
		}
		if(strcmp(searched ->Account_ID , Acc_ID)==0)
		{
			printf("*************************************************\n");
			printf("*  1- CLIENT ID : %s                            *\n", searched ->Account_ID ); fflush(stdout);
			printf("*  2-ACCOUNT BALANCE: %d                        *\n", searched -> Balance);fflush(stdout);
			printf("*  3-CLIENT NAME is: %s                         *\n",searched ->Name); fflush(stdout);
			if(Money>0) 
			{
				searched -> Balance=(searched -> Balance)+Money;
			    printf("\n*  ACCOUNT BALANCE AFTER DEPOSIT CASH : %d  *\n", searched -> Balance);fflush(stdout);
		    }
	         else {
				 printf("\n*-----------------WRONG AMOUNT OF MONEY PLEASE TRY AGAIN----------------- \n");
				 }
			
		}//else {printf("* -----------------WRONG ID PLEASE TRY AGAIN----------------- \n");}
		
	}
	fclose(fp);
	printf("---------------------------------------------------------------------------\n\n\n");
}






void Make_Transaction(u8 Acc_ID[],u8 SEC_ID[],u32 Money)
{
	u8 i=0;
	FILE *fp, *fu;
	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	/*if (ListLength > 0) 
	{*/
        user *searched =&head;
		user *searched_2 =&head;
 while(fread(&head, sizeof(head),
				1, fp))
	{
			searched =&head;
	    
		while((strcmp(searched ->Account_ID , Acc_ID))&&(searched -> Next != NULL))
		{
			searched = (searched -> Next);
			
		}
		if(strcmp(searched ->Account_ID , Acc_ID)==0)
		{
			printf("*************************************************\n");
			//printf("*  1- CLIENT ID : %s                            *\n", searched ->Account_ID ); fflush(stdout);
			printf("*  First ACCOUNT BALANCE: %d                    *\n", searched -> Balance);fflush(stdout);
			//printf("*  3-CLIENT NAME is: %s                         *\n",searched ->Name); fflush(stdout);
			
			
		}//else printf("\n* -----------------WRONG ID PLEASE TRY AGAIN----------------- \n");
		
	    while((strcmp(searched_2 ->Account_ID , SEC_ID))&&(searched_2 -> Next != NULL))
		{
			searched_2 = (searched_2 -> Next);
			
		}
		if(strcmp(searched_2 ->Account_ID , SEC_ID)==0)
		{
			printf("*************************************************\n");
			//printf("*  1- CLIENT ID : %s                            *\n", searched_2 ->Account_ID ); fflush(stdout);
			//printf("*    SECOND ACCOUNT BALANCE: %d                 *\n", searched_2 -> Balance);fflush(stdout);
			//printf("*  3-CLIENT NAME is: %s                         *\n",searched ->Name); fflush(stdout);
			
			
		}//else printf("* -----------------WRONG ID PLEASE TRY AGAIN----------------- \n");
	
	   if((searched -> Balance)>=Money){ 
	   searched -> Balance=(searched -> Balance)-Money;
	   searched_2 -> Balance=(searched_2 -> Balance)+Money;}
	   else {printf("\n*-----------------WRONG AMOUNT OF MONEY PLEASE TRY AGAIN----------------- \n");}
	   printf("*  First ACCOUNT BALANCE: %d                    *\n", searched -> Balance);fflush(stdout);
	}
	fclose(fp);
	printf("---------------------------------------------------------------------------\n\n\n");
}

void User_mode(){
	

	u8 i=0, n=1;
	u8  ExitFlag = 0;
	u8 Sec_Acc_ID[14];
	u8  choice_1, choice_2;
	u8 age;
    u32	balance, amount_of_money;
	u8 gender;
	u8 name[20];
	char N_ID[14];
	u8 Acc_ID[14];
	u8 address[20];
	printf("*************************************************\n");
	printf("*Please Enter Account_ID::"); fflush(stdout);
	scanf("%s",&Acc_ID);
	if (ListLength > 0) 
	{
	    user *searched =&head;
		while((strcmp(searched ->Account_ID , Acc_ID))&&(searched -> Next != NULL))
		{
			searched = (searched -> Next);
			
		}
		if(strcmp(searched ->Account_ID , Acc_ID)==0)
		{
			/*
			printf("*************************************************\n");
			printf("*  1- CLIENT ID : %s                            *\n", Acc_ID ); fflush(stdout);
			printf("*  2-ACCOUNT BALANCE: %d                        *\n", searched -> Balance);fflush(stdout);
			printf("*  3-CLIENT NAME is: %s                         *\n\n", searched ->Name); fflush(stdout);
			*/
			printf("*************************************************\n");
			printf("*  1- TO MAKE TRANSACTION                       *\n"); fflush(stdout);
			printf("*  2- TO CHANGE Account PASSWORD                  *\n"); fflush(stdout);
			printf("*  3- TO GET CASH                               *\n"); fflush(stdout);
			printf("*  4- TO DEPOSIT IN ACCOUNT                     *\n"); fflush(stdout);
		    printf("*  0- TO RETURN TO MAIN MENU                    *\n"); fflush(stdout);
			printf("*************************************************\n\n");
			printf("*************************************************\n::"); fflush(stdout);
		    scanf("%d", &choice_2);
			printf("\n*************************************************\n"); 
			switch(choice_2) {
					 case 0:
                       printf("*************************************************\n");
				       printf("*       RETURN TO MAIN MENU                     *\n");
				       printf("*       Thank You  Good Bye                     *\n"); 
				       printf("*************************************************\n");
				       break;
                     case 1:	
                       printf("*************************************************\n");
					   printf("*  1- YOU WANT TO MAKE TRANSACTION              *\n"); fflush(stdout);
				       
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   printf("*Please Enter 2ND Account_ID::"); fflush(stdout);
				       n=1;
					   scanf("%s",&Sec_Acc_ID);
					   
						  Make_Transaction(Acc_ID, Sec_Acc_ID, amount_of_money);
                        break;	
					case 2:	
                       printf("*************************************************\n");
					   printf("*  2- YOU WANT TO CHANGE Account PASSWORD         *\n"); fflush(stdout);
				       printf("*Please Enter  Account_ID::"); fflush(stdout);
				       n=1;
					   scanf("%s",&Acc_ID);
				       
                        break;	
					case 3:	
                       printf("*************************************************\n");
					   printf("*  3- YOU WANT TO GET A CASH                    *\n"); fflush(stdout);
				       
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   Get_Cash(Acc_ID, amount_of_money);
                        break;	
					case 4:	
                       printf("*************************************************\n");
					   printf("*  4- YOU WANT TO DEPOSIT IN ACCOUNT                   *\n"); fflush(stdout);
				    
					   printf("* please Enter AMOUNT oF  MONEY  ::"); fflush(stdout);
				       scanf("%d", &amount_of_money) ;
					   Deposit_InAccount( Acc_ID,  amount_of_money);
                        break;
                    default :
					   printf("*************************************************\n");
				       printf("* Invalid Choice please try again               *\n");
				       printf("* Thank You\nGood Bye                           *\n"); 
				       printf("*************************************************\n");
                        ExitFlag = 1;
		               break;						
					  
					  
					  
				  }   
		}//else printf("* -----------------WRONG ID PLEASE TRY AGAIN----------------- \n");
		
	}else
	 {
		printf("--------------------------List is Empty--------------------------\n");
	 }
	
	printf("---------------------------------------------------------------------------\n\n\n");
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


void accountcreated(void)
{
	int i, j;
	char ch;
	system("cls");
	
	printf(
		"\nPLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for(j = 0; j < 50; j++){
	for (i = 0; i < 12000000; i++) {
		i++;
		i--;
	}printf(".");
	}
	printf("\n");
	gotoxy(30, 10);
	
	printf("								ACCOUNT CREATED SUCCESSFULLY...			\n");
	gotoxy(0, 20);

	/*printf("Press enter to login");

	*/
}
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void randomPasswordGeneration(int N)
{
    // Initialize counter
    int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";
  
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
  
    // Stores the random password
    char password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
}