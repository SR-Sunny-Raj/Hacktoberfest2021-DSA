// Problem Link :  https://www.codechef.com/START14C/problems/RCBPLAY

/* Question : Team RCB has earned X points in the games it has played so far in this year's IPL. To qualify for the playoffs they must earn at least a total of Y points. They currently have Z games left, in each game they earn 2 points for a win, 1 point for a draw, and no points for a loss. 
Is it possible for RCB to qualify for the playoffs this year?
*/


#include <stdio.h>

int main(void) {
	// your code goes here
	int x,y,z,i,j;
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
	    scanf("%d%d%d",&x,&y,&z);
	    if(((z*2)+x>=y))
	        printf("YES\n");
	    else
	        printf("NO\n");
	}
	return 0;
}

//End of Program
