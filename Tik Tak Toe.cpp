#include<iostream>
using namespace std;

void board(char box[][3])
{
	cout << "     |     |     " << endl;
	cout << "  " << box[0][0] << "  |  " << box[0][1] << "  |  " << box[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << box[1][0] << "  |  " << box[1][1] << "  |  " << box[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << box[2][0] << "  |  " << box[2][1] << "  |  " << box[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

int main()
{
	system("cls");
	char x = 0;
	int count = 1;
	char **choice=new char *[3];
	for(int i=0;i<3;i++)
		choice[i]=new char[3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			choice[i][j]=count;
			count ++;
		}
	cout<<"\t\t-------------------------------------------------------------------------\n";
	cout<<"\t\t-------------------------------Tik Tak Toe-------------------------------\n";
	cout<<"\t\t-------------------------------------------------------------------------\n";
	cout<<"1.Play game\n2.Rules\n3.Exit\n";		cin>>x;
	while((x!=1)&&(x!=2)&&(x!=3))
	{
		cout<<"Input correct choice: ";
		cin>>x;
	}
	switch(x)
	{
		case 1:
			board(choice);
		case 2:
			system("cls");
			cout<<"1. The game is played on a grid that's 3 squares by 3 squares.\n";
			cout<<"2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares.\n";
			cout<<"3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n";
			cout<<"4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n";
			cout<<"0. Back\n";
			cin>>x;
			while(x!=0)
			{
				cout<<"Press 0 to go back.\n";
				cin>>x;
			}
			if(x==0)
				main();
		case 3:
			system("cls");
			break;
	}
	for(int i=0;i<3;i++)
		delete choice[i];
	delete choice;
}
