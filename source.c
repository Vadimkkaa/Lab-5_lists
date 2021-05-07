#include"library.h"

void push(Tours** head, Tours** tail) {
	Tours* p = malloc(sizeof(Tours));
	int amountOfLists = 0;
	Tours* current = *head;
	while (current) {//for checking whether we have any lists
		amountOfLists++;
		current = current->next;
	}
	if (amountOfLists == 0) {//if we don't have any-head and tail gonna point to the same list now
		*head = p;
		p->next = NULL;
		*tail = p;
	}
	if (amountOfLists > 0) {//all other cases
		(*tail)->next = p;
		p->next = NULL;
		*tail = p;
	}
	int pricee, dayss, flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0;//position for letters in name
	char datee[9];
	char* namee = malloc(sizeof(char));

	p->name = malloc(1 * sizeof(char));
	while (1) {
		printf("Please,enter the price:\n");
		rewind(stdin);
		if (!(scanf("%d", &pricee)) && pricee < 0) {
			printf("Wrong number!Please,try again\n");
		}
		else {
			p->price = pricee;
			break;
		}
	}

	printf("Please,enter the Tour name:\n");
	rewind(stdin);
	while (1) {

		scanf("%c", &symbol);  //enter a letter
		if (symbol == '\n') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos] = symbol; //one more letter is entered:)
		pos++; //transfer to the next position
	}

	while (1) {
		printf("What would you like to add:\n0-The date of start\n1-The trip's duration\n");
		rewind(stdin);
		if (!(scanf("%d", &flagg)) || flagg != 0 && flagg != 1) {
			printf("Wrong number!Please,try again\n");
		}
		else {
			switch (flagg)
			{
			case 0:
				p->flag = 0;
				while (1) {
					printf("Please,enter the start date in the format dd/mm/yy:\n");
					rewind(stdin);
					fgets(p->unite.date, 9, stdin);
					if (p->unite.date[2] != '/' || p->unite.date[5] != '/' || atoi(p->unite.date) > 31 || ((p->unite.date[3] - '0') * 10 + (p->unite.date[4] - '0') > 12))
						printf("Wrong format!Try again\n");
					else break;
				}
				break;

			case  1:
				p->flag = 1;
				printf("Please,enter the trip's duration:\n");
				rewind(stdin);
				scanf("%d", &p->unite.days);
				break;


			}
			break;
		}

	}

	system("CLS");
	printf("Done\n");
	Sleep(600);
	system("CLS");
}

void pushSpecialDate(Tours** head, Tours** tail, char* namee, int pricee, char* dataa) {
	Tours* p = malloc(sizeof(Tours));

	if (*tail == NULL) {//if we try to upload a list into a zero list
		(*head) = p;
		*tail = p;
	}
	else
		(*tail)->next = p;//we connect new list to the previous chain of lists
	*tail = p;//now tail points to the new list
	p->next = NULL;//don't forget about it
	int  flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0, g = 0;//position for letters in name
	//p->unite.date = (char*)malloc(9*sizeof(char));

	p->name = malloc(1 * sizeof(char));
	p->price = pricee;


	while (1) {

		//enter a letter
		if (namee[g] == '\0') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos++] = namee[g++]; //one more letter is entered:)
		 //transfer to the next position
	}
	//p->unite.date = (Tours*)realloc(p->unite.date,9*sizeof(Tours));
	strcpy(p->unite.date, dataa);
	p->flag = 0;
}

void pushSpecialDays(Tours** head, Tours** tail, char* namee, int pricee, int dayss) {
	Tours* p = malloc(sizeof(Tours));
	if (*tail == NULL) {//if we try to upload a list into a zero list
		(*head) = p;
		*tail = p;
	}
	else
		(*tail)->next = p;//we connect new list to the previous chain of lists
	*tail = p;//now tail points to the new list
	p->next = NULL;//don't forget about it

	int  flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0, g = 0;//position for letters in name


	p->name = malloc(1 * sizeof(char));
	p->price = pricee;

	while (1) {

		//enter a letter
		if (namee[g] == '\0') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos++] = namee[g++]; //one more letter is entered:)
		 //transfer to the next position
	}

	p->unite.days = dayss;
	p->flag = 1;
}

void delete(Tours** head, Tours** tail) {
	Tours* pos2;
	Tours* pos1 = NULL;
	int choice;
	int amount = 0;
	char ch;
	for (pos2 = *head; pos2 != NULL; pos2 = pos2->next)//wanna know how many lists i have
		amount++;
	if (amount <= 0) {//no lists left?-instructions below
		system("CLS");
		printf("No lists left:(\n");
		Sleep(600);
		system("CLS");
		return;
	}
	printf("Are you sure you wanna delete a list?\ny/n\n");
	while (1) {
		rewind(stdin);
		if (!(scanf("%c", &ch)))//ch==choice
			printf("Wrong letter!Try again\n"); else break;
	}
	if (ch == 'y' || ch == 'Y' && amount > 0) {
		system("CLS");
		while (1) {
			printf("Enter the number of list you wanna delete:\n");
			rewind(stdin);
			scanf("%d", &choice);
			choice++;//the thing is:the task tells me that my lists start with 0 list(not 1 as it should be)
			if (choice < 1)
				continue;

			if (amount < choice) {//amount of lists vs. user choice
				system("CLS");
				printf("We don't have this amount of lists\n");
				Sleep(1100);
				system("CLS");
				continue;
			}

			else break;

		}
		system("CLS");
		pos2 = *head;//pos 2 now goes to the head
		if (choice == 1) {//user wanna delete the first list(remember?--choice==0 but i did choice++)
			*head = pos2->next;//i just rewrite head pointer
			free(pos2);//free the previous position of *head
			pos2 = *head;//don't what for

		}
		else if (choice == amount) {//dear user wanna delete the last list

			Tours* current = *head;//i nedd a pointer that points to list BEFORE the one i wanna delete(the last one actually)
			Tours* delet = *tail;//the one i'm gonna delete(the last one)
			amount -= 2;//need this for correct working
			while (amount > 0) {//this cycle's target to point *current to the list before the last one
				current = current->next;
				amount--;
			}
			*tail = current;//now tail points to the prevois one
			free(delet);//free prevois tail
			(*tail)->next = NULL;


		}
		else {

			Tours* current = *head;//i nedd a pointer that points to list  i wanna delete
			Tours* before = pos2;//i nedd a pointer that points to list BEFORE the one i wanna delete
			Tours* after = pos1;//i nedd a pointer that points to list AFTER the one i wanna delete

			choice -= 2;

			while (choice > 0) {//need to find location for before pointer
				before = before->next;
				choice--;
			}
			after = before->next;//just wanna find current(the one to delete)
			current = after;
			after = after->next;//now after points where it should
			free(current);
			before->next = after;

		}
		system("CLS");
		printf("Deleted\n\n");
		Sleep(600);
		system("CLS");


	}
	if (ch == 'n' || ch == 'N' && amount > 0) {
		system("CLS");
		printf("Ok\n");
		Sleep(800);
		system("CLS");
	}
}

void printFull(Tours* head) {
	int number = 0;//number of the head
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|Information of the list   |   Price   |   The Tour's name   |   The Tour's date of start   |   The Tour's duration   |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	for (Tours* p = head; p != NULL; p = p->next, number++) {
		printf("|%-26d", number);
		printf("|%-11d", p->price);
		printf("|%-21s", p->name);
		if (p->flag == 0) {
			printf("|%-30s", p->unite.date);
			printf("|\t\t\t      |");
		}
		if (p->flag == 1) {
			printf("|\t\t\t            |");
			printf("%-25d|", p->unite.days);
		}
		printf("\n");
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
	printf("\n");

}

void print(Tours* head, int Amount) {
	int number = 0;//number of the head
	number = Amount - 1;
	Tours* p = head;
	while (Amount > 1) {
		p = p->next;
		Amount--;
	}

	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|Information of the list   |   Price   |   The Tour's name   |   The Tour's date of start   |   The Tour's duration   |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	printf("|%-26d", number);
	printf("|%-11d", p->price);
	printf("|%-21s", p->name);
	if (p->flag == 0) {
		printf("|%-30s", p->unite.date);
		printf("|\t\t\t      |");
	}
	if (p->flag == 1) {
		printf("|\t\t\t            |");
		printf("%-25d|", p->unite.days);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	printf("\n");

}

void isEmptyPrint(Tours* head, int Amount) {
	if (head == NULL) {//if we don't have any lists
		system("CLS");
		printf("List is empty\n");
		Sleep(800);
		system("CLS");
	}
	else print(head, Amount);
}

void isEmptyPrintFull(Tours* head) {
	if (head == NULL) {//if we don't have any lists
		system("CLS");
		printf("List is empty\n");
		Sleep(800);
		system("CLS");
	}

	else printFull(head);
}

void freeLists(Tours* head) {
	Tours* current = head;
	Tours* current1 = NULL;
	int amount = 1;
	while (current) {//wanna find out how many lists we have
		current = current->next;
		amount++;
	}
	current = head;
	current1 = current;//we need one more list in order to always delete this one(of course it changes)
	while (amount > 0) {
		current = current->next;//we go farther
		free(current1);//free before
		if (current == NULL)//if we run out of lists
			break;
		current1 = current;
		amount--;
	}

	system("CLS");
}

void isEmptyFree(Tours* head) {
	if (head == NULL)//do we have any lists to free??
		exit(0); else freeLists(head);
}

void Search(Tours* head) {
	Tours* current;
	current = head;
	int choice;
	int Amount = 1;
	int searchFlag = 0;
	printf("Please,choose the parameter u wanna find by\n1-Name   2-Price   3-Tour's start date   4-Tour's duration\n");
	rewind(stdin);
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &choice))
			printf("Wrong number.Try again\n"); else break;
	}
	switch (choice) {
	case 1:
	{
		int symbol = 'a';
		char* namee = malloc(sizeof(char));
		int pos = 0;
		int amount = 1;
		printf("Enter the Tour's name:\n");
		rewind(stdin);

		while (1) {

			scanf_s("%c", &symbol);  //enter a letter
			if (symbol == '\n') {   //if this was the end of our word('\n')--we also need to finish
				//amount++;
				namee[pos] = '\0';
				break;
			}
			amount++; //enlarge the amount of letters in our massive
			namee = (char*)realloc(namee, amount * sizeof(char)); //we just extend our massive
			namee[pos] = symbol; //one more letter is entered:)
			pos++; //transfer to the next position
		}
		for (current = head; current != NULL; current = current->next, Amount++) {

			if (strcmp(current->name, namee) == 0) {//if names a match --show this list!!
				searchFlag = 1;//at least once we found sth
				isEmptyPrint(head, Amount);
			}

		}
		if (searchFlag == 0) {//if we didn't find anything--show a message
			system("CLS");
			printf("Nothing was found :(\n\n");
			Sleep(1000);
			system("CLS");
		}
		break;
	}
	case 2: {
		int pricee;
		printf("Enter the price:\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &pricee))
				printf("Wrong number.Try again\n"); else break;
		}

		for (current = head; current != NULL; current = current->next, Amount++) {

			if (current->price == pricee) {//if prcie a match --show this list!!
				searchFlag = 1;
				isEmptyPrint(head, Amount);
			}

		}
		if (searchFlag == 0) {//if we didn't find anything--show a message
			system("CLS");
			printf("Nothing was found :(\n\n");
			Sleep(1000);
			system("CLS");
		}
		break;
	}
	case 3:
	{
		char datee[9];
		int unionFlag = 0;
		rewind(stdin);
		while (1) {
			printf("Please,enter the start date in the format dd/mm/yy:\n");
			rewind(stdin);
			fgets(datee, 9, stdin);
			if (datee[2] != '/' || datee[5] != '/' || atoi(datee) > 31 || ((datee[3] - '0') * 10 + (datee[4] - '0') > 12))
				printf("Wrong format!Try again\n");
			else break;
		}

		for (current = head; current != NULL; current = current->next, Amount++) {
			if (unionFlag == current->flag) {//if flags don't match--what for to go further?

				if (strcmp(datee, current->unite.date) == 0) {//if date a match --show this list!!
					searchFlag = 1;
					isEmptyPrint(head, Amount);
				}


			}
		}
		if (searchFlag == 0) {//if we didn't find anything--show a message
			system("CLS");
			printf("Nothing was found :(\n\n");
			Sleep(1000);
			system("CLS");
		}
		break;
	}
	case 4: {
		int unionFlag = 1;
		int dayss;
		printf("Please,enter the The Tour's duration\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &dayss))
				printf("Wrong number!Try again\n");
			else break;
		}

		for (current = head; current != NULL; current = current->next, Amount++) {
			if (unionFlag == current->flag) {//if flags don't match--what for to go further?

				if (dayss == current->unite.days) {//if days a match --show this list!!
					searchFlag = 1;
					isEmptyPrint(head, Amount);
				}

			}
		}
		if (searchFlag == 0) {//if we didn't find anything--show a message
			system("CLS");
			printf("Nothing was found :(\n\n");
			Sleep(1000);
			system("CLS");
		}
		break;
	}
	default:
		printf("Wrong number\n\n");
	}

}

void CompleteSearch(Tours* head) {
	Tours* current;
	current = head;
	int pricee;

	char datee[9];
	int dayss;
	int unionFlag;

	char* namee = malloc(sizeof(char));
	char symbol;
	int pos = 0, amount = 1;

	int searchFlag = 0;

	int Amount = 1;//for calling the function of Print
	printf("Enter all required aspects\n\n");
	Sleep(1100);
	system("CLS");
	rewind(stdin);
	printf("Enter the price:\n");
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &pricee))
			printf("Wrong number.Try again\n"); else break;
	}

	printf("Enter the Tour's name:\n");
	rewind(stdin);
	while (1) {

		scanf("%c", &symbol);  //enter a letter
		if (symbol == '\n') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			namee[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		namee = (char*)realloc(namee, amount * sizeof(char)); //we just extend our massive
		namee[pos] = symbol; //one more letter is entered:)
		pos++; //transfer to the next position
	}

	printf("What would you like to enter?\n0-The Tour's date of start\n1-The Tour's duration\n");
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &unionFlag) || unionFlag != 1 && unionFlag != 0)
			printf("Wrong number!Try again\n");
		else break;
	}
	switch (unionFlag) {
	case 0:
		printf("Please,enter the Date of start:\n");
		rewind(stdin);
		fgets(datee, 9, stdin);
		break;
	case 1:
		printf("Please,enter the The Tour's duration\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &dayss))
				printf("Wrong number!Try again\n");
			else break;
		}
		break;
	}

	for (current = head; current != NULL; current = current->next, Amount++) {//checkimg for all parameteres
		if (unionFlag == current->flag) {
			if (strcmp(current->name, namee) == 0 && pricee == current->price)
				if (unionFlag == 0)
				{
					if (strcmp(datee, current->unite.date) == 0) {
						searchFlag = 1;//found sth
						isEmptyPrint(head, Amount);
					}
				}
				else if (unionFlag == 1) {
					if (dayss == current->unite.days) {
						searchFlag = 1;//found sth 
						isEmptyPrint(head, Amount);
					}
				}
		}
	}
	printf("\n");
	if (searchFlag == 0) {//didn't find anything--show a message
		system("CLS");
		printf("Nothing was found :(\n");
		Sleep(1000);
		system("CLS");
	}

}

void inputIntoText(Tours* head, char* arr) {
	Tours* current = head;
	//char addInformation;
	int i = 0;
	FILE* f;
	fpos_t endSet = 0;

	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "a+")) == NULL) {
			system("CLS");
			printf("Open error\n");
			Sleep(900);
			system("CLS");
			return 0;
		}
		while (current) {
			fsetpos(f, &endSet);
			fprintf(f, "%d", i);
			fprintf(f, "%c", '.');
			fprintf(f, "%s", "Name:");
			fprintf(f, "%s", current->name);
			fprintf(f, "%c", ' ');
			fprintf(f, "%s", "Price:");
			fprintf(f, "%d", current->price);
			if (current->flag == 0) {
				fprintf(f, "%c", ' ');
				fprintf(f, "%s", "Date of start:");
				fprintf(f, "%s", current->unite.date);
			}
			else {
				fprintf(f, "%c", ' ');
				fprintf(f, "%s", "Trips's duration:");
				fprintf(f, "%d", current->unite.days);
			}
			fprintf(f, "%c", '\n');
			current = current->next;
			i++;
		}

		fclose(f);
		break;
	}
	system("CLS");
	printf("Done\n");
	Sleep(600);
	system("CLS");

}

void inputIntoBin(Tours* head, FILE* f) {
	Tours* p = head;
	int i = 0;
	char c, name[20];
	char name_f[100];
	char date[100];
	char* arr = malloc(sizeof(char));
	char symbol;
	int length = 1;
	char enter = '\n';


	while (1) {

		i = 0;
		fwrite(&(head->price), sizeof(int), 1, f);
		strcpy(name_f, head->name);//just copy name from a list to char massive
		while (name_f[i]) {//writing symbol after symbol into bin file our name
			fwrite(&name_f[i], sizeof(char), 1, f);
			i++;
		}
		fwrite(&name_f[i], sizeof(char), 1, f);//to input '\0'
		i = 0;
		fwrite(&(head->flag), sizeof(int), 1, f);
		if (head->flag == 0) {
			strcpy(date, head->unite.date);//just copy date from a list to char massive
			while (date[i]) {
				fwrite(&date[i], sizeof(char), 1, f);
				i++;
			}
			date[i] = '\0';
			fwrite(&date[i], sizeof(char), 1, f);

		}
		else {
			fwrite(&(head->unite.days), sizeof(int), 1, f);
		}
		fwrite(&enter, sizeof(char), 1, f);
		if (!((head)->next)) {
			break;
		}

		head = (head)->next;

	}

	system("CLS");
	printf("Done\n");
	Sleep(600);
	system("CLS");
}

void FileCreate(Tours** head) {
	int choice;
	char symbol;
	char* arr;
	int i = 0, length = 1;
	int max;
	int Amount;//of numbers
	arr = (char*)malloc(1 * sizeof(char));

	while (1) {
		printf("Please,choose the file type\n1-Text\n2-Binary\n3-Exit\n");
		rewind(stdin);
		scanf_s("%d", &choice);
		if (choice == 1) {                                                              //TEXT
			printf("Please enter the file name:\n");
			rewind(stdin);
			while (1) {
				scanf("%c", &symbol);
				if (symbol == '\n') {

					if (arr[i - 4] == '.' && arr[i - 3] == 't' && arr[i - 2] == 'x' && arr[i - 1] == 't') {
						arr[i] = '\0';
						break;
					}

					if (arr[i - 1] == '.') {
						length += 3;
						arr = (char*)realloc(arr, length * sizeof(char));
						arr[i] = 't';
						arr[i + 1] = 'x';
						arr[i + 2] = 't';
						arr[i + 3] = '\0';
						break;
					}

					length += 4;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = '.';
					arr[i + 1] = 't';
					arr[i + 2] = 'x';
					arr[i + 3] = 't';
					arr[i + 4] = '\0';
					break;
				}
				arr[i] = symbol;
				i++;
				length++;
				arr = (char*)realloc(arr, length * sizeof(char));
			}
			rewind(stdin);
			system("CLS");
			inputIntoText(head, arr);

			break;
		}
		else if (choice == 2) {                                                           //bINARY
			printf("Please enter the file name:\n");
			rewind(stdin);
			while (1) {
				scanf("%c", &symbol);
				if (symbol == '\n') {

					if (arr[i - 4] == '.' && arr[i - 3] == 'b' && arr[i - 2] == 'i' && arr[i - 1] == 'n') {
						arr[i] = '\0';
						break;
					}

					if (arr[i - 1] == '.') {
						length += 3;
						arr = (char*)realloc(arr, length * sizeof(char));
						arr[i] = 'b';
						arr[i + 1] = 'i';
						arr[i + 2] = 'n';
						arr[i + 3] = '\0';
						break;
					}

					length += 4;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = '.';
					arr[i + 1] = 'b';
					arr[i + 2] = 'i';
					arr[i + 3] = 'n';
					arr[i + 4] = '\0';
					break;
				}
				arr[i] = symbol;
				i++;
				length++;
				arr = (char*)realloc(arr, length * sizeof(char));
			}
			rewind(stdin);
			FILE* file;
			if ((file = fopen(arr, "ab+")) == NULL) {
				system("CLS");
				printf("Open error\n");
				Sleep(900);
				system("CLS");
				return 0;
			}
			system("CLS");
			inputIntoBin(head, file);
			fclose(file);

			break;
		}

		else if (choice == 3) return 0;
		else {
			system("CLS");
			printf("Wrong number!\n");
			Sleep(900);
			system("CLS");
			return 0;
		}
	}
}

int UploadBin(Tours** head, Tours** tail) {
	FILE* f;

	Tours* p;
	char file, c;
	int i = 0;
	char name[20];
	char name_for_copy[100], date[100];
	char* arr = malloc(sizeof(char));
	char symbol;
	int length = 1;
	int amountOfEnters = 0;
	printf("Please enter the file name:\n");
	rewind(stdin);
	while (1) {
		scanf("%c", &symbol);
		if (symbol == '\n') {

			if (arr[i - 4] == '.' && arr[i - 3] == 'b' && arr[i - 2] == 'i' && arr[i - 1] == 'n') {
				arr[i] = '\0';
				break;
			}

			if (arr[i - 1] == '.') {
				length += 3;
				arr = (char*)realloc(arr, length * sizeof(char));
				arr[i] = 'b';
				arr[i + 1] = 'i';
				arr[i + 2] = 'n';
				arr[i + 3] = '\0';
				break;
			}

			length += 4;
			arr = (char*)realloc(arr, length * sizeof(char));
			arr[i] = '.';
			arr[i + 1] = 'b';
			arr[i + 2] = 'i';
			arr[i + 3] = 'n';
			arr[i + 4] = '\0';
			break;
		}
		arr[i] = symbol;
		i++;
		length++;
		arr = (char*)realloc(arr, length * sizeof(char));
	}
	rewind(stdin);
	system("CLS");

	if (!(f = fopen(arr, "rb+"))) {
		system("CLS");
		printf("Error opening\n");
		Sleep(900);
		system("CLS");
		return 0;
	}
	rewind(stdin);
	while (!feof(f)) {//wanna know how many strings(lists) i have in file
		fread(&symbol, sizeof(char), 1, f);
		if (symbol == '\n')
			amountOfEnters++;
	}
	amountOfEnters--;//one '\n' extends my number of strings 
	//amountOfEnters--;
	i = 0;
	rewind(f);
	while (amountOfEnters > 0) {
		c = ' ';
		i = 0;

		if (feof(f)) {
			break;
		}

		if (!(p = (Tours*)malloc(sizeof(Tours)))) {
			system("CLS");
			printf("Error allocating memory\n");
			Sleep(1000);
			system("CLS");
			return 0;
		}
		if (*head == NULL) {//we don't have any lists 
			*head = p;
			p->next = NULL;
			*tail = p;

		}
		else {
			(*tail)->next = p;
			p->next = NULL;
			(*tail) = p;

		}


		fread(&(p)->price, sizeof(int), 1, f);
		while (1) {
			fread(&name_for_copy[i], sizeof(char), 1, f);
			if (name_for_copy[i] == '\0') {
				break;
			}
			i++;
		}
		(p)->name = (char*)calloc(30, sizeof(char));
		strcpy((p)->name, name_for_copy);
		i = 0;
		fread(&(p)->flag, sizeof(int), 1, f);
		if ((p)->flag == 0) {
			while (1) {
				fread(&date[i], sizeof(char), 1, f);
				if (date[i] == '\0') {
					break;
				}
				i++;
			}

			strcpy((p)->unite.date, date);
		}
		else {
			fread(&(p)->unite.days, sizeof(int), 1, f);
		}



		if (feof(f)) {
			break;
		}

		fread(&symbol, sizeof(char), 1, f);
		if (feof(f)) {
			break;
		}
		amountOfEnters--;
	}

	fclose(f);
	system("CLS");
	printf("Done\n");
	Sleep(600);
	system("CLS");
	return 1;

}

void TextUpload(Tours** head, Tours** tail) {
	char* arr;
	char* name, * data;
	int price;
	int flag;
	int days;
	char symbol;
	FILE* f;
	fpos_t current = 0;
	int i = 0, length = 1;
	int amount = 0;// Counter of amount of Lists for my reversePushing Function

	int amount1 = 0;
	char symbol1;
	char symbol2;
	int flag1 = 0;

	char number;//for the number of the string:1 or 2 and more importantly 13
	arr = (char*)malloc(1 * sizeof(char));
	name = (char*)malloc(1 * sizeof(char));
	data = (char*)malloc(9 * sizeof(char));
	printf("Please enter the file name:\n");
	rewind(stdin);
	while (1) {
		scanf("%c", &symbol);
		if (symbol == '\n') {

			if (arr[i - 4] == '.' && arr[i - 3] == 't' && arr[i - 2] == 'x' && arr[i - 1] == 't') {
				arr[i] = '\0';
				break;
			}

			if (arr[i - 1] == '.') {
				length += 3;
				arr = (char*)realloc(arr, length * sizeof(char));
				arr[i] = 't';
				arr[i + 1] = 'x';
				arr[i + 2] = 't';
				arr[i + 3] = '\0';
				break;
			}

			length += 4;
			arr = (char*)realloc(arr, length * sizeof(char));
			arr[i] = '.';
			arr[i + 1] = 't';
			arr[i + 2] = 'x';
			arr[i + 3] = 't';
			arr[i + 4] = '\0';
			break;
		}
		arr[i] = symbol;
		i++;
		length++;
		arr = (char*)realloc(arr, length * sizeof(char));
	}
	rewind(stdin);
	system("CLS");
	if ((f = fopen(arr, "r+")) == NULL) {
		system("CLS");
		printf("Open error\n");
		Sleep(900);
		system("CLS");
		return 0;
	}

	fseek(f, 0, 0);
	while (1) {//findin out how many lists we have
		fscanf(f, "%c", &symbol1);
		if (symbol1 == '\n')
			amount1++;
		if (feof(f))
			break;

	}
	amount1--;//one '\n' spoils my number 

	rewind(stdin);
	fseek(f, 0, 0);
	while (amount1 > 0) {
		fseek(f, 7, 1);//i start lik1 '1.Name:' soo need to get right to the info 


		length = 1;
		i = 0;
		while (1) {
			fscanf(f, "%c", &symbol);
			if (symbol == ' ') {
				name[i] = '\0';
				break;
			}
			name = (char*)realloc(name, ++length * sizeof(char));
			name[i++] = symbol;
		}

		fseek(f, 6, 1);//the goes 'Price:' so need to get to the info
		fscanf(f, "%d", &price);
		fseek(f, 1, 1);
		fscanf(f, "%c", &symbol);
		if (symbol == 'D') {
			flag = 0;
			fseek(f, 13, 1);//'Date of start:' info after
			i = 0;
			while (1) {
				fscanf(f, "%c", &symbol);
				if (symbol == '\n') {
					data[i++] = '\0';

					pushSpecialDate(head, tail, name, price, data);

					if (feof(f))
						break;

					amount1--;

					if (amount1 < 1) {
						system("CLS");
						printf("Done\n");
						Sleep(600);
						system("CLS");

						return;
					}

					break;
				}

				data[i++] = symbol;


			}
		}
		else {
			flag = 1;
			fseek(f, 16, 1);//'Trip's duration:' info after

			fscanf(f, "%d", &days);
			fscanf(f, "%c", &symbol);

			pushSpecialDays(head, tail, name, price, days);
			if (feof(f))
				break;

			amount1--;
			if (amount1 < 1) {
				system("CLS");
				printf("Done\n");
				Sleep(600);
				system("CLS");
				return;
			}


		}


	}
	fclose(f);
	system("CLS");
	printf("Done\n");
	Sleep(600);
	system("CLS");

}
