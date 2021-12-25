#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const unsigned short int n = 20 , T = 10;
fstream outputFile("Graphic.txt",ios::out);

bool Crossing(unsigned short int A[][n],unsigned short int B[][n],char s,int i,int j,unsigned short int Ai,bool prcl){
    if (prcl==0){
        switch (s){
            case 'U':
                B[i][j] = Ai+1;
                outputFile << i+1 << " " << j+1 << " " << "b" << " ";
                if (i==0){
                    if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                        prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                    }
                }else if (i==n-1){
                        prcl = 1;
                }else{
                    if (j==0){
                        if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                            prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                        }
                        if (A[i][j+1]==Ai+1 && B[i][j+1]<Ai+1){
                            prcl = Crossing(A,B,'L',i,j+1,Ai,prcl);
                        }
                    }else if (j==n-1){
                        if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                            prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                        }
                        if(A[i][j-1]==Ai+1 && B[i][j-1]<Ai+1){
                            prcl = Crossing(A,B,'R',i,j-1,Ai,prcl);
                        }
                    }else{
                        if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                            prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                        }
                        if (A[i][j+1]==Ai+1 && B[i][j+1]<Ai+1){
                            prcl = Crossing(A,B,'L',i,j+1,Ai,prcl);
                        }
                        if (A[i][j-1]==Ai+1 && B[i][j-1]<Ai+1){
                            prcl = Crossing(A,B,'R',i,j-1,Ai,prcl);
                        }
                    }
                }
                break;
            case 'L':
                B[i][j] = Ai+1;
                outputFile << i+1 << " " << j+1 << " " << "b" << " ";
                if (j==n-1){
                    if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                        prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                    }
                }else{
                    if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                        prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                    }
                    if (A[i][j+1]==Ai+1 && B[i][j+1]<Ai+1){
                        prcl = Crossing(A,B,'L',i,j+1,Ai,prcl);
                    }
                }
                break;
            case 'R':
                B[i][j] = Ai+1;
                outputFile << i+1 << " " << j+1 << " " << "b" << " ";
                if (j==0){
                    if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                        prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                    }
                }else{
                    if (A[i+1][j]==Ai+1 && B[i+1][j]<Ai+1){
                        prcl = Crossing(A,B,'U',i+1,j,Ai,prcl);
                    }
                    if (A[i][j-1]==Ai+1 && B[i][j-1]<Ai+1){
                        prcl = Crossing(A,B,'R',i,j-1,Ai,prcl);
                    }
                }
                break;
        }
    }
    return prcl;
}

int main()
{
    double sum = 0,p=0; //Intial Value
    unsigned short int A[n][n],B[n][n],Ai,Aj,i,j;
    int n2 = n*n;
//-------------------------------------------------------------------
    for (Ai=0;Ai<n;Ai++) //Zeros Array
        for(Aj=0;Aj<n;Aj++){
            A[Ai][Aj] = 0;
            B[Ai][Aj] = 0;
        }
//-------------------------------------------------------------------
        if ( !outputFile)
	{
		cerr << "some thing wrong during opening file!" << endl;
		exit(1);
	}
    outputFile << n << " " << T << " " << endl;
    for (Ai=0;Ai<T;Ai++){
        p = 0;
        unsigned int opnst = 0;
        bool prcl = 0;
        while (prcl==0){
            i = rand()%n;
            j = rand()%n;
            if (A[i][j]<Ai+1 && B[i][j]<Ai+1){
                opnst++;
                if (i==0){
                    prcl = Crossing(A,B,'U',i,j,Ai,prcl);
                }else if (B[i-1][j]==Ai+1){
                    prcl = Crossing(A,B,'U',i,j,Ai,prcl);
                }else if (j!=0 && B[i][j-1]==Ai+1){
                    prcl = Crossing(A,B,'L',i,j,Ai,prcl);
                }else if(j!=n-1 && B[i][j+1]==Ai+1){
                    prcl = Crossing(A,B,'R',i,j,Ai,prcl);
                }else{
                A[i][j] = Ai+1;
                outputFile << i+1 << " " << j+1 << " " << "w" << " ";
                } //Set Site is Full or Open
            } //is Site Blocked? - if (A[i][j]<=Ai || B[i][j]<=Ai)
        } // End of Total While - while (prcl==0)

        p = (double)(opnst)/n2;
        sum = sum + p;
        outputFile << 'E' << " " << opnst<< " " << p << " " << sum << " " << endl;
    }
    double pstar = sum/T;
    cout << pstar << endl;
    outputFile << pstar << " ";
//-------------------------------------------------------------------
    return 0;
}


