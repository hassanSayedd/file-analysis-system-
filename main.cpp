#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <sstream>
#include <cstring>
#include <locale>     //for tolower function
#include <cstddef>   //for NULL
#include <fstream>  //to read file
#include "inorder_list.h"
using namespace std;
int main(int argc,char**argv)
{
	bool check;
	inorder_list MyList;
	int i=0;
	int command_flag;
    if(argc!=3)
    {
	    cout<<"Incorret number of arguments\n";
    }
    else
    {
        ifstream myfile (argv[1]);
        ifstream command (argv[2]);
        if(!myfile)
		{
            cout<<"File not found"<<endl;
            return 0;
        }
        else if(!command)
		{
            cout<<"File not found"<<endl;
            return 0;
        }
		
		////////////////////////////////////
        
		string line="",data="";
		double N_line=1;
		double S_line=0;
		double NumOfchar=0;
        while ( getline (myfile,line) )
        {
			S_line=0;
			i=0;
			double LineLength=line.length();
			while( S_line<LineLength)   // < msh <= 3ashan S_line btbd2a mn zero 
			{
				for(i=0 ; line[S_line]!='\0' ; i++)
			    {
				    if(line[S_line] == '\n' || line[S_line] == '\t' || line[S_line] == ' ' || line[S_line] == '.' || line[S_line] == ',' ) //: \n space \t , .
				    {
					   S_line++;
					   if(i==0)
					   {
						   continue;
					   }
					   else if(i>0)
					   {
							break;
					   }
				    }
					data=data+line[S_line];
				    S_line++;
			    }
				if(data!="")
			    check=MyList.Insert(data,N_line);
			    data="";	
			}
			NumOfchar=NumOfchar+S_line+1;
			N_line++;
        }
		
		while ( getline (command,line) )
		{
			command_flag=0;
		    if(line.find("wordCount")==0)
		    {
				command_flag = 1;
				if(line.length()!=9)
				{
					cout<<"Incorret number of arguments\n";
				}
				else
				{
					int x = MyList.WordCount();
					cout<<x<<" words\n";
					continue;
				}
		    }
		    else if(line.find("distWords")==0)
		    {
				command_flag = 1;
				if(line.length()!=9)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else
				{
					double x = MyList.DistCount();
					cout<<x<<" distinct words\n";
					continue;
				}
		    }
		    else if(line.find("charCount")==0)
		    {
				command_flag = 1;
				if(line.length() != 9)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else
				{
					MyList.CharCount(NumOfchar);
					continue;
				}
			}
		    else if(line.find("frequentWord")==0)
		    {
				command_flag=1;
				if(line.length()!=12)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else
				{
					MyList.FrequentWord();
					cout<<endl;
					continue;
				}
		    }
		    else if( line.find("countWord")==0 )
		    {
				if(line.length()==9)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else if(line[9]==' ')
				{
				command_flag = 1;
				for( i=10;i<line.length()&&line[i]==' ';i++);
				if(line.length()<10 && line.length()>i+1 )
				{
					cout<<"Incorret number of arguments\n";
					continue;
				}
				string kelma="";
				for(int ha=10 ; ha<line.length() ; ha++)
				{
					kelma=kelma+line[ha];
				}
				MyList.CountWord(kelma);
				continue;
				}
		    }
		    else if(line.find("starting")==0)
		    {
				if(line.length()==8)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else if(line[8]==' ')
				{
				command_flag = 1;
				for( i=9; i<line.length() && line[i]!=' ';i++);
				if(line.length()<9 && line.length()>i+1 )
				{
					cout<<"Incorret number of arguments\n";
					continue;
				}
				string kelma="";
				int i=0;
				for(int ha=9 ; ha<line.length() ; ha++)
				{
					kelma=kelma+line[ha];
				}
				MyList.Starting(kelma);
				continue;
				}
		    }
		    else if(line.find("containing ")==0)   ////// fe 7aga hena 
		    {
				
				if(line.length()==10)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else if(line[10]==' ')
				{
				command_flag = 1;
				for( i=11; i<line.length() && line[i+1]!=' ' ; i++);
				if(line.length()<11 || line.length()>i )
				{
					cout<<"Incorrect number of arguments\n";
					continue;
				}
				string kelma="";
				int i=0;
				for(int ha=11 ; ha<line.length() ; ha++)
				{
					kelma=kelma+line[ha];
				}
				MyList.Containing(kelma);
				continue;
				}
		    }
			else if(line.find("search")==0)
		    {
				if(line.length()==6)
				{
					cout<<"Incorrect number of arguments\n";
				}
				else if(line[6]==' ')
				{
				command_flag = 1;
				for( i=7;i<line.length() && line[i]!=' ';i++);
				if(line.length()<7 && line.length()>i+1 )
				{
					cout<<"Incorrect number of arguments\n";
					continue;
				}
				string kelma="";
				int i=0;
				for(int ha=7 ; ha<line.length() ; ha++)
				{
					kelma=kelma+line[ha];
				}
				MyList.Search(kelma);
				continue;
				}
		    }
			else if(command_flag == 0)
			{
				cout<<"Undefined command\n";
			}
		}
    }
	//cout<<endl<<"list is:"<<endl;
	//MyList.Print();
 return 0;
}
