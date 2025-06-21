# Autocomplete-Trie
The TRIE Data Structure, also known as the Prefix Tree or Radix Tree, is regarded as an excellent Data Structure for processing and storing strings, and is primarily used for word retrieval. Autocomplete is one of the most popular features utilized in Search Engines from the User Experience perspective.<br>
It is a simple idea that recommends auto-completing the query based on the strings stored in the Trie. It is assumed trie stores past searches by the users. Given a query prefix, we search for all words that match this query.
<br>
# Improvements
The number of matches might just be too large if the strings stored are large. So we have to be selective while displaying them. We can restrict ourselves to displaying only the relevant results. We can consider the past search history and show only the most searched matching strings as relevant results. Store another value for each node where isleaf=True, which contains the number of hits for that query search. For example, if “daksh” is searched 8 times, then we store this 8 at the last node for “ashi”. Now when we want to show the recommendations, we display the top 'k' matches with the highest hits.
<br>
# Time Complexity
This is a very efficient method used for auto-suggesting. The run time complexity of adding a word is proportional to the length of the word to be added. We can safely assume that a word is not more than 26 characters, so it is constant time work. Or if you want to say it L as the max length of the word, then the insertion runtime is O(L). Adding N words in the Trie would take O(L×N) time. Finding all words by prefix will take O(P+K×L), where P is the length of the prefix supplied, K is the number of words where the prefix matched, and L is the average length of suffixes.
<br>
# Advantages
1. No Collision of different Keys in a TRIE Data Structure make it an effective Data Structure for storing lexicographic words found in a Dictionary.
2. The Best Case Time Complexity has been described as O(P) while the Average and Worst Case is described as O(P+K×L).
3. It can be optimized to support a larger collection of words using Compact TRIE Data Structure Implementations.
