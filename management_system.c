#include<stdio.h>
#include<math.h>
#include<string.h>

struct meal_count 
{
   
   int chart[30][10][3];
   int person[10];
   int x;
   int day1;
   
};

struct money_management
{
    float money[10];
    float total_breakfast_cost[300];
    float total_lunch_cost[300];
    float total_dinner_cost[300];
    float total_money;

};

struct food
{
    char breakfast[20];
    char lunch[20];
    char dinner[20];
    float meal_rate_breakfast;
    float meal_rate_lunch;
    float meal_rate_dinner;
    
};

struct people
{
    char name[30];
    int count;
    
};


void add_people(struct people s[], int *person);
void food(struct food a[], struct meal_count b , int *y);
void people_details(struct people s[], int  person);
void money_management(struct money_management c, struct people s[] , struct meal_count b, int person);
void meal_count(struct meal_count b, struct people s[], struct money_management c , struct food a[] ,int *y );
void money_details(struct money_management c, struct people s[] , struct meal_count b);
void meal_chart(struct meal_count b , struct people s[] );



int main()
{
    struct people s[100];
    struct food a[100];
    struct meal_count b;
    struct money_management c;
    int  person=0;
    int x , y=0;
    int i;
    for(i=0;i<1000;i++)
    {
        printf("   MEAL MANAGEMENT SYSTEM    \n");
        printf("\n");
        printf("1. Add people.\n");
        printf("2. people datails.\n");
        printf("3. Enter today's food details.\n");
        printf("4. MEAL COUNT \n");
        printf("5. MEAL CHART.\n");
        printf("6. Add money of bazaar.\n");
        printf("7. See money details.\n");
        printf("8. Exit.\n");
        printf("\n");
        printf("Enter task NO. :");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
        {
          add_people(s , &person);
            
          break;
        }
        case 2:
          people_details(s, person);
            
            break;
        case 3:
          food(a , b , &y );
          break;
        case 4:
          meal_count(b,s,c,a ,&y );
          break;
        case 5:
         meal_chart(b,s);
         break;
        case 6:
          money_management(c,s,b,person);
          break;
        case 7:
          money_details(c,s,b);
          break;
        case 8:
          return 0;
          break;
        }
    }
   return 0;
}
 
 void add_people(struct people s[], int *person)
{
   struct people new;
   char choice[10];
   
   while(1)
   {
    printf("You can add maximum 10 member !!\n");
     printf("Add ?(yes/no) : ");
     scanf("%s", choice);
     if(strcmp(choice ,"yes")==0)
     {
        
        printf(" PERSON %d \n \n Enter Name :", *person+1);
        scanf("%s", new.name );
        
        printf("new people is added.\n");
        printf("\n");
        new.count=*person;
        s[*person]=new;
        *person+=1;
        new.count=*person+2;
     }
     else if(strcmp(choice,"no")==0)
     {
        break;
     }
   }
}




void money_details(struct money_management c, struct people s[] , struct meal_count b)
{
    printf("MONEY LEFT :\n");
    printf("Total money left : %2f\n", c.total_money);
    printf("\n");
    printf("Individually money left :\n");

   for(int i=0;i<10;i++)
   {
    
    printf("%s : %2f\n", s[i].name , b.person[i] );

   }

}
void food(struct food a[], struct meal_count b , int *y)
{
    
getchar();
    printf("DAY %d \n \n" , *y);
    printf("Enter the name of food for Breakfast :");
    fgets(a[*y].breakfast , sizeof(a[*y].breakfast), stdin);
    printf("Avarage meal rate per person:");
    scanf("%f", &a[*y].meal_rate_breakfast);

getchar();
    printf("DAY %d \n \n" , *y);
    printf("Enter the name of food for Lunch :");
    fgets(a[*y].lunch , sizeof(a[*y].lunch), stdin);
    printf("Avarage meal rate per person:");
    scanf("%f", &a[*y].meal_rate_lunch);

getchar();
    printf("DAY %d \n \n" , *y);
    printf("Enter the name of food for Dinner :");
    fgets(a[*y].dinner , sizeof(a[*y].dinner), stdin);
    printf("Avarage meal rate per person:");
    scanf("%f", &a[*y].meal_rate_dinner);


    printf("Todays food is added for today .\n");
    (*y)++;
    
}





void people_details(struct people s[], int  person)
{ 
    int i;
    for(i=0;i<person;i++)
    {
        printf("PERSON %d (serial number) : \n" , i+1);
        printf("Name: %s\n", s[i].name);
        printf("\n");
        printf("\n");

    }
}

void money_management(struct money_management c, struct people s[] , struct meal_count b, int person)
{
    int i;
    printf("ADD MONEY \n");
    for(i=0; i<person;i++)
    {
       printf("%s:", s[i].name);
       getchar();
       scanf(" %2f ", &c.money[i]);
       c.total_money+=c.money[i];
    }
    printf("MONEY IS ADDED !!\n");
}

void meal_count(struct meal_count b, struct people s[], struct money_management c, struct food a[], int *y)
{
    int p, q;
    printf("1. Count meal\n");
    
    printf("3. Go to main menu\n");
    scanf("%d", &p);
    switch(p)
    { 
        case 1:
        printf("Enter the serial number of the member: ");
        scanf("%d", &q); 
        q-=1;
        printf("DAY %d:\n", *y + 1);
        printf("%s:\n", s[q].name);
        
      
        printf("Breakfast: %s and meal rate: %.2f\n", a[*y].breakfast, a[*y].meal_rate_breakfast);
        printf("Add meals: ");
        scanf("%d ", &b.chart[*y][q][0]);  
        c.money[q] -= (a[*y].meal_rate_breakfast) * b.chart[*y][q][0];  
        
        
        printf("Lunch: %s and meal rate: %.2f\n", a[*y].lunch, a[*y].meal_rate_lunch);
        printf("Add meals: ");
        scanf("%d ", &b.chart[*y][q][1]);  
        c.money[q] -= (a[*y].meal_rate_lunch) * b.chart[*y][q][1]; 
        
        
        printf("Dinner: %s and meal rate: %.2f\n", a[*y].dinner, a[*y].meal_rate_dinner);
        printf("Add meals: ");
        scanf("%d ", &b.chart[*y][q][2]);  
        c.money[q] -= (a[*y].meal_rate_dinner) * b.chart[*y][q][2];  
        
        break;

    case 2:
        break;
    }
}


void meal_chart(struct meal_count b, struct people s[])
{
    int i, j;

    printf("Meal Chart:\n");
    
    printf("      ");
    for (i = 0; i < 10; i++)
    {
        printf("%s \t", s[i].name);
    }
    printf("\n");

    
    for (i = 0; i < 30; i++)  
    {
        printf("Day %d: ", i + 1);
        
        for (j = 0; j < 10; j++)  
        {
            printf("%d %d %d \t",  b.chart[i][j][0], b.chart[i][j][1], b.chart[i][j][2]);         
        }
        printf("\n");
    }
}


