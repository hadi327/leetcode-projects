var findWords = function(board, words) {
    const root = {};

    for (const word of words) {
        let node = root;

        for (const ch of word) {
            if (!node[ch]) {
                node[ch] = {};
            }

            node = node[ch];
        }

        node.word = word;
    }

    const result = [];
    const rows = board.length;
    const cols = board[0].length;

    function dfs(r, c, node) {
        if (
            r < 0 || r >= rows ||
            c < 0 || c >= cols
        ) {
            return;
        }

        const ch = board[r][c];

        if (ch === '#' || !node[ch]) {
            return;
        }

        const next = node[ch];

        if (next.word) {
            result.push(next.word);
            next.word = null;
        }

        board[r][c] = '#';

        dfs(r + 1, c, next);
        dfs(r - 1, c, next);
        dfs(r, c + 1, next);
        dfs(r, c - 1, next);

        board[r][c] = ch;
    }

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            dfs(r, c, root);
        }
    }

    return result;
};