#include<iostream>
#include<conio.h>
#include <iomanip>
#include<windows.h>
#include<unistd.h>
//#include<stdlib.h>
#include<time.h>
using namespace std;
int gameend;
void left(double** a, int N)
{
    int tmp;
    for(int i=0;i<N;i++)
    {
        //Bring to be close
        for(int j=0;j<N;j++)
        {
            if(a[i][j]!=0)continue;
            tmp=0;
            for(int k=j;k<N;k++)
            {
                if(!a[i][k]){tmp++;continue;}else
                {
                    a[i][j]=a[i][j+tmp];
                    a[i][j+tmp]=0;
                    break;
                }  
            }
        }
        //Merging
        for(int j=1;j<N;j++)
        {
            if(!a[i][j])continue;
            if(a[i][j-1]==a[i][j])
            {
                a[i][j-1]*=2;a[i][j]=0;
            }
        }
        //Bring to be close
        for(int j=0;j<N;j++)
        {
            if(a[i][j]!=0)continue;
            tmp=0;
            for(int k=j;k<N;k++)
            {
                if(!a[i][k]){tmp++;continue;}else
                {
                    a[i][j]=a[i][j+tmp];
                    a[i][j+tmp]=0;
                    break;
                }  
            }
        }
    }
}
void right(double** a, int n)
{
    int tmp;int N=n-1;
    for(int i=0;i<n;i++)
    {
        //Bring to be close
        for(int j=0;j<n;j++)
        {
            if(a[N-i][N-j]!=0)continue;
            tmp=0;
            for(int k=j;k<n;k++)
            {
                if(!a[N-i][N-k]){tmp++;continue;}else
                {
                    a[N-i][N-j]=a[N-i][N-j-tmp];
                    a[N-i][N-j-tmp]=0;
                    break;
                }  
            }
        }
        //Merging
        for(int j=1;j<n;j++)
        {
            if(!a[N-i][N-j])continue;
            if(a[N-i][N-j+1]==a[N-i][N-j])
            {
                a[N-i][N-j+1]*=2;a[N-i][N-j]=0;
            }
        }
         //Bring to be close
        for(int j=0;j<n;j++)
        {
            if(a[N-i][N-j]!=0)continue;
            tmp=0;
            for(int k=j;k<n;k++)
            {
                if(!a[N-i][N-k]){tmp++;continue;}else
                {
                    a[N-i][N-j]=a[N-i][N-j-tmp];
                    a[N-i][N-j-tmp]=0;
                    break;
                }  
            }
        }
    }
}
void down(double** a, int n)
{
    int tmp;int N=n-1;
    for(int i=0;i<n;i++)
    {
        //Bring to be close
        for(int j=0;j<n;j++)
        {
            if(a[N-j][N-i]!=0)continue;
            tmp=0;
            for(int k=j;k<n;k++)
            {
                if(!a[N-k][N-i]){tmp++;continue;}else
                {
                    a[N-j][N-i]=a[N-j-tmp][N-i];
                    a[N-j-tmp][N-i]=0;
                    break;
                }  
            }
        }
        //Merging
        for(int j=1;j<n;j++)
        {
            if(!a[N-j][N-i])continue;
            if(a[N-j+1][N-i]==a[N-j][N-i])
            {
                a[N-j+1][N-i]*=2;a[N-j][N-i]=0;
            }
        }
        //Bring to be close
        for(int j=0;j<n;j++)
        {
            if(a[N-j][N-i]!=0)continue;
            tmp=0;
            for(int k=j;k<n;k++)
            {
                if(!a[N-k][N-i]){tmp++;continue;}else
                {
                    a[N-j][N-i]=a[N-j-tmp][N-i];
                    a[N-j-tmp][N-i]=0;
                    break;
                }  
            }
        }
    }
}
void up(double** a, int N)
{
    int tmp;
    for(int i=0;i<N;i++)
    {
        //Bring to be close
        for(int j=0;j<N;j++)
        {
            if(a[j][i]!=0)continue;
            tmp=0;
            for(int k=j;k<N;k++)
            {
                if(!a[k][i]){tmp++;continue;}else
                {
                    a[j][i]=a[j+tmp][i];
                    a[j+tmp][i]=0;
                    break;
                }  
            }
        }
        //Merging
        for(int j=1;j<N;j++)
        {
            if(!a[j][i])continue;
            if(a[j-1][i]==a[j][i])
            {
                a[j-1][i]*=2;a[j][i]=0;
            }
        }
        //Bring to be close
        for(int j=0;j<N;j++)
        {
            if(a[j][i]!=0)continue;
            tmp=0;
            for(int k=j;k<N;k++)
            {
                if(!a[k][i]){tmp++;continue;}else
                {
                    a[j][i]=a[j+tmp][i];
                    a[j+tmp][i]=0;
                    break;
                }  
            }
        }
    }
}
void input(double** a, int N)
{
    int c2;
	c2 = _getch();
	switch (c2)
	{
	case 72: // up
		up(a,N);
		break;
	case 80: // down
        down(a,N);
		break;
	case 75: // left
		left(a,N);
		break;
	case 77: // right
		right(a,N);
		break;
	//default:
	//	cout << '!';
	//	break;
	}
}
void desk(double** a, int N)
{
    for(int i=0;i<2*N+1;i++)  
    {
        if(i%2==0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            //for(int i=0;i<N;i++)
            //    cout << "+------";
            //cout << "+\n";
            switch (N)
            {
            case 4 :
                cout << "+------+------+------+------+\n";
                break;
            case 5 :
                cout << "+------+------+------+------+------+\n";
                break;
            case 6 :
                cout << "+------+------+------+------+------+------+\n";
                break;
            case 7 :
                cout << "+------+------+------+------+------+------+------+\n";
                break;
            case 8 :
                cout << "+------+------+------+------+------+------+------+------+\n";
                break;
            case 9 :
                cout << "+------+------+------+------+------+------+------+------+------+\n";
                break;
            case 10 :
                cout << "+------+------+------+------+------+------+------+------+------+------+\n";
                break;
            default:
                break;
            }
        }
        else
        {
            for(int j=0;j<N;j++)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
                cout << "| "; 
                switch ((int)a[(i-1)/2][j])
                {
                case 0:;
                    break;
                case 1:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE); //White
                    break;
                case 2:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN); //Yellow
                    break;
                case 4:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); //Green
                    break;
                case 8:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); //Bule
                    break;
                case 16:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);   //Cyen
                    break;
                default:;
                    break;
                }
                if(a[(i-1)/2][j]!=0)
                cout << setw(4) << a[(i-1)/2][j] <<' ' ;
                else
                cout << setw(4) << ' ' <<' ' ;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "|\n" ;
        }
    }
}

void generation(double** a, int N)
{
    srand((unsigned)time(NULL)); 
    int flag(0),znum(0),twog;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(!a[i][j])znum++;
    if(!znum)
    {
        gameend = 1;
        return;
    }
    znum=rand()%znum;
    twog=znum%4;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!a[i][j])
            {
                if(znum!=0)
                {
                    znum--;
                    continue;
                }
                flag=1;
                if(!twog)
                a[i][j]=2;
                else
                a[i][j]=1;
                return;
            }
        }
    }
}

int main()
{
    int N;  //the number of rows and columns
    cout << "Enter your number of rows and columns \n(a number from 4 to 10):" ;cin >> N;
    while(N<4||N>10)
    {
        cout << "Error data,plz re-enter：";
        cin >> N;
        system("cls");
    }
    //creat double*,initialization
    double** a = new double* [N];
    for (int i=0;i<N;i++)
        a[i] = new double[N];
    a[N-1][0]=1;a[N-1][1]=1;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {
        a[i][j]=0;
    }
    //official start
    int swy(0);
    while(!gameend)
    {
        if(swy)swy=0;else swy=1;
        system("cls");
        desk(a,N); 
        if(swy) 
        {
            generation(a,N);
            system("cls");
            desk(a,N);
        }  
        input(a,N);   
    }
    cout <<"GameOver";
    
}