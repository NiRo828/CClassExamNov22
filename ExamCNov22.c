#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996) 


void main_QCone()
{
	char OrigStr[100] = "0123456789";//HardCode
	char FirstHalf[50];
	char SecondHalf[50];
	int MidString;
	
	//printf("Enter a sentence: ");//Get from user
	//gets(str1);
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(OrigStr));
	
	
	/* copy to sized buffer (overflow safe): */
	strncpy(FirstHalf, OrigStr, sizeof(FirstHalf));
	int StrCount = (unsigned)strlen(OrigStr);
	//printf("%u", strlen(str1));
	MidString = StrCount /2;

	/* partial copy (MidString): */
	strncpy(SecondHalf, OrigStr, MidString);
	SecondHalf[MidString] = '\0';   /* null character manually added */

	//puts(str1);
	puts(FirstHalf);
	puts(SecondHalf);

	return 0;
}

void main_QCtwo()
{
	char OrigStr[100];

	scanf("%s", &OrigStr);
	int OrigStrlen = strlen(OrigStr) / 2;
	
	for (int i = 0; i < strlen(OrigStr); i++)
	{
		printf("%c", OrigStr[i]);
	
		if (OrigStrlen == 1)
		{
			return;
		}
		if (i == OrigStrlen)
		{
			printf("\n");
			i = 0;
			OrigStrlen = OrigStrlen / 2;
		}

	}
}

void main_QCthree(int number)
{
	printf("%d\n", number);
	
	if (number==100)
	{
		return;
	}
	
	main_QCthree(number + 1);
}

typedef struct s_Lotto
{
	int Raffle_ID;
	char Raffle_Date[20];
	char Numbers[50];
	struct s_Lotto* next;
	struct s_Lotto* prev;

}Lotto;
Lotto* Head = NULL;
Lotto* Tail= NULL;

void ReadFile();
void CreateDictionary(Lotto*curr);
void Search(int number);


void main_QCfour()
{
	char UserResponse = 0;
	printf("Hello Dear Gambler\n What's Your Desired Raffle ID: ");
	
	while (UserResponse != 'Q')
	{
		scanf("%c", &UserResponse);

		switch (UserResponse)
		{
		case 'R':
			ReadFile();
			printf("Read File\n");
			break;

		case 'S':
			printf("choose lottery Number to search\n");
			int number;
			scanf("%d", &number);
			Search(number);
			break;

		
		default:
			printf("Too Bad... Raffle ID Does Not Exist\n");
			break;
		}
		printf("Hello Dear Gambler\n What's Your Desired Raffle ID: ");
	}
	printf("See You In The Next Raffle Mate!\n");
}

void ReadFile()
{

	FILE* Lotto_file = fopen("Lotto.txt", "r");
	if (!Lotto_file)
	{
		//error
	}
	char str[1000];
	char* token = NULL;
	fgets(str, 1000, Lotto_file);
	while (str[0] != NULL)
	{
		Lotto* curr;
		curr = (Lotto*)malloc(sizeof(Lotto));
		if (!curr)
		{
			//log error;
			return;
		}
		token = strtok(str, ",");
		int num;
		num = atoi(token);
		curr->Raffle_ID = num;

		token = strtok(NULL, ",");
		
		strcpy(curr->Raffle_Date, token);

		token = strtok(NULL, "\n");
		strcpy(curr->Numbers, token);

		CreateDictionary(curr);
		

		str[0] = NULL;
		fgets(str, 1000, Lotto_file);


	}

}

void Search(int number)
{
	Lotto* Find;
	Find = Head;

	while (Find->Raffle_ID != number)
	{
		if (Find->next != NULL)
		{
			Find = Find->next;
		}
		else
		{
			printf("Too Bad... Raffle ID Does Not Exist\n");
			return;
		}

	}
	printf("%s\n", Find->Raffle_Date);
}

void CreateDictionary(Lotto* curr)
{

	if (Head == NULL)
	{
		Head = Tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		Tail->next = curr;
		curr->prev = Tail;
		curr->next = NULL;

		Tail = curr;
	}

}

void CopyChar(char* dst, char* src, int size)
	{
		for (int i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}

int main()
{
	main_QCfour();
}