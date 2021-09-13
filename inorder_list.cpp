#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <sstream>
#include <locale> //for tolower function
#include <cstddef>    //for NULL
#include "inorder_list.h"
using namespace std;

double Words=0;
string IntToString(int a) //to convert int to string
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

inorder_list::inorder_list()  //constructer
{
	Head=NULL;
	Tail=NULL;
	Current=NULL;
	Pred=NULL;
} 

bool inorder_list::Insert(ListElemType &e,int Line) //insert passed word
{
	int j=0;
    while (e[j]) 
	{ 
		e[j]=(tolower(e[j])); 
        j++; 
    }
	j=0;
	
	
	Link AddedNode=new Node;
	Link Pred;
	if(!AddedNode)
		return false;
	
	AddedNode->Elem=e;
	AddedNode->Line=Line;
	
	if(Head==NULL || e<=Head->Elem)
	{
		AddedNode->Next=Head;
		Head=AddedNode;
		Words++;
	}
	else
	{
		Pred=Head;
		while(Pred->Next!=0 && Pred->Next->Elem<=AddedNode->Elem)
			Pred=Pred->Next;
		AddedNode->Next = Pred->Next;
		Pred->Next = AddedNode;
		Words++;
    }
	Current=Head;
	while(Current->Next!=NULL)
	{
		if(Current->Elem==Current->Next->Elem)
		{
			if(Current->Line > Current->Next->Line)
			{
				int temp;
				temp=Current->Line;
				Current->Line=Current->Next->Line;
				Current->Next->Line=temp;
			}
		}
		Current=Current->Next;
	}
    return true;
	
}

bool inorder_list::First(ListElemType &e)       //retrive first word in linked list
{
	if(Head==NULL)
	{
		//the list is empty
		return false;
	}
	else
	{
		Current=Head;
		e=Current->Elem;
		return true;
	}
}

bool inorder_list::Next(ListElemType &e)        //retrive next word in linked list 
{
	if(Current==NULL || Current->Next==NULL)
		return false;
	Current=Current->Next;
	e=Current->Elem;
	return true;
}

int inorder_list::WordCount()                  //count #words in file
{
	//return Words;
	int number=0;
	Current=Head;
	if(Head==NULL)
	{
		return 0;
	}
	else
	{
		while(Current->Next != NULL)
		{
			number++;
			Current=Current->Next;
		}
	}
	return number+1;
	
}

double inorder_list::DistCount()                  //count #distinct word in file
{
	double NumOfWord=0;
	int lastflag=0;
	string prevword;
	Current=Head;
	if(Current==NULL)
	{
		return NumOfWord;
	}
	
	if(Current->Next==NULL)
	{
		return 1;
	}	
	while(Current->Next!=NULL)
	{
		if( Current!=NULL && (Current->Elem == Current->Next->Elem) )
		{
			Current=Current->Next;
		}
		else if(Current!=NULL && (Current->Elem != Current->Next->Elem))
		{
			NumOfWord++;
			prevword=Current->Elem;
			Current=Current->Next;
		}
	}
	if(Current->Elem != prevword && Current->Next==NULL)
	{
		return NumOfWord+1;
	}
	else
	{
		return NumOfWord;
	}
}

void inorder_list::CharCount(const double &NumberOfChar)  //count #charachter in file
{
	double x=NumberOfChar;
	cout<<x<<" characters\n";
}

void inorder_list::FrequentWord() //retrive most frequent word
{
	int size=WordCount();
	int counter=0,temp;
	string word[size];
	string tempo;
	int repetation[size]={};
	Current=Head;
	//repetation[counter]={};
	while(Current->Next != NULL)
	{
		if(Current->Elem==Current->Next->Elem)
		{
			if(!(Current->Elem==("a") || Current->Elem==("an")|| Current->Elem==("the")|| Current->Elem==("in")|| Current->Elem==("on")|| Current->Elem==("of")|| Current->Elem==("and")|| Current->Elem==("is")|| Current->Elem==("are")))
			{
				word[counter]=Current->Elem;
				repetation[counter]++;
			}
		}
		else if (Current->Elem!=Current->Next->Elem)
		{
			counter++;
			repetation[counter]=0;
		}
		Current=Current->Next;
	}
	for(int end=counter ; end>=0 ; end--)
	{
		for(int start=0;start<end;start++)
		{
			if(repetation[start]>repetation[start+1])
			{ 
		        temp=repetation[start]; 
		        repetation[start]=repetation[start+1];
		        repetation[start+1]=temp;
				
				tempo=word[start]; 
		        word[start]=word[start+1];
		        word[start+1]=tempo;
		    }
		}
	}
	cout<<"Most frequent word is: ";
	int flago=0;
	while(counter>=0)
	{
		if(repetation[counter]>repetation[counter-1])  //sorting algorithm
		{
			if(flago!=1)
			cout<<word[counter]<<" ";
			break;
		}
		else if(repetation[counter]==repetation[counter-1])
		{
			if(word[counter]<=word[counter-1])
				cout<<word[counter]<<" "<<word[counter];
			else if (word[counter]>=word[counter-1])
				cout<<word[counter-1]<<" "<<word[counter];
			counter--;
			flago=1;
		}
		
	}
	//cout<<endl;
		
}

void inorder_list::CountWord(ListElemType &e) //count h.m passed word appears
{
	int j=0;
    while (e[j]) 
	{ 
		e[j]=(tolower(e[j])); 
        j++; 
    }
	j=0;
	
	int size=WordCount(),NumberOfRepet=0;
	Current=Head;
	for(int i=0;i<=size && Current!=NULL && Current->Next!=NULL ;i++)
	{
		if(e==Current->Elem)
		{
			NumberOfRepet++;
		}
		Current=Current->Next;
	}
	if(!NumberOfRepet)
	{
		cout<<e<<" is repeated 0 times\n";
	}
	else
	{	
		cout<<e<<" is repeated "<<NumberOfRepet<<" times\n";
	}
}

void inorder_list::Starting(ListElemType &e)        //lesa msh fahmha
{
	int j=0;
    while (e[j]) 
	{ 
		e[j]=(tolower(e[j])); 
        j++; 
    }
	j=0;
	int size=WordCount(),NumberOfRepet[size]={};
	int counter=0;
	Current=Head;
	string data[size];
	string word[size];
	for(int i=0;i<=size && Current!=NULL ;i++)
	{	
		data[counter]="";
		for(int j=0;j<e.length();j++)
			data[i]=data[i]+Current->Elem[j];
		if(e==data[i])
		{
			
			word[counter]=Current->Elem;
			if(Current->Elem==Current->Next->Elem)
			{
			    NumberOfRepet[counter]++;
			}
			if(Current->Elem!=Current->Next->Elem)
			{
				NumberOfRepet[counter]++;
				counter++;
			}
		}
		Current=Current->Next;
	}
	if(counter==0)
		cout<<"Word not found\n";
	else
	{
		for(int i=0;i<counter;i++)
	    {
	        if(NumberOfRepet[counter]>=0)
		    cout<<word[i]<<": "<<NumberOfRepet[i]<<"\t";
	    }
		cout<<endl;
	}
}
void inorder_list::Containing(ListElemType &e) //count #word that containg passed chars
{
	int j=0;
    while (e[j]) 
	{ 
		e[j]=(tolower(e[j])); 
        j++; 
    }
	j=0;
	
	int size=WordCount(),NumberOfRepet=0;
	Current=Head;
	int flag=0,Oflag=0,repflag=0,lastflag=0;
	int x;
	for(int i=0 ; i<=size && Current!=NULL && Current->Next!=NULL ;i++)
	{
        x=Current->Elem.find(e);		
        if( x>=0 )
		{
			Oflag=1;
			if(flag==0)
			{
				cout<<Current->Elem<<": ";
				flag=1;
				NumberOfRepet++;
			}
			/*else*/ if(flag==1 && Current->Elem==Current->Next->Elem )
			{
				lastflag=0;
				NumberOfRepet++;
				repflag=1;
			}
			if (flag==1 && Current->Elem!=Current->Next->Elem)
			{
				if(i==size-1 && lastflag==0)
				{
					NumberOfRepet++;
				}
				lastflag=1;
				/*if(repflag==1)
				{
					NumberOfRepet++;
				}*/
				cout<<NumberOfRepet<<"\t";
				flag=0;
				NumberOfRepet=0;
				repflag=0;
			}
		}
		Current=Current->Next;
	}
	
	x=Current->Elem.find(e);		
    if( x>=0 && lastflag==1)
	{
		cout<<Current->Elem<<": "<<"1"<<"\t";
	}
	if(Oflag==0)
	{
		cout<<"Word not found\n";
	}
	else if(Oflag==1)
	{
		cout<<endl;
	}
}

void inorder_list::Search(ListElemType &e) //search on words that containing passed chars
{
	int j=0,flago=0;
    while (e[j]) 
	{ 
		e[j]=(tolower(e[j])); 
        j++; 
    }
	j=0;
	int size=WordCount(),NumberOfRepet=0;
	Current=Head;
	int flag=0,RepFlag=0;
	string PrevWord;
	int x,PrevLine;
	if(Current==NULL)
	{
		cout<<"Word not found\n";
	}
	for(int i=0;i<=size && Current!=NULL && Current->Next!=NULL ;i++)
	{
        x=Current->Elem.find(e);		
		if(x>=0)
		{
			flago=1;
			if( Current==Head || Current->Elem != PrevWord)
			{
				cout<<Current->Elem<<":\t"<<"lines "<<Current->Line;
			}
			else if(Current!=Head&&PrevWord==Current->Elem&&PrevLine!=Current->Line)
			{
				cout<<" "<<Current->Line;
			}
			if(Current->Elem!=Current->Next->Elem)
			{
				cout<<endl;
			}
			PrevWord=Current->Elem;
			PrevLine=Current->Line;
		}
		Current=Current->Next;
	}
	if(!flago)
	{
		cout<<"Word not found\n";
	}
}

void inorder_list::Print()
{
	Current=Head;
	for(;Current!=NULL;Current=Current->Next)
	{
		cout<<Current->Elem<<" line "<<Current->Line<<endl;
	}
}

/*inorder_list::~inorder_list()	//distructer
{
	Current=Head;
	while(Current != NULL && Current->Next!=NULL)
	{
		delete Current;
		Current=Current->Next;
	}
} */