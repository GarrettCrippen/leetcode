// let's implement a Trie

// this trie will store the 26 lower case chars
struct TrieNode
{
    bool isLeaf;
    char val;
    vector<TrieNode *> children;
    TrieNode() : isLeaf(false), children(26, nullptr), val('U') {}
};

class WordDictionary
{
private:
    TrieNode *head = nullptr;

public:
    WordDictionary()
    {
        head = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *temp = head;
        for (int i = 0; i < word.size(); i++)
        {
            vector<TrieNode *> &c = temp->children;
            // see if letter exists -> go to existing
            if (c[word[i] - 'a'])
            {
                temp = c[word[i] - 'a'];
            }
            // else add it
            else
            {
                TrieNode *child = new TrieNode();
                child->val = word[i];
                c[word[i] - 'a'] = child;
                temp = child;
            }
        }
        temp->isLeaf = true;
    }

    // if dot, then we need to enumerate all possibilities.... -> use stack
    bool search(string word)
    {
        return searchHelper(word, 0, head);
    }

    bool searchHelper(string word, int idx, TrieNode *node)
    {
        if (idx == word.size())
        {
            return node->isLeaf;
        }

        char c = word[idx];
        if (c == '.')
        {
            for (TrieNode *child : node->children)
            {
                if (child && searchHelper(word, idx + 1, child))
                {
                    return true;
                }
            }
        }
        else
        {
            TrieNode *child = node->children[c - 'a'];
            if (child)
            {
                return searchHelper(word, idx + 1, child);
            }
        }
        return false;
    }
};
