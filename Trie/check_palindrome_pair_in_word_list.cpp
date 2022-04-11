#include <bits/stdc++.h>
using namespace std;
                               
  
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
	    return pp->isTerminal;                                      
	      
	    TrieNode *cp;
	    int i = word[0]-'a';
	    if(pp->children[i]==NULL)
	    return 0;
	    else
	    cp = pp->children[i];
	    
	    bool r = search(cp, word.substr(1));
	    
	    return r;	}
	
	bool isPalindromeWord(string s)                                    // checks input word is palindrome or not            
	{   
	    for(int i=0,j=s.size()-1;  i<j;  i++,j--)
	    {   if(s[i] != s[j])
	        return 0;  }
	        
	    return 1;
    }
	        
	int maxSymmetryLengthOnLeft(string s)                              // it will return (3) if input string (miximabc) 
	{   
	    for(int i=0,L=s.size();  L>0;  i++,L--)
	    {   if(isPalindromeWord(s.substr(0,s.size()-i)))
	        return L;  }
    } 
	                                                                                              
	int maxSymmetryLengthOnRight(string s)                             // it will return (3) if input string (abcmixim) 
	{   
	    for(int i=0,R=s.size();  R>0;  i++,R--)
	    {   if(isPalindromeWord(s.substr(i)))
	        return R;  }
    } 
 
        public:
	void insertWord(string word)
	{   insertWord(root, word);  }
	                                                 
	bool search(string word)
	{   return search(root, word);	 }
	
  // palindrome = sequence that reads (same backwards) as (forwards)
  // (a), (axa), (aaaa) are palindrome words
  // (abc, cba), (abcmixim, cba), (miximabc, cba) are palindrome pairs  
	
	bool checkPalindromePairInWordList(vector<string> words)         
	{   
	    for(int i=0; i<words.size(); i++)
	    {   string s = words[i];
	        insertWord(s);                                             // inserting (all words of WordList) in Trie
	        
	        int L = maxSymmetryLengthOnLeft(s);
	        int R = maxSymmetryLengthOnRight(s);    
	    	
	    	insertWord(s.substr(L));                                   // inserting (abc) if words[i]=(miximabc)  [covering (miximabc,cba) case]
	    	insertWord(s.substr(0,s.size()-R));	 }                     // inserting (abc) if words[i]=(abcmixim)  [covering (abcmixim,cba) case]
	
	    for(int i=0; i<words.size(); i++)
	    {   reverse(words[i].begin(), words[i].end());
	        if(search(words[i]))
	        return 1;	}                                              // return 1, if palindrome word/pair is found 
	        
	    return 0;                                                      // return 0, otherwise                                 
	} 
};


int main() 
{
	Trie t;
 
    vector<string> words;                                              // WordList
    words.push_back("abcmixim");
    words.push_back("def");
    words.push_back("cba");
    words.push_back("wolf");
                      
					                      
	cout<<"Is palindrome word/pair present in the given WordList: "; 
	cout<<(t.checkPalindromePairInWordList(words) ? "Yes\n\n" : "No\n\n");
	
}       // checking any (palindrome word) or (pair of 2 words which forms palindrome word on joining) is present in WordList or not
  
 











