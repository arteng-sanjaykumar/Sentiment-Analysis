#include<sstream>

#include"DynamicSafeArray.cpp"

#include"Singly_Linked_List Final.cpp"

#define MAX_SIZE 100

using namespace std;

struct node
{
	char Word[MAX_SIZE]={};
	float Polarity=0;
	float Subjectivity=0;
};
void Create_Polar_Dictionary()
{
	int j=0;
	DSA<node> Polar_Words(5);
	string Text,File_Name="vader_lexicon.txt";
	ifstream R_File;
	R_File.open(File_Name,ios::in);
	while(!R_File.eof())
	{
		int i=0;
		node Obj;
		getline(R_File,Text);
		while(Text[i]!='\t')
		{
			Obj.Word[i]=Text[i];
			i++;
		}
		stringstream str_to_int_Pol(Text.substr(i,i+5));
		str_to_int_Pol >> Obj.Polarity;
		stringstream str_to_int_Subj(Text.substr(i+5,i+10)); 
		str_to_int_Subj >> Obj.Subjectivity;
		Polar_Words[j]=Obj;
		node Obj1=Polar_Words[j];
//		cout<<Obj1.Word<<"		"<<Obj1.Polarity<<"		"<<Obj1.Subjectivity<<endl;
		j++;
	}

	R_File.close();	
}
void Tokenization_and_StopWords()
{
	string S;
	ifstream File;
	File.open("read_data.txt",ios::in);
	if(!File.is_open())
	{
		cout<<"Can Not Open File"<<endl;
		exit(0);
	}
	else
	{
		char Arr[MAX_SIZE]={};		
		while(getline(File,S))
		{
			int i=0,j=-1;
			SinglyLinkedList<string>L1;
			while(S[i]!='\0')
			{
				if(S[i]!=' ' && isalpha(S[i]))
				{
					Arr[++j]=S[i];
				}
				else if(j!=-1)
				{
					string D(Arr);
					L1.Add_Node_at_Last(D);					
					for(;j>-1;j--)
					{
						Arr[j]={};
					}
				}
				i++;
			}
			L1.lower();
			L1.stop_words();
			L1.print_Nodes();
		}

	}			
}
int main(void)
{
	Create_Polar_Dictionary();
	Tokenization_and_StopWords();
}
