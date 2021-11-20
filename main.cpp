#include <iostream>
#include <fstream>
#include <sstream>
#include "linked_list.h"

using namespace std;
int read_data_file(string name);
void read_comm_file(string comm);
void numof_ch();
//void rebuild_list();
void count_word(string word);
void put_lines();
void word_num();
void dist_word();
void freq_word();
void starting(string sub);
void containing(string sub);
void searching(string sub);
int check_string(string str1, string str2);
LinkedList my_list;
static string file_temp;

int main(int argc , char ** argv)
{
    string line,file_name=argv[1];  string n;
	string comm_name=argv[2]; 
	//int num_before_rebuild;  int num_after_build;
	int flag=0;
	flag= read_data_file(file_name);
	//int flag2=read_comm_file(comm_name);
	
   if(flag ==1 )
   {
	//num_before_rebuild=my_list.numof_node();
	//rebuild_list();
	put_lines();
	//num_after_build=my_list.numof_node();
	file_temp=file_name;
	read_comm_file(comm_name);
   }
   



   /*int nu= my_list.numof_node();
   for(int i=1; i<=nu;i++)
   {
	   cout<<my_list.display_node(i)<<' '<<my_list.get_count(i)<<' '<<my_list.get_linenum(i)<<endl;


   }*/
  // int flag2=read_comm_file(comm_name);
   
 //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!";
	
return 0;
}


int read_data_file(string name)
{
	string word,word2, line; int r=0;
	//ifstream file;
	//file.open(name.c_str());
	
	ifstream file (name);
	if (file.is_open())
		{
	while(getline(file,line) )
	{
		r++;
		istringstream iss(line);
		while(iss>>word)
		{
			
			for(int j=0; j< word.length();j++)
			{
				if( word[j] =='.' || word[j]==',')
					word[j]=' ';
			}
			istringstream isss(word);
			while(isss>> word2)
			{
				for(int i=0; i< word2.length();i++)
				{
					if( word2[i] >='A' && word2[i]<='Z')
						word2[i]+=32;
				}
				
				
				
				my_list.add_node(word2,r);
			}
			
			/*for(int i=0; i< word.length();i++)
			{
				if( word[i] >='A' && word[i]<='Z')
					word[i]+=32;
			}
			
			my_list.add_node(word,r);*/
		}
		
		
	}
		}
		else {
    
    cout << "File not found"<<endl;
	return 0;
			}
		
	file.close();
	return 1;
}

//get num of ch in file 
void numof_ch()
{
	string name=file_temp;
	ifstream  fin(name);
        char ch;
        long int  c=0;
        while(fin.get(ch))
        {
            //    fin.get(ch);
                //i=ch;
               // if(ch !=' ')
                    c++;
                //else if(ch== ' ')
                //    sp++;
				
        }
		fin.close();
        cout<<c<<" characters"<<endl;
        
//return c;
}
/*
void rebuild_list()
{
	int num= my_list.numof_node();
	int i,k,p,l;  int flag=0;   string temp,line;
	for(i=1; i<=num; i++)
	{



		temp= my_list.display_node(i);
		k=temp.length(); 
		
		if( k==1)
		{
			if( !((temp[0]>='a' && temp[0]<='z')||(temp[0]>='A' && temp[0]<='Z')||(temp[0]>='0' && temp[0]<='9')   )      ) 
			{p= my_list.delete_node(i);
		    num-=1;
			i-=1;
			}
			//cout<<"done";
		}
		else
		{   
			
			if( !((temp[0]>='a' && temp[0]<='z')||(temp[0]>='A' && temp[0]<='Z')||(temp[0]>='0' && temp[0]<='9')   )      )
			{
				flag=1;
				line=temp.substr(1, (k-1)); 
				
				my_list.update_val(line, i);
			}
			if( !((temp[k-1]>='a' && temp[k-1]<='z')||(temp[k-1]>='A' && temp[k-1]<='Z')||(temp[k-1]>='0' && temp[k-1]<='9')   )      )
			{
				if(flag==0)
				{
					line=temp.substr(0, k-1);
					my_list.update_val(line, i);
				}
				else
				{
					line=temp.substr(1, k-2);
				    my_list.update_val(line, i);
				}
				
			}
			flag=0;
		}

	}
	my_list.sort_node();
	
}
*/
void put_lines()
{
	my_list.sort_node();
	int num=my_list.numof_node();
	string word; int counter;
	int arr[3000];
	for(int i=1; i<=num; i++)
	{
		word= my_list.display_node(i);
		counter=my_list.find_node( word ,arr );
		my_list.access_count( i , counter);
			
	}
	
	my_list.sort_node();
}

void count_word(string word)
{
	int c;  int arr[1000];
	c= my_list.find_node(word, arr);
	if(c !=0)
		cout<<word<<" is repeated "<<c<<" times"<<endl;
    else
		cout<<word<<" is repeated "<<c<<" times"<<endl;
}

void word_num()
{
	int num= my_list.numof_node();
	cout<<num<<" words"<<endl;
	
}

void dist_word()
{
	int num= my_list.numof_node();
	
	int var, dist=0;
	
	for(int i=1; i<=num; i++)
	{
		var= my_list.get_count(i);
		
		if(var== 1)
			dist++;
		else
		{
			dist++;
			i=i+var-1;
		}
	
	}
	cout<<dist<<" distinct words"<<endl;
}

void freq_word()
{
	string word;
	string temp_store[5000]; string temp[5000];
	int num= my_list.numof_node();
	int max=1; int c=0;  int n=0;
	for(int i=1; i<=num; i++)
	{
		c= my_list.get_count(i);
		word= my_list.display_node(i);
		if( word!="a" && word!="an" && word!="the" && word!="in" && word!="on" && word!="of" && word!="and" && word!="is" && word!="are")
		{
			if(c>max)
			{
				max= c;
			}
		}
	}
	 int m=0;
	for(int u=1; u<=num; u++)
	{
		c= my_list.get_count(u);
		if(c== max)
		{
			string ge=my_list.display_node(u);
			
			if( ge!="a" && ge!="an" && ge!="the" && ge!="in" && ge!="on" && ge!="of" && ge!="and" && ge!="is" && ge!="are")
			{
			temp_store[m]=ge;
			m++;
			}
		}
		
	}
	
	     int j = 0; 
    for (int i=0; i<m-1; i++) 
  
        
        if (temp_store[i] != temp_store[i+1]) 
            temp[j++] = temp_store[i]; 
  
    
    temp[j++] = temp_store[m-1]; 
  
    for (int i=0; i<j; i++) 
        temp_store[i] = temp[i]; 
  
    n=j; 
		cout<<"Most frequent word is: ";
		for (int i=0; i<n; i++) 
		{
			
			cout <<  temp_store[i] <<" "; 
		}
	
	
	cout<< endl;
	
	
}

void starting(string sub)
{
	int num=my_list.numof_node();
	string temp;  int pos=0; int flag=0; 
	string words[5000]; int arr[5000];
	string words_t[5000]; int arr_t[5000];
	int m=0; int n=0;
	for(int i=1; i<= num; i++)
	{
		temp=my_list.display_node(i);
		pos=check_string(temp, sub);
		if(pos ==1)
		{
			flag=1;
			words[m]=temp;
			arr[m]=my_list.get_count(i);
			m++;
		}
		
	}
	
	if (flag==1)
	{
	int j = 0; 
    for (int i=0; i<m-1; i++) 
  
        
        if (words[i] != words[i+1]) 
		{
			int y=j++;
			words_t[y] = words[i]; 
			arr_t[y]= arr[i];
		}
		int g=j++;
		words_t[g] = words[m-1]; 
		arr_t[g] = arr[m-1];
  
    for (int i=0; i<j; i++) 
	{
		words[i] = words_t[i];
		
		arr[i] = arr_t[i];
	}
  
    n=j; 
	}
	if(flag==1)
	{
	for (int i=0; i<n; i++) 
		{
			
			cout <<  words[i] <<':'<<" "<<arr[i]<<'	'; 
		}
	}
	else
		cout<<"Word not found";
	cout<<endl;
	//if flag=1 found if not not found
	
}

void containing(string sub)
{
	
	int num=my_list.numof_node();
	string temp;  int pos=0; int flag=0; 
	string words[5000]; int arr[5000];
	string words_t[5000]; int arr_t[5000];
	int m=0; int n=0;
	for(int i=1; i<= num; i++)
	{
		temp=my_list.display_node(i);
		pos=check_string(temp, sub);
		if(pos !=0)
		{
			flag=1;
			words[m]=temp;
			arr[m]=my_list.get_count(i);
			m++;
		}
		
	}
	
	if (flag==1)
	{
	int j = 0; 
    for (int i=0; i<m-1; i++) 
  
        
        if (words[i] != words[i+1]) 
		{
			int y=j++;
			words_t[y] = words[i]; 
			arr_t[y]= arr[i];
		}
		int g=j++;
		words_t[g] = words[m-1]; 
		arr_t[g] = arr[m-1];
  
    for (int i=0; i<j; i++) 
	{
		words[i] = words_t[i];
		
		arr[i] = arr_t[i];
	}
  
    n=j; 
	}
	if(flag==1)
	{
	for (int i=0; i<n; i++) 
		{
			
			cout <<  words[i] <<':'<<" "<<arr[i]<<'	'; 
		}
	}
	else
		cout<<"Word not found";
	cout<<endl;
	
	
}

void searching(string sub)
{
	int num=my_list.numof_node();
	string temp;  int pos=0; int flag=0;  int once_flag=0;
	string words[5000];    int arr_line[5000];   
	//string words_t[50]; int arr_count_t[50];
	//string kept;
	int m=0; int n=0;
	for(int i=1; i<= num; i++)
	{
		temp=my_list.display_node(i);
		pos=check_string(temp, sub);
		if(pos !=0)
		{
			flag=1;
			words[m]=temp;
			arr_line[m]=my_list.get_linenum(i);
			//arr_count[m]=my_list.get_count(i);
			m++;
		}
		
	}
	if (flag==1)
	{
	for(int i=0; i<m; i++)
	{
		if(once_flag ==0)
		{
			cout<<words[i]<<":"<<'	'<<"lines "<<arr_line[i];
			once_flag=1;
			continue;
		}
		if(words[i]==words[i-1] && arr_line[i]==arr_line[i-1])
			continue;
		else if(words[i]==words[i-1] && arr_line[i]!=arr_line[i-1])
			cout<<' '<<arr_line[i];
		else if(words[i]!=words[i-1])
			cout<<endl<<words[i]<<":"<<"	"<<"lines "<<arr_line[i];
		
		
	}
	}
	else
		cout<<"Word not found";
	
	cout<<endl;
}



int check_string(string str1, string str2)
{
	int l = 0; 

		l=str1.find(str2);



		return l+1;
	
	
}



void read_comm_file(string comm)
{
	string word[5]; string line,temp; int u,r=0;
	
	ifstream file (comm);
if (file.is_open()) 
{
	while(getline(file,line) )
	{
		
		r++;
		istringstream iss(line);
		u=0;
		while(iss>>temp)
		{
			
			
			word[u]=temp;
						
			u++;
		}
		
		
		if(word[0]=="wordCount")
		{
			if(u==1)
			{
				word_num();
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="distWords")
		{
			if(u==1)
			{
				dist_word();
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
			
		}
		else if(word[0]=="charCount")
		{
			if(u==1)
			{
				numof_ch();
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="frequentWord")
		{
			if(u==1)
			{
				freq_word();
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="countWord")
		{
			if(u==2)
			{
				string s=word[1];
				int l=s.length();
				for(int i=0; i<l ;i++)
				{
					if( s[i] >='A' && s[i]<='Z')
					s[i]+=32;
				}
				
				
				count_word(s);
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="starting")
		{
			if(u==2)
			{
				
				string s=word[1];
				int l=s.length();
				for(int i=0; i<l ;i++)
				{
					if( s[i] >='A' && s[i]<='Z')
					s[i]+=32;
				}
				
				
				starting(s);
				
				
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="containing")
		{
			if(u==2)
			{
				string s=word[1];
				int l=s.length();
				for(int i=0; i<l ;i++)
				{
					if( s[i] >='A' && s[i]<='Z')
					s[i]+=32;
				}
				
				
				containing(s);
			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(word[0]=="search")
		{
			if(u==2)
			{
				string s=word[1];
				int l=s.length();
				for(int i=0; i<l ;i++)
				{
					if( s[i] >='A' && s[i]<='Z')
					s[i]+=32;
				}
				
				
				searching(s);

			}
			else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else
		{
			cout<<"Undefined command"<<endl;
		}
	
	
	}
	cout<<r;
}
	else {
    
    cout << "File not found";
//	return 0;
			}
	file.close();
	//return 1;

}



























