/*

Check if a given sequence of moves for a robot is circular or not
Given a sequence of moves for a robot, check if the sequence is circular or not. A sequence of moves is circular if first and last positions of robot are same. A move can be on of the following.

  G - Go one unit
    L - Turn left
      R - Turn right 



*/

#include<string.h>
#include<iostream>

#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;
/*

// Let us assume he starts from diretion North.

      N
      |
      |
W - - - - - E
      |
      |
      S



If he moves in N then y++
If he moves in S then y--
If he moves in E then x++
If he moves in W then x--

If he takes R from N then direction = E
If he takes L from N then direction = W


Let's initialize x and y to 0,0. Update x and y for every moves while iterating the string
Once string is iterated then check for the value of x and y.

*/


bool isCircular(char *str)
{
    int dir = N;

    int x=0,y=0;
    for(int i=0;i<strlen(str);++i)
    {
        char move = str[i];

        cout<<move<<endl;
        if(move == 'R') // Move the direction
            dir = (dir+1)%4;
        else if(move == 'L')
            dir = (4+dir-1)%4;
        else // If the direction is G - Update x and y
        {
            if(dir == N)
                y++;
            else if(dir == E)
                x++;
            else if(dir == S)
                y--;
            else
                x--;
        }

        cout<<"Dir : "<<dir<<endl;
    }
    cout<<"X : "<<x<<", Y : "<<y<<endl;
    return (x==0 && y==0);

    
}



int main()
{
    char str[]="GLGLGLGG";
    if(isCircular(str))
        cout<<"Circular \n";
    else
        cout<<"Not Circular\n";
}
