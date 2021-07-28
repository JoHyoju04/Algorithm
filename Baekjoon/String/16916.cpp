#include<iostream>
#include<vector>
#include<string>

using namespace std;



vector<int> makeTable(string str)
{
	int size = str.size();
	vector<int> table(size,0);
    
    int j = 0;
    for(int i = 1; i < size; i++)
    {
    	while(j > 0 && str[j] != str[i])
        {
        	j = table[j - 1];
        }
        
        if(str[j] == str[i])
        {
        	table[i] = ++j;
        }
    }
    
    return table;
}

int KMP(string parent, string pattern)
{
	int parentSize = parent.size();
    int patternSize = pattern.size();
    
    int j = 0;
    vector<int> table = makeTable(pattern);
    for(int i = 0; i < parentSize; i++)
    {
    	while(j > 0 && parent[i] != pattern[j])
        {
        	j = table[j-1];
        }
        if(parent[i] == pattern[j])
        {
 			if(j == patternSize - 1)
            {
            	return 1;
            }
            else
            {
            	j++;
            }
        }
        
    }
    
    return 0;
}

int main()
{
	string str1, str2;
    
    cin >> str1 >> str2;
    
   	int check = KMP(str1,str2);

    cout<<check;
    
}