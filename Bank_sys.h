#ifndef _BANK_SYS_H
#define _BANK_SYS_H

typedef struct Bank_Account user;

struct Bank_Account{
    char National_ID[14] ;
	u8 Account_ID[14];
    u8 Name[50];
	u8 Address[50];
	u8 Age;
	u32 date, month, year;
	u8 Gender[5];
	u32 Balance;
	u8 typeaccount[20];
	u8 password[50];
	user *Next;
	
};



/* 2- Prototype */
void Create_New_Account(void);
void PrintLinkedList(void);
void Open_Existing_Account(void);
void Make_Transaction(u8 Acc_ID[],u8 SEC_ID[],u32 Money);
void Get_Cash(u8 Acc_ID[], u32 Money);
void Deposit_InAccount(u8 Acc_ID[], u32 Money);
void User_mode();
void accountcreated(void);
void gotoxy(int x, int y);
void randomPasswordGeneration(int N);



#endif