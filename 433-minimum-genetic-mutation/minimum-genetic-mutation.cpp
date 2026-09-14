class Solution {
public:
    int minMutation(
        string startGene,
        string endGene,
        vector<string>& bank
    ) {
        unordered_set<string> valid(
            bank.begin(),
            bank.end()
        );

        if (!valid.count(endGene)) {
            return -1;
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({startGene, 0});
        visited.insert(startGene);

        string genes = "ACGT";

        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();

            if (gene == endGene) {
                return steps;
            }

            for (int i = 0; i < gene.size(); i++) {
                char original = gene[i];

                for (char c : genes) {
                    if (c == original) continue;

                    gene[i] = c;

                    if (valid.count(gene) &&
                        !visited.count(gene)) {
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }

                gene[i] = original;
            }
        }

        return -1;
    }
};