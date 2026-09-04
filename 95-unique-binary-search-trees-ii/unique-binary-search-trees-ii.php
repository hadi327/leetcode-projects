class Solution {
    public function generateTrees($n) {
        if ($n == 0) {
            return [];
        }

        return $this->build(1, $n);
    }

    private function build($start, $end) {
        $trees = [];

        if ($start > $end) {
            $trees[] = null;
            return $trees;
        }

        for ($root = $start; $root <= $end; $root++) {
            $leftTrees = $this->build($start, $root - 1);
            $rightTrees = $this->build($root + 1, $end);

            foreach ($leftTrees as $left) {
                foreach ($rightTrees as $right) {
                    $node = new TreeNode($root);
                    $node->left = $left;
                    $node->right = $right;

                    $trees[] = $node;
                }
            }
        }

        return $trees;
    }
}