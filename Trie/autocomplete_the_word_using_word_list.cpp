#include <bits/stdc++.h>
using namespace std;

  // Trie = (Digital Tree), (O(1)), (for each node (data=char) & (no of children<=26) & (size of children array=26))
  
class TrieNode
{      public:
	char data;
	TrieNode **children;
	bool isTerminal;
	
	TrieNode(char d)
	{  data = d;
	   children = new TrieNode*[26];
	   for(int i=0; i<26; i++)
	   children[i] = NULL;
	   
	   isTerminal = false;	 } 
};


class Trie
{   TrieNode *root;                                          // root pointer of Trie (digital tree)                         

        public:
    Trie()
    {   root = new TrieNode('\0');	 }
	
	    private:
	void insertWord(TrieNode *pp, string word)
	{   if(word.size()==0)
        {  pp->isTerminal = true;
           return;   }		
		
		TrieNode *cp;
		int i = word[0]-'a';
		if(pp->children[i]==NULL)
		{  cp = new TrieNode(word[0]);
		   pp->children[i] = cp;  }
		else
		cp = pp->children[i];
		
		insertWord(cp, word.substr(1));
		return;	 }

	TrieNode* search(TrieNode *pp, string word)
	{   if(word.size()==0)
	    return pp;                                           // special search function which returns address of (node storing last char of word)
	    
	    TrieNode *cp;                                        // pointer corresponding to current char
	    int i = word[0]-'a';                                 // index no corresponding to current char 
	    if(pp->children[i]==NULL)
	    return NULL;
	    else
	    cp = pp->children[i];
	    
	    TrieNode *r = search(cp, word.substr(1));
	    
	    return r;	}
 
        public:
	void insertWord(string word)
	{   insertWord(root, word);  }
	
	TrieNode* search(string word)
	{   return search(root, word);	 }
	
	void printWords(TrieNode *pp, string stored)             // store the complete words in "stored" string & print finally
	{
		if(pp==NULL)
		return;
		else if(pp->isTerminal)
		cout<<stored<<endl;
		
		for(int i=0; i<26; i++)
		{  if(pp->children[i]==NULL)
		   continue;  
		
		   string s = stored + pp->children[i]->data;
		   printWords(pp->children[i], s);  }
	}
	                                                      
	void autocompleteTheWordsUsingWordList(vector<string> words, string pattern)
	{   
	    for(int i=0; i<words.size(); i++)                    // inserting (all words of WordList) in Trie
	    insertWord(words[i]);                    
		
		TrieNode *pp = search(pattern);                      // get (address of node storing last char of pattern) from Trie                                        
		printWords(pp, pattern);                             // print (all complete words) for input pattern 
	} 
};


int main()
{
	Trie t;
	
    string s="d";                                            // pattern
	
    vector<string> words; 
    words.push_back("abc");
    words.push_back("def");
    words.push_back("ghi");
    words.push_back("dog");
     
	cout<<"Words after autocompleting word 'd' using given WordList: \n"; 
	t.autocompleteTheWordsUsingWordList(words, s);           // printing complete words 
	cout<<endl<<endl;
}
  
 




 

