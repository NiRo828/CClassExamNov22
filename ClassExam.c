#include <stdio.h> //Q1 PreProcesseor Syntax was wrong<>
#include <stdlib.h> 
#pragma warning(disable:4996) 



/********************   Q1    ************************************/
int main_Qone() 
{
    int a = 4; // Can be initialized "int a ,b;" 
    int b = 7;
    float c=0; // UnInitialized float + Indentation was out of place
    scanf("%f", &c);    
    if (5 == c)//Condition missed '='
    {
        printf("%f", c);
    }
    else
    {
        printf("Not My Number");
    } 
    return;
}

/********************   Q2    ************************************/
int main_Qtwo()

{
    int x, y;
    int nums[6];
    int* arrPtr;


    // Section A - Print the variables 

    puts("** Section A **");

    //printf(" Base = %d\n", x);// x Not Contained with value
    x = 7;
    printf(" Base = %d\n", x);

    //printf(" Height = %d\n", y);// y Not Contained with value
    y = 14;
    printf(" Height = %d\n", y);

    printf(" Area = %d\n", x * y);



    // Section B - Print the static array "nums". 

    puts("**** Section B ****");

    int i = 0;

    while (i < 6)  // Infinite while loop / No promotion made to Index i/
    {

        //printf("  nums[%d] = %d\n", i, nums[i]);/ Array initialized with trash.
        nums[i] = i;//Add values to array so they could be printed.
        printf("  nums[%d] = %d\n", i, nums[i]);
        i++; 
    }



    // Section C - Print allocated array. 

    puts("** Section C **");

    //arrPtr = malloc(sizeof(int) * 10); // Allocates excess place
    arrPtr = (int*)malloc(sizeof(int) * 6);

    if (arrPtr) {

        for (i = 0; i < 6; i++) {
            arrPtr[i] = i * 5;
            printf("  array[%d] = %d\n", i, arrPtr[i]);
        }
    }
    else {
        printf("Error Allocating Memory!\n");
        exit(1);
    }
    return 0;

} // Missing Syntax a "}"

/********************   Q3    ************************************/

// struct to collect counting info about english letters found in a text file. 

typedef struct letter {

    char small;

    char big;

    int counter;

    struct letter* next;
    struct letter* prev;


}letter;


//Function to free linked list 

void freeList(letter* head) {

    letter* releaseItem;

    letter* runItem = head;

    while (runItem != NULL) 
    {

        releaseItem = runItem;

        runItem = runItem->next;

        free(releaseItem);

    }

}


int main_Qthree()

{

    //Next two string represents all the english alphabets (small and capital) 

    char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";

    char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int lettersCountArr[26] = { 0 };

    char readChar, ch;

    FILE* f;



    f = fopen("myFile.txt", "r");
    fputs("This is D String.",f);
    fclose(f);



    // Display the content of myFile.txt and count letters 
    f = fopen("myFile.txt", "r");
    printf("the content of myFile.txt :\n");



    while ((readChar = fgetc(f)) != EOF) {

        printf("%c", readChar);



        for (int i = 0; i < strlen(smallAlpha); ++i) {

            if (readChar == smallAlpha[i] || readChar == bigAlpha[i])

                lettersCountArr[i]++;

        }

    }

    fclose(f);





    // Build Linked list from file content 

    // Every node represent English letter (small and big). 

    letter* HEAD = NULL;

    letter* TAIL = NULL;



    for (int j = 0; j < strlen(smallAlpha); ++j) {

        letter* letterItem = (letter*)malloc(sizeof(letter));

        if (!letterItem) {

            puts("Error Allocating Memory!");

            exit(1);

        }

        letterItem->small = 'a' + j;

        letterItem->big = 'A' + j;

        letterItem->counter = lettersCountArr[j];



        // Creating the linked list 
        if (HEAD == NULL)
        {
            HEAD = TAIL = letterItem;
            letterItem->next = NULL;
            letterItem->prev = NULL;
        }
        else
        {
            TAIL->next = letterItem;
            letterItem->prev = TAIL;
            letterItem->next = NULL;

            TAIL = letterItem;
        }
    }
    return 0;

}




/****************   Q2 Not Working       ***********************/
//int main()
//
//{
//    typedef struct MyTriangle
//    {
//        int Height;
//        int Base;
//        int Area;
//        
//
//    }Tri;
//
//    Tri* retTri = (Tri*)malloc(sizeof(retTri));
//    if (!retTri)
//    {
//
//        puts("***** Section A *****");
//
//        printf(" Base = %d\n", retTri->Base);
//
//        printf(" Height = %d\n", retTri->Height);
//        
//        printf(" Area = %d\n", retTri->Area=retTri->Height*retTri->Base );
//    }
//    else
//    {
//        printf("Triangle Not Allocated");
//    }
//    
//    //int x, y;
//
//    int nums[6];
//
//    int* arrPtr;
/****************    Not Working       ***********************/
