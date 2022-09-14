#ifndef _BANK_SYS_H
#define _BANK_SYS_H

typedef struct Bank_Account user;

struct Bank_Account{     //The Structure Containing all The Account Data 
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
void Create_New_Account(void);  // This Function Creates a New Account then adds it to the Linked Lis
void PrintLinkedList(void);
void Open_Existing_Account(void); // THis Function Scans Account ID and search for it in the Linked List
void Make_Transaction(u8 Acc_ID[],u8 SEC_ID[],u32 Money);  // THis Function makes Transaction Between Two Accounts
void Get_Cash(u8 Acc_ID[], u32 Money);  // THis Function Withdraw Cash from The Account
void Deposit_InAccount(u8 Acc_ID[], u32 Money); // THis Function Deposits Cash to the Account
void User_mode();
void accountcreated(void);
void gotoxy(int x, int y);
void randomPasswordGeneration(int N);



#endif