#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#include "qsage.h"

int *visited;
int *result;
int *final;
int cost = 0, objective = 1000;
int b[4][4];

unsigned int bounds(unsigned int k);





/*----------------INITIALIZATION---------------------------*/


int tsproblem_init()
{

                             // loading cost matrix into b[4][4]
b[0][0]= a_a;
b[0][1]= a_b;
b[0][2]= a_c;
b[0][3]= a_d;
b[1][0]= b_a;
b[1][1]= b_b;
b[1][2]= b_c;
b[1][3]= b_d;
b[2][0]= c_a;
b[2][1]= c_b;
b[2][2]= c_c;
b[2][3]= c_d;
b[3][0]= d_a;
b[3][1]= d_b;
b[3][2]= d_c;
b[3][3]= d_d;


printf("\n\nNumber of Cities are: %d\n\n",N);

                                   // setting visited array to track visited cities
visited = malloc(N * sizeof(int));
memset(visited, 0,N * sizeof(int)); 


                                   // setting result array to store intermediate path
result = malloc((N+1) * sizeof(int));
memset(result, 0,(N+1)* sizeof(int)); 


                                   // setting final array to store minimized path
final = malloc((N+1) * sizeof(int));
memset(final, 0,(N+1)* sizeof(int)); 

 
return N*N;
}





/*---------------upper bound and lowerbound----------------*/


unsigned int bounds(unsigned int k)
{
int i = 0,j =0;
unsigned int min_value = 0 , max_value = 0 , m = 0,min_row = 0,max_row =0;

                                     // calculate minimum value when k=0
if (k==0) 
{     
 for(i=0;i<4;i++)
     {
      min_row = b[i][0];
      for(j=0;j<4;j++)
        {
         
         if (b[i][j]<min_row)        //min_row captures minimum element of each row
                min_row = b[i][j];

        }
        min_value += min_row;        //min_value calculates lower bound by adding all min_row's
}
return min_value;
}
                                     // calculate maximum value when k=1 
if (k==1)
{
  for(i=0;i<4;i++)
     {
      max_row = b[i][0];             //max_row captures maximum element of each row

      for(j=0;j<4;j++)
        {
              if (b[i][j]>max_row)
              max_row = b[i][j];
        }
              max_value += max_row;  //max_value calculates upper bound by adding all max_row's
     }
            


return max_value;
}
}



/*-----------------OBJECTIVE---------------------------------------*/

double tsproblem_obj(const int* state, size_t len)

{

double obj = 0.0 ;
int city=0;
int i=0,j=0,k=0, ncity;

                                               // calculate lower and upper bounds     
unsigned int lower = 0, upper = 0;   
lower = bounds(0);
upper = bounds(1);

                                             // resetting initial conditions for every iteration
cost=0;
result[0] = 0;result[1] = 0;result[2] = 0;result[3] = 0;result[4] = 0;
visited[0] = 1;visited[1] = 0;visited[2] = 0;visited[3] = 0;


                                          // as path should start from 0 and end at 0
                                         // consider only middle 3 cities [0, (1,2,3 - order varies), 0
                                        // states are randomly generated 0 and 1's
                                       // cosider 6 states such that each city is determined by 2 states 
                                      // 0 1- city1     1 0- city2     1 1- city3
                                     // 0 0 - city0  is already fixed as starting and end city


         for(i = 0; i < 6; i+=2)
            {
                j= i+1;
                ncity =  ((2 * state[i]) + state[j]);     // ncity = next city is determined by states
        
                    if (visited[ncity] != 1 )             // check weather city is visited ?
                         {
                             cost += b[city][ncity];      // cost is distance from city to next city from cost-matrix
                             city = ncity ;
                             visited[city] = 1;           // setting city as visited
                             k = (i+2)/2;
                             result[k] = city;            // intermediate path
                   	
                         }
                    else
                           {
                             goto label;                  // if city is visited jump to end
                           }
            }	
        
        cost += b[city][0];                               // else add distance cost for returning to start point  


                                                 // if all cities are visited and
                                                 // total distance is between the limits (upper and lower bounds)
                                                 // obj = cost 
    
label: 
       if(visited[0] == 1 && visited[1] == 1 && visited[2] == 1 && visited[3] == 1)                     
           {
              if ((cost < upper) && (cost > lower))
                  {
                   if (cost<objective)                   // comparing result with previous minimum value 
                        {
                            objective = cost;            // to store better results if present cost is less
                            final[0] = result [0];        
                            final[1] = result [1];       // than previous cost
                            final[2] = result [2];
                            final[3] = result [3];
                            final[4] = result [4];
                        }
                  obj += cost;

                  }
              else
                  obj += upper;                          // if cost is not between bounds return maximum    

           }
       else
              obj += upper;                              // if every city is not visited return maximum 
return obj ;


}




/*----------FINAL---------------------------------------*/
 
void tsproblem_final(const int* state, size_t len)
{

int r;

printf("\n\n total distance travelled is:%d\n\n" ,objective);


printf(" path:\n\n ");
  for (r=0; r<5; r++)
    
         printf("%2d ", final[r]);                     // print final path

  printf("\n");     
    
}

