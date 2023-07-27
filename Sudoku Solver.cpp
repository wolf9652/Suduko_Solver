#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
bool isSafe(int row,int col,vector<vector<int>>&sudoku,int val)
{
    for(int i=0;i<sudoku[0].size();i++){
		if (sudoku[row][i] == val){
			return false;
        }
		if (sudoku[i][col] == val){
			return false; 
        }
        if(sudoku[ 3 * (row/3) + i / 3][3*(col/3)+ i % 3]==val){
            return false; 
        }
    }
	return true; 
}
bool solveSudoku(vector<vector<int>>&sudoku)
{
	int n=sudoku[0].size(); 
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sudoku[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(i,j,sudoku,val)){
                        sudoku[i][j]=val;
                        bool next=solveSudoku(sudoku);
                        if(next){
                            return true;
                        }
                        else{
                            sudoku[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cout<<"========================================================================="<<endl;
    cout<<"------------------------------|| MINI PROJECT ||-------------------------"<<endl;
    cout<<"========================================================================="<<endl<<endl;
    cout<<"                                                            ADARSH (CS_1)"<<endl;
    cout<<"                                                       ARYAN GUPTA (CS_1)"<<endl;
    cout<<"                                                    RISHABH SANGAL (CS_2)"<<endl<<endl;;

    cout<<"================================|| SUDOKU ||============================="<<endl;
    while(true){
        char check;
        cout<<"DO YOU WANT TO SOLVE SUDOKU"<<endl;
        cout<<"press Y (TO YES...)"<<endl;
        cout<<"press N (TO NO...)"<<endl;
        cin>>check;
        system("cls");
        if(check=='y'|| check=='Y'){
            cout<<"Enter Sudoku values\n\n";
            vector<vector<int>>sudoku; 
            for(int i=0;i<9;i++){
                vector<int>vtr;
                for(int i=0;i<9;i++){
                    int val;cin>>val;
                    vtr.push_back(val);
                }
                sudoku.push_back(vtr);
            }

            cout<<("\n\n\n")<<endl<<"SOLUTION OF SUDOKU..."<<endl<<endl;

            if(solveSudoku(sudoku)){
                cout<<"_________________"<<("\n\n");
                for(int i=0;i<sudoku.size();i++){
                    for(int j=0;j<sudoku[i].size();j++){
                        cout<<sudoku[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"__________________\n\n\n\n"<<endl;
            }
            else{
                cout<<"NO SOLUTION!!!"<<endl;
            }        
        }
        if(check=='n'|| check=='N'){
            cout<<"\n\n\nTHANKYOU......HAVE A NICE DAY :) "<<endl;
            return 0;
        }
    }
}