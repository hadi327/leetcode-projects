var WordDictionary = function() {
    this.children = {};
    this.isEnd = false;
};

WordDictionary.prototype.addWord = function(word) {
    let node = this;

    for (const ch of word) {
        if (!node.children[ch]) {
            node.children[ch] = new WordDictionary();
        }

        node = node.children[ch];
    }

    node.isEnd = true;
};

WordDictionary.prototype.search = function(word) {
    function dfs(node, index) {
        if (index === word.length) {
            return node.isEnd;
        }

        const ch = word[index];

        if (ch === '.') {
            for (const key in node.children) {
                if (dfs(node.children[key], index + 1)) {
                    return true;
                }
            }

            return false;
        }

        if (!node.children[ch]) {
            return false;
        }

        return dfs(node.children[ch], index + 1);
    }

    return dfs(this, 0);
};