class TrieNode
{
public:
    char val;
    bool isWord;
    vector<TrieNode *> children;
    TrieNode(char c) : val(c), isWord(false), children(26, nullptr) {}
};

class Trie
{
private:
    TrieNode *head;

public:
    Trie()
    {
        head = new TrieNode(' ');
    }

    void insert(string word)
    {
        TrieNode *temp = head;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                temp->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *temp = head;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[word[i] - 'a'];
        }
        return temp->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = head;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children[prefix[i] - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[prefix[i] - 'a'];
        }
        return true;
    }
};