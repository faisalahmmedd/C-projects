#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>
typedef struct Student student;

struct Student{
      int id;
      char name[30];
      float gpa;

};

void addStudentInfo()
{
    FILE *file = fopen("students.txt","a");

    if(file==NULL)
    {
        printf("File does not open\n");
        exit(1);
    }


    student s1;
    printf("Enter Student's id: ");
    scanf("%d",&s1.id);
    getchar();
    printf("Enter student's  Name: ");
    scanf("%s",s1.name);

    printf("Enter student's gpa out of 4.00: ");
    scanf("%f",&s1.gpa);



    fprintf(file,"%d %s %.2f\n",s1.id,s1.name,s1.gpa);

    fclose(file);

    printf("Student's Information added succesfully\n\n");


}

void showAllStudentsInfo()
{
    printf("\n\nAll the information of the students: \n");

    FILE* file = fopen("students.txt","r");

    if(file==NULL)
    {
        perror("File not opened\n");
        return;
    }
    student s1;

    while(fscanf(file,"%d %s %f",&s1.id,s1.name,&s1.gpa) != EOF)
    {
        printf("ID: %d, Name: %s, GPA: %.2f\n",s1.id,s1.name,s1.gpa);

    }

    fclose(file);


}

void updateStudentInfo()
{
    FILE* file = fopen("students.txt","r");
    FILE* file2 = fopen("temp.txt","w");

    if(file==NULL || file2==NULL)
    {
        printf("File not opened\n");
        return;
    }

    printf("Enter the id of the sutdent you want to update info:");
    int updateID;
    getchar();
    scanf("%d",&updateID);

    bool found = 0;
    student s1;

    while(fscanf(file,"%d %s %f",&s1.id,s1.name,&s1.gpa)!=EOF)
    {

        if(s1.id==updateID)
        {
           printf("Enter student's name: ");
           scanf("%s",s1.name);
           printf("Enter student's GPA out of 4: ");
           scanf("%f",&s1.gpa);
           found=1;
        }

        fprintf(file2,"%d %s %.2f\n",s1.id,s1.name,s1.gpa);
    }

    fclose(file2);
    fclose(file);


    remove("students.txt");
    rename("temp.txt","students.txt");


     if(!found)
    {
        printf("Student with %d ID not found on the list\n\n",updateID);
    }
    else
    {
         printf("Student info successfully udpated\n\n");
    }




}

void deleteStudentInfo()
{
    FILE *file=fopen("students.txt","r");
    FILE *file2=fopen("temp.txt","w");

    if(file2==NULL || file==NULL)
    {
        printf("File does not open\n");
        exit(1);
    }

    student s1;

    printf("Enter the ID of the student you want to delete: ");
    int deleteID;
    scanf("%d",&deleteID);

    bool found=0;

    while(fscanf(file,"%d %s %f",&s1.id,s1.name,&s1.gpa)!=EOF)
    {
        if(deleteID==s1.id)
        {
            found=1;
        }
        else
        {
            fprintf(file2,"%d %s %.2f\n",s1.id,s1.name,s1.gpa);
        }
    }


    fclose(file2);
    fclose(file);

    remove("students.txt");
    rename("temp.txt","students.txt");

    if(found)
    {
        printf("Successfully deleted info with %d ID\n\n",deleteID);
    }
    else
    {
        printf("Student with %d ID not found\n\n",deleteID);
    }

}

int main()
{
    while(1)
    {


        printf("\n\nWelcome to Student Management System.\n");
        printf("--------------------------------------\n\n");





        printf("1. Add the information of a student\n");
        printf("2. Dispaly all the student's information\n");
        printf("3. Update a student's information\n");
        printf("4. Delete a student's information\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");

        int choice;
        scanf("%d",&choice);


        switch(choice)
        {
        case 1:
            addStudentInfo();
            break;
        case 2:
            showAllStudentsInfo();
            break;
        case 3:
            updateStudentInfo();
            break;
        case 4:
            deleteStudentInfo();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Enter a valid operation\n");


        }
      //   system("cls");

    }
}
