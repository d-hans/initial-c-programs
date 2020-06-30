#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 1

struct  record
{
    char name[30];
    int age;
    char sex;
    int salary;
};

void
get_input(struct record *memory, struct record **myrecord)
{
    printf("Enter the name:");
    scanf("%s", &memory->name[0]);

    printf("Enter age: ");
    scanf("%d", &memory->age);

    printf("Enter sex:");
    scanf(" %c", &memory->sex);

    printf("Enter salary:");
    scanf("%d", &memory->salary);

    *myrecord = memory;
}

void
print_input(struct record **dptr)
{
    printf("\nNAME: %s AGE: %d SEX: %c SALARY: %d\n",
            (*dptr)->name, (*dptr)->age,
            (*dptr)->sex, (*dptr)->salary);
}

int main()
{
    struct record *myrecord[ARRAY_SIZE];

    struct record **dptr = &myrecord[0];

    struct record *memory = (struct record *)malloc(sizeof(struct record) * ARRAY_SIZE);
    struct record *original_address = memory;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        get_input(memory, dptr);
        memory++;
        dptr++;
    }
    dptr= &myrecord[0];

    for (int j = 0; j < ARRAY_SIZE; j++)
    {
        print_input(dptr);
        dptr++;
    }
    free(original_address);

    return 0;
}

