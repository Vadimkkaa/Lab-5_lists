#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>


typedef struct Tours Tours;

struct Tours {
	int price;
	char* name;
	union {
		char date[9];
		int days;
	}unite;
	int flag;
	
	Tours* next;
};

void push(Tours** head); //to add new lists

void pushSpecialDate(Tours** head, char* namee, int pricee, char* dataa); //uploading list with date of start from  file

void pushSpecialDays(Tours** head, char* namee, int pricee, int dayss); //uploading list with trip's duration from file

void delete(Tours** head);//delete a list

void printFull(Tours* head);

void print(Tours* head, int Amount);

void isEmptyPrint(Tours* head, int Amount);//to check whether there's information in a list for printing one list

void isEmptyPrintFull(Tours* head);//to check whether there's information in a list for printing the whole list

void freeLists(Tours* head);//to free lists

void isEmptyFree(Tours* head);//to check whether we have lists at all

void Search(Tours* head);//to find a list using one parametere

void CompleteSearch(Tours* head);//to find a list entering all parameteres

void inputIntoText(Tours* head, char* arr);

void inputIntoBin(Tours* head, static int flagg, FILE* f);

void FileCreate(Tours* head);//need this function to creater file(txt or bin) in order to save into them

int UploadBin(Tours** head);

void TextUpload(Tours** head);
