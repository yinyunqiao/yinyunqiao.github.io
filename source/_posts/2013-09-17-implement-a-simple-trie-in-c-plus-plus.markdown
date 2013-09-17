---
layout: post
title: "Implement a simple trie in C++"
date: 2013-09-17 10:38
comments: true
categories: Data Structures
---

The following introduction is copied from [Wikipedia][1]:

> In computer science, a trie, also called digital tree or sometimes radix tree or prefix tree 
> (as they can be searched by prefixes), is an ordered tree data structure that is used to store
> a dynamic set or associative array where the keys are usually strings. 

Trie is a good choice for [bioinformatic applications (for DNA sequence alighment)][2].
Also because trie supports ordered traversal, outputing all keys in the trie is actually a pre-order traversal.
So obviously trie can be used for sorting, for example [Burstsort][3], it's even faster than [quicksort][4] for
large data sets ( Worst case: $$ O(n\log(n)) $$ ).

A simple trie tree looks like:

{% digraph %}
  root [label=" "]
  inn [color=red]
  to [color=red]
  tea [color=red]
  ten [color=red]
  root -> i [label=i]
  root -> t [label=t]
  i -> in [label=n]
  in -> inn [label=n]
  t -> to [label=o]
  t -> te [label=e]
  te -> tea [label=a]
  te -> ten [label=n]
{% enddigraph%}

{% codeblock naive trie implementation lang:c++ %}
#include <iostream>
#include <string>
using namespace std;
class node {
public:
	node() : is_word(false) {
		memset(children, 0, sizeof(children));
	}
	node *children[26];
	bool is_word;
};
class trie {
	node *root;
	trie() : root(0) {}
	void insert(const string& str) {
		if (!root)
			root = new node;
		node *loc = root;
		for (int i=0; i < str.size(); i++) {
			int idx = str[i] - 'a';
			if (!loc->children[idx]) {
				loc->children[idx] = new node;
			}
			loc = loc->children[idx];
		}
		loc->is_word = true;
	}
	bool search(const string& str) {
		node *loc = root;
		for (int i=0; i < str.size(); i++) {
			int idx = str[i] - 'a';
			if (!loc->children[idx]) return false;
			loc = loc->children[idx];
		}
		return loc->is_word;
	}
};

{% endcodeblock %}

## Follow-ups ##
1. tripple array trie
2. double array trie
3. http://en.wikipedia.org/wiki/Ternary_search_tree
4. Succinct Data Structures http://stevehanov.ca/blog/index.php?id=120
5. http://en.wikipedia.org/wiki/BK-tree    spell checking
6. http://en.wikipedia.org/wiki/Patricia_tree

## References ##
1. <http://wenku.baidu.com/view/71e82437f111f18583d05a54.html>
2. <http://linux.thai.net/~thep/datrie/datrie.html>

[1]: http://en.wikipedia.org/wiki/Trie
[2]: http://citeseerx.ist.psu.edu/viewdoc/download;jsessionid=89F5C5F504C452DFA838F1E4AD659D7C?doi=10.1.1.57.2897&rep=rep1&type=pdf
[3]: http://en.wikipedia.org/wiki/Burstsort
[4]: http://en.wikipedia.org/wiki/Quicksort
