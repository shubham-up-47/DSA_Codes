#include <bits/stdc++.h>
using namespace std;

  // Trie = (Digital Tree), (O(1)), (for each node (data=char) & (no of children<=26) & (size of children array=26))
   
class TrieNode                                                       // Trie node class
{       public:
	char data;                                                       // data(char) stored in node
	TrieNode **children;                                             // baseAddresssOfArray storing addressesOfChildrenNodes 
	bool isTerminal;                                                 // tells that currentNodeIsTerminal or not
	
	TrieNode(char d)                                                 // constructor
	{  data = d;
	
	   children = new TrieNode*[26];
	   for(int i=0; i<26; i++)
	   children[i] = NULL;                                           // initialize the memory storing address by NULL
	    
	   isTerminal = false;	 } 
};


class Trie                                                           // Trie class 
{   TrieNode *root;                                                  // root pointer of Trie (Digital Tree)
  
        public:
    Trie()                                                           // constructor
    {   root = new TrieNode('\0');	 }
	
	    private:
	void insertWord(TrieNode *pp, string word)
	{   if(word.size()==0)
        {  pp->isTerminal = true;
           return;   }		
		
		TrieNode *cp;                                                // pointer corresponding to current char
		int i = word[0]-'a';                                         // index no corresponding to current char 
		if(pp->children[i]==NULL)
		{  cp = new TrieNode(word[0]);
		   pp->children[i] = cp;  }
		else                                                         // current char already found 
		cp = pp->children[i];
		
		insertWord(cp, word.substr(1));
		
		return;	 }

	bool search(TrieNode *pp, string word)
	{   if(word.size()==0)
	    return pp->isTerminal;
	    
	    TrieNode *cp;                                                // pointer corresponding to current char
	    int i = word[0]-'a';                                         // index no corresponding to current char 
	    if(pp->children[i]==NULL)
	    return 0;
	    else
	    cp = pp->children[i];
	    
	    bool r = search(cp, word.substr(1));
	    
	    return r;	}

	void removeWord(TrieNode *pp, string word)
	{   if(word.size()==0)
	    {  pp->isTerminal = 0;
	       return;	 }
	       
	    TrieNode *cp;                                                // pointer corresponding to current char
	    int i = word[0]-'a';                                         // index no corresponding to current char 
	    if(pp->children[i]==NULL)
	    return;                                                      // char not found
	    else
	    cp = pp->children[i];
		
	    removeWord(cp, word.substr(1));
		
		if(cp->isTerminal==0)
		{   for(int i=0; i<26; i++)
		    {  if(cp->children[i]!=NULL)
		       return;	 }
			
			delete cp;                                               // delete aloneleft useless Trie node            
			pp->children[i] = NULL;
			return;	 }	
		else
		return;	   }   
   
        public:                // pp is not a input in these function, so create private helper functions, to apply recursion 
	void insertWord(string word)                                     // insert
	{   insertWord(root, word);  } 
	
	bool search(string word)                                         // search
	{   return search(root, word);	 }
	
	void removeWord(string word)                                     // delete
	{   removeWord(root, word);   } 
};


int main()
{
    Trie t;
    
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    
	cout<<"Is 'and' present: "<<t.search("and")<<endl;
	cout<<"Is 'are' present: "<<t.search("are")<<endl;
	
	t.removeWord("and");
	
	cout<<"Is 'and' present: "<<t.search("and")<<endl; 
	cout<<"Is 'dot' present: "<<t.search("dot")<<endl;
}
  
  

/*

    ->  Trie (Digital Tree) 
*it's each node stores char
*it's each parent has <= 26 children & addresses of child nodes are stored in children array
*it causes (space optimization) & (fast search) 
*it has structure similar to tree, so try to apply (recursion) in all questions related to Trie
*make that node terminal (isTerminal = true), if any word ends on it 

 
*/


   // (pp=parentPointer), (cp=childPointer), (i=indexNo corresponding to currentChar in childrenArray)                            








