#include<iostream>
#include<stdlib.h>

#define NO_OF_ROWS 4
#define NO_OF_COLUMNS 4

using namespace std;
enum all_direction {LEFT,RIGHT,TOP,BOTTOM,LEFTTOPDIAGONAL,RIGHTTOPDIAGONAL,LEFTBOTTOMDIAGONAL,RIGHTBOTTOMDIAGONAL} direction;

int oneDArray[]={1,6,11};
int n=sizeof(oneDArray)/sizeof(int);

int twoDArray[][NO_OF_COLUMNS]={1,2,3,4,
		     5,6,7,8,
		     9,10,11,12,
		     13,14,15,16};

int searchRightBottomDiagonal(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( row == NO_OF_ROWS-1 || column == NO_OF_COLUMNS-1)
	{
		return 0;
	}
	while (row < NO_OF_ROWS  && i < n)
	{
		cout<<"Inside RIGHT Bottom\n";   
		if(oneDArray[i] != twoDArray[row][column])
		{
			cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column++;
		row++;
	}
	
	cout<<"Item Found at RIGHTBOTTOMDIAGONAL\n";
	
	return 1;
}

int searchLeftBottomDiagonal(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( row < NO_OF_ROWS && column == 0)
	{
		return 0;
	}
	while (row < NO_OF_ROWS  && i < n)
	{
		cout<<"Inside Left Bottom\n";   
		if(oneDArray[i] != twoDArray[row][column])
		{
			cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column--;
		row++;
	}
	
	cout<<"Item Found at LEFTBOTTOMDIAGONAL\n";
	
	return 1;
}

int searchRightTopDiagonal(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( column == NO_OF_COLUMNS - 1 )
	{
		return 0;
	}
	while (column < NO_OF_COLUMNS  && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column++;
		row--;
	}
	
	cout<<"Item Found at RIGHTTOPDIAGONAL\n";
	
	return 1;
}

int searchLeftTopDiagonal(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( row == 0 )
	{
		return 0;
	}
	while (row >= 0  && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column--;
		row--;
	}
	
	cout<<"Item Found at LEFTTOPDIAGONAL\n";
	
	return 1;
}

int searchBottom(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( row == NO_OF_ROWS - 1 )
	{
		return 0;
	}
	while (row < NO_OF_ROWS && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		row++;
	}
	
	cout<<"Item Found at BOTTOM\n";
	
	return 1;
}

int searchLeft(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( column == 0 )
	{
		return 0;
	}
	while (column >= 0 && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column--;
	}
	
	cout<<"Item Found at LEFT\n";
	
	return 1;
}

int searchTop(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( row == 0 )
	{
		return 0;
	}
	while (row >= 0 && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		row--;
	}
	
	cout<<"Item Found at TOP\n";
	
	return 1;
}

int searchRight(int row, int column)
{
	int i=0;
	cout<<"["<<row<<","<<column<<"] ="<<twoDArray[row][column]<<"\n";
	if( column == NO_OF_COLUMNS - 1 )
	{
		return 0;
	}
	while (column < NO_OF_COLUMNS && i < n)
	{
		if(oneDArray[i] != twoDArray[row][column])
		{
			//cout<<oneDArray[i] <<"!="<< twoDArray[row][column]<<"\n";
			return 0;
			
		}
		cout<<oneDArray[i] <<"=="<< twoDArray[row][column]<<"\n";
		i++;
		column++;
	}
	
	cout<<"Item Found at RIGHT\n";
	
	return 1;
}

int main()
{
	cout<<"Hello World\n";
	cout<<"N : "<<n<<"\n";
	for(int i=0;i<NO_OF_ROWS;i++)
	{
		int temp_direction=0;
		for(int j=0;j<NO_OF_COLUMNS;j++)
		{
			int temp_direction=0;
			//cout<<"["<<i<<","<<j<<"] "<<"\n";
			while (temp_direction < 8)
			{
				switch(temp_direction)
				{
					case LEFT 		: //cout<<"LEFT\n";
						    		if(searchLeft(i,j))
					    	    		{
									return 0;
					    	    		}
									break;
					case RIGHT 		: //cout<<"RIGHT\n";
								if(searchRight(i,j))
								{
									return 0;
								}
									break;
					case TOP 		: //cout<<"TOP\n";
								if(searchTop(i,j))
								{
									return 0;
								}
									break;
					case BOTTOM 		: //cout<<"BOTTOM\n";
								if(searchBottom(i,j))
								{
									return 0;
								}
									break;
					case LEFTTOPDIAGONAL 	: //cout<<"LEFTTOPDIAGONAL\n";
								if(searchLeftTopDiagonal(i,j))
								{
									return 0;
								}
									break;
					case RIGHTTOPDIAGONAL 	: //cout<<"RIGHTTOPDIAGONAL\n";
								if(searchRightTopDiagonal(i,j))
								{
									return 0;
								}
									break;
					case LEFTBOTTOMDIAGONAL : cout<<"LEFTBOTTOMDIAGONAL\n";
								if(searchLeftBottomDiagonal(i,j))
								{
									return 0;
								}
									break;
					case RIGHTBOTTOMDIAGONAL: //cout<<"RIGHTBOTTOMDIAGONAL\n";
								if(searchRightBottomDiagonal(i,j))
								{
									return 0;
								}
									break;
					default : cout<<"Default";
							exit(0);	
				}
				//direction = direction+1;
				temp_direction++;
			}
		}
	}
}
