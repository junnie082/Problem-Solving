//https://www.goeduhub.com/9692/to-implement-hashing-using-open-addressing-linear-probing

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert()
{
    int key, index, i, flag = 0, hkey;

    printf("Enter a value to insert into hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;

        if (h[index] == NULL) {
            h[index] = key;
            break;
        }
    }

    if (i == TABLE_SIZE) 
        printf("\nElement cannot be inserted!\n");    
}

void search()
{
    int key, index, i, flag = 0, hkey;

    printf("Enter search element: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;

        if(h[index] == key) {
            printf("Value is found at index: %d", index);

            break;
        }
    }

    if (i == TABLE_SIZE) 
        printf("Value is not found!");
}

void display()
{
    int i;
    printf("\nElements in the hash table are:");

    for(i = 0; i < TABLE_SIZE; i++)
        printf("\nAt Index: %d \t Value: %d", i, h[i]);
}

int main()
{
    clrscr();
    int opt i;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter the choice: ");

        scanf("%d", &opt);

        switch(opt) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                exit(0);

        }
    }
}