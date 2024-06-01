#include<iostream>

using namespace std;

int main()
{
	int boxes[3][3], value, playerchance1 = 0, playerchance2 = 0; 
    for(int i=0; i<3; i++) // For taking input
    {
   	    for(int j=0; j<3; j++)
        {
   	        cin >> value;
   	        boxes[i][j]= value;
        }
    }
	for(int i=0; i<3; i++) // Checking validity
    {
   	    for(int j=0; j<3; j++)
        {
   	        if(boxes[i][j]==1)
   	        {
   		        playerchance1 = playerchance1 + 1;
	        }
	        else if(boxes[i][j] == 2)
   	        {
   		        playerchance2 = playerchance2 + 1;
	        }
		}
    }
    if((playerchance1 > playerchance2 + 1) || (playerchance2 > playerchance1 + 1)) // Ouput
    {
        cout << "-1";
   	}
    else if(boxes[0][0] == 2 && boxes[1][1] == 1 && boxes[2][2] == 1)
    {
   	    cout << "0";
    }
    else // Final case
    {
        playerchance1 = 0;
        playerchance2 = 0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(boxes[i][j-i] == 1)
                {
                    playerchance1 = playerchance1 + 1;
                }
                else if(boxes[i][j-i] == 2)
                {
                    playerchance2 = playerchance2 + 1;
                }
                if(boxes[i][j] == 1)
                {
                    playerchance1 = playerchance1 + 1;
                }
                else if(boxes[i][j] == 2)
                {
                    playerchance2=playerchance2 + 1;
                }
                if(boxes[j][i] == 1)
                {
                    playerchance1 = playerchance1 + 1;
                }
                else if(boxes[j][i] == 2)
                {
                    playerchance2 = playerchance2 + 1;
                }
            }
        }
        if(playerchance1 > playerchance2) // Output
        {
            cout << "2";
        }
        else if(playerchance2 > playerchance1)
        {
            cout << "1";
        }
	}
}