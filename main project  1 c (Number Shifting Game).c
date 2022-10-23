
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void rules();
void showmatrix(char *p);
void randommatrix(char *p);
 int rightkey(char *p);
 int leftkey(char *p);
 int upkey(char *p);
 int downkey(char *p);
 int input();
 void swap(char *p, char*q);
 int winner(char *p);


int main()
{
   char name[20];
   printf("Players name: ");
   fgets(name,20,stdin);
   system("cls");
   int len;
   for(len=0;name[len];len++);
    name[len-2]=='\0';
      char arr[16];
      char *p;
      p=arr;
   
   while(1)
   {
    system("cls");
      rules();
     char a;
    scanf("%c",&a);
    system("cls");
    
    randommatrix(arr);
    
    int remainingtry=10;
    while(!winner(arr))
    {   
        if(!remainingtry)
         break;
        system("cls");
        printf("\n\n         Hello %s  , Move remaining : %d\n",name,remainingtry);
        showmatrix(arr);
       int b=input();
        switch(b)
        {   
            case 27:
            {
                printf("              press 'ENTER' to exit the game\n");
                char e=input();
                return 0;
            }
            case 77:
             {
                 if(rightkey(arr))
                 remainingtry--;
                break;
             }
             case 75:
             {
                 if(leftkey(arr))
                 remainingtry--;
                break;
             }
             case 72:
             {
                 if(upkey(arr))
                 remainingtry--;
                break;
             }
             case 80:
             {
                 if(downkey(arr))
                 remainingtry--;
                break;
             }
             default:
             {
                 printf("Enter a valid key\n");
             }
        }
    }
    if(remainingtry==0)
    {
        printf("          You lose! \n");
    }
    if(winner(arr))
    {
        printf("          hurray! You Win   \n");
    }
    
    printf("Do you want to play again: if yes press 'y' otherwise 'n' for no:");
    char check=input();
    if(check==78 || check==110)
    {
        break;
    }
    
   }
   

return 0;
}
   
  void rules()
  {
   printf("\n\n                   RULES OF THIS GAME\n\n");
   printf("     1. You can move only 1 step at a time with the arrow key.\n");
   printf("          MOVE UP: by up arrow key\n");
   printf("          MOVE DOWN: by down arrow key\n");
   printf("          MOVE LEFT: by left arrow key\n");
   printf("          MOVE RIGHT: by right arrow key\n\n");
   printf("     2. You can move numbers at an empty position only.\n");
   printf("     3. For each valid move : your total number of moves will decrease by 1.\n");
   printf("     4. Winning Situation :\n         Number in a 4*4 matrix should be in order from 1 to 15\n");
   printf("           ---------------------\n");
   int count=1;
   for(int i=0;i<=3;i++)
   {   
       printf("           ");
       for(int j=0;j<=3;j++)
       {   if(count==16)
            { printf("|    ");
             break;}
            else if(count<=9) 
            { printf("| %d  ",count);
              count++;}
             else
               { printf("| %d ",count);
              count++;}
       }
       printf("|");
       printf("\n");
   }
    printf("           ---------------------\n");
    printf("     5.You can exit the game at any time by pressing Escape Key\n      so try to win by minimum no of move\n");
    printf("                     Happy Gaming, Good luck\n\n");
    printf("     Enter any key to start.......");
  } 
  
  
  //for creating the random matrix
  void randommatrix(char *p)
  {   
      int  n[15],lastindex=14;
      for(int i=0;i<15;i++)
         {
             n[i]=i+1;
         }
      srand(time(NULL));   //using srand for monitoring the seed value,time() is used to generate the different seq in different runs
      int i;
      for( i=0;i<15;i++)
      {
         int index=rand()%(lastindex+1);    //rand is used to generate the random numbers
         p[i]=n[index];
         n[index]=n[lastindex--];
      }
      p[i]=' ';
      
  }
  
  //to show the matrix
  
  void showmatrix(char *p)
  {
       printf("           -------------------------\n");
       int count=0;
      for(int i=0;i<4;i++)
      {  
          printf("           ");
          printf("| ");
      
          for(int j=0;j<4;j++)
          {  
              if(p[count]!=' ')
              {   
                  if(p[count]<=9)
                 { printf(" %d  | ",p[count]);
                  count++;}
                  else
                   {printf("%d  | ",p[count]);
                   count++;}
              }
              else
              {
                   printf(" %c  | ",p[count]);
                   count++;
              }
          }
          printf("\n");
      }
      printf("           -------------------------\n");
  }

//to take the input
   int input()
   {  
    //   fflush(stdin);
      char c=getch();
      if(c==8)
        c=input();
    return c;
   }
    
    
 int rightkey(char *p)
 {   
     int i;
     for( i=0;i<16;i++)
     {
         if(p[i]==' ')
           break;
     }
     if(i%4==0)
       return 0;
     int j=i-1;  
     swap(p+i,p+j);
     return 1;
 }
 int leftkey(char *p)
 {
     int i;
     for( i=0;i<16;i++)
     {
         if(p[i]==' ')
           break;
     }
     if(i==3 || i==7 || i==11 || i==15)
       return 0;
     int j=i+1;  
     swap(p+i,p+j);
     return 1;
 }
  int upkey(char *p)
  {
      int i;
     for( i=0;i<16;i++)
     {
         if(p[i]==' ')
           break;
     }
     if(i>=12)
       return 0;
     int j=i+4;  
     swap(p+i,p+j);
     return 1;
  }
  
   int downkey(char *p)
   {
       int i;
     for( i=0;i<16;i++)
     {
         if(p[i]==' ')
           break;
     }
     if(i<=3)
       return 0;
     int j=i-4;  
     swap(p+i,p+j);
     return 1;
   }
 
 // for swap the values by passing the address
 void swap(char *p,char *q)
 {
     char temp=*p;
          *p=*q;
          *q=temp;
 }
 
 //to check the matrix for wiining situation
 int winner(char *p)
 {   
     int i;
     for( i=0;i<15;i++)
     {
         if(p[i]!=i+1)
          break;
     }
     if(i==15)
      return 1;
     return 0; 
 }





