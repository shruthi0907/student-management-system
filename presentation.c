#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Student
{
    int rollnumber;
    char firstname[100];
    char secondname[100];
    char phone[100];
    char course[50];
    float cgp;
    struct Student *next;
    
}* head;
struct display
{
    int rollnumber;
    float cgp;
    struct display *next;
}*rear, *front;
void insert(int rollnumber, char* firstname,char* secondname, char* phone,char*course,float cgp)
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->firstname,firstname);
    strcpy(student->secondname,secondname);
    strcpy(student->phone, phone);
    strcpy(student->course,course);
    student->cgp = cgp;
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    
}
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("FirstName: %s\n", temp->firstname);
            printf("SecondName: %s\n", temp->secondname);
            printf("Phone: %s\n", temp->phone);
            printf("Course:%s\n",temp->course);
            printf("Cgp: %0.4f\n", temp->cgp);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(int rollnumber)
{
    
    struct Student * temp = head;
    while(temp!=NULL){
        
        if(temp->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new firstname: ");
            scanf("%s", temp->firstname);
            printf("Enter new secondname: ");
            scanf("%s", temp->secondname);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter your course of study:");
            scanf("%s",temp->course);
            printf("Enter new cgp: ");
            scanf("%f",&temp->cgp);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}
void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rollnumber==rollnumber){
            
            printf("Record with roll number %d Found !!!\n", rollnumber);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !!!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("FirstName: %s\n", temp->firstname);
        printf("SecondName: %s\n", temp->secondname);
        printf("Phone: %s\n", temp->phone);
        printf("Course:%s\n",temp->course);
        printf("cgp: %0.4f\n\n", temp->cgp);
        temp = temp->next;
        
    }
}
void queue()
{
	int x;
    struct display *newnode;
	struct Student *temp;
    newnode = (struct display *)malloc(sizeof(struct display));
    temp = head;
   	newnode->rollnumber=temp->rollnumber;
   	newnode->cgp=temp->cgp;    
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void cgpdisplay()
{
    struct display * temp = front;
    while(temp!=NULL)
	{        
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("cgp: %0.4f\n\n", temp->cgp);
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    int adminchoice;
    int studentchoice;
    char firstname[100];
    char secondname[100];
    char phone[100];
    char course[50];
    char pass[15];
    int rollnumber;
    float cgp;
    do
    {
    
    	system("cls");
    	printf("\n\n\t\t\t\t\t\t\tSTUDENT RECORD SYSTEM\n");
    	printf("\n\t\t\t\t=======================================================");
		printf("\n\n\t\t\t\t\t\t\tLOGIN\n");
		printf("\n\t\t\t\t=======================================================");
		printf("\n\n\t\t\t\t\t\t\t1.ADMIN");
		printf("\n\n\t\t\t\t\t\t\t2.STUDENTS");
		printf("\n\n\t\t\t\t\t\t\t3. Exit\n");
		printf("\n\t\t\t\t=======================================================");
		printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
		scanf("%d", &choice);
	    switch(choice)
	    {
	        case 1:
				printf("\n\n\n\n\n\n\t\t\t\t\t\tEnter admin password : ");
				scanf("%s", &pass);
				if("pass==20330")
				{
						do
					{
						printf("\n\t\t\t\t==========================================================");
						printf("\n\t\t\t\t\t\t\tADMIN PANEL");
					    printf("\n\t\t\t\t==========================================================");
						printf("\n\n\t\t\t\t\t\t1.To Insert Student Details ");
						printf("\n\n\t\t\t\t\t\t2.To Delete Student Details");
						printf("\n\n\t\t\t\t\t\t3.To Update Student Details ");
						printf("\n\n\t\t\t\t\t\t4. Back to Main page");
						printf("\n\t\t\t\t==========================================================");
						printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
					    scanf("%d",&adminchoice);
					    switch(adminchoice)
					    {
	
					    case 1:
					    	printf("Enter roll number: ");
                            scanf("%d", &rollnumber);
                            printf("Enter Firstname: ");
                            scanf("%s", firstname);
                            printf("Enter Secondname: ");
                            scanf("%s", secondname);
                            printf("Enter phone number: ");
                            scanf("%s", phone);
                            printf("Enter course of study:");
                            scanf("%s",course);
                            printf("Enter cgp: ");
                            scanf("%f", &cgp);
                            insert(rollnumber, firstname, secondname, phone,course, cgp);
                            queue();
                            break;
                        case 2:
                            printf("Enter roll number to delete: ");
                            scanf("%d", &rollnumber);
                            Delete(rollnumber);
                            break;
                        case 3:
                            printf("Enter roll number to update: ");
                            scanf("%d", &rollnumber);
                            update(rollnumber);
                            break;
                        }
						
					    }while(adminchoice!=4);
					    	break;
					
			case 2:
				printf("\n\n\n\n\n\n\t\t\t\t\t\tEnter student rollnumber : ");
				scanf("%s", &rollnumber);
				do
				{
				    printf("\n\t\t\t\t==========================================================");
					printf("\n\t\t\t\t\t\t VIEW STUDENT PORTAL");
				    printf("\n\t\t\t\t==========================================================");
					printf("\n\n\t\t\t\t\t1.To Search for Student Details");
					printf("\n\n\t\t\t\t\t2.To Display All Student Details");
					printf("\n\n\t\t\t\t\t3.To Display All Student CGP: ");
					printf("\n\n\t\t\t\t\t4. Back to Main Menu");
					printf("\n\t\t\t\t==========================================================");
					printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
				    scanf("%d",&studentchoice);
					switch(studentchoice)
					{
						case 1:
                             printf("Enter roll number to search: ");
                             scanf("%d", &rollnumber);
                             search(rollnumber);
                             break;
                        case 2:
                             display();
                             break;     
						case 3:
							 queue();
                             cgpdisplay();
                             break;  
					}
				}while(studentchoice!=4);
					    	break;
			}
		}
  }while(choice!=3);
}
