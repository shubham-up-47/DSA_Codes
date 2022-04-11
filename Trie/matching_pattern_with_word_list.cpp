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
{   TrieNode *root;

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

	bool search(TrieNode *pp, string word)
	{   if(word.size()==0)
	    return 1;                                      // if subString of inputString isPresent in WordList, then also patternMatched (Suffix Trie)
	    
	    TrieNode *cp;
	    int i = word[0]-'a';
	    if(pp->children[i]==NULL)
	    return 0;
	    else
	    cp = pp->children[i];
	    
	    bool r = search(cp, word.substr(1));
	    
	    return r;	}
 
        public:
	void insertWord(string word)
	{   insertWord(root, word);  }
	
	bool search(string word)
	{   return search(root, word);	 }
	
	bool matchPatternWithWordList(vector<string> words, string pattern)
	{   
	    for(int i=0; i<words.size(); i++)
		{  for(int j=0; j<words[i].size(); j++)
		   {  if(search(words[i].substr(j)))
		      continue;
		      else
		      insertWord(words[i].substr(j));  }  }    // inserting all patterns of words (of WordList) in Trie
		      
		return search(pattern);                        // searching inputString (pattern) in Suffix Trie (WordList)                            
	} 
};


int main()
{
	Trie t;
	
    string s="hi";
	
    vector<string> words; 
    words.push_back("abc");
    words.push_back("def");
    words.push_back("ghi");
    words.push_back("hg");
    
	if(t.matchPatternWithWordList(words, s))
	cout<<"'hi' is present in WordList"<< endl; 
	else
	cout<<"'hi' is not present in WordList"<< endl; 
}
  
  

/*

    ->    Suffix Trie  
*it's a type of Trie, in which (all the patterns of inputString) are stored in Trie
*it is generally used in que related to (pattern matching)                             
*use Compressed Trie along with it for more (space optimization) & (fast search)   

 
*/










