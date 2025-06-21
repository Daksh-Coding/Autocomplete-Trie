#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)

struct Trienode
{
    Trienode* letter[ALPHABET_SIZE];
    bool isEnd;
    Trienode()
    {
        for(int i=0;i<ALPHABET_SIZE;i++)
        {
            letter[i]=NULL;
        }
        isEnd=false;
    }
};

void insert(Trienode* root,string str)
{
    Trienode* current=root;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        int index=str[i]-'a';
        if(current->letter[index]==NULL)
        {
            current->letter[index]=new Trienode();
        }
        current=current->letter[index];
    }
    current->isEnd=true;
}

bool search(Trienode* root,string str)
{
    Trienode* current=root;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        int index=str[i]-'a';
        if(current->letter[index]==NULL)
        {
            return false;
        }
        current=current->letter[index];
    }
    if(current->isEnd==false)
    {
        return false;
    }
    return true;
}

bool isLastNode(Trienode* root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->letter[i])
        {
            return false;
        }
    }
    return true;  
}

void suggestionsRecursively(Trienode* root, string currPrefix)
{
    if(root->isEnd)
    {
        cout<<currPrefix<<endl;
    }
    if(isLastNode(root))
    {
        return ;
    }
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(root->letter[i])
        {
            currPrefix.push_back(97+i);
            suggestionsRecursively(root->letter[i],currPrefix);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(Trienode* root, const string query)
{
    Trienode* current=root;
    int n=query.length();
    for(int i=0;i<n;i++)
    {
        int index=query[i]-'a';
        if(current->letter[index]==NULL)
        {
            return 0;
        }
        current=current->letter[index];
    }
    bool isLastWord= (current->isEnd==true);
    bool isLast=isLastNode(current);
    if(isLastWord && isLast)
    {
        cout<<query<<endl;
        return -1;
    }
    if(!isLast)
    {
        suggestionsRecursively(current,query);
        return 1;
    }
}

int main()
{
    Trienode* root=new Trienode();
    insert(root, "hello"); 
    insert(root, "dog"); 
    insert(root, "hell"); 
    insert(root, "cat"); 
    insert(root, "a"); 
    insert(root, "hel"); 
    insert(root, "help"); 
    insert(root, "helps"); 
    insert(root, "helping");
    int comp=printAutoSuggestions(root, "hel");
    if(comp==-1)
        cout << "No other strings found with this prefix\n";
    if(comp==0)
        cout << "No string found with this prefix\n";
    return 0;
}