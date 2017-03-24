class Trie {

public:
	bool end = false;
	vector<Trie*> child;

	/** Initialize your data structure here. */
	Trie() {
		child.clear(); child.resize(26, NULL);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {

		if (word == "") {
			end = true;
			return;
		}

		int idx = word[0] - 'a';
		string sub = word.substr(1, int(word.length()) - 1);

		if (child[idx] == NULL) {
			child[idx] = new Trie();
		}
		child[idx]->insert(sub);

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

		if (word == "") {
			return end;
		}

		int idx = word[0] - 'a';
		string sub = word.substr(1, int(word.length()) - 1);

		if (child[idx] == NULL) {
			return false;
		} else {
			return child[idx]->search(sub);
		}

	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {

		if (prefix == "") {
			return true;
		}

		int idx = prefix[0] - 'a';
		string sub = prefix.substr(1, int(prefix.length()) - 1);

		if (child[idx] == NULL) {
			return false;
		} else {
			return child[idx]->startsWith(sub);
		}

	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
